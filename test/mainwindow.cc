#include "mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QToolBar>
#include <QFileDialog>
#include <QTextStream>
#include <QCloseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
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
    menuBar()->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
    textEdit->installEventFilter(this);

    connect(textEdit,&QTextEdit::textChanged,[this](){
        this->setWindowModified(true);
    });

    setWindowTitle(tr("TextPad [*]"));

    QStatusBar *statBar = statusBar();
//    statBar->addAction(openAction);
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if(isWindowModified()){
        bool exit = QMessageBox::question(this,tr("Quit"),tr("Are you sure to quit this application?"),
                                          QMessageBox::Yes|QMessageBox::No,QMessageBox::No) == QMessageBox::Yes;
        if(exit)
            e->accept();
        else
            e->ignore();
    }else{
        e->accept();
    }
}

bool MainWindow::eventFilter(QObject * obj, QEvent * evt)
{
    if(obj==textEdit){
        if(evt->type()==QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(evt);
            qDebug() << "Ate key press" << keyEvent->key();
            return false;
        }else{
            return false;
        }
    }else{
        QMainWindow::eventFilter(obj,evt);
    }
}

//void MainWindow::open()
//{
//    QMessageBox::aboutQt(this);
//    QMessageBox::information(this,tr("Information"),tr("open"));
//    QDialog *dialog = new QDialog(this);
//    dialog->resize(120,50);
//    dialog->setAttribute(Qt::WA_DeleteOnClose);
//    dialog->setWindowTitle(tr("Hello, Dialog!"));
//    dialog->show();
//}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,tr("open file"),".",tr("Text File(*.txt)"));
    if(!path.isEmpty()){
        QFile file(path);
        if(!file.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(this,tr("read file"),tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
        setWindowModified(false);
    } else {
        QMessageBox::warning(this,tr("path"),tr("you did not select any file."));
    }
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,tr("save file"),".",tr("Text File(*.txt)"));
    if(!path.isEmpty()){
        QFile file(path);
        if(!file.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this,tr("write file"),tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
        setWindowModified(false);
    }else{
        QMessageBox::warning(this,tr("path"),tr("you did not select any file."));
    }
}
