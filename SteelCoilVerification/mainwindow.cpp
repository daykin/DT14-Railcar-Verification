#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SteelCoil.h"
#include <QListIterator>
#include <QMessageBox>
#include <QFile>
#include <unistd.h>
#include <iostream>
#include <QtSql>

//class SteelCoil;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;

    QFile img("image.png");
    img.remove();

    QFile img1("out.jpg");
    img1.remove();

    QFile img2("outi.jpg");
    img2.remove();
}

void MainWindow::init(){
    ui->stackedWidget->setCurrentIndex(0);

    if(QCameraInfo::availableCameras().count() > 0){
        camera =  new QCamera(QCamera::FrontFace);
        qInfo("Front camera selected");

        camera->setViewfinder(ui->viewWindow_ScanID);

        camera->setCaptureMode(QCamera::CaptureStillImage);

        camera->start();
    }
    else{
        qInfo("No camera available");
    }

    // build sample database
    ds = new ShipmentSchedule();
    ds->BuildDatabase();

    //create ocr object
    ocr = new OCR();
}

//main menu click functions
void MainWindow::on_scanButton_Main_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_jobButton_Main_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

    QVBoxLayout* containerLayout = new QVBoxLayout();
    QWidget* widget = new QWidget();

    QVector<RailCar*> cars = ds->getCars();

    for(int i=0; i<cars.size(); i++){
        containerLayout->addWidget(buildMainBlock(cars[i]));
    }

    widget->setLayout(containerLayout);

    ui->scrollArea_JobList->setWidget(widget);
}

//scanID click functions
void MainWindow::on_backButton_ScanID_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_photoButton_ScanID_clicked()
{
    camImage = QGuiApplication::primaryScreen()->grabWindow(ui->viewWindow_ScanID->winId());

    ui->stackedWidget->setCurrentIndex(2);

    ui->viewWindow_VerifyID->setPixmap(camImage);

    //save the image
    if(camImage.save("image.png", "PNG")){
        qInfo("image.png saved");
    }
    else{
        qInfo("Image not saved");
    }

    //run ocr
    ocrID = ocr->getId("image.png");

    //ocrID = "IHB 166590";
     ui->railcarIDLabel_VerifyID->setText(ocrID);
    std::cerr<<ocrID.toStdString()<<endl;

    //set ocr output to textbox

}

//verifyID click functions
void MainWindow::on_retakeButton_VerifyID_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_backButton_VerifyID_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_correctButton_VerifyID_clicked()
{
    //get railcar object for confirmed id
    ocrID = ui->railcarIDLabel_VerifyID->text();
    ocrCar = ds->GetCar(ocrID);

    if(ocrCar == nullptr){
        QMessageBox::information(this,tr("NOTICE"),tr("GIVEN RAILCAR ID NOT FOUND"));
        return;
    }

    ui->stackedWidget->setCurrentIndex(3);

    QVBoxLayout* containerLayout = new QVBoxLayout();
    QWidget* widget = new QWidget();

    containerLayout->addWidget(buildMainBlock(ocrCar));

    widget->setLayout(containerLayout);

    ui->scrollArea_ScanCoil->setWidget(widget);
}

//scanCoil click functions
void MainWindow::on_scanIDButton_ScanCoil_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_mainButton_ScanCoil_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_confirmButton_ScanCoil_clicked()
{
    //BARCODE SCANNING LOGIC HERE
    QString s = ui->barcodeInput_ScanCoil->text(); //assign plaintext
    QString subString=s.mid(0,1);
    QString barcodenum = s;

    ui->barcodeInput_ScanCoil->clear();//clear text box everytime

    ui->barcodeInput_ScanCoil->setFocus();

    //parsing
    if(subString=="I"||subString=="O")
    {
        s = s.simplified();
        QStringList barcode = s.split("A");
        barcodenum = barcode.at(1);
        barcodenum = barcodenum.simplified();
    }
    if (subString=="*")
    {
        QStringList barcode = s.split("*");
        barcodenum = barcode.at(1);
    }

    //checking
    QVector<SteelCoil*> coils = ocrCar->getCoilVector();

    for(int i=0; i<coils.size(); i++){
        if(coils[i]->GetCoil() == barcodenum && !coils[i]->isVerified()){
            coils[i]->verify();
            ocrCar->verify();
            ds->UpdateDatabase(coils[i]->GetCoil(), ocrCar);

            QVBoxLayout* containerLayout = new QVBoxLayout();
            QWidget* widget = new QWidget();

            containerLayout->addWidget(buildMainBlock(ocrCar));

            widget->setLayout(containerLayout);

            ui->scrollArea_ScanCoil->setWidget(widget);

            return;
        }
    }

    //not found
    QMessageBox::information(this,tr("NOTICE"),tr("COIL ID DOES NOT MATCH RAIL CAR"));
}

//jobList click functions
void MainWindow::on_mainButton_JobList_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//utility functions
QWidget* MainWindow::buildMainBlock(RailCar* railCar){
    QHBoxLayout* mainLayout = new QHBoxLayout();
    QVBoxLayout* left = new QVBoxLayout();
    QVBoxLayout* right = new QVBoxLayout();
    QWidget* widget = new QWidget();

    QLabel* id = new QLabel();
    id->setText(railCar->getCarID());
    id->setAlignment(Qt::AlignCenter | Qt::AlignLeft);

    if(railCar->isVerified()){
        id->setStyleSheet("background-color: rgba(13, 135, 35, .4); color: black; opacity: .5; border: 1px solid black; margin: 5px; padding: 5px;");
    }
    else{
       id->setStyleSheet("background-color: rgba(249, 36, 24, .4); color: black; opacity: .5; border: 1px solid black; margin: 5px; padding: 5px;");
    }

    id->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    left->addWidget(id);

    QWidget* empty = new QWidget();
    empty->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    empty->setStyleSheet("border: 0px;");

    left->addWidget(empty);

    QVector<SteelCoil*> coils = railCar->getCoilVector();

    for(int i=0; i<coils.size(); i++){
        right->addWidget(buildRailCar(coils[i]));
    }

    mainLayout->addLayout(left);
    mainLayout->addLayout(right);

    widget->setStyleSheet("border: 1px solid black;  margin: 5px;");
    widget->setLayout(mainLayout);

    return widget;
}

QLabel* MainWindow::buildRailCar(SteelCoil* sCoil){
    QLabel* coil = new QLabel();
    coil->setText(sCoil->GetCoil());
    if(sCoil->isVerified()){
        coil->setStyleSheet("background-color: rgba(13, 135, 35, .4); color: black; opacity: .5; border: 1px solid black; margin: 5px;");
    }
    else{
        coil->setStyleSheet("background-color: rgba(246, 255, 12, .4); color: black; opacity: .5; border: 1px solid black; margin: 5px;");
    }

    coil->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

    return coil;
}
