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

private:
    void process();
    Ui::MainWindow *ui;
    cv::Mat sourceImage;
    cv::Mat redImage;
    cv::Mat greenImage;
    cv::Mat blueImage;
};

#endif // MAINWINDOW_H
