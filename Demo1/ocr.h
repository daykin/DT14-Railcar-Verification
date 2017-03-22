#ifndef OCR_H
#define OCR_H

#include <cstdlib>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <regex>
#include <iostream>
#include <QString>

class OCR
{
public:
    OCR();

    QString getId(QString);
};

#endif // OCR_H
