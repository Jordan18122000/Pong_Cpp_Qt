#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "balle.h"
#include "findujeu.h"
#include <QMessageBox>
#include "score.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_balle(*new Balle()),
    score(*new Score())
{
    ui->setupUi(this);
    //permet de détruire la barre en blanc en bas
    delete ui->statusBar;
    // create a game scene

    scene->setSceneRect(0, 0, width(), height());
    // add game objects
    //position barre init joueur
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

    //position init de nombre barre cpu
    computer->setPos(width() - computer->width() - 5, (height() / 2) - computer->height());

    //Balle *balle = new Balle();
    m_balle.setBarres(player, computer);
   // m_balle.setPos(player->x() + m_balle.width() + 12, player->y() + player->height() / 2);
    m_balle.setPos(this->size().width()/ 2, this->size().height()/2);

    scene->addItem(&score);

    Findujeu *findujeu= new Findujeu();
    scene->addItem(findujeu);

    scene->addItem(player);
    scene->addItem(computer);
    scene->addItem(&m_balle);

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

    //connect balle pour faire appel au reset balle et au reset position
    connect(&m_balle, &Balle::resetBall,
            this, &MainWindow::reset_balle_position);

    //on connect notre score pour compter les points et avoir la victoire
    connect(&score, &Score::cpuWinSignal,
            this, &MainWindow::cpuWin);
    connect(&score, &Score::playerWinSignal,
            this, &MainWindow::playerWin);

    //on initialise la variable qui contient la longueur de la fenetre
    m_balle.windowSizeX = this->size().width();
    m_balle.windowsSizeY = this->size().height();

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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //fonction qui permet de gerer notre barre espace
    switch(event->key())
    {
        case Qt::Key_Space:
            qDebug() <<"je suis la )";
            WaitKey = false;
            break;
        default:
            break;
    }
}

void MainWindow::reset_balle_position()
{
    if(resetIsOK) //cela nous permet d'être sur de revenir à 0 pour les scores
    {
        bool whoWin = true; // notre fonction bool pour savoir qui gagne
        if(m_balle.x() <= 0) //fonction pour vainceur cpu
        {
           score.pointcpu();

           whoWin = false;
        }
        if(m_balle.x() > 0) //fonction pour vainceur player
        {
            score.pointplayer();

            whoWin = true;
        }
        m_balle.Reset(whoWin);//on repositionne la balle en jeu
        while (WaitKey) {//on attent de cliquer sur notre touche espace
            //cela nous permet d'attendre l'évenement barre escpace avant de continuer
            QApplication::processEvents(QEventLoop::AllEvents, 100);
        }

        WaitKey = true;//notre action a été réalisé

        //on reset à la position init de la barre par la hauteur de la fentre / 2 - la hauteur de la barre
        player->Barre_reset(scene->height()/2 - player->height());
        //on reset notre barre cpu
        computer->setPos(width() - computer->width() - 5, (height() / 2) - computer->height()/2);

    }

}


void MainWindow::on_actionComment_jouer_triggered()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Comment jouer");
    msgBox->setText("Utilisez les touches fléchées Haut et Bas afin de déplacer la barre afin de frapper la balle");
    msgBox->setInformativeText("Vous gagnez lorsque le ballon passe la barre de l'ordinateur");
    msgBox->exec();
}
//notre fin du jeu par deux messages
void MainWindow::playerWin() //fonction victoire du joueur
{
    resetIsOK = false;
    QMessageBox::information(this, "Player Win", "You have 10 points ! Good Job !");
    score.reset();
    reset_balle_position();
    resetIsOK = true;
}

void MainWindow::cpuWin() //fonction victoire de l'ordinateur
{
    resetIsOK = false;
    QMessageBox::information(this, "Computer Win", "CPU have 10 points ! You are a looser !");
    score.reset();
    reset_balle_position();
    resetIsOK = true;
}
