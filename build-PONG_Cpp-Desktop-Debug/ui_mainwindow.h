/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionApropos;
    QAction *actionComment_jouer;
    QAction *actionAide;
    QWidget *centralWidget;
    QGraphicsView *gameView;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(800, 600);
        actionApropos = new QAction(MainWindow);
        actionApropos->setObjectName(QString::fromUtf8("actionApropos"));
        actionComment_jouer = new QAction(MainWindow);
        actionComment_jouer->setObjectName(QString::fromUtf8("actionComment_jouer"));
        actionAide = new QAction(MainWindow);
        actionAide->setObjectName(QString::fromUtf8("actionAide"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gameView = new QGraphicsView(centralWidget);
        gameView->setObjectName(QString::fromUtf8("gameView"));
        gameView->setGeometry(QRect(-10, 10, 821, 551));
        gameView->setContextMenuPolicy(Qt::NoContextMenu);
        gameView->setStyleSheet(QString::fromUtf8("border-image: url(:/images/background.png);"));
        gameView->setFrameShadow(QFrame::Plain);
        gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gameView->setInteractive(true);
        gameView->setRenderHints(QPainter::Antialiasing|QPainter::LosslessImageRendering|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        gameView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actionApropos);
        mainToolBar->addAction(actionComment_jouer);
        mainToolBar->addAction(actionAide);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pong Game", nullptr));
        actionApropos->setText(QCoreApplication::translate("MainWindow", "A propos", nullptr));
        actionComment_jouer->setText(QCoreApplication::translate("MainWindow", "Comment jouer", nullptr));
        actionAide->setText(QCoreApplication::translate("MainWindow", "Aide", nullptr));
#if QT_CONFIG(tooltip)
        actionAide->setToolTip(QCoreApplication::translate("MainWindow", "Aide", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
