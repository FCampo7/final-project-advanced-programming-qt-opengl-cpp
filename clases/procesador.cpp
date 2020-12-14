#ifndef PROCESADOR_H
#define PROCESADOR_H

#include "imagen.h"

using namespace std;

class Procesador{
public:
    Procesador(){}
    virtual void procesar(Imagen &ima)=0;
    virtual ~Procesador(){}
};

#endif

