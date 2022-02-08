#ifndef FINDUJEU_H
#define FINDUJEU_H

#include <QGraphicsTextItem>

class Findujeu: public QGraphicsTextItem
{
public:
    Findujeu();
    void cwin(int w);
    void pwin(int w);
    void Hide();
    bool isNewGame();
    void setNewGame(bool);
private:
    bool NewGame = false;
};

#endif // FINDUJEU_H
