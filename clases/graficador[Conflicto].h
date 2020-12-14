#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include <QOpenGLFunctions_3_0>
#include <QOpenGLWidget>
#include <QEvent>
#include <QMouseEvent>
#include "imagen.h"

class Graficador : public QOpenGLWidget, protected QOpenGLFunctions_3_0{
    Q_OBJECT
private:
    bool estado;
    Imagen *imagraf;
    int x, y;
    float propancho, propalto;
public:
    Graficador(QWidget *parent = 0);
    void recibir_imagen(Imagen *ima);
    int verx();
    int very();
    ~Graficador();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
};

#endif
