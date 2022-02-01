#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "barre.h"
#include "balle.h"
#include "score.h"
#include "findujeu.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // create a game scene
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());

    // add game objects
    Barre *player = new Barre();
    player->setPos(5, (height() / 2.0) - player->height());
    player->setBrush(Qt::blue);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    /*
    Paddle *player2 = new Paddle();
    player->setPos(5, (height() / 2.0) - player2->height());
    player->setBrush(Qt::blue);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    */

    Barre *computer = new Barre();
    computer->setPos(width() - computer->width() - 5, (height() / 2) - computer->height());

    Balle *balle = new Balle();
    balle->setBarres(player, computer);
    balle->setPos(player->x() + balle->width() + 12, player->y() + player->height() / 2);

    Score *score= new Score();
    scene->addItem(score);

    Findujeu *findujeu= new Findujeu();
    scene->addItem(findujeu);

    scene->addItem(player);
    scene->addItem(computer);
    scene->addItem(balle);

    /*
    Ball *ball = new Ball();
    ball->setPaddles(player, player2);
    ball->setPos(player->x() + ball->width() + 12, player->y() + player->height() / 2);
    ball->setPos(player2->x() + ball->width() + 12, player2->y() + player2->height() / 2);///////////////

    scene->addItem(player);
   // scene->addItem(computer);
    scene->addItem(player2);
    scene->addItem(ball);
    */

    // create a game view
    ui->gameView->setScene(scene);
    ui->gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->setGeometry(0, 0, width(), height());
    ui->gameView->setFixedSize(width(), height());

}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////
void MainWindow::resetGame()
{
    this->update();
}


void MainWindow::on_actionApropos_triggered()
{
    QMessageBox::information(this, "A propos", "Il s'agit d'un projet QT en cours de dévelopement par CLEMENT J. et CARAYON J.", "OK");
}

void MainWindow::on_actionComment_jouer_triggered()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Comment jouer");
    msgBox->setText("Utilisez les touches fléchées Haut et Bas afin de déplacer la barre afin de frapper la balle");
    msgBox->setInformativeText("Vous gagnez lorsque le ballon passe la barre de l'ordinateur");
    msgBox->exec();
}
