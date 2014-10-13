#include <QFileDialog>
#include "videoplayer.h"
#include "ui_videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
    , videoThread(new VideoEngine)
    , colorKeyerHSV(new ColorKeyerHSV())
    , colorKeyerRGB(new ColorKeyerRGB())
{
    ui->setupUi(this);
    videoThread->setProcessor(colorKeyerHSV);
    connect(videoThread, SIGNAL(sendInputImage(const QImage&)), ui->inputFrame, SLOT(setImage(const QImage&)));
    connect(videoThread, SIGNAL(sendProcessedImage(const QImage&)), ui->processedFrame , SLOT(setImage(const QImage&)));
    setThresholds();
}

VideoPlayer::~VideoPlayer()
{
    delete videoThread;
    delete colorKeyerHSV;
    delete colorKeyerRGB;
    delete ui;
}


void VideoPlayer::on_playButton_clicked()
{
    videoThread->start();
}


void VideoPlayer::on_openVideoFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
        videoThread->openFile(fileName);
     }

}

void VideoPlayer::on_hueSlider_valueChanged(int value)
{
    setThresholds();
}

void VideoPlayer::on_hueTolerance_valueChanged(int value)
{
    setThresholds();
}

void VideoPlayer::on_saturationSlider_valueChanged(int value)
{
    setThresholds();
}
void VideoPlayer::setThresholds(){
    int hueValue = ui->hueSlider->value();
    int hueTolerance = ui->hueTolerance->value();
    int hueLowerThreshold = hueValue - hueTolerance;
    if (hueLowerThreshold < 0){
        hueLowerThreshold += 360;
    }
    int hueUpperThreshold = hueValue + hueTolerance;
    if (hueUpperThreshold > 360){
        hueUpperThreshold -= 360;
    }
    int saturationThreshold = ui->saturationSlider->value();


    colorKeyerHSV->setHueLowerThreshold(hueLowerThreshold);
    colorKeyerHSV->setHueUpperThreshold(hueUpperThreshold);
    colorKeyerHSV->setSaturationThreshold(saturationThreshold);

    ui->labelHue->setNum(hueValue);
    ui->labelHueTolerance->setNum(hueTolerance);
    ui->labelSaturation->setNum(saturationThreshold);
}
