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
    setPlainText(QString("Player1: ") + QString::number(playerpoints) + QString("\nComputer: ") + QString::number(cpupoints));
    setFont(QFont("times",16));
    /*
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
    */
}

void Score::refresh() {
    setPlainText(QString("Player1: ") + QString::number(playerpoints) + QString("\nComputer: ") + QString::number(cpupoints));
}

void Score::pointcpu() {//gestion point cpu
    cpupoints++;
    refresh();
    if(cpupoints == 10) //condition de victoire
        emit cpuWinSignal();
}
void Score::pointplayer() {//gestion point player
    playerpoints++;
    refresh();
    if(playerpoints == 10) //condition de victoire
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

