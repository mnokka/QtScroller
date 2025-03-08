#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();  // Konstruktorin määrittely

private slots:
    void moveText();  // Skrollauslogiikan metodi

private:
    QLabel *label;     // QLabel, johon teksti sijoitetaan
    QTimer *timer;     // QTimer, joka ohjaa skrollauksen
    int xPos;          // Labelin nykyinen horisontaalinen sijainti
    int direction;     // Liikennesuunta: 1 oikealle, -1 vasemmalle
};

#endif // MAINWINDOW_H
