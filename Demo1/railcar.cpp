#include "railcar.h"


RailCar::RailCar()
{

}

RailCar::~RailCar()
{
}

RailCar::RailCar(const QString carID,  QMap<QString, QString> coils)
{
    coilsVerified = 0;
    verified = false;
    _carID = carID;
    this->BuildCoilData(carID, coils);
}

void RailCar::BuildCoilData(const QString carID, const QMap<QString, QString> coildata)
{
  QMap<QString, QString>::const_iterator i = coildata.constBegin();
       while (i != coildata.constEnd()) {

           if (carID == i.key())
           {
               _coilvector.push_back(new SteelCoil(i.value()));
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
