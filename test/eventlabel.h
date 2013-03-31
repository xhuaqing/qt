#ifndef EVENTLABEL_H
#define EVENTLABEL_H

#include <QLabel>

class EventLabel : public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

public:
    bool event(QEvent *e);
};

#endif // EVENTLABEL_H
