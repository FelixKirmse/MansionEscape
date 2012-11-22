/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created: Thu Nov 22 15:52:03 2012
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
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
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
    QPushButton *ForwardButton;
    QPushButton *TurnLeftButton;
    QPushButton *TurnRightButton;
    QListWidget *InventoryView;
    QTextBrowser *FeedbackArea;
    QPushButton *InspectButton;
    QPushButton *Context3Button;
    QPushButton *CommentItemButton;
    QPushButton *Context2Button;
    QPushButton *Context1Button;
    QLabel *ImageFrame;
    QToolBar *MainToolBar;
    QStatusBar *StatusBar;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(640, 480);
        centralWidget = new QWidget(GUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ForwardButton = new QPushButton(centralWidget);
        ForwardButton->setObjectName(QString::fromUtf8("ForwardButton"));
        ForwardButton->setGeometry(QRect(130, 100, 51, 51));
        TurnLeftButton = new QPushButton(centralWidget);
        TurnLeftButton->setObjectName(QString::fromUtf8("TurnLeftButton"));
        TurnLeftButton->setGeometry(QRect(70, 150, 51, 51));
        TurnRightButton = new QPushButton(centralWidget);
        TurnRightButton->setObjectName(QString::fromUtf8("TurnRightButton"));
        TurnRightButton->setGeometry(QRect(190, 150, 51, 51));
        InventoryView = new QListWidget(centralWidget);
        InventoryView->setObjectName(QString::fromUtf8("InventoryView"));
        InventoryView->setGeometry(QRect(10, 330, 621, 81));
        InventoryView->setIconSize(QSize(100, 100));
        InventoryView->setViewMode(QListView::IconMode);
        InventoryView->setUniformItemSizes(true);
        FeedbackArea = new QTextBrowser(centralWidget);
        FeedbackArea->setObjectName(QString::fromUtf8("FeedbackArea"));
        FeedbackArea->setGeometry(QRect(10, 250, 621, 71));
        InspectButton = new QPushButton(centralWidget);
        InspectButton->setObjectName(QString::fromUtf8("InspectButton"));
        InspectButton->setGeometry(QRect(20, 110, 98, 27));
        Context3Button = new QPushButton(centralWidget);
        Context3Button->setObjectName(QString::fromUtf8("Context3Button"));
        Context3Button->setGeometry(QRect(20, 60, 271, 27));
        CommentItemButton = new QPushButton(centralWidget);
        CommentItemButton->setObjectName(QString::fromUtf8("CommentItemButton"));
        CommentItemButton->setGeometry(QRect(190, 110, 98, 27));
        Context2Button = new QPushButton(centralWidget);
        Context2Button->setObjectName(QString::fromUtf8("Context2Button"));
        Context2Button->setGeometry(QRect(20, 30, 271, 27));
        Context1Button = new QPushButton(centralWidget);
        Context1Button->setObjectName(QString::fromUtf8("Context1Button"));
        Context1Button->setGeometry(QRect(20, 0, 271, 27));
        ImageFrame = new QLabel(centralWidget);
        ImageFrame->setObjectName(QString::fromUtf8("ImageFrame"));
        ImageFrame->setGeometry(QRect(310, 0, 320, 240));
        GUI->setCentralWidget(centralWidget);
        MainToolBar = new QToolBar(GUI);
        MainToolBar->setObjectName(QString::fromUtf8("MainToolBar"));
        GUI->addToolBar(Qt::TopToolBarArea, MainToolBar);
        StatusBar = new QStatusBar(GUI);
        StatusBar->setObjectName(QString::fromUtf8("StatusBar"));
        GUI->setStatusBar(StatusBar);

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QApplication::translate("GUI", "Mansion Escape", 0, QApplication::UnicodeUTF8));
        ForwardButton->setText(QApplication::translate("GUI", "\303\216", 0, QApplication::UnicodeUTF8));
        TurnLeftButton->setText(QApplication::translate("GUI", "<-", 0, QApplication::UnicodeUTF8));
        TurnRightButton->setText(QApplication::translate("GUI", "->", 0, QApplication::UnicodeUTF8));
        InspectButton->setText(QApplication::translate("GUI", "Untersuche", 0, QApplication::UnicodeUTF8));
        Context3Button->setText(QApplication::translate("GUI", "ContextAction3", 0, QApplication::UnicodeUTF8));
        CommentItemButton->setText(QApplication::translate("GUI", "Kommentiere", 0, QApplication::UnicodeUTF8));
        Context2Button->setText(QApplication::translate("GUI", "ContextAction2", 0, QApplication::UnicodeUTF8));
        Context1Button->setText(QApplication::translate("GUI", "ContextAction1", 0, QApplication::UnicodeUTF8));
        ImageFrame->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
