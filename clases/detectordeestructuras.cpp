#include "detectordeestructuras.h"

DetectorDeEstructuras::DetectorDeEstructuras(int px, int py, Pixel p1){
    posx=px;
    posy=py;
    p=p1;
    Cbase.ModVerde(1.0);
}

void DetectorDeEstructuras::procesar(Imagen &img){
    imaux=img;
    Pixel pixelaux;
    for(unsigned i=0; i<img.VerTamY(); i++){
        for(unsigned j=0;j<img.VerTamX();j++){
            imaux.ModificarVP(pixelaux,j,i);
        }
    }
    detectar(posx,posy,img);
    img=imaux;
}

void DetectorDeEstructuras::detectar(int px, int py, Imagen &ima){
	if (((px<ima.VerTamX())&&(px>=0))&&((py<ima.VerTamY())&&(py>=0))){
        if (ima.VerPixel(px,py)==p){
            if(!(imaux.VerPixel(px,py)==Cbase)){
                imaux.ModificarVP(Cbase,px,py);
                for (int i=(py-1);i<(py+2);i++){
                    for (int j=(px-1);j<(px+2);j++){
                        if(!((px==0)&&(py==0))){
                            detectar(j,i,ima);
                        }
                    }
                }
            }
        }
    }
}
