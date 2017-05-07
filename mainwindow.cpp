/**
 * @file mainwindow.cpp.
 *
 * Implements the mainwindow class.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * Constructor.
 *
 * @param [in,out] parent If non-null, the parent.
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->
//    CardView * c = new CardView();
//    c->setStyleSheet("background-color: orange;");

}

MainWindow::~MainWindow()
{
    delete ui;
}
