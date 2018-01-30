#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "images.h"

#include <QImage>
#include <QRectF>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImage(QImage &img)
{
#define WIDTH   128
#define HIGHT   160

   int i, j;
   QRgb value;

   for (j=0; j<HIGHT; j++)
   {
       for (i=0; i<WIDTH; i++)
       {
            value = qRgb(Pickachu[j*WIDTH*3+i*3],
                         Pickachu[j*WIDTH*3+i*3+1],
                         Pickachu[j*WIDTH*3+i*3+2]);
            img.setPixel(i, j, value);
       }
   }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QRectF rect(50, 50, 128, 160);

    QImage img(128, 160, QImage::Format_RGB32);

    //img.setPixel(100, 100, value);

    loadImage(img);
    painter.drawImage(50, 50+32, img);
}

void MainWindow::on_pushButton_clicked()
{
//    QRectF rect(50, 50, 128, 160);
//    QImage img;



    ui->label->setText("UP");




}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText("Down");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText("Scan");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->label->setText("Cancel");
}

