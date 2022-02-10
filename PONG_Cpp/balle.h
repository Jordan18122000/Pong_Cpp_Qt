#ifndef BALLE_H
#define BALLE_H
#include <iostream>
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QPainter>
#include "barre.h"
#include <QWidget>


using namespace std;

class Balle: public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT

    Q_PROPERTY(int width READ width)
    Q_PROPERTY(int height READ height)
    Q_PROPERTY(int speed READ speed)

public:
    Balle();
    void Reset(bool winner);
    void setBarres(Barre *player, Barre *computer);
    bool insideBoard(int dx);
    int width();
    int height();
    int speed();
    int windowSizeX;
    int windowsSizeY;

signals:
    void resetBall();
public slots:
    void move();

private:
    Barre *m_player;
    Barre *m_computer;
    int m_width = 10;
    int m_height = 10;
    qreal dx, dy, m_speed;
};

#endif // BALLE_H
