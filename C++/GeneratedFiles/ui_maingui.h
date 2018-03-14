/********************************************************************************
** Form generated from reading UI file 'maingui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGUI_H
#define UI_MAINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGUI
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *saveLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *csvButton;
    QPushButton *htmlButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainGUI)
    {
        if (MainGUI->objectName().isEmpty())
            MainGUI->setObjectName(QStringLiteral("MainGUI"));
        MainGUI->resize(800, 600);
        centralwidget = new QWidget(MainGUI);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        saveLabel = new QLabel(centralwidget);
        saveLabel->setObjectName(QStringLiteral("saveLabel"));
        saveLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(saveLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        csvButton = new QPushButton(centralwidget);
        csvButton->setObjectName(QStringLiteral("csvButton"));

        horizontalLayout->addWidget(csvButton);

        htmlButton = new QPushButton(centralwidget);
        htmlButton->setObjectName(QStringLiteral("htmlButton"));

        horizontalLayout->addWidget(htmlButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        horizontalLayout_2->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(centralwidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout_2->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainGUI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(MainGUI);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainGUI->setStatusBar(statusbar);

        retranslateUi(MainGUI);

        QMetaObject::connectSlotsByName(MainGUI);
    } // setupUi

    void retranslateUi(QMainWindow *MainGUI)
    {
        MainGUI->setWindowTitle(QApplication::translate("MainGUI", "MainWindow", 0));
        saveLabel->setText(QApplication::translate("MainGUI", "Save as:", 0));
        csvButton->setText(QApplication::translate("MainGUI", "CSV file", 0));
        htmlButton->setText(QApplication::translate("MainGUI", "HTML file", 0));
        nameLabel->setText(QApplication::translate("MainGUI", "Give a name for the file", 0));
    } // retranslateUi

};

namespace Ui {
    class MainGUI: public Ui_MainGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGUI_H
