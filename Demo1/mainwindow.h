#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QScreen>
#include <QString>
#include "SteelCoil.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget* buildMainBlock();

private slots:
    void on_scanButton_Main_clicked();
    void on_backButton_ScanID_clicked();
    void on_retakeButton_VerifyID_clicked();
    void on_backButton_VerifyID_clicked();
    void on_photoButton_ScanID_clicked();
    void on_scanIDButton_ScanCoil_clicked();
    void on_mainButton_ScanCoil_clicked();
    void on_correctButton_VerifyID_clicked();
    void on_jobButton_Main_clicked();
    void on_mainButton_JobList_clicked();

    void on_confirmButton_ScanCoil_clicked();

private:
    void init();

    Ui::MainWindow *ui;
    QPixmap camImage;
    QCamera* camera;
    QList<QString> myList;






};

#endif // MAINWINDOW_H
