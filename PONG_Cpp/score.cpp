#include "score.h"

#include <QFont>
#include "configuration.h"

#include <QBrush>
#include <QTimer>
#include <QList>

Score::Score() {
    //initialisation des scores
    cpupoints = 0;
    playerpoints = 0;

    //gestion de l'affichage de notre score
    setPlainText(QString("Player: ") + QString::number(playerpoints)+ "  " + QString("Computer: ") + QString::number(cpupoints));
    setFont(QFont("times",20)); //nous permet de gerer la taille est la police
    setDefaultTextColor(QColor("white")); //nous permet de modifier la couleur de notre afficheur
    /*
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
    */
}

void Score::refresh() {
    //gestion de l'affichage de notre score
    setPlainText(QString("Player: ") + QString::number(playerpoints)+ "  " + QString("Computer: ") + QString::number(cpupoints));
    setFont(QFont("times",20)); //nous permet de gerer la taille est la police
    setDefaultTextColor(QColor("white")); //nous permet de modifier la couleur de notre afficheur
}

void Score::pointcpu() {//gestion point cpu
    cpupoints++;
    refresh();
    if(cpupoints == 5) //condition de victoire
        emit cpuWinSignal();
}
void Score::pointplayer() {//gestion point player
    playerpoints++;
    refresh();
    if(playerpoints == 5) //condition de victoire
        emit playerWinSignal();
}
int Score::getcpuscore() {
    return cpupoints;
}
int Score::getplayerscore() {
    return playerpoints;
}

void Score::reset() //On remet les scores à 0
{
    playerpoints = 0;
    cpupoints = 0;
    refresh();
}

