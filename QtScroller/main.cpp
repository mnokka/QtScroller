#include "mainwindow.h"

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QApplication>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow()
{
    // Pääikkunan asetukset
    setWindowTitle("Skrollaava Teksti");
    setFixedSize(800, 200);

    // Luodaan QLabel, jossa skrollattava teksti
    label = new QLabel("Tämä on skrollaava teksti, joka liikkuu vasemmalta oikealle ja takaisin.", this);
    label->setStyleSheet("font-size: 40px;");
    label->adjustSize();
    QFontMetrics fm(label->font());
    int textWidth = fm.horizontalAdvance(label->text());
    //textWidth=textWidth*2;
    qDebug() << "text widhr: " << textWidth;

    // Asetetaan labelin sijainti ja visuaaliset asetukset
     label->setGeometry(0, height() / 2 - 20, textWidth, 40);

    // Asetetaan QTimer, joka päivittää labelin sijainnin
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveText);
    timer->start(5); // Päivittää sijainnin 50 millisekunnin välein

    xPos = 0;
    direction = 1;  // 1 tarkoittaa liikettä oikealle, -1 vasemmalle
}

void MainWindow::moveText()
{
    // Siirretään labelia vasemmalle ja oikealle
    xPos += direction;

    // Jos label menee vasempaan tai oikeaan reunaan, vaihdetaan liikennesuunta
    if (xPos >= width()) {
        direction = -1;  // Liikettä vasemmalle
    } else if (xPos <= -label->width()) {
        direction = 1;   // Liikettä oikealle
    }

    // Päivitetään labelin sijainti
    label->move(xPos, height() / 2 - 20);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
