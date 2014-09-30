#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
#include "brightnessprocessor.h"
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
    void on_brightnessSlider_valueChanged(int value);

    void on_openVideoFileButton_clicked();


private:
    Ui::VideoPlayer *ui;
    VideoEngine *videoThread;
    BrightnessProcessor* brightnessProcessor;
};

#endif // VIDEOPLAYER_H
