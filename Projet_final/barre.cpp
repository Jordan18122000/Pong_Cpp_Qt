#include "barre.h"
#include <QBrush>

Barre::Barre()
{
    setRect(0, 0, m_width, m_height);
    setBrush((QBrush)Qt::black);
}

void Barre::move(Barre::MoveType moveType)
{
    if(validMove(moveType) && moveType == UP)
        setPos(x(), y() - m_moveStep);
    else if(validMove(moveType) && moveType == DOWN)
        setPos(x(), y() + m_moveStep);
}

void Barre::randomMove(qreal ballY)
{
    MoveType m = ((y() - ballY) > -10) ? UP : DOWN;
//  MoveType moveType = static_cast<MoveType>(-(qrand() % 2) + 1);
    move(m);
}

void Barre::keyReleaseEvent(QKeyEvent *event)
{
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
