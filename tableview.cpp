#include "tableview.h"
#include "ui_tableview.h"

TableView::TableView(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TableView)
{
    ui->setupUi(this);

}

TableView::~TableView()
{
    delete ui;
}
