#include "filtrocolor.h"

FiltroColor::FiltroColor(Pixel p1){
    p=p1;
}

void FiltroColor::procesar(Imagen &ima){
    Pixel pixfil;
    float aux;
    for (unsigned int i=0; i<ima.VerTamY(); i++){
       for (unsigned int j=0; j<ima.VerTamX(); j++){
           pixfil=ima.VerPixel(j, i);
           if (!(pixfil==p)){
                aux=pixfil.CalcularBrillo();
                pixfil.ModRojo(aux);
                pixfil.ModVerde(aux);
                pixfil.ModAzul(aux);
                ima.ModificarVP(pixfil, j, i);
           }
        }
    }
}
