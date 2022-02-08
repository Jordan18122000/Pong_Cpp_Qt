#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "barre.h"
#include "balle.h"


class GameManager
{
public:
    GameManager();
    void move(Barre *computer);
    void resetpos_cpu(Barre *computer);
protected:
    qreal m_speed;
};
#endif // GAMEMANAGER_H
