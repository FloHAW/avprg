#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
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
    void on_open_clicked();

    void on_start_clicked();

    void on_stop_clicked();

    void on_volume_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QMediaPlayer mediaPlayer;
};

#endif // MAINWINDOW_H
