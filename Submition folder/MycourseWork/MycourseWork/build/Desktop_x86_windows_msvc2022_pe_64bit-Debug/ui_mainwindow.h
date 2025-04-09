/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelect_File;
    QWidget *centralwidget;
    QLabel *label;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QPushButton *pushButton;
    QPushButton *Push_seekback;
    QPushButton *Push_play;
    QPushButton *Push_seekfoward;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QListWidget *listWidget;
    QLabel *label_5;
    QMenuBar *menubar;
    QMenu *menuOpen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(869, 494);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
" }\n"
"background-color: rgb(26, 26, 26);\n"
""));
        MainWindow->setIconSize(QSize(40, 40));
        actionSelect_File = new QAction(MainWindow);
        actionSelect_File->setObjectName("actionSelect_File");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 210, 311, 21));
        label->setStyleSheet(QString::fromUtf8("border-color: 2px solid rgb(255, 255, 255);"));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(30, 220, 801, 41));
        horizontalSlider->setStyleSheet(QString::fromUtf8("Qslider::groovehorizontal\n"
"{\n"
"	height:10px;\n"
"	width:460px;\n"
"	background:red;\n"
"	border-radius:5x;\n"
"}\n"
"Qslider::handle:horizontal\n"
"{\n"
"	background:rgb(52,50,64);\n"
"	width:20px;\n"
"	height:20px;\n"
"	margin:-7px-7px;\n"
"	border-radius:10px;\n"
"}"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(130, 380, 381, 20));
        horizontalSlider_2->setStyleSheet(QString::fromUtf8("Qslider::groovehorizontal\n"
"{\n"
"	height:10px;\n"
"	width:460px;\n"
"	background:red;\n"
"	border-radius:5x;\n"
"}\n"
"Qslider::handle:horizontal\n"
"{\n"
"	background:rgb(52,50,64);\n"
"	width:20px;\n"
"	height:20px;\n"
"	margin:-7px-7px;\n"
"	border-radius:10px;\n"
"}"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 350, 91, 81));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	border-radius:50px;\n"
"	background-color:rgb(255,255,255);\n"
"	color:rgb(52,51,64);\n"
"	padding:0px;\n"
"}"));
        pushButton->setIconSize(QSize(40, 40));
        Push_seekback = new QPushButton(centralwidget);
        Push_seekback->setObjectName("Push_seekback");
        Push_seekback->setGeometry(QRect(210, 290, 50, 50));
        Push_seekback->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	border-radius:50px;\n"
"	background-color:rgb(255,255,255);\n"
"	color:rgb(52,51,64);\n"
"	min-width:50px;\n"
"	max-width:50px;\n"
"	min-height:50px;\n"
"	max-height:50px;\n"
"	padding:0px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(109, 109, 109);\n"
"}"));
        Push_seekback->setIconSize(QSize(40, 40));
        Push_play = new QPushButton(centralwidget);
        Push_play->setObjectName("Push_play");
        Push_play->setGeometry(QRect(300, 290, 50, 50));
        Push_play->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	border-radius:50px;\n"
"	background-color:rgb(255,255,255);\n"
"	color:rgb(52,51,64);\n"
"	min-width:50px;\n"
"	max-width:50px;\n"
"	min-height:50px;\n"
"	max-height:50px;\n"
"	padding:0px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(109, 109, 109);\n"
"}"));
        Push_play->setIconSize(QSize(40, 40));
        Push_seekfoward = new QPushButton(centralwidget);
        Push_seekfoward->setObjectName("Push_seekfoward");
        Push_seekfoward->setGeometry(QRect(400, 290, 50, 50));
        Push_seekfoward->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	border-radius:50px;\n"
"	background-color:rgb(255,255,255);\n"
"	color:rgb(52,51,64);\n"
"	min-width:50px;\n"
"	max-width:50px;\n"
"	min-height:50px;\n"
"	max-height:50px;\n"
"	padding:0px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(109, 109, 109);\n"
"}"));
        Push_seekfoward->setIconSize(QSize(40, 40));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 260, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(770, 260, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 291, 191));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setScaledContents(true);
        label_2->setWordWrap(false);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(500, 20, 351, 191));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(790, 340, 63, 101));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 869, 25));
        menuOpen = new QMenu(menubar);
        menuOpen->setObjectName("menuOpen");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpen->menuAction());
        menuOpen->addAction(actionSelect_File);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSelect_File->setText(QCoreApplication::translate("MainWindow", "Select File", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton->setText(QString());
        Push_seekback->setText(QString());
        Push_play->setText(QString());
        Push_seekfoward->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Just Light", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
