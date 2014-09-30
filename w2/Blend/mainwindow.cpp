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
    blend(1)
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
    sourceImage1 = imread(fileName.toStdString());


    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",  tr("Images (*.png *.xpm *.jpg)"));
    Mat mat = imread(fileName.toStdString());
    cv::resize(mat, sourceImage2, Size(sourceImage1.cols, sourceImage1.rows));

    destinationImage.create(sourceImage1.rows, sourceImage1.cols, CV_8UC3);
    process();


    ui->sourceImage1->setPixmap(cvMatToQPixmap(sourceImage1));
    ui->sourceImage2->setPixmap(cvMatToQPixmap(sourceImage2));
    ui->destinationImage->setPixmap(cvMatToQPixmap(destinationImage));
}

void MainWindow::process(){
    float alpha = blend / 100.f;

    for(int x = 0; x < sourceImage1.cols; x++){
        for(int y = 0; y < sourceImage1.rows; y++){
            Vec3b sourcePixel1 = sourceImage1.at<Vec3b>(y,x);
            Vec3b sourcePixel2 = sourceImage2.at<Vec3b>(y,x);
            Vec3b destinationPixel = sourcePixel1 * alpha + sourcePixel2 * (1 - alpha);
            destinationImage.at<Vec3b>(y, x) = destinationPixel;
        }
    }
}

void MainWindow::on_blendSlider_valueChanged(int value)
{
    blend = value;
    process();
    ui->destinationImage->setPixmap(cvMatToQPixmap(destinationImage));
}
