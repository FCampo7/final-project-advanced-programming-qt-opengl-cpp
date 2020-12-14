#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clases/sistema.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_CargarImagen_clicked();

    void on_GuardarImagen_clicked();

    void on_AplicarFiltro_clicked();

    void on_AplicarDetector_clicked();

	void on_Met_textChanged();

private:
    bool click;
	Imagen ima;
    Sistema sis;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
