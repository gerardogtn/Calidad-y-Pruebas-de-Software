#pragma once

template <class Base, class SubClase>
class ClonTemplate : public Base
{
public:
    //using Base::Base;

    virtual void clonar(Base*& b)
    {
        b = new SubClase(dynamic_cast<SubClase&>(*this));    
    }
};
