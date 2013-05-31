#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QString>
#include <QDebug>

#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QLabel *label = new QLabel("<center><h1><i>Hello, </i><font color=red>Qt!</font></h1></center>");
//    label->show();


//    QPushButton *button = new QPushButton("Quit");
//    QObject::connect(button,&QPushButton::clicked,&QApplication::quit);
//    button->show();


//    QWidget *window = new QWidget;
//    window->setWindowTitle("输入年龄");

//    QSpinBox *spinbox = new QSpinBox;
//    QSlider *slider = new QSlider(Qt::Horizontal);
//    spinbox->setRange(0,120);
//    slider->setRange(0,120);

//    QObject::connect(spinbox,static_cast<void(QSpinBox:: *)(int)>(&QSpinBox::valueChanged),slider,&QSlider::setValue);
//    QObject::connect(slider,&QSlider::valueChanged,spinbox,&QSpinBox::setValue);
//    QObject::connect(slider,&QSlider::valueChanged,[&](int i){
//        QString str;
//        str.setNum(i);
//        str.prepend("年龄是：");
//        window->setWindowTitle(str);
//        qDebug() << str;
//    });

//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(spinbox);
//    layout->addWidget(slider);

//    window->setLayout(layout);
//    window->show();

//    FindDialog *dialog = new FindDialog;
//    dialog->show();


//    GoToCellDialog *dialog = new GoToCellDialog;
//    dialog->show();

    SortDialog *dialog = new SortDialog;
    dialog->setColumnRange('A','E');
    dialog->show();

    return a.exec();
}
