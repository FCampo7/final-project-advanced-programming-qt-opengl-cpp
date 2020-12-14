#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    click=false;
    ui->gridLayout_2->setColumnStretch(1,1);
    ui->GuardarImagen->setEnabled(false);
    ui->AplicarFiltro->setEnabled(false);
	ui->AplicarDetector->setEnabled(false);
	ui->Met->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CargarImagen_clicked()
{
    click=false;
    QString Qnombre = QFileDialog::getOpenFileName(this);
    string nombre=Qnombre.toLocal8Bit().constData();

    if(!Qnombre.isEmpty()){
        sis.CargarImagen(nombre);
        ima=sis.DevolverImg();
        ui->Graf->recibir_imagen(&ima);
        ui->Graf->update();
        ui->GuardarImagen->setEnabled(true);
        ui->AplicarFiltro->setEnabled(true);
        ui->AplicarDetector->setEnabled(true);
		ui->Met->setEnabled(true);
        ui->Pixeles->setText(QString::fromStdString(sis.VerTamPixeles()));
        ui->Tamano->setText(QString::fromStdString(sis.VerTamUnidad()));
        ui->Met->setText(QString::fromStdString(sis.VerMetadatos()));
		ui->Met->setFocus();
		ui->Met->moveCursor(QTextCursor::End);
    }
}

void MainWindow::on_GuardarImagen_clicked()
{
	QString Qnombre = QFileDialog::getSaveFileName(this, QString(), QString(), tr("Imagen (*.mif)"));
    string nombre = Qnombre.toLocal8Bit().constData();

    if(!Qnombre.isEmpty()){
        sis.GuardarImagen(nombre);
    }
}

void MainWindow::on_AplicarFiltro_clicked()
{
    Pixel p;
    if(!click){
        ui->Graf->setCursor(Qt::CrossCursor);
        connect(ui->Graf, SIGNAL(clicked()),ui->AplicarFiltro,SLOT(click()));
        ui->AplicarDetector->setEnabled(false);
        click=true;
    }
    else{
        if(((ui->Graf->verx()>=0)&&(ui->Graf->verx()<ima.VerTamX()))&&((ui->Graf->very()>=0)&&(ui->Graf->very()<ima.VerTamY()))){
            click=false;
            ui->Error->setText("");
            disconnect(ui->Graf, SIGNAL(clicked()),ui->AplicarFiltro,SLOT(click()));
            ui->Graf->setCursor(Qt::ArrowCursor);
            ima=sis.DevolverImg();
            p=ima.VerPixel(ui->Graf->verx(), ui->Graf->very());
            sis.AplicarFiltro(p);
            ima=sis.DevolverImg();
            ui->Graf->update();
            ui->AplicarFiltro->setEnabled(false);
        }
        else{
            ui->Error->setText("Error: no se pudo aplicar filtro, click fuera de la imagen. Intente de nuevo");
        }
    }
}

void MainWindow::on_AplicarDetector_clicked()
{
    Pixel p;
    if(!click){
        ui->Graf->setCursor(Qt::CrossCursor);
        connect(ui->Graf, SIGNAL(clicked()),ui->AplicarDetector,SLOT(click()));
        ui->AplicarFiltro->setEnabled(false);
        click=true;
    }
    else{
        if(((ui->Graf->verx()>=0)&&(ui->Graf->verx()<ima.VerTamX()))&&((ui->Graf->very()>=0)&&(ui->Graf->very()<ima.VerTamY()))){
            click=false;
            ui->Error->setText("");
            disconnect(ui->Graf, SIGNAL(clicked()),ui->AplicarDetector,SLOT(click()));
            ui->Graf->setCursor(Qt::ArrowCursor);
            ima=sis.DevolverImg();
            p=ima.VerPixel(ui->Graf->verx(), ui->Graf->very());
            sis.Detectar(ui->Graf->verx(), ui->Graf->very(), p);
            ima=sis.DevolverImg();
            ui->Graf->update();
            ui->AplicarDetector->setEnabled(false);
        }
        else{
            ui->Error->setText("Error: no se pudo aplicar detector, click fuera de la imagen. Intente de nuevo");
        }
    }
}

void MainWindow::on_Met_textChanged()
{
	QString Meta=ui->Met->toPlainText();
	Meta+='\n';
	QStringList Lista=Meta.split(QRegularExpression("\n"));
	QStringList::Iterator il=Lista.begin();
	QStringList Lista2;
	ima.VaciarMetadato();
	for(int i=0; i<Lista.size()-1; i++){
		Lista2=il->split(QRegularExpression(": "));
		ima.ModifMeta(Lista2.first().toStdString() , Lista2.last().toStdString());
		il++;
	}
	sis.RecibirImagen(ima);
}
