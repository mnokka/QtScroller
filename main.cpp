#include "mainwindow.h"

#include <QWidget>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow()
{
    setWindowTitle("Skrollaava Teksti MPN 2025");
    setFixedSize(800, 150);

    scene = new QGraphicsScene(this);
    QString scrollingText = "----- By mika.nokka1@gmail.com 2025 ---    Forever scrolling text example!";

    textItem1 = new QGraphicsTextItem(scrollingText);
    textItem2 = new QGraphicsTextItem(scrollingText);
    QFont font("Arial", 40);
    textItem1->setFont(font);
    textItem2->setFont(font);

    textItem1->setDefaultTextColor(Qt::darkYellow);
    textItem2->setDefaultTextColor(Qt::darkYellow);

    scene->addItem(textItem1);
    scene->addItem(textItem2);

    int textWidth = textItem1->boundingRect().width();
    scene->setSceneRect(0, 0, textWidth , 200);


    view = new QGraphicsView(scene, this);
    view->setFixedSize(800, 200);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveText);
    timer->start(3);

    xPos1 = 0;
    xPos2 = textWidth; // Toinen teksti alkaa ensimmäisen perästä
}

void MainWindow::moveText()
{
    int textWidth = textItem1->boundingRect().width();
    int windowWidth = width();

    xPos1 -= 1;
    xPos2 -= 1;

    // Jos teksti menee kokonaan vasemmalle ohi, siirretään se oikealle
    if (xPos1 + textWidth < 0) {
        xPos1 = xPos2 + textWidth;
    }
    if (xPos2 + textWidth < 0) {
        xPos2 = xPos1 + textWidth;
    }

    textItem1->setPos(xPos1, height() / 2 - 20);
    textItem2->setPos(xPos2, height() / 2 - 20);
    }



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QFile file(QCoreApplication::applicationDirPath() + "/../../darktheme.css");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream ts(&file);
        a.setStyleSheet(ts.readAll());
    } else {
        qWarning("Tyylitiedoston lataaminen epäonnistui.");
    }


    MainWindow w;
    w.show();

    return a.exec();
}
