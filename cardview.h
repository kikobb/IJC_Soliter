#ifndef CARDVIEW_H
#define CARDVIEW_H

#include <QFrame>

namespace Ui {
class CardView;
}

class CardView : public QFrame
{
    Q_OBJECT

public:
    explicit CardView(QWidget *parent = 0);
    ~CardView();

private:
    Ui::CardView *ui;
};

#endif // CARDVIEW_H
