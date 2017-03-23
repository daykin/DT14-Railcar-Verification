#include "ocr.h"

using namespace std;

OCR::OCR()
{

}

QString OCR::getId(QString file){
    //2 to 4 characters, zero or more spaces, 5 numbers
    const char* imgName = file.toStdString().c_str();

    //const regex rc_reg("([A-Z]{2,4})+(\\s)*+(\\d{2-6})");
    //cmatch lbl;
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
    //    regex_match(railcarLabel, lbl, rc_reg);
    //    cout<<lbl.empty()<<endl;
    api->End();

    QString output = QString(railcarLabel);
    delete[] railcarLabel;

    return output;
}
