#include "steelcoil.h"

SteelCoil::SteelCoil()
{
}

SteelCoil::~SteelCoil()
{
}

SteelCoil::SteelCoil(QString id, QString verfy)
{
    if (verfy == "Yes")
         verified = true;
    else
        verified = false;
    this->_id = id;
}

QString SteelCoil::GetCoil()
{
    return this->_id;
}

bool SteelCoil::isVerified(){
    return verified;
}

void SteelCoil::verify(){
    verified = true;
}
