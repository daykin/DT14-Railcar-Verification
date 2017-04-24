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
   

    _db.setConnectOptions();
    QString dsn = QString("DRIVER={SQL Server}; SERVER=%1;DATABASE=%2;"

                          "Trusted_Connection=Yes;").arg(_servername).arg(_dbname);

    _db.setDatabaseName(dsn);

    QMap<QString,QString>key_map;


    if (_db.open())

    {

            QSqlQuery qry;

            QString temp_str;



            if (qry.exec("SELECT * FROM [rcdata].dbo.Table_2"))

            {

                while(qry.next())

                {

                     QList<QString> data;

                    temp_str = qry.value(0).toString();

                    key_map.insert(temp_str,qry.value(2).toString()); // build map with all railcar ID as keys

                    data << qry.value(1).toString()<< qry.value(3).toString();

                    _map.insertMulti(temp_str, data); //map[RailcarID] = [coilsIDs, verify_stat]



                }

            }

            _db.close();

     }



     QMap<QString, QString>::const_iterator i = key_map.constBegin();



     while (i != key_map.constEnd()) {

         this->_railcarvector.push_back(new RailCar(i.key(), _map, i.value()));

         ++i;

    }
}

void ShipmentSchedule::UpdateDatabase(QString coilID, QString RCID)
{
    QSqlQuery qry;
    if (_db.open())

    {

       // qry.first();

        QString execline = QString("UPDATE Table_2 SET Coils_Verification ='Yes' "

                                   "WHERE CoilsID in (%1)").arg(coilID);

        qry.exec(execline);



        QString execRC = QString("UPDATE Table_2 SET RC_Verification ='Yes' WHERE RailcarID in (%1)").arg(RCID);



        qry.exec(execRC);



    }

    _db.close();

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

