#include "paintedwidget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QTextEdit>

PaintedWidget::PaintedWidget(QWidget *parent) :
    QWidget(parent)
{
//    QVBoxLayout *layout = new QVBoxLayout(this);
//    layout->addWidget(new QTextEdit,1);
//    layout->addWidget(new QTextEdit,10);
}

void PaintedWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing,true);

    painter.setPen(QPen(Qt::black,5,Qt::DashDotLine,Qt::RoundCap));

    QConicalGradient conicalGradient(110, 85, 0);

    conicalGradient.setColorAt(0.0, Qt::red);
    conicalGradient.setColorAt(60.0/360.0, Qt::yellow);
    conicalGradient.setColorAt(120.0/360.0, Qt::green);
    conicalGradient.setColorAt(180.0/360.0, Qt::cyan);
    conicalGradient.setColorAt(240.0/360.0, Qt::blue);
    conicalGradient.setColorAt(300.0/360.0, Qt::magenta);
    conicalGradient.setColorAt(1.0, Qt::red);

//    painter.translate(r,r);

    painter.setBrush(QBrush(conicalGradient));
    painter.drawEllipse(QPoint(110,85),100,75);


    QLinearGradient linearGradient(220,10,420,160);
    linearGradient.setColorAt(0.2,Qt::white);
    linearGradient.setColorAt(0.6,Qt::green);
    linearGradient.setColorAt(1.0,Qt::black);
    painter.setBrush(QBrush(linearGradient));
    painter.drawEllipse(220,10,200,150);

    painter.setPen(QPen(Qt::cyan,4,Qt::DashDotDotLine,Qt::RoundCap));
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(2,2,width()-4,height()-4);

    painter.fillRect(10,10,50,100,Qt::red);
    painter.save();
    painter.translate(100,0);
    painter.fillRect(10,10,50,100,Qt::yellow);

    painter.restore();
    painter.save();
    painter.translate(300,0);
    painter.rotate(30);
    painter.fillRect(10,10,50,100,Qt::green);

    painter.restore();
    painter.save();
    painter.translate(400,0);
    painter.scale(2,3);
    painter.fillRect(10,10,50,100,Qt::blue);

    painter.restore();
    painter.save();
    painter.translate(600,0);
    painter.rotate(35);
    painter.shear(1,2);
    painter.fillRect(10,10,50,100,Qt::cyan);

    painter.restore();

}
