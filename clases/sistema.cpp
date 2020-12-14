#include "sistema.h"
#include <sstream>

Sistema::Sistema(){}

void Sistema::CargarImagen(string nombre){
    img.VaciarMetadato();
    arch=new Formatomif();
    arch->cargar(nombre, img);
    delete arch;
}

void Sistema::GuardarImagen(string nombre){
	arch=new Formatomif();
    arch->guardar(nombre, img);
    delete arch;
}

int Sistema::VerPosX(){
    return graf.verx();
}

int Sistema::VerPosY(){
    return graf.very();
}

void Sistema::RecibirImagen(Imagen ima){
	img=ima;
}

Pixel Sistema::VerPixel(unsigned posx, unsigned posy){
    return img.VerPixel(posx, posy);
}

Imagen Sistema::DevolverImg(){
    return img;
}

void Sistema::GraficarImagen(){
    graf.recibir_imagen(&img);
    graf.resize(400, 300);
    graf.show();
}

void Sistema::GrafImg(){
    graf.update();
}

void Sistema::ModificarTam(unsigned tamx, unsigned tamy){
    img.ModificarTam(tamx, tamy);
}

void Sistema::ModificarAncho(float ancho){
    img.ModificarAncho(ancho);
}

void Sistema::ModificarAlto(float alto){
    img.ModificarAlto(alto);
}

void Sistema::ModificarUnidad(string unidad){
    img.ModificarUnidad(unidad);
}

void Sistema::ModificarMetadatos(string clave, string valor){
    img.ModifMeta(clave, valor);
}

void Sistema::ModificarPixel(Pixel p, unsigned posx, unsigned posy){
    img.ModificarVP(p, posx, posy);
}

void Sistema::AplicarFiltro(Pixel p){
    proc=new FiltroColor(p);
    proc->procesar(img);
    delete proc;
}

void Sistema::Detectar(int px, int py, Pixel p){
    proc=new DetectorDeEstructuras(px, py, p);
    proc->procesar(img);
    delete proc;
}

string Sistema::VerTamPixeles(){
    stringstream aux;
    string s="Pixeles: ";
    aux<<s<<img.VerTamX()<<"x"<<img.VerTamY()<<'\n';
    s=aux.str();
    return s;
}

string Sistema::VerTamUnidad(){
    stringstream aux;
    string s="Tamaño: ";
    aux<<s<<img.VerAncho()<<"x"<<img.VerAlto()<<" "<<img.VerUnidad()<<'\n';
    s=aux.str();
    return s;
}

string Sistema::VerMetadatos(){
    return img.VerMetadato();
}
