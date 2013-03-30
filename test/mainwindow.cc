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
    resize(300,200);
    openAction = new QAction(QIcon(":/images/doc-open"),tr("&Open..."),this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));

    saveAction = new QAction(QIcon(":/images/doc-open"),tr("&Save..."),this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));

    connect(openAction,&QAction::triggered,this,&MainWindow::openFile);
    connect(saveAction,&QAction::triggered,this,&MainWindow::saveFile);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    QStatusBar *statBar = statusBar();
//    statBar->addAction(openAction);
}

MainWindow::~MainWindow()
{
}

void MainWindow::openFile()
{
//    QMessageBox::aboutQt(this);
//    QMessageBox::information(this,tr("Information"),tr("open"));
//    QDialog *dialog = new QDialog(this);
//    dialog->resize(120,50);
//    dialog->setAttribute(Qt::WA_DeleteOnClose);
//    dialog->setWindowTitle(tr("Hello, Dialog!"));
//    dialog->show();
}

void MainWindow::saveFile()
{

}
