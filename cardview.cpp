/**
 * @file cardview.cpp.
 *
 * @author xuhlia03
 * 		   
 * Implements the cardview class.
 */

#include "cardview.h"
#include "ui_cardview.h"

/**
 * Constructor.
 *
 * @param [in,out] parent If non-null, the parent.
 */

CardView::CardView(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CardView)
{
    ui->setupUi(this);
}

/** Destructor. */
CardView::~CardView()
{
    delete ui;
}
