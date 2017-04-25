/*
 * This program is free software. For more information and usage rights see the inlcuded license file.
 */

#include "railcar.h"


RailCar::RailCar()
{

}

RailCar::~RailCar()
{
}

RailCar::RailCar(const QString carID,  QMap<QString, QList<QString>> coils, QString verfy)
{
    coilsVerified = 0;
    if (verfy == "Yes")
        verified = true;
    else
        verified = false;
    _carID = carID;
    this->BuildCoilData(carID, coils);
}

void RailCar::BuildCoilData(const QString carID, const QMap<QString, QList<QString>> coildata)
{
  QMap<QString, QList<QString>>::const_iterator i = coildata.constBegin();
       while (i != coildata.constEnd()) {


           if (carID == i.key())
           {
               
               _coilvector.push_back(new SteelCoil(i.value()[0], i.value()[1]));
           }
           ++i;
       }
}


int RailCar::VectCoilSize()
{
    return _coilvector.size();
}

QString RailCar::getCarID()
{
    return this->_carID;
}

QVector<SteelCoil*> RailCar::getCoilVector()
{
    return this->_coilvector;
}

bool RailCar::isVerified(){
    return verified;
}

void RailCar::verify(){
    coilsVerified++;

    if(coilsVerified == _coilvector.size()){
        verified = true;
    }
}
