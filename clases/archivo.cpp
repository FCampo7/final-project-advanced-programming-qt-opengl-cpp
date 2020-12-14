#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "imagen.h"

using namespace std;

class archivo{
public:
    archivo(){}
	virtual void guardar(string nombrenuevo, Imagen img)=0;
    virtual void cargar(string nombrenuevo, Imagen &img)=0;
    virtual ~archivo(){}
};

#endif
