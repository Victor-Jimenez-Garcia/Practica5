#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    timerEnemy = new QTimer;
    connect(timerEnemy, SIGNAL(timeout()),this,SLOT(MovEnemy()));
    timerEnemy->start(500);

    ui->setupUi(this);
    scene= new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,765,513);
    for (int i=0;i<=487;i+=25) {
            for (int j=0;j<=740;j+=25) {
                if (i==0 || i==487 || j==0 || j==740) {
                    paredesfijas.push_back(new paredfija(j,i,25));
                    scene->addItem(paredesfijas.back());
                }
                else if(j%50==0 && i%50==0){
                    paredesfijas.push_back(new paredfija(j,i,25));
                    scene->addItem(paredesfijas.back());
                }
                else if (i+j>74 && rand()%3==1) {
                     paredesdest.push_back(new pareddest(j,i,25));
                     scene->addItem(paredesdest.back());
                }

            }
        }
    //otra forma para el mapa
//    for(int col=0;col<x;col++){
//        for(int fil=0;fil<y;fil++){
//            if(col==0 || col==x-1 || fil==0 || fil==y-1 || (fil%2==0 && col%2==0)) matriz[col][fil]=2;
//            else if(!random() || (col==1 && fil==1) || (col==2 && fil==1) || (col==1 && fil==2)) matriz[col][fil]=0;
//            else matriz[col][fil]=1;
//        }
//    }
    enemy1 = new enemigos();
    scene->addItem(enemy1);
    bomber = new personaje();
    scene->addItem(bomber);

}
bool MainWindow::evaluarColision()
{
    for (itPF=paredesfijas.begin();itPF!=paredesfijas.end();itPF++) {
        if ((*itPF)->collidesWithItem(bomber)) {
            return true;
        }
    }
    for (itPD=paredesdest.begin();itPD!=paredesdest.end();itPD++) {
        if ((*itPD)->collidesWithItem(bomber)) {
            return true;
        }
    }
    for (itPF=paredesfijas.begin();itPF!=paredesfijas.end();itPF++) {
        if ((*itPF)->collidesWithItem(enemy1)) {
            return true;
        }
    }
    for (itPD=paredesdest.begin();itPD!=paredesdest.end();itPD++) {
        if ((*itPD)->collidesWithItem(enemy1)) {
            return true;
        }
    }
    //if(enemy1->collidesWithItem(bomber)) scene->removeItem(bomber);
    return false;

}
void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if (evento->key()==Qt::Key_W) {
        if(!evaluarColision())
            bomber->moveUp();
        else
            bomber->moveDown();
    }

    else if (evento->key()==Qt::Key_S) {
        if(!evaluarColision())
            bomber->moveDown();
        else
            bomber->moveUp();
    }

    else if (evento->key()==Qt::Key_A) {
        if(!evaluarColision())
            bomber->moveLeft();
        else
            bomber->moveRight();
    }

    else if (evento->key()==Qt::Key_D) {

        if(!evaluarColision())
            bomber->moveRight();
        else
            bomber->moveLeft();
    }
}

void MainWindow::MovEnemy()
{
    timeEnemy++;
    if (timeEnemy==1 && !evaluarColision()) {
        enemy1->moveRight();
        if(evaluarColision()) enemy1->moveLeft();
        timeEnemy=0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
