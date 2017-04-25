#ifndef SHIPMENTSCHEDULE_H
#define SHIPMENTSCHEDULE_H
#include <QVector>
#include <QString>
#include <QMap>
#include <QtSql>
#include <vector>
#include <QList>
#include "RailCar.h"


class ShipmentSchedule
{
public:
    // initialize railcar database -- can improvise to be ShipmentSchedule(date);
    ShipmentSchedule();

    //copy constructor
    ShipmentSchedule(const ShipmentSchedule &other);
    void BuildDatabase();

    void UpdateDatabase(QString coilID, QString RCID);

    // Compare if RailCar in database
    //RailCar* CheckCar(const QString id);


    RailCar* GetCar(const QString id);

    QVector<RailCar*> getCars();

    QMap<QString, QString> getCoilData();

    ~ShipmentSchedule();


private:

    // contains list of railcar IDs
    QVector<RailCar*> _railcarvector;
    QVector<QString> _rcvectStr;
    QMap<QString, QList<QString>> _map;

    QString _servername = "DLI108WES7";
    QString _dbname = "rcdata";
    QSqlDatabase _db = QSqlDatabase::addDatabase("QODBC");

};

#endif // SHIPMENTSCHEDULE_H
