#ifndef STEELCOIL_H
#define STEELCOIL_H
#include <QString>
#include <Qvector>


class SteelCoil
{

private:
    QString _id;


public:
    SteelCoil(); // default constructor

    SteelCoil(QString id); //constructor with ID

    //copy constructor
    SteelCoil(const SteelCoil &other);
    QString GetCoil();
    ~SteelCoil();


};

#endif // STEELCOILS_H
