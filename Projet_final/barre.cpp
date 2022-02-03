#include "barre.h"
#include <QBrush>

Barre::Barre()
{
    setRect(0, 0, m_width, m_height);
    setBrush((QBrush)Qt::black);
}

void Barre::move(Barre::MoveType moveType)
{
    //nous permet en fonction de la touche utilisé faire varier notre axe Y
    // en fonctiondes position retourner sur x et y
    if(validMove(moveType) && moveType == UP)
        setPos(x(), y() - m_moveStep);
    else if(validMove(moveType) && moveType == DOWN)
        setPos(x(), y() + m_moveStep);
}

void Barre::randomMove(qreal ballY)
{
        //QRandomGenerator::global()->bounded(-40,40) --> permet de générer notre erreur
        //   sur Y de manière aléa
    MoveType m = ((y() - ballY+(QRandomGenerator::global()->bounded(-40,40))) > -10) ? UP : DOWN;
//  MoveType moveType = static_cast<MoveType>(-(qrand() % 2) + 1);
    move(m);
}

void Barre::keyReleaseEvent(QKeyEvent *event)
{
    //cette fonction nous permet de gerer les mouvment en fonction du clavier
    //nous avons flèche du haut pour move Up
    //et pour flèche du bas nous avons move Down
    switch (event->key()) {
    case Qt::Key_Up:
        move(UP);
        break;
    case Qt::Key_Down:
        move(DOWN);
        break;
    default:
        break;
    }
}

bool Barre::validMove(Barre::MoveType moveType)
{
    if(moveType == UP) return (y() - m_moveStep) >= 0;
    else if(moveType == DOWN) return (y() + m_moveStep) <=460;
    else return false;
}

int Barre::width()
{
    return m_width;
}

int Barre::height()
{
    return m_height;
}

//cette fonction nous permet d'init lors d'un reset
//une position pour notre barre players

void Barre::Barre_reset(int y)
{
 setPos(5,y);
}
