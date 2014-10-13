#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
#include "colorkeyerhsv.h"
#include "colorkeyerrgb.h"

namespace Ui {
class VideoPlayer;
}

class VideoPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();

private slots:
    void on_playButton_clicked();

    void on_openVideoFileButton_clicked();


    void on_hueSlider_valueChanged(int value);

    void on_hueTolerance_valueChanged(int value);

    void on_saturationSlider_valueChanged(int value);

private:
    Ui::VideoPlayer *ui;
    VideoEngine *videoThread;
    ColorKeyerHSV* colorKeyerHSV;
    ColorKeyerRGB* colorKeyerRGB;
    void setThresholds();
};

#endif // VIDEOPLAYER_H
