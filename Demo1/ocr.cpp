#include "ocr.h"

using namespace cv;
using namespace std;

OCR::OCR()
{

}

QString OCR::getId(QString file){
    //testing static images
//    file = "input1.jpg";

    //image processing
    processInput(file);

    //non-inverted
    QString output = runRegex(runOCR("out.jpg"));

    if(found){
        return output;
    }

    //inverted
    return runRegex(runOCR("outi.jpg"));
}

string OCR::runOCR(QString file){
    //2 to 4 characters, zero or more spaces, 5 numbers
    const char* imgName = file.toStdString().c_str();

    const char* railcarLabel = "";
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    api->SetVariable("tessedit_write_images", "true");
    if (api->Init(NULL, "eng")){
            cerr<<"Something broke initializing Tesseract..."<<endl;
            exit(1);
    }

    // plug the picture into the API
    Pix *img = pixRead(imgName);
    api->SetImage(img);

    //Get API response in tesseract
    api->SetSourceResolution(70);
    railcarLabel = api->GetUTF8Text();
    api->End();

    string outText(railcarLabel);

    delete[] railcarLabel;

    return outText;
}

QString OCR::runRegex(string outText){

    outText.erase(find_if_not(outText.rbegin(),outText.rend(),[](int c){return isspace(c);}).base(), outText.end());

    //regex search
    regex rc_reg("([A-Z]{2,4}) *([0-9]{6})");
    smatch match;

    QString output = QString::fromStdString(outText);

    if(regex_search(outText, match, rc_reg)){
        output = QString::fromStdString(match.str(1) + " " + match.str(2));
        found = true;
    }

    return output;
}

//image processing
void OCR::processInput(QString file){
    //load image
    string imgName = file.toStdString();

    //convert image to b/w
    Mat image = imread(imgName, CV_LOAD_IMAGE_GRAYSCALE);
    Mat large  = image > 60; // >60

    Mat rgb;
    // downsample and use it for processing
    pyrDown(large, rgb);

    //inverted and non-inverted for white or black text
    //non-inverted
    processImage(rgb, "out.jpg");

    //inverted
    bitwise_not(rgb, rgb);
    processImage(rgb, "outi.jpg");

}

void OCR::processImage(Mat rgb, string name){
    //create output base image
    Mat out = Mat::zeros(rgb.size(), rgb.type());
    out.setTo(Scalar(255,255,255));

    // morphological gradient
    Mat grad;
    Mat morphKernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
    morphologyEx(rgb, grad, MORPH_GRADIENT, morphKernel);

    // binarize
    Mat bw;
    threshold(grad, bw, 0.0, 255.0, THRESH_BINARY | THRESH_OTSU);

    // connect horizontally oriented regions
    Mat connected;
    morphKernel = getStructuringElement(MORPH_RECT, Size(9, 1));
    morphologyEx(bw, connected, MORPH_CLOSE, morphKernel);

    // find contours
    Mat mask = Mat::zeros(bw.size(), CV_8UC1);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(connected, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    // filter contours
    for(int idx = 0; idx >= 0; idx = hierarchy[idx][0])
    {
        Rect rect = boundingRect(contours[idx]);
        Mat maskROI(mask, rect);
        maskROI = Scalar(0, 0, 0);
        // fill the contour
        drawContours(mask, contours, idx, Scalar(255, 255, 255), CV_FILLED);
        // ratio of non-zero pixels in the filled region
        double r = (double)countNonZero(maskROI)/(rect.width*rect.height);

        if (r > .60 /* assume at least 60% of the area is filled if it contains text */
            &&
            (rect.height > 30 && rect.width > 30) //30
           )
        {
            Mat roi = rgb(rect);
            roi.copyTo(out(rect));
        }
    }

//    imwrite(string("rgb.jpg"), rgb); //enable to see output before processing
    imwrite(string(name), out);
}
