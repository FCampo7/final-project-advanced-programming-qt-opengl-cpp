#ifndef METADATO_H
#define METADATO_H

#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

class Metadato{
private:
    map<string, string> contenido;
public:
    void CargarMetadato(string f, string s);
    unsigned int TamMet();
    void VaciarMetadato();
    void ModifMeta(string clave, string valor);
    string VerMetadatos();
    string GuardarMetadatos();
};

#endif
