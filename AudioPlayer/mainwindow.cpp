#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
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

void MainWindow::on_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());
    mediaPlayer.setMedia(QUrl::fromLocalFile(fileName));
}

void MainWindow::on_start_clicked()
{
    mediaPlayer.play();
}

void MainWindow::on_stop_clicked()
{
    mediaPlayer.stop();
}

void MainWindow::on_volume_valueChanged(int value)
{
    mediaPlayer.setVolume(value);
}
