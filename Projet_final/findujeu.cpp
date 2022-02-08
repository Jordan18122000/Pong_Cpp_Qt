#include "findujeu.h"

#include <QFont>
#include <QGraphicsScene>

Findujeu::Findujeu()
{
    setPlainText(QString(""));
    setFont(QFont("times",16));
    setPos(-100, -100);

}

void Findujeu::cwin(int w)
{
    setPlainText(QString("Game Over! Computer Wins"));
    setPos(w/2-100,50);
    NewGame = true;
}

void Findujeu::pwin(int w)
{
    setPlainText(QString("Game Over! Player Wins"));
    setPos(w/2-100,50);
    NewGame = true;
}

void Findujeu::Hide()
{
    setPlainText(QString(""));
    setPos(-100, -100);
}

bool Findujeu::isNewGame()
{
    return NewGame;
}

void Findujeu::setNewGame(bool ng)
{
    NewGame = ng;
}
