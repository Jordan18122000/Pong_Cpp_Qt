#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "configuration.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    QMessageBox *msgBox = new QMessageBox(&w);
    msgBox->setWindowTitle("Comment jouer");
    msgBox->setText("Utilisez les touches fléchées Haut et Bas afin de déplacer la barre afin de frapper la balle");
    msgBox->setInformativeText("Vous gagnez lorsque le ballon passe la barre de l'ordinateur");
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setModal(true);
    w.setFixedSize(PLANCHE_WIDTH, PLANCHE_HEIGHT);
    w.show();

    return a.exec();
}
