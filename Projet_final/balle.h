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
    void relaunch();
    bool canLaunch();

    void setBarres(Barre *player, Barre *computer);
    bool insideBoard(int dx);
//  QRectF boundingRect() const override;
    int width();
    int height();
    int speed();
    int windowSizeX;
    int windowsSizeY;

signals:
    void resetBall();
public slots:
    void move();
    //test2
    // void resetBall();
    //


private:
    //test
    int vmove = 0;
    int hmove = 0;
    int winPts = 10;
    bool launchable = true;
    int screenh;
    int screenw;
    //


    Barre *m_player;
    Barre *m_computer;
    int m_width = 10;
    int m_height = 10;
    qreal dx, dy, m_speed;
};

#endif // BALLE_H
