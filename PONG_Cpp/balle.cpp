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
    //setPos((width()/2-10),(height()/2-10));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
    dx = -1;
    dy = -1;
    m_speed = 10;

}

void Balle::Reset(bool winner)
{
    if(winner)
        dx = 1;
    else
        dx = -1;
    //QRandomGenerator::global()->bounded(-1,1) -> nous permet de donner
    //une valeur variant de manière aléatoire entre -1 et 1
    dy = QRandomGenerator::global()->bounded(-1,1);
    //Nous permet de positionner notre balle au centre de notre fenetre
    this->setX(windowSizeX / 2);
    this->setY(windowsSizeY/2);

    //Autre méthode de position pour notre balle
    //setPos(windowSizeX / 2, windowsSizeY/2);

    //Méthode pour positionner notre balle sur le centre de notre barre
    //setPos(m_player->x() + this->width() + 12, m_player->y() + m_player->height() / 2);

    //this->setX(50);
    //this->setY(YPos);

}


void Balle::setBarres(Barre *player, Barre *computer)
{
    m_player = player;
    m_computer = computer;
}

bool Balle::insideBoard(int x)
{

    if(x > 0)
    {
        if(x > windowSizeX)// condition victoire player
            return false;
        else
            return true;
     }
    else
        return false; // condition victoire cpu

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

/*
void Balle::resetBall()
{

}
*/

void Balle::move()
{

    //gestion de la collision avec les barres --> player et computer
    if(collidesWithItem(m_computer) || collidesWithItem(m_player)){
//      dx = -dx;
        dx = -dx;
        //nous réalisons le modulo 3 pour les actions suivante:
        // --> direction haut, direction milieur et dirction bas
        // --> gestion de l'axe Y
        dy = -(rand() % 3) + 1; // random y
    }

    //gestion de la collision avec bordure haut et bas de notre fenetre
    //Nous enlevons 70 sur notre valeur initiale de notre fenetre
    //pour mieux gerer le rebon du bas
    if(this->y() > PLANCHE_HEIGHT - 70) {
        dy = -dy;
    }

    //Nous enlevons pour mieux gerer le rebon du bas
    //on se met à 10 au lieu de 0 du à la barre blanche cela nous permet de corriger
    if(this->y() < 10) {
        dy = -dy;
    }
//    else {
//    //    dy = -(rand() % 2) + 1; // random y
//    }

    // Normal move de la balle
    setPos(x() + (m_speed * dx), y() + (m_speed * dy));
    m_computer->randomMove(y());

    if(!insideBoard(x()))
    {
        //qDebug() << "hello";
        emit resetBall();
    }

}
