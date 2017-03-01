#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    containerLayout->addWidget(buildMainBlock());
    containerLayout->addWidget(buildMainBlock());
    containerLayout->addWidget(buildMainBlock());
    containerLayout->addWidget(buildMainBlock());

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

    ui->railcarIDLabel_VerifyID->setText("Sample text");
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
    ui->stackedWidget->setCurrentIndex(3);

    QVBoxLayout* containerLayout = new QVBoxLayout();
    QWidget* widget = new QWidget();

    containerLayout->addWidget(buildMainBlock());

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
}

//jobList click functions
void MainWindow::on_mainButton_JobList_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

QWidget* MainWindow::buildMainBlock(){
    QHBoxLayout* mainLayout = new QHBoxLayout();
    QVBoxLayout* left = new QVBoxLayout();
    QVBoxLayout* right = new QVBoxLayout();
    QWidget* widget = new QWidget();

    QLabel* id = new QLabel();
    id->setText("RAILCAR ID");
    id->setAlignment(Qt::AlignCenter | Qt::AlignLeft);
    id->setStyleSheet("background-color: rgba(249, 36, 24, .4); color: black; opacity: .5; border: 1px solid black; margin: 5px; padding: 5px;");
    id->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    left->addWidget(id);

    QWidget* empty = new QWidget();
    empty->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    empty->setStyleSheet("border: 0px;");

    left->addWidget(empty);

    //left->addSpacerItem(space);

    QLabel* coil1 = new QLabel();
    coil1->setText("COIL ID");
    coil1->setStyleSheet("background-color: rgba(246, 255, 12, .4); color: black; opacity: .5; border: 1px solid black; margin: 5px;");
    coil1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

    QLabel* coil2 = new QLabel();
    coil2->setText("COIL ID");
    coil2->setStyleSheet("background-color: rgba(246, 255, 12, .4); color: black; opacity: .5; border: 1px solid black; margin: 5px;");
    coil2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

    QLabel* coil3 = new QLabel();
    coil3->setText("COIL ID");
    coil3->setStyleSheet("background-color: rgba(246, 255, 12, .4); color: black; opacity: .5; border: 1px solid black; margin: 5px;");
    coil3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

    right->addWidget(coil1);
    right->addWidget(coil2);
    right->addWidget(coil3);

    mainLayout->addLayout(left);
    mainLayout->addLayout(right);

    widget->setStyleSheet("border: 1px solid black;  margin: 5px;");
    widget->setLayout(mainLayout);

    return widget;
}
