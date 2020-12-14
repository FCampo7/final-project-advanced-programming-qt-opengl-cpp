#ifndef PIXEL_H
#define PIXEL_H

class Pixel{
private:
    float rojo;
    float verde;
    float azul;
public:
    Pixel();
    Pixel(float r, float v, float a);
    void ModRojo(float r);
    void ModVerde(float v);
    void ModAzul(float a);
    float VerRojo();
    float VerVerde();
    float VerAzul();
    float CalcularBrillo();
    bool operator==(Pixel p);
};

#endif
