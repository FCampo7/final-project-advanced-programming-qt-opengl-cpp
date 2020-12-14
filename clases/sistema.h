#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "clases/archivo.cpp"
#include "clases/formatomif.h"
#include "clases/imagen.h"
#include "clases/graficador.h"
#include "clases/procesador.cpp"
#include "clases/filtrocolor.h"
#include "clases/detectordeestructuras.h"

using namespace std;

class Sistema{
private:
    Imagen img;
    Graficador graf;
    archivo *arch;
    Procesador *proc;
public:
    Sistema();
    void CargarImagen(string nombre);
    void GuardarImagen(string nombre);
    int VerPosX();
    int VerPosY();
    Pixel VerPixel(unsigned posx, unsigned posy);
    Imagen DevolverImg();
    void RecibirImagen(Imagen ima);
    void GraficarImagen();
    void GrafImg();
    void ModificarTam(unsigned tamx, unsigned tamy);
    void ModificarAncho(float ancho);
    void ModificarAlto(float alto);
    void ModificarUnidad(string unidad);
    void ModificarMetadatos(string clave, string valor);
    void ModificarPixel(Pixel p, unsigned posx, unsigned posy);
    void AplicarFiltro(Pixel p);
    void Detectar(int px, int py, Pixel p);
    string VerTamPixeles();
    string VerTamUnidad();
    string VerMetadatos();
};

#endif // SISTEMA_H
