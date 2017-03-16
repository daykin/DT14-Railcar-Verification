/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qvideowidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *main;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLabel_Main;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *scanButton_Main;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *jobButton_Main;
    QSpacerItem *horizontalSpacer_2;
    QWidget *scanID;
    QVBoxLayout *verticalLayout_3;
    QLabel *nameLabel_ScanID;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QVideoWidget *viewWindow_ScanID;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *backButton_ScanID;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *photoButton_ScanID;
    QSpacerItem *horizontalSpacer_6;
    QWidget *verifyID;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *viewWindow_VerifyID;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nameLabel_VerifyID;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QLabel *railcarIDLabel_VerifyID;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *correctButton_VerifyID;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *backButton_VerifyID;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *manualButton_VerifyID;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *retakeButton_VerifyID;
    QWidget *scanCoil;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *nameLabel_ScanCoil;
    QSpacerItem *horizontalSpacer_17;
    QVBoxLayout *verticalLayout_8;
    QPlainTextEdit *barcodeInput_ScanCoil;
    QPushButton *confirmButton_ScanCoil;
    QTableWidget *coils_preloaded_list;
    QLabel *label_5;
    QLabel *railCarLabel_ScanCoil;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *scanIDButton_ScanCoil;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *mainButton_ScanCoil;
    QSpacerItem *horizontalSpacer_16;
    QWidget *jobList;
    QVBoxLayout *verticalLayout_7;
    QLabel *nameLabel_JobList;
    QHBoxLayout *horizontalLayout_7;
    QLabel *railCarLabel_JobList;
    QLabel *steelCoilLabel_JobLIst;
    QScrollArea *scrollArea_JobList;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *mainButton_JobList;
    QSpacerItem *horizontalSpacer_13;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        main = new QWidget();
        main->setObjectName(QStringLiteral("main"));
        verticalLayout_2 = new QVBoxLayout(main);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nameLabel_Main = new QLabel(main);
        nameLabel_Main->setObjectName(QStringLiteral("nameLabel_Main"));
        QFont font;
        font.setPointSize(16);
        nameLabel_Main->setFont(font);
        nameLabel_Main->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(nameLabel_Main);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        scanButton_Main = new QPushButton(main);
        scanButton_Main->setObjectName(QStringLiteral("scanButton_Main"));
        scanButton_Main->setMinimumSize(QSize(150, 100));

        horizontalLayout_2->addWidget(scanButton_Main);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        jobButton_Main = new QPushButton(main);
        jobButton_Main->setObjectName(QStringLiteral("jobButton_Main"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(jobButton_Main->sizePolicy().hasHeightForWidth());
        jobButton_Main->setSizePolicy(sizePolicy);
        jobButton_Main->setMinimumSize(QSize(150, 100));

        horizontalLayout_2->addWidget(jobButton_Main);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(main);
        scanID = new QWidget();
        scanID->setObjectName(QStringLiteral("scanID"));
        verticalLayout_3 = new QVBoxLayout(scanID);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        nameLabel_ScanID = new QLabel(scanID);
        nameLabel_ScanID->setObjectName(QStringLiteral("nameLabel_ScanID"));
        nameLabel_ScanID->setFont(font);
        nameLabel_ScanID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(nameLabel_ScanID);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        viewWindow_ScanID = new QVideoWidget(scanID);
        viewWindow_ScanID->setObjectName(QStringLiteral("viewWindow_ScanID"));
        viewWindow_ScanID->setMinimumSize(QSize(600, 200));

        horizontalLayout->addWidget(viewWindow_ScanID);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        backButton_ScanID = new QPushButton(scanID);
        backButton_ScanID->setObjectName(QStringLiteral("backButton_ScanID"));
        backButton_ScanID->setMinimumSize(QSize(150, 100));

        horizontalLayout_3->addWidget(backButton_ScanID);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        photoButton_ScanID = new QPushButton(scanID);
        photoButton_ScanID->setObjectName(QStringLiteral("photoButton_ScanID"));
        photoButton_ScanID->setMinimumSize(QSize(150, 100));

        horizontalLayout_3->addWidget(photoButton_ScanID);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(scanID);
        verifyID = new QWidget();
        verifyID->setObjectName(QStringLiteral("verifyID"));
        verticalLayout_4 = new QVBoxLayout(verifyID);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        viewWindow_VerifyID = new QLabel(verifyID);
        viewWindow_VerifyID->setObjectName(QStringLiteral("viewWindow_VerifyID"));
        viewWindow_VerifyID->setMinimumSize(QSize(600, 200));
        viewWindow_VerifyID->setFrameShape(QFrame::Box);

        horizontalLayout_6->addWidget(viewWindow_VerifyID);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        nameLabel_VerifyID = new QLabel(verifyID);
        nameLabel_VerifyID->setObjectName(QStringLiteral("nameLabel_VerifyID"));
        nameLabel_VerifyID->setMinimumSize(QSize(300, 0));
        nameLabel_VerifyID->setFont(font);
        nameLabel_VerifyID->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(nameLabel_VerifyID);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        railcarIDLabel_VerifyID = new QLabel(verifyID);
        railcarIDLabel_VerifyID->setObjectName(QStringLiteral("railcarIDLabel_VerifyID"));
        railcarIDLabel_VerifyID->setMinimumSize(QSize(200, 50));
        QFont font1;
        font1.setPointSize(12);
        railcarIDLabel_VerifyID->setFont(font1);
        railcarIDLabel_VerifyID->setFrameShape(QFrame::Box);
        railcarIDLabel_VerifyID->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(railcarIDLabel_VerifyID);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        correctButton_VerifyID = new QPushButton(verifyID);
        correctButton_VerifyID->setObjectName(QStringLiteral("correctButton_VerifyID"));
        correctButton_VerifyID->setMinimumSize(QSize(150, 100));

        horizontalLayout_4->addWidget(correctButton_VerifyID);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        backButton_VerifyID = new QPushButton(verifyID);
        backButton_VerifyID->setObjectName(QStringLiteral("backButton_VerifyID"));
        backButton_VerifyID->setMinimumSize(QSize(150, 100));

        horizontalLayout_5->addWidget(backButton_VerifyID);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        manualButton_VerifyID = new QPushButton(verifyID);
        manualButton_VerifyID->setObjectName(QStringLiteral("manualButton_VerifyID"));
        manualButton_VerifyID->setMinimumSize(QSize(150, 100));

        horizontalLayout_5->addWidget(manualButton_VerifyID);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

        retakeButton_VerifyID = new QPushButton(verifyID);
        retakeButton_VerifyID->setObjectName(QStringLiteral("retakeButton_VerifyID"));
        retakeButton_VerifyID->setMinimumSize(QSize(150, 100));

        horizontalLayout_5->addWidget(retakeButton_VerifyID);


        verticalLayout_4->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(verifyID);
        scanCoil = new QWidget();
        scanCoil->setObjectName(QStringLiteral("scanCoil"));
        verticalLayout_6 = new QVBoxLayout(scanCoil);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        nameLabel_ScanCoil = new QLabel(scanCoil);
        nameLabel_ScanCoil->setObjectName(QStringLiteral("nameLabel_ScanCoil"));
        nameLabel_ScanCoil->setMinimumSize(QSize(0, 50));
        nameLabel_ScanCoil->setFont(font);

        horizontalLayout_10->addWidget(nameLabel_ScanCoil);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_17);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        barcodeInput_ScanCoil = new QPlainTextEdit(scanCoil);
        barcodeInput_ScanCoil->setObjectName(QStringLiteral("barcodeInput_ScanCoil"));
        barcodeInput_ScanCoil->setMaximumSize(QSize(200, 50));

        verticalLayout_8->addWidget(barcodeInput_ScanCoil);

        confirmButton_ScanCoil = new QPushButton(scanCoil);
        confirmButton_ScanCoil->setObjectName(QStringLiteral("confirmButton_ScanCoil"));
        confirmButton_ScanCoil->setMaximumSize(QSize(200, 100));

        verticalLayout_8->addWidget(confirmButton_ScanCoil);


        horizontalLayout_10->addLayout(verticalLayout_8);


        verticalLayout_6->addLayout(horizontalLayout_10);

        coils_preloaded_list = new QTableWidget(scanCoil);
        coils_preloaded_list->setObjectName(QStringLiteral("coils_preloaded_list"));

        verticalLayout_6->addWidget(coils_preloaded_list);

        label_5 = new QLabel(scanCoil);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_6->addWidget(label_5);

        railCarLabel_ScanCoil = new QLabel(scanCoil);
        railCarLabel_ScanCoil->setObjectName(QStringLiteral("railCarLabel_ScanCoil"));
        railCarLabel_ScanCoil->setMinimumSize(QSize(0, 0));
        railCarLabel_ScanCoil->setFont(font1);
        railCarLabel_ScanCoil->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_6->addWidget(railCarLabel_ScanCoil);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_15);

        scanIDButton_ScanCoil = new QPushButton(scanCoil);
        scanIDButton_ScanCoil->setObjectName(QStringLiteral("scanIDButton_ScanCoil"));
        scanIDButton_ScanCoil->setMinimumSize(QSize(150, 100));

        horizontalLayout_8->addWidget(scanIDButton_ScanCoil);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_14);

        mainButton_ScanCoil = new QPushButton(scanCoil);
        mainButton_ScanCoil->setObjectName(QStringLiteral("mainButton_ScanCoil"));
        mainButton_ScanCoil->setMinimumSize(QSize(150, 100));

        horizontalLayout_8->addWidget(mainButton_ScanCoil);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_16);


        verticalLayout_6->addLayout(horizontalLayout_8);

        stackedWidget->addWidget(scanCoil);
        jobList = new QWidget();
        jobList->setObjectName(QStringLiteral("jobList"));
        verticalLayout_7 = new QVBoxLayout(jobList);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        nameLabel_JobList = new QLabel(jobList);
        nameLabel_JobList->setObjectName(QStringLiteral("nameLabel_JobList"));
        nameLabel_JobList->setFont(font);

        verticalLayout_7->addWidget(nameLabel_JobList);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        railCarLabel_JobList = new QLabel(jobList);
        railCarLabel_JobList->setObjectName(QStringLiteral("railCarLabel_JobList"));
        railCarLabel_JobList->setFont(font1);

        horizontalLayout_7->addWidget(railCarLabel_JobList);

        steelCoilLabel_JobLIst = new QLabel(jobList);
        steelCoilLabel_JobLIst->setObjectName(QStringLiteral("steelCoilLabel_JobLIst"));
        steelCoilLabel_JobLIst->setFont(font1);

        horizontalLayout_7->addWidget(steelCoilLabel_JobLIst);


        verticalLayout_7->addLayout(horizontalLayout_7);

        scrollArea_JobList = new QScrollArea(jobList);
        scrollArea_JobList->setObjectName(QStringLiteral("scrollArea_JobList"));
        scrollArea_JobList->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 774, 384));
        scrollArea_JobList->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_7->addWidget(scrollArea_JobList);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        mainButton_JobList = new QPushButton(jobList);
        mainButton_JobList->setObjectName(QStringLiteral("mainButton_JobList"));
        mainButton_JobList->setMinimumSize(QSize(150, 100));

        horizontalLayout_9->addWidget(mainButton_JobList);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_13);


        verticalLayout_7->addLayout(horizontalLayout_9);

        stackedWidget->addWidget(jobList);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Steel Car Load Verifiaction", Q_NULLPTR));
        nameLabel_Main->setText(QApplication::translate("MainWindow", "Steel Car Load Verification Program", Q_NULLPTR));
        scanButton_Main->setText(QApplication::translate("MainWindow", "Scan Rail Car ID", Q_NULLPTR));
        jobButton_Main->setText(QApplication::translate("MainWindow", "Current Jobs List", Q_NULLPTR));
        nameLabel_ScanID->setText(QApplication::translate("MainWindow", "Scan Rail Car ID Number", Q_NULLPTR));
        backButton_ScanID->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        photoButton_ScanID->setText(QApplication::translate("MainWindow", "Take Photo", Q_NULLPTR));
        viewWindow_VerifyID->setText(QApplication::translate("MainWindow", "Captured Picture", Q_NULLPTR));
        nameLabel_VerifyID->setText(QApplication::translate("MainWindow", "Rail Car ID", Q_NULLPTR));
        railcarIDLabel_VerifyID->setText(QApplication::translate("MainWindow", "*Rail Car ID*", Q_NULLPTR));
        correctButton_VerifyID->setText(QApplication::translate("MainWindow", "Correct", Q_NULLPTR));
        backButton_VerifyID->setText(QApplication::translate("MainWindow", "Main Menu", Q_NULLPTR));
        manualButton_VerifyID->setText(QApplication::translate("MainWindow", "Manual Entry", Q_NULLPTR));
        retakeButton_VerifyID->setText(QApplication::translate("MainWindow", "Retake", Q_NULLPTR));
        nameLabel_ScanCoil->setText(QApplication::translate("MainWindow", "Steel Coil Scan", Q_NULLPTR));
        confirmButton_ScanCoil->setText(QApplication::translate("MainWindow", "Confirm", Q_NULLPTR));
        label_5->setText(QString());
        railCarLabel_ScanCoil->setText(QApplication::translate("MainWindow", "Rail Car:", Q_NULLPTR));
        scanIDButton_ScanCoil->setText(QApplication::translate("MainWindow", "Scan Rail Car ID", Q_NULLPTR));
        mainButton_ScanCoil->setText(QApplication::translate("MainWindow", "Main Menu", Q_NULLPTR));
        nameLabel_JobList->setText(QApplication::translate("MainWindow", "Current Jobs", Q_NULLPTR));
        railCarLabel_JobList->setText(QApplication::translate("MainWindow", "Rail Car", Q_NULLPTR));
        steelCoilLabel_JobLIst->setText(QApplication::translate("MainWindow", "Steel Coil", Q_NULLPTR));
        mainButton_JobList->setText(QApplication::translate("MainWindow", "Main Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
