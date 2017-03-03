#ifndef STEELCOIL_H
#define STEELCOIL_H
#include <QString>
#include <Qvector>


class SteelCoil
{

private:
    QString _id;


public:
    SteelCoil();
    SteelCoil(QString id);
    QString GetCoil();


};

#endif // STEELCOILS_H
