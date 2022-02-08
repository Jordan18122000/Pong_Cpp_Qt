#include "gamemanager.h"


GameManager::GameManager()
{
m_speed = 10;
}

void GameManager::move(Barre *computer)
{
    qreal dy = -(rand() % 2) + 1;
    computer->setPos(computer->x(), computer->y() + (GameManager::m_speed * dy));
}

void GameManager::resetpos_cpu(Barre *computer)
{
    computer->setPos(computer->x(), computer->y());
}

