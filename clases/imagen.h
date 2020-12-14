#ifndef IMAGEN_H
#define IMAGEN_H

#include <vector>
#include <string>
#include <utility>
#include "metadato.h"
#include "pixel.h"

using namespace std;

class Imagen{
private:
    vector< vector<Pixel> > pix;
    Metadato met;
    float ancho, alto;
    unsigned TamPX, TamPY;
    string unidad;
    void InicializarVector();
public:
    Imagen();
    void ModificarTam(unsigned x, unsigned y);
    void ModificarVP(Pixel pixar, unsigned posx, unsigned posy); //modificar un pixel en particular
    void ModificarMetadato(string p, string s);
    void ModificarAlto(float a);
    void ModificarAncho(float a);
    void ModificarTamX(unsigned x);
    void ModificarTamY(unsigned y);
    void ModificarUnidad(string u);
    Pixel VerPixel(unsigned posx, unsigned posy);
    string VerMetadato();
    float VerAlto();
    float VerAncho();
    unsigned VerTamX();
    unsigned VerTamY();
    string VerUnidad();
    string GuardarMetadato();
    void ModifMeta(string clave, string valor);
    void VaciarMetadato();
};

#endif
