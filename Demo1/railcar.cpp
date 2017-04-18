#include "railcar.h"


RailCar::RailCar()
{

}

RailCar::~RailCar()
{
}

RailCar::RailCar(const QString carID)
{
    coilsVerified = 0;
    verified = false;
    _carID = carID;
    this->BuildCoilData(carID);
}

void RailCar::BuildCoilData(const QString carID)
{
    std::vector<SteelCoil*> stdvect;
//    // find carID that matches -- then add all the coils
    const QString one = "AOK 494535";
    const QString two = "CSXT 493506";
    const QString three = "IHB 166590";
    const QString four = "NS 166154";
    const QString five = "NS 167155";

    if (carID == one)
    {

        SteelCoil* coil1 = new SteelCoil("855-05865");
        SteelCoil* coil2 = new SteelCoil("854-05990");
        SteelCoil* coil3 = new SteelCoil("855-18280");
        SteelCoil* coil4 = new SteelCoil("857-77063");
        SteelCoil* coil5 = new SteelCoil("857-77175");
        // add the coils to the _coilvector
        stdvect.push_back(coil1);
        stdvect.push_back(coil2);
        stdvect.push_back(coil3);
        stdvect.push_back(coil4);
        stdvect.push_back(coil5);

    }
    else if (carID == two)
    {
        SteelCoil* coil1 = new SteelCoil("854-05807");
        SteelCoil* coil2 = new SteelCoil("854-05851");
        SteelCoil* coil3 = new SteelCoil("854-05879");
        SteelCoil* coil4 = new SteelCoil("854-05986");
        SteelCoil* coil5 = new SteelCoil("857-77286");
        // add the coils to the _coilvector
        stdvect.push_back(coil1);
        stdvect.push_back(coil2);
        stdvect.push_back(coil3);
        stdvect.push_back(coil4);
        stdvect.push_back(coil5);
    }
    else if (carID == three)
    {
        SteelCoil* coil1 = new SteelCoil("852-19957");
        SteelCoil* coil2 = new SteelCoil("852-20057");
        SteelCoil* coil3 = new SteelCoil("852-20065");
        // add the coils to the _coilvector
        stdvect.push_back(coil1);
        stdvect.push_back(coil2);
        stdvect.push_back(coil3);
    }
    else if (carID == four)
    {
        SteelCoil* coil1 = new SteelCoil("855-11944");
        SteelCoil* coil2 = new SteelCoil("840-20888");
        // add the coils to the _coilvector
        stdvect.push_back(coil1);
        stdvect.push_back(coil2);
    } else if (carID == five)
    {
        SteelCoil* coil1 = new SteelCoil("854-57226");
        SteelCoil* coil2 = new SteelCoil("840-20863");
        // add the coils to the _coilvector
        stdvect.push_back(coil1);
        stdvect.push_back(coil2);
    }

    _coilvector = QVector<SteelCoil*>::fromStdVector(stdvect);
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
