#include "mainwindow.h"
#include <sstream>
#include <string>
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QSlider>
#include <QHBoxLayout>
#include <QSpinBox>

class Circle : public QWidget
{
public:
    QColor color=QColor(0,255,0);
    void paintEvent(QPaintEvent *) override
    {
        QPainter painter;
        painter.begin(this);
        painter.setBrush(color);
        painter.drawEllipse(10, 10, 80, 80);
        painter.end();
    }
    void getColor(int sliderPos){
        double buf = sliderPos - 50;
        double r, g, b = 0;
        if(buf==0){
            r=255;
            g=255;
        }
        if(buf<0){
            g=255;
            r=255*((buf+50)/50);
        }
        if(buf>0){
            r=255;
            g=255*(1-(buf)/50);
        }
        color.setRgb(r,g,b);
        update();
    }
};

class MainWin:public QWidget{
public:
    Circle circle = Circle();
    QSlider slider = QSlider();
    QSpinBox spinbox = QSpinBox();
    MainWin(QWidget *){
        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(&circle, 0, 0, 1, 2);

        layout->addWidget(&slider, 1, 0);
        layout->addWidget(&spinbox, 2, 0);


        slider.setOrientation(Qt::Horizontal);
        slider.setMinimum(0);
        slider.setMaximum(100);
        QObject::connect(
            &slider,
            &QSlider::valueChanged,
            &circle,
            &Circle::getColor
            );
        QObject::connect(
            &slider,
            &QSlider::valueChanged,
            &spinbox,
            &QSpinBox::setValue
            );
        QObject::connect(
            &spinbox,
            &QSpinBox::valueChanged,
            &slider,
            &QSlider::setValue
            );
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWin win = MainWin(nullptr);
    win.show();

    return a.exec();
}
