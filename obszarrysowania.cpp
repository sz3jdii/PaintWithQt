#include "obszarrysowania.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPaintEvent>
#include <qpainter.h>
#include <QResizeEvent>
ObszarRysowania::ObszarRysowania(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    mRysunek = QImage(800, 300, QImage::Format_ARGB32);
    mRysunek.fill(QColor(255, 255, 255));
}
ObszarRysowania::~ObszarRysowania()
{
    //
}
void ObszarRysowania::on_red_clicked()
{
     qDebug() << "Kolor: " << "czerwony";
     this->mKolor = Qt::red;
}
void ObszarRysowania::on_blue_clicked()
{
    qDebug() << "Kolor: " << "niebieski";
    this->mKolor = Qt::blue;
}
void ObszarRysowania::on_yellow_clicked()
{
    qDebug() << "Kolor: " << "żółty";
    this->mKolor = Qt::yellow;
}
void ObszarRysowania::on_green_clicked()
{
    qDebug() << "Kolor: " << "zielony";
    this->mKolor = Qt::green;
}
void ObszarRysowania::on_erase_clicked()
{
    qDebug() << "Czynność: " << "Usuwanie";

}
bool ObszarRysowania::on_save_clicked(const QString &fileName)
{
    qDebug() << "Czynność: " << "Zapisywanie" << fileName;
    return true;
}
void ObszarRysowania::mousePressEvent(QMouseEvent *zdarzenie)
{
    if (zdarzenie->buttons()==Qt::LeftButton)
    {
        qDebug() << "Nastąpiło kliknięcie lewego przycisku: " << zdarzenie;
    }
    if (zdarzenie->buttons()==Qt::RightButton)
    {
        qDebug() << "Nastąpiło kliknięcie prawego przycisku: " << zdarzenie;
    }
}
void ObszarRysowania::mouseMoveEvent(QMouseEvent *zdarzenie)
{
    qDebug() << "Pozycja myszy: " << zdarzenie->pos();
}
void ObszarRysowania::mouseReleaseEvent(QMouseEvent *zdarzenie)
{
    if (zdarzenie->buttons()==Qt::NoButton)
    {
        qDebug() << "Nastąpiło uwolnienie przycisku: " << zdarzenie;
    }
}
void ObszarRysowania::paintEvent(QPaintEvent *zdarzenie)
{
    qDebug() << "Nastąpiło rysowanie: " << zdarzenie;
    QPainter rysownik;
    rysownik.begin(this);
    rysownik.drawImage(0, 0, this->mRysunek);
    rysownik.end();
}
void ObszarRysowania::resizeEvent(QResizeEvent *zdarzenie)
{
    if (zdarzenie->size()!= zdarzenie->oldSize())
    {
        qDebug() << "Nastąpiła zmiana rozmiaru okna: " << zdarzenie;
    }
}
