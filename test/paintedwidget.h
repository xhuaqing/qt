#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QWidget>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintedWidget(QWidget *parent = 0);
    
protected:
    void paintEvent(QPaintEvent *);
    
};

#endif // PAINTEDWIDGET_H
