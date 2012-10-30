/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created: Tue Oct 30 16:33:22 2012
**      by: Qt User Interface Compiler version 4.8.1
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
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QWidget *dockWidgetContents;
    QPushButton *TestButton;
    QLabel *label;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(943, 567);
        dockWidgetContents = new QWidget(GUI);
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        TestButton = new QPushButton(dockWidgetContents);
        TestButton->setObjectName(QString::fromUtf8("TestButton"));
        TestButton->setGeometry(QRect(320, 290, 171, 27));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 260, 341, 17));
        GUI->setCentralWidget(dockWidgetContents);

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QApplication::translate("GUI", "DockWidget", 0, QApplication::UnicodeUTF8));
        TestButton->setText(QApplication::translate("GUI", "Push me to test slots", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GUI", "This label should change once you push the button.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
