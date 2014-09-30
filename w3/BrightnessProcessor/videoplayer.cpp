#include <QFileDialog>
#include "videoplayer.h"
#include "ui_videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
    , videoThread(new VideoEngine)
    , brightnessProcessor(new BrightnessProcessor())
{
    ui->setupUi(this);
    videoThread->setProcessor(brightnessProcessor);
    connect(videoThread, SIGNAL(sendInputImage(const QImage&)), ui->inputFrame, SLOT(setImage(const QImage&)));
    connect(videoThread, SIGNAL(sendProcessedImage(const QImage&)), ui->processedFrame , SLOT(setImage(const QImage&)));

}

VideoPlayer::~VideoPlayer()
{
    delete videoThread;
    delete brightnessProcessor;
    delete ui;
}


void VideoPlayer::on_playButton_clicked()
{
    videoThread->start();
}

void VideoPlayer::on_brightnessSlider_valueChanged(int value)
{
    brightnessProcessor->setOffset(value);
}

void VideoPlayer::on_openVideoFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
        videoThread->openFile(fileName);
     }

}
