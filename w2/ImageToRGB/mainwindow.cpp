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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_ffnen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",  tr("Images (*.png *.xpm *.jpg)"));
    sourceImage = imread(fileName.toStdString());
    redImage.create(sourceImage.rows, sourceImage.cols, CV_8UC1);
    greenImage.create(sourceImage.rows, sourceImage.cols,  CV_8UC1);
    blueImage.create(sourceImage.rows, sourceImage.cols,  CV_8UC1);

    process();

    ui->sourceImage->setPixmap(cvMatToQPixmap(sourceImage));
    ui->redImage->setPixmap(cvMatToQPixmap(redImage));
    ui->greenImage->setPixmap(cvMatToQPixmap(greenImage));
    ui->blueImage->setPixmap(cvMatToQPixmap(blueImage));
}



void MainWindow::process(){
    for(int x = 0; x < sourceImage.cols; x++){
        for(int y = 0; y < sourceImage.rows; y++){
            Vec3b sourcePixel = sourceImage.at<Vec3b>(y,x);
            int b = sourcePixel[0];
            int g = sourcePixel[1];
            int r = sourcePixel[2];

            redImage.at<uchar>(y,x) = r;
            greenImage.at<uchar>(y,x) = g;
            blueImage.at<uchar>(y,x) = b;
        }
    }
}
