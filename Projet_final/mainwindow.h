#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
     void resetGame();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionApropos_triggered();

    void on_actionComment_jouer_triggered();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
