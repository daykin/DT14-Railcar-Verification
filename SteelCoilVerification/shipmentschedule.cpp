#include "shipmentschedule.h"
#include <QtSql>
class mainwindow;


ShipmentSchedule::ShipmentSchedule()
{
    _railcarvector = QVector<RailCar*>();
}

ShipmentSchedule::~ShipmentSchedule()
{

}

void ShipmentSchedule::BuildDatabase()
{
    /**this->_railcarvector.push_back(new RailCar("AOK 494535"));
    this->_railcarvector.push_back(new RailCar("CSXT 493506"));
    this->_railcarvector.push_back(new RailCar("IHB 166590"));
    this->_railcarvector.push_back(new RailCar("NS 166154"));
    this->_railcarvector.push_back(new RailCar("NS 167155"));
    */

    _db.setConnectOptions();
    QString dsn = QString("DRIVER={SQL Server}; SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(_servername).arg(_dbname);
    _db.setDatabaseName(dsn);

    QMap<QString,int>key_map;

    if (_db.open())
    {
            QSqlQuery qry;
            QString temp_str;

            if (qry.exec("SELECT * FROM [rcdata].dbo.Table_2"))
            {
                while(qry.next())
                {
                    temp_str = qry.value(0).toString();
                    key_map.insert(temp_str,1);
                    _map.insertMulti(temp_str, qry.value(1).toString());
                }
            }
            _db.close();
     }

     QMap<QString, int>::const_iterator i = key_map.constBegin();
     while (i != key_map.constEnd()) {
         this->_railcarvector.push_back(new RailCar(i.key(), _map));
         ++i;
    }
}

void ShipmentSchedule::UpdateDatabase(QString coilID, RailCar* RCID)
{
    QSqlQuery qry;
    if (_db.open())
    {
       // qry.first();
        QString execline = QString("UPDATE Table_2 SET Coils_Verification ='Yes' WHERE CoilsID ='%1'").arg(coilID);
        qry.exec(execline);

        _db.close();
    }

    // Update railcar status in the database
    if (_db.open())
    {
        if (RCID->isVerified())
        {
            QString execRC = QString("UPDATE Table_2 SET RC_Verification ='Yes' WHERE RailcarID ='%1'").arg(RCID->getCarID());
            qry.exec(execRC);

        }
        _db.close();
    }

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

QVector<RailCar*> ShipmentSchedule::getCars(){
    return _railcarvector;
}

