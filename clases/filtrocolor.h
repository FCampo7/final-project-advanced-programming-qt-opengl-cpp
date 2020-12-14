#ifndef FILTROCOLOR_H
#define FILTROCOLOR_H

#include "procesador.cpp"
#include "imagen.h"

class FiltroColor : public Procesador{
private:
    Pixel p;
public:
    FiltroColor(Pixel p1);
    void procesar (Imagen &ima);
    ~FiltroColor(){}
};

#endif
