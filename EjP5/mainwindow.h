#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <cstdlib>
#include <QTimer>
#include <QList>
#include "paredfija.h"
#include "pareddest.h"
#include "personaje.h"
#include "enemigos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool evaluarColision();

private slots:
    void MovEnemy();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    personaje *bomber;
    enemigos *enemy1;
    QTimer *timerEnemy;
    QList <paredfija*>paredesfijas;
    QList <paredfija*>::Iterator itPF;
    QList <pareddest*>paredesdest;
    QList <pareddest*>::Iterator itPD;
    void keyPressEvent(QKeyEvent *evento);

    int timeEnemy=0;
};
#endif // MAINWINDOW_H
