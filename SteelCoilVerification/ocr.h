#ifndef OCR_H
#define OCR_H

#include <cstdlib>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/text/ocr.hpp>
#include <regex>
#include <iostream>
#include <QString>

using namespace cv;
using namespace std;

class OCR
{
public:
    OCR();
    bool isFound()const{return found;}
    QString getId(QString);
    QString runRegex(string);
private:
    void processInput(QString);
    void processImage(Mat, string);
    string runOCR(QString);
    bool found=false;

};

#endif // OCR_H
