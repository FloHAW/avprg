#include <QFileDialog>

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
    Mat image = imread(fileName.toStdString());

    ui->imageLabel->setPixmap(cvMatToQPixmap(rescale(image)));
}

Mat MainWindow::rescale(Mat &mat){
    // Skalierungsfaktor bestimmen
    float labelWidth = ui->imageLabel->width();
    float labelHeight = ui->imageLabel->height();
    float imageWidth = mat.cols;
    float imageHeight = mat.rows;
    float scale = labelWidth / imageWidth;
    if (labelHeight/imageHeight < scale){
        scale = labelHeight / imageHeight;
    }

    // neue Bildbreite berechnen
    float scaledImageWidth = imageWidth * scale;
    float scaledImageHeight = imageHeight * scale;

    // skaliertes Mat-Objekt erzeugen
    Mat scaledImage (scaledImageHeight, scaledImageWidth, mat.type());
    cv::resize(mat, scaledImage, Size(scaledImageWidth, scaledImageHeight));
    return scaledImage;
}
