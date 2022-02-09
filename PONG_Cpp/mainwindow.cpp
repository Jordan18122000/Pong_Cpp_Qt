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

    // Création d'une scène de jeu

    scene->setSceneRect(0, 0, width(), height());
    // add game objects
    //Positionne la barre du joueur en mode init
    player->setPos(5, (height() / 2.0) - player->height());
    player->setBrush(Qt::blue);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Positionne la barre de l'ordinateur en mode init
    computer->setPos(width() - computer->width() - 5, (height() / 2) - computer->height());
    m_balle.setBarres(player, computer);
    m_balle.setPos(this->size().width()/ 2, this->size().height()/2);

    scene->addItem(&score);
    Findujeu *findujeu= new Findujeu();
    scene->addItem(findujeu);
    scene->addItem(player);
    scene->addItem(computer);
    scene->addItem(&m_balle);

    // Assignation des éléments de la scène dans notre widget
    ui->gameView->setScene(scene);
    ui->gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->setGeometry(0, 0, width(), height());
    ui->gameView->setFixedSize(width(), height());

    //Connecte balle pour faire appel au reset balle et au reset position.
    connect(&m_balle, &Balle::resetBall,
            this, &MainWindow::reset_balle_position);

    //On connecte notre score pour compter les points et avoir la victoire.
    connect(&score, &Score::cpuWinSignal,
            this, &MainWindow::cpuWin);
    connect(&score, &Score::playerWinSignal,
            this, &MainWindow::playerWin);

    //On initialise la variable qui contient la longueur de la fenetre.
    m_balle.windowSizeX = this->size().width();
    m_balle.windowsSizeY = this->size().height();

}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////


void MainWindow::on_actionApropos_triggered()
{
    QMessageBox::information(this, "A propos", "Il s'agit d'un projet QT en cours de dévelopement par CLEMENT J. CARAYON J. et COM-NOUGUE G.", "OK");
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //fonction qui permet de gerer notre barre espace
    switch(event->key())
    {        case Qt::Key_Space:
            qDebug() <<"Barre Espace appuyée";

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

void MainWindow::on_actionAide_triggered()
{
    QMessageBox::information(this, "Aide", "En cas de problème pour bouger votre raquette, appuyez sur TAB afin de reprendre le contrôle de celle-ci.", "OK");

}
