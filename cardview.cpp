#include "cardview.h"
#include "ui_cardview.h"

CardView::CardView(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CardView)
{
    ui->setupUi(this);
}

CardView::~CardView()
{
    delete ui;
}
