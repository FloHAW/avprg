#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_actionKreise_triggered();

    void on_actionPunkte_triggered();

    void on_actionZebrastreifen_triggered();

    void on_actionFarbiges_Schachbrett_triggered();

    void on_actionSchachbrett_triggered();

private:
    void showMat(const cv::Mat& mat);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
