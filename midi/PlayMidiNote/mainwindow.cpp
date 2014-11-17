#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList connections = midiOutput.connections(true);
    ui->comboBox->addItems(connections);
    midiOutput.open("Microsoft GS Wavetable Synth");
    midichannel = ui->midichannel->value();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_note_1_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 60, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 60, 0);
    }
}
void MainWindow::on_note_2_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 61, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 61, 0);
    }
}
void MainWindow::on_note_3_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 62, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 62, 0);
    }
}
void MainWindow::on_note_4_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 63, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 63, 0);
    }
}
void MainWindow::on_note_5_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 64, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 64, 0);
    }
}
void MainWindow::on_note_6_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 65, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 65, 0);
    }
}
void MainWindow::on_note_7_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 66, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 66, 0);
    }
}
void MainWindow::on_note_8_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 67, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 67, 0);
    }
}
void MainWindow::on_note_9_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 67, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 67, 0);
    }
}
void MainWindow::on_note_10_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 67, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 67, 0);
    }
}
void MainWindow::on_note_11_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 67, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 67, 0);
    }
}
void MainWindow::on_note_12_clicked(bool checked)
{
    if (checked){
        midiOutput.sendNoteOn(midichannel, 67, 127);
    }
    else{
        midiOutput.sendNoteOff(midichannel, 67, 0);
    }
}
void MainWindow::on_volume_valueChanged(int value)
{
   midiOutput.sendController(midichannel, 7, value);
}

void MainWindow::on_pitchbend_valueChanged(int value)
{
    midiOutput.sendPitchBend(midichannel, value);
}

void MainWindow::on_midichannel_valueChanged(int arg1)
{
    midichannel = arg1;
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    midiOutput.open(arg1);
}

void MainWindow::on_program_valueChanged(int arg1)
{
    midiOutput.sendProgram(midichannel, arg1);
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    ui->note_1->setCheckable(checked);
    ui->note_2->setCheckable(checked);
    ui->note_3->setCheckable(checked);
    ui->note_4->setCheckable(checked);
    ui->note_5->setCheckable(checked);
    ui->note_6->setCheckable(checked);
    ui->note_7->setCheckable(checked);
    ui->note_8->setCheckable(checked);
    ui->note_9->setCheckable(checked);
    ui->note_10->setCheckable(checked);
    ui->note_11->setCheckable(checked);
    ui->note_12->setCheckable(checked);
}

