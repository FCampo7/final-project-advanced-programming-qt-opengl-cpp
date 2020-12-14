#include "imagen.h"

Imagen::Imagen(){
    ancho=0;
    alto=0;
    TamPX=0;
    TamPY=0;
    unidad="n/s";
}

void Imagen::ModificarTam(unsigned x, unsigned y){
    TamPX=x;
    TamPY=y;
    InicializarVector();
}

void Imagen::ModificarVP(Pixel pixar, unsigned posx, unsigned posy){
    pix[posy][posx]=pixar;
}

void Imagen::ModificarMetadato(string p, string s){
    met.CargarMetadato(p, s);
}

void Imagen::ModificarAlto(float a){
    alto=a;
}

void Imagen::ModificarAncho(float a){
    ancho=a;
}

void Imagen::ModificarTamX(unsigned x){
    TamPX=x;
}

void Imagen::ModificarTamY(unsigned y){
    TamPY=y;
}

void Imagen::ModificarUnidad(string u){
    unidad=u;
}

Pixel Imagen::VerPixel(unsigned posx, unsigned posy){
    return pix[posy][posx];
}

string Imagen::VerMetadato(){
    string s;
    s=met.VerMetadatos();
    return s;
}

float Imagen::VerAlto(){
    return alto;
}

float Imagen::VerAncho(){
    return ancho;
}

unsigned Imagen::VerTamX(){
    return TamPX;
}

unsigned Imagen::VerTamY(){
    return TamPY;
}

string Imagen::VerUnidad(){
    return unidad;
}

void Imagen::InicializarVector(){
    pix.resize(TamPY);
    for(unsigned int i=0;i<TamPY;i++){
        pix[i].resize(TamPX);
    }
}

string Imagen::GuardarMetadato(){
    return met.GuardarMetadatos();
}

void Imagen::ModifMeta(string clave, string valor){
    met.ModifMeta(clave, valor);
}

void Imagen::VaciarMetadato(){
    met.VaciarMetadato();
}
