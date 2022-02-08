#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QObject>

class Score: public QGraphicsTextItem
{
    Q_OBJECT

public:
    Score();
    void refresh();
    void pointcpu();
    int getcpuscore();
    void pointplayer();
    int getplayerscore();
    void reset();

signals:
    void playerWinSignal();
    void cpuWinSignal();

private:
    int playerpoints = 0;
    int cpupoints = 0;


};

#endif // SCORE_H



