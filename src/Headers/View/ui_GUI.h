/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created: Mon Nov 12 14:54:57 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QWidget *centralWidget;
    QPushButton *_forward;
    QPushButton *_turnLeft;
    QPushButton *_turnRight;
    QListView *_inventarBar;
    QTextBrowser *_textOutput;
    QPushButton *_action2;
    QPushButton *_action1;
    QPushButton *_action3;
    QPushButton *_action4;
    QPushButton *_action3_2;
    QPushButton *_action3_4;
    QLabel *_imageFrame;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(640, 480);
        centralWidget = new QWidget(GUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        _forward = new QPushButton(centralWidget);
        _forward->setObjectName(QString::fromUtf8("_forward"));
        _forward->setGeometry(QRect(130, 100, 51, 51));
        _turnLeft = new QPushButton(centralWidget);
        _turnLeft->setObjectName(QString::fromUtf8("_turnLeft"));
        _turnLeft->setGeometry(QRect(70, 150, 51, 51));
        _turnRight = new QPushButton(centralWidget);
        _turnRight->setObjectName(QString::fromUtf8("_turnRight"));
        _turnRight->setGeometry(QRect(190, 150, 51, 51));
        _inventarBar = new QListView(centralWidget);
        _inventarBar->setObjectName(QString::fromUtf8("_inventarBar"));
        _inventarBar->setGeometry(QRect(10, 330, 621, 81));
        _textOutput = new QTextBrowser(centralWidget);
        _textOutput->setObjectName(QString::fromUtf8("_textOutput"));
        _textOutput->setGeometry(QRect(10, 250, 621, 71));
        _action2 = new QPushButton(centralWidget);
        _action2->setObjectName(QString::fromUtf8("_action2"));
        _action2->setGeometry(QRect(20, 110, 98, 27));
        _action1 = new QPushButton(centralWidget);
        _action1->setObjectName(QString::fromUtf8("_action1"));
        _action1->setGeometry(QRect(110, 210, 98, 27));
        _action3 = new QPushButton(centralWidget);
        _action3->setObjectName(QString::fromUtf8("_action3"));
        _action3->setGeometry(QRect(20, 60, 271, 27));
        _action4 = new QPushButton(centralWidget);
        _action4->setObjectName(QString::fromUtf8("_action4"));
        _action4->setGeometry(QRect(190, 110, 98, 27));
        _action3_2 = new QPushButton(centralWidget);
        _action3_2->setObjectName(QString::fromUtf8("_action3_2"));
        _action3_2->setGeometry(QRect(20, 30, 271, 27));
        _action3_4 = new QPushButton(centralWidget);
        _action3_4->setObjectName(QString::fromUtf8("_action3_4"));
        _action3_4->setGeometry(QRect(20, 0, 271, 27));
        _imageFrame = new QLabel(centralWidget);
        _imageFrame->setObjectName(QString::fromUtf8("_imageFrame"));
        _imageFrame->setGeometry(QRect(310, 0, 320, 240));
        GUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 25));
        GUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUI);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GUI->setStatusBar(statusBar);

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QApplication::translate("GUI", "Mansion Escape", 0, QApplication::UnicodeUTF8));
        _forward->setText(QApplication::translate("GUI", "\303\216", 0, QApplication::UnicodeUTF8));
        _turnLeft->setText(QApplication::translate("GUI", "<-", 0, QApplication::UnicodeUTF8));
        _turnRight->setText(QApplication::translate("GUI", "->", 0, QApplication::UnicodeUTF8));
        _action2->setText(QApplication::translate("GUI", "Untersuche", 0, QApplication::UnicodeUTF8));
        _action1->setText(QApplication::translate("GUI", "Benutze", 0, QApplication::UnicodeUTF8));
        _action3->setText(QApplication::translate("GUI", "Nehme Kondom", 0, QApplication::UnicodeUTF8));
        _action4->setText(QApplication::translate("GUI", "Kommentiere", 0, QApplication::UnicodeUTF8));
        _action3_2->setText(QApplication::translate("GUI", "Nehme Staubsaugerschl\303\274ssel", 0, QApplication::UnicodeUTF8));
        _action3_4->setText(QApplication::translate("GUI", "Nehme Vase", 0, QApplication::UnicodeUTF8));
        _imageFrame->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
