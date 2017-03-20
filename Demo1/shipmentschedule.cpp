#include "shipmentschedule.h"

class mainwindow;


ShipmentSchedule::ShipmentSchedule()
{
}

ShipmentSchedule::~ShipmentSchedule()
{

}

void ShipmentSchedule::BuildDatabase()
{

    std::vector<RailCar*> stdcarvec;
    stdcarvec.push_back(new RailCar("AOK 494535"));
    stdcarvec.push_back(new RailCar("CSXT 493506"));
    stdcarvec.push_back(new RailCar("IHB 166590"));
    this->_railcarvector = QVector<RailCar*>::fromStdVector(stdcarvec);




}

/*** check if the RailCar is in the database
 * if yes, return railcar pointer
 * else return nullptr
 */
RailCar* ShipmentSchedule::GetCar(const QString id)
{
   for (int i = 0 ; i < _railcarvector.size(); i++)
   {
       if (_railcarvector[i]->getCarID() == id)
           return _railcarvector[i];

   }
   return nullptr;

}

