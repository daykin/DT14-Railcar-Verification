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

    // constructor for railcar
    RailCar(const QString carID);

    //copy constructor
    RailCar(const RailCar &other);

    void BuildCoilData(const QString carID);

    // get size of vector coils
    int VectCoilSize();

    QString getCarID();

    QVector<SteelCoil*> getCoilVector();


    ~RailCar();



private:
    QString _carID; //railcar ID

    // list that contains all the coils
    QVector<SteelCoil*> _coilvector;


};

#endif // RAILCAR_H
