#ifndef SHIPMENTSCHEDULE_H
#define SHIPMENTSCHEDULE_H
#include <QVector>
#include <QString>
#include <vector>
#include "RailCar.h"


class ShipmentSchedule
{
public:
    // initialize railcar database -- can improvise to be ShipmentSchedule(date);
    ShipmentSchedule();

    //copy constructor
    ShipmentSchedule(const ShipmentSchedule &other);
    void BuildDatabase();

    // Compare if RailCar in database
    //RailCar* CheckCar(const QString id);


    RailCar* GetCar(const QString id);

    QVector<RailCar*> getCars();

    ~ShipmentSchedule();


private:

    // contains list of railcar IDs
    QVector<RailCar*> _railcarvector;
    QVector<QString> _rcvectStr;

};

#endif // SHIPMENTSCHEDULE_H
