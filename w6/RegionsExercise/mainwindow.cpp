#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "cvmattoqimage.h"
#include <vector>
using namespace std;
using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Mat image = createImage();

//  AUFGABE: Implementieren Sie eine Methode findRegions(), die folgendes tut:
//    1.	Bestimmung der Anzahl der Regionen und Ausgabe über qDebug().
//    2.	Ausgabe der Fläche jeder einzelnen Region über qDebug()
//    3.	Bestimmung der Region mit der größten Fläche
//    4.	Schwärzung aller Regionen deren Fläche kleiner ist
//
//  diese Methode soll hier aufgerufen werden.

    image = findRegions(image);
    ui->imageLabel->setPixmap(cvMatToQPixmap(image));
}

MainWindow::~MainWindow()
{
    delete ui;
}


Mat MainWindow::createImage(){
    Mat image(300, 400, CV_8UC1);
    // Hintergrund schwarz füllen
    image = 0;
    // weisse Region (Rechteck 2x3) darin zeichnen
    rectangle(image, Point(10,10), Point(11,12),255,CV_FILLED);
    rectangle(image, Point(53,10), Point(100, 137), 255, CV_FILLED);
    rectangle(image, Point(50,80), Point(153, 100), 255, CV_FILLED);
    rectangle(image, Point(200, 200), Point(250, 250), 255, CV_FILLED);
    return image;
}
