#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include "eventlabel.h"
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /**
     * 鼠标事件
     */
//    EventLabel label;
//    label.setWindowTitle("MouseEvent Demo");
//    label.resize(300,200);
////    label.setText("<center><h1>MouseEvent Demo</h1></center>");
//    label.setMouseTracking(true);
//    label.show();

    /*
     * Scene View
     */
    QGraphicsScene scene;
    scene.addLine(0,0,300,200);
    scene.setSceneRect(0,0,300,300);
    QGraphicsView view(&scene);
    view.show();



    /**
     * 打开保存文件Dialog
     */
    MainWindow w;
    w.show();



    /**
     * 布局管理器
     */
//    QWidget window;
//    window.setWindowTitle("Enter your age");

//    QSpinBox *spinBox = new QSpinBox(&window);
//    QSlider *slider = new QSlider(Qt::Horizontal, &window);
//    spinBox->setRange(0, 130);
//    slider->setRange(0, 130);

//    QObject::connect(slider, &QSlider::valueChanged, spinBox,
//                     &QSpinBox::setValue);

//    void (QSpinBox::*spinBoxSignal)(int) = &QSpinBox::valueChanged;
//    QObject::connect(spinBox,spinBoxSignal,slider,&QSlider::setValue);
//    spinBox->setValue(35);

//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(spinBox);
//    layout->addWidget(slider);
//    window.setLayout(layout);
//    window.show();

    return a.exec();
}
