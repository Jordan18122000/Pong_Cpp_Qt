#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "barre.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>


namespace Ui {
class MainWindow;
}

class Balle;
class Score;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
     bool WaitKey;
     bool resetIsOK = true;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void keyPressEvent(QKeyEvent* event);
     //void keyReleaseEvent(QKeyEvent *event);

private slots:
    void on_actionApropos_triggered();
    void reset_balle_position();
    void on_actionComment_jouer_triggered();
    void playerWin();
    void cpuWin();


    void on_actionAide_triggered();

signals:
    void partWin();

private:
    Ui::MainWindow *ui;
    Balle& m_balle;
    Barre *player = new Barre();
    Barre *computer = new Barre();
    Score& score;
    QGraphicsScene *scene = new QGraphicsScene(this);

};

#endif // MAINWINDOW_H
