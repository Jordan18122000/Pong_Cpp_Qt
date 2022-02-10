#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "barre.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>


namespace Ui {
class MainWindow;
}

class Balle;    //On initialise les classes qui sont appelés par notre MainWindow
class Score;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
     bool WaitKey = true; // permet d'initialiser notre valeur afin de ne pas voir repartir la balle lors du premier point
     bool resetIsOK = true;
     Ui::MainWindow *ui;
     Balle& m_balle;
     Barre *player = new Barre();
     Barre *computer = new Barre();
     Score& score;
     QGraphicsScene *scene = new QGraphicsScene(this);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void keyPressEvent(QKeyEvent* event);

private slots:
    void on_actionApropos_triggered();
    void on_actionComment_jouer_triggered();
    void on_actionAide_triggered();
    void reset_balle_position();
    void playerWin();
    void cpuWin();


signals:
    void partWin();
};

#endif // MAINWINDOW_H
