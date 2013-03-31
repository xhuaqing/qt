#include "eventlabel.h"
#include <QMouseEvent>
#include <QMessageBox>

void EventLabel::mouseMoveEvent(QMouseEvent *ev)
{
    this->setText(QString("<center><h1>Move:(%1, %2)</h1></center>")
                  .arg(QString::number(ev->x()),QString::number(ev->y())));
}

void EventLabel::mousePressEvent(QMouseEvent *ev)
{
    QString msg;
    msg.sprintf("<center><h1>Press:(%d, %d)</h1></center>",ev->x(),ev->y());
    this->setText(msg);
}

void EventLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString msg;
    msg.sprintf("<center><h1>Release:(%d, %d)</h1></center>",ev->x(),ev->y());
    this->setText(msg);
}

bool EventLabel::event(QEvent *e)
{
    if(e->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(e);
        if(keyEvent->key() == Qt::Key_Tab)
            QMessageBox::information(this,"?","按下Tab");
    }
    return QLabel::event(e);
}
