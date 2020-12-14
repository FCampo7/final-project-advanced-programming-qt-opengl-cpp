#ifndef FORMATOMIF_H
#define FORMATOMIF_H

#include <fstream>
#include <iostream>
#include <string>
#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include "imagen.h"
#include "archivo.cpp"

using namespace std;

class Formatomif : public archivo{
public:
    Formatomif(){}
	void guardar(string nombrenuevo, Imagen img);
    void cargar(string nombrenuevo, Imagen &img);
    ~Formatomif(){}
};

#endif
