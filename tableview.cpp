/**
 * @file tableview.cpp.
 *
 * @author xuhlia03
 * 		   
 * Implements the tableview class.
 */

#include "tableview.h"
#include "ui_tableview.h"

/**
 * Constructor.
 *
 * @param [in,out] parent If non-null, the parent.
 */

TableView::TableView(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TableView)
{
    ui->setupUi(this);

}

/** Destructor. */
TableView::~TableView()
{
    delete ui;
}
