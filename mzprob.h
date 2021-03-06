#ifndef MZPROB_H
#define MZPROB_H

#include <QMainWindow>

namespace Ui {
class mzProb;
}

class mzProb : public QMainWindow
{
    Q_OBJECT

public:
    explicit mzProb(QWidget *parent = 0);
    ~mzProb();

private slots:

    void on_pushButton_4_clicked();

    void on_enter_clicked();

    void on_exit_clicked();

    void on_fromBoToLeft_clicked();

    void on_fromRighttoBo_clicked();

    void on_surrender_clicked();

    void on_lst_left_pressed(const QModelIndex &index);

    void on_lst_boat_pressed(const QModelIndex &index);

    void on_lst_right_pressed(const QModelIndex &index);

private:
    Ui::mzProb *ui;
    int counter;
    int lmCount;
    int bmCount;
    int rmCount;
    int lhCount;
    int bhCount;
    int rhCount;
};

#endif // MZPROB_H
