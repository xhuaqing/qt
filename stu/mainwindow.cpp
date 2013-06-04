#include "mainwindow.h"
#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"
#include "spreadsheet.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);

    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();

    findDialog = 0;

    setWindowIcon(QIcon(":/images/icon.png"));
    setCurrentFile("");
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"),this);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(newAction, &QAction::triggered, this, &MainWindow::newFile);


    exitAction = new QAciton(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);

    selectAllAction = new QAction(tr("&All"),this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
    connect(selectAllAction, &QAction::triggered, spreadsheet, &Spreadsheet::selectAll);


    showGridAction = new QAction(tr("&Show Grid"), this);
    showGridAction->setCheckable(true);
    showGridAction->setChecked(spreadsheet->showGrid());
    showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
    connect(showGridAction, &QAction::toggled, spreadsheet, &Spreadsheet::setShowGrid);

    aboutQtAction = new QAction(tr("About &Qt"),this);
    aboutQtAction->setStatusTip(tr("Show the Qt libary's About box"));
    conncet(aboutQtAction, &QAction::triggered, &QApplication::aboutQt);

    for(int i=0; i<MaxRecentFiles; ++i){
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], &QAction::triggered, this, &MainWindow::openRecentFile);
    }

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);

    separatorAction = fileMenu->addSeparator();
    for(int i=0; i<MaxRecentFiles; ++i)
        fileMenu->addAction(recentFileActions[i]);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
}
