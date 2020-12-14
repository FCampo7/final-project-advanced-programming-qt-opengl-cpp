#include "graficador.h"

Graficador::Graficador(QWidget *parent)
    : QOpenGLWidget(parent){
    x=0;
    y=0;
    estado=false;
}


Graficador::~Graficador(){}


void Graficador::recibir_imagen(Imagen *ima){
    estado=true;
    imagraf=ima;
}

void Graficador::mousePressEvent(QMouseEvent *e){
    if(e->type()==QMouseEvent::MouseButtonPress){
        x=e->x();
        y=e->y();
        if(propancho>propalto){
            x=((x-(((width()-(imagraf->VerTamX()*propalto))/2.0f)))/propalto); //Quitamos las transformaciones de traslacion y escala para obtener la posicion de x donde se encuntra el pixel
            y=y/propalto; //Solo quitamos la escala en y, ya que no sufrio traslacion en este eje

        }
        else{
            x=x/propancho; //Solo quitamos la escala en x, ya que no sufrio traslacion en este eje
            y=((y-(((height()-(imagraf->VerTamY()*propancho))/2.0f)))/propancho); //Quitamos las transformaciones de traslacion y escala para obtener la posicion de y donde se encuntra el pixel
        }
        emit clicked();
    }
}

int Graficador::verx(){
    return x;
}

int Graficador::very(){
    return y;
}

void Graficador::initializeGL(){
    initializeOpenGLFunctions();
    // color de fondo
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void Graficador::resizeGL(int width, int height){
    // tamaño ventana de salida
    glViewport(0, 0, width, height);

    // como será la proyección
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Graficador::paintGL(){
    Pixel colorpixel;

    // borrar la pantalla
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(estado){
        // Imagen 1
        glPushMatrix();

        propancho=((width()*1.0)/(imagraf->VerTamX()*1.0));
        propalto=((height()*1.0)/(imagraf->VerTamY()*1.0));

        if(propancho>propalto){
            glTranslatef((width()-(imagraf->VerTamX()*propalto))/2.0f, 0, 0);
            glScalef(propalto, propalto, 0);
            x=((x-(((width()-(imagraf->VerTamX()*propalto))/2.0f)))/propalto); //Quitamos las transformaciones de traslacion y escala para obtener la posicion de x donde se encuntra el pixel
            y=y/propalto; //Solo quitamos la escala en y, ya que no sufrio traslacion en este eje

        }
        else{
            glTranslatef(0, (height()-(imagraf->VerTamY()*propancho))/2.0f, 0);
            glScalef(propancho, propancho, 0);
            x=x/propancho; //Solo quitamos la escala en x, ya que no sufrio traslacion en este eje
            y=((y-(((height()-(imagraf->VerTamY()*propancho))/2.0f)))/propancho); //Quitamos las transformaciones de traslacion y escala para obtener la posicion de y donde se encuntra el pixel
        }
        glBegin(GL_QUADS);
            for (unsigned int i=0; i<imagraf->VerTamY(); i++){
                   for (unsigned int j=0; j<imagraf->VerTamX(); j++){
                       colorpixel=imagraf->VerPixel(j, i);
                       glColor3f(colorpixel.VerRojo(),colorpixel.VerVerde(),colorpixel.VerAzul());
                       glVertex3f(j, (imagraf->VerTamY()-i)-1, 0.0);
                       glVertex3f(j+1, (imagraf->VerTamY()-i)-1, 0.0);
                       glVertex3f(j+1, (imagraf->VerTamY()-i), 0.0);
                       glVertex3f(j, (imagraf->VerTamY()-i), 0.0);
                   }
            }
        glEnd();
        glPopMatrix();
    }
}
