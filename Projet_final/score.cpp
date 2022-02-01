#include "score.h"

#include <QFont>
#include "configuration.h"

#include <QBrush>
#include <QTimer>
#include <QList>

Score::Score() {
    cpupoints = 0;
    playerpoints = 0;

    setPlainText(QString("Player1: ") + QString::number(playerpoints) + QString("\nComputer: ") + QString::number(cpupoints));
    setFont(QFont("times",16));
    /*
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);*/
}

void Score::refresh() {
    setPlainText(QString("Player1: ") + QString::number(playerpoints) + QString("\nComputer: ") + QString::number(cpupoints));
}

void Score::pointcpu() {
    cpupoints++;
    refresh();
}
void Score::pointplayer() {
    playerpoints++;
    refresh();
}
int Score::getcpuscore() {
    return cpupoints;
}
int Score::getplayerscore() {
    return playerpoints;
}

void Score::reset()
{
    playerpoints = 0;
    cpupoints = 0;
    refresh();
}

