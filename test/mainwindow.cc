#include "mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"),tr("&Open..."),this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));

    connect(openAction,&QAction::triggered,this,&MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    QStatusBar *statBar = statusBar();
    statBar->addAction(openAction);
}

MainWindow::~MainWindow()
{
    delete openAction;
}

void MainWindow::open()
{
    QMessageBox::information(this,tr("Information"),tr("open"));
}
