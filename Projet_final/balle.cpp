#include "balle.h"
#include "configuration.h"
#include "score.h"
#include "mainwindow.h"
#include "gamemanager.h"
#include <QBrush>
#include <QTimer>
#include <QList>

Balle::Balle()
{
    setRect(0, 0, m_width, m_height);
    setBrush((QBrush)Qt::green);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
    dx = -1;
    dy = -1;
    m_speed = 10;
}

void Balle::setBarres(Barre *player, Barre *computer)
{
    m_player = player;
    m_computer = computer;
}

bool Balle::insideBoard()
{
    return true;
}

//QRectF Ball::boundingRect() const
//{
//    return QRectF(x(), y(), m_width, m_height);
//}

int Balle::width()
{
    return m_width;
}

int Balle::height()
{
    return m_height;
}

int Balle::speed()
{
    return m_speed;
}


void Balle::resetBall()
{


}


void Balle::move()
{

    //balle collides with players
    if(collidesWithItem(m_computer) || collidesWithItem(m_player)){
//        dx = -dx;
        dx = -dx;
        dy = -(rand() % 2) + 1; // random y
    }
    else if(y()>PLANCHE_HEIGHT - BARRE_HEIGHT) {
        dy = -dy;
    }
    else {
//        dy = -(rand() % 2) + 1; // random y
    }
    setPos(x() + (m_speed * dx), y() + (m_speed * dy));
    m_computer->randomMove(y());

}
