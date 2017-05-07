//
// Created by xuhlia03
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

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
