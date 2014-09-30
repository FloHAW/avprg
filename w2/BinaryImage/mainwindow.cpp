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
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    threshold = ui->thresholdSlider->value();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_ffnen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",  tr("Images (*.png *.xpm *.jpg)"));
    sourceImage = imread(fileName.toStdString());
    grayImage.create(sourceImage.rows, sourceImage.cols, CV_8UC1);
    binaryImage.create(sourceImage.rows, sourceImage.cols,  CV_8UC1);

    process();

    ui->sourceImage->setPixmap(cvMatToQPixmap(sourceImage));
    ui->grayImage->setPixmap(cvMatToQPixmap(grayImage));
    ui->binaryImage->setPixmap(cvMatToQPixmap(binaryImage));
}



void MainWindow::process(){
    for(int x = 0; x < sourceImage.cols; x++){
        for(int y = 0; y < sourceImage.rows; y++){
            Vec3b sourcePixel = sourceImage.at<Vec3b>(y,x);
            int b = sourcePixel[0];
            int g = sourcePixel[1];
            int r = sourcePixel[2];

            int brightness = (r + g + b) / 3;
            grayImage.at<uchar>(y,x) = (uchar) brightness;

            if (brightness > threshold){
                binaryImage.at<uchar>(y,x) = 255;
            }
            else{
                binaryImage.at<uchar>(y,x) = 0;
            }
        }
    }
}


void MainWindow::on_thresholdSlider_valueChanged(int value)
{
    threshold = value;
    process();
    ui->binaryImage->setPixmap(cvMatToQPixmap(binaryImage));
}
