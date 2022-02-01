#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
    Score();
    void refresh();
    void pointcpu();
    int getcpuscore();
    void pointplayer();
    int getplayerscore();
    void reset();
private:
    int playerpoints = 0;
    int cpupoints = 0;
};

#endif // SCORE_H



