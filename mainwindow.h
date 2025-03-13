#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QTimer>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void moveText();

private:
    QGraphicsScene *scene;         // Grafiikkasuuntaus
    QGraphicsView *view;           // Näkymä grafiikkasuuntausta
    QGraphicsTextItem *textItem1;   // Tekstikohde grafiikkasuuntauksessa
    QGraphicsTextItem *textItem2;
    QTimer *timer;
    int xPos1;
    int xPos2;
    int direction=-1;     // Liikennesuunta: 1 oikealle, -1 vasemmalle
};

#endif // MAINWINDOW_H
