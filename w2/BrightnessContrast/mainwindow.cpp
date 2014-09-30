#include <QFileDialog>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "cvmattoqimage.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    brightness(0),
    contrast(1)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_ffnen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",  tr("Images (*.png *.xpm *.jpg)"));
    sourceImage = imread(fileName.toStdString());
    sourceImage.copyTo(destinationImage);

    ui->sourceImage->setPixmap(cvMatToQPixmap(sourceImage));
    ui->destinationImage->setPixmap(cvMatToQPixmap(destinationImage));
}

void MainWindow::process(){
    for(int x = 0; x < sourceImage.cols; x++){
        for(int y = 0; y < sourceImage.rows; y++){
            Vec3b sourcePixel = sourceImage.at<Vec3b>(y,x);
            int b = sourcePixel[0];
            int g = sourcePixel[1];
            int r = sourcePixel[2];

            r = saturate_cast<uchar>(r * contrast + brightness);
            g = saturate_cast<uchar>(g * contrast + brightness);
            b = saturate_cast<uchar>(b * contrast + brightness);

            Vec3b destinationPixel(b, g, r);
            destinationImage.at<Vec3b>(y, x) = destinationPixel;


        }
    }
    ui->destinationImage->setPixmap(cvMatToQPixmap(destinationImage));

}

void MainWindow::on_brightnessSlider_valueChanged(int value)
{
   brightness = value;
   process();

}

void MainWindow::on_contrastSlider_valueChanged(int value)
{
    contrast = pow(2, value/50.f );
    qDebug() << contrast;
    process();
}
