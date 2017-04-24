#ifndef STEELCOIL_H
#define STEELCOIL_H
#include <QString>
#include <Qvector>


class SteelCoil
{

private:
    QString _id;
    bool verified;

public:
    SteelCoil(); // default constructor

    ~SteelCoil();

     SteelCoil(QString id, QString verfy); //constructor with ID

    //copy constructor
    SteelCoil(const SteelCoil &other);

    QString GetCoil();

    bool isVerified();

    void verify();
};

#endif // STEELCOILS_H
