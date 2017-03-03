#include "steelcoil.h"

SteelCoil::SteelCoil()
{

}

SteelCoil::SteelCoil(QString id)
{
    this->_id = id;
}

QString SteelCoil::GetCoil()
{
    return this->_id;
}
