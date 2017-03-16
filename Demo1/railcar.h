#ifndef RAILCAR_H
#define RAILCAR_H
#include <QString>
#include <QVector>
#include <vector>
#include "steelcoil.h"


class RailCar
{
public:
    RailCar();

    // initialize all the coils number correspond to the carID
    RailCar(const QString carID);

    void BuildCoilData(const QString carID);

    // get size of vector coils
    int VectCoilSize();

    QString getCarID();

    QVector<SteelCoil*> getCoilVector();


private:
    QString _carID; //railcar ID

    // list that contains all the coils
    QVector<SteelCoil*> _coilvector;


};

#endif // RAILCAR_H
