#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <opencv2/opencv.hpp>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_action_ffnen_triggered();
    void on_blendSlider_valueChanged(int value);

private:
    void process();
    Ui::MainWindow *ui;
    cv::Mat sourceImage1;
    cv::Mat sourceImage2;
    cv::Mat destinationImage;
    int blend;
};

#endif // MAINWINDOW_H
