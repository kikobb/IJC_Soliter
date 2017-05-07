/**
 * @file C:\Users\jaime\Desktop\IJC_Soliter-master\tableview.h.
 *
 * @author xuhlia03
 * 
 * Declares the tableview class.
 */

#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QFrame>
#include "ViewAbstractClass.h"
#include "cardview.h"

namespace Ui {
class TableView;
}

class TableView : public QFrame, public ViewAbstractClass
{
    Q_OBJECT

public:
    explicit TableView(QWidget *parent = 0);
    ~TableView();

private:
    Ui::TableView *ui;
};

#endif // TABLEVIEW_H
