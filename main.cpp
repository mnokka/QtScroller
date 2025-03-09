#include "mainwindow.h"

#include <QWidget>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow()
{
    setWindowTitle("Skrollaava Teksti MPN 2025");
    setFixedSize(800, 150);

    scene = new QGraphicsScene(this);
    textItem = new QGraphicsTextItem("Tämä on skrollaava teksti, joka liikkuu vasemmalta oikealle iankaikkisesti.");
    textItem->setFont(QFont("Arial", 40));
    textItem->setPos(0, 80);
    scene->addItem(textItem);

    int textWidth = textItem->boundingRect().width();
    scene->setSceneRect(0, 0, textWidth , 200);


    view = new QGraphicsView(scene, this);
    view->setFixedSize(800, 200);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveText);
    timer->start(3);

    xPos = 0;
}

void MainWindow::moveText()
{
    // scroll from right to left, forever

    xPos += direction;
    int textWidth = textItem->boundingRect().width();
    int windowWidth = width();
    int offset = (textWidth > windowWidth) ? (textWidth-windowWidth) : 0;
    //qDebug() << "xPos" << xPos;
    //if (xPos  > windowWidth + offset) { // to right
    if (xPos  + windowWidth +offset < 0) {

        xPos=width()+offset;
        //xPos = -textWidth; // to right
        //qDebug() << "----------- siirros vasempaan laitaan ---------------------------";
        //qDebug() << "windowWidth" << windowWidth;
        //qDebug() << "textWidth" << textWidth;
        //qDebug() << "offset" << offset;
        //qDebug() << "-----------------------------------------------------------------";
    }

    textItem->setPos(xPos, height() / 2 - 20);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
