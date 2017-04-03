#include "mzprob.h"
#include "ui_mzprob.h"
#include "QMessageBox"


const QString M = "Misszionárius";
const QString K = "Kannibál";

mzProb::mzProb(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mzProb)
{
    ui->setupUi(this);
}



mzProb::~mzProb()
{
    delete ui;
}

void mzProb::on_pushButton_4_clicked()
{
    this->ui->groupBox->setEnabled(false);
    this->ui->enter->setEnabled(false);
    this->ui->exit->setEnabled(false);
    this->ui->fromBoToLeft->setEnabled(false);
    this->ui->fromRighttoBo->setEnabled(false);
    lmCount = 0;
    bmCount = 0;
    rmCount = 0;
    lhCount = 0;
    bhCount = 0;
    rhCount = 0;
    this->ui->lst_left->clear();
    this->ui->lst_boat->clear();
    this->ui->lst_right->clear();

    for(int i = 0; i< (this->ui->n->value()); ++i){
        this->ui->lst_left->addItem(M);
        lmCount++;
    }


    for(int i = 0; i< (this->ui->n->value()); ++i){
        this->ui->lst_left->addItem(K);
        lhCount++;
    }

    counter = 0;
    this->ui->Display->display(0);
}

void mzProb::on_enter_clicked()
{

    QString KvM = this->ui->lst_left->currentItem()->text();
    int bCount = this->ui->lst_boat->count();
    int kValue = this->ui->k->value();
    if(KvM == M){
        ++bmCount;
        --lmCount;
    }else{
        ++bhCount;
        --lhCount;
    }


    if(bCount < kValue && (lmCount == 0 || lmCount >= lhCount) && (bmCount >= bhCount || bmCount == 0)){ //feltétel, hogy a klikk után nem lesz több K mint M
       this->ui->lst_boat->addItem(this->ui->lst_left->currentItem()->clone());
       delete this->ui->lst_left->currentItem();
       counter++;
       this->ui->Display->display(counter);
    }else{
        if (KvM == M){
            --bmCount;
            ++lmCount;
        }else{
            --bhCount;
            ++lhCount;
        }
        QMessageBox msgBox;
        msgBox.setText("A megadottnál többen lennének a csónakban vagy M<K");
        msgBox.exec();
    }

    this->ui->lcdNumber->display(lmCount);
    this->ui->lcdNumber_2->display(lhCount);
    this->ui->lcdNumber_3->display(bmCount);
    this->ui->lcdNumber_4->display(bhCount);
    this->ui->lcdNumber_5->display(rmCount);
    this->ui->lcdNumber_6->display(rhCount);
    if (this->ui->lst_left->count() == 0) this->ui->enter->setEnabled(false);


}

void mzProb::on_exit_clicked()
{
    QString KvM = this->ui->lst_boat->currentItem()->text();

    if(KvM == M){
        --bmCount;
        ++rmCount;

    }else{
        --bhCount;
        ++rhCount;

    }



    if (( bmCount == 0 || bmCount >= bhCount) && (rmCount >= rhCount || rmCount == 0)){
        this->ui->lst_right->addItem(this->ui->lst_boat->currentItem()->clone());
        delete this->ui->lst_boat->currentItem();
        counter++;
        this->ui->Display->display(counter);

        int all = (this->ui->n->value())*2;

        if (this->ui->lst_right->count() == all){
            QMessageBox msgBox;
            msgBox.setText("Gratulálok megnyerted a játékot!!");
            msgBox.exec();
            on_pushButton_4_clicked();
        }
    }else{
        if (KvM == M){
            ++bmCount;
            --rmCount;
        }else{
            ++bhCount;
            --rhCount;
        }

        QMessageBox msgBox;
        msgBox.setText("M<K");
        msgBox.exec();

    }

    this->ui->lcdNumber->display(lmCount);
    this->ui->lcdNumber_2->display(lhCount);
    this->ui->lcdNumber_3->display(bmCount);
    this->ui->lcdNumber_4->display(bhCount);
    this->ui->lcdNumber_5->display(rmCount);
    this->ui->lcdNumber_6->display(rhCount);
    if (this->ui->lst_boat->count()==0){
        this->ui->fromBoToLeft->setEnabled(false);
        this->ui->exit->setEnabled(false);
    }

}

void mzProb::on_fromBoToLeft_clicked()
{
    QString KvM = this->ui->lst_boat->currentItem()->text();

    if(KvM == M){
        --bmCount;
        ++lmCount;
    }else{
        --bhCount;
        ++lhCount;

    }
    if(( bmCount == 0 || bmCount >= bhCount) && (lmCount >= lhCount || lmCount == 0 )){
        this->ui->lst_left->addItem(this->ui->lst_boat->currentItem()->clone());
        delete this->ui->lst_boat->currentItem();
        counter++;
        this->ui->Display->display(counter);
    }else{
        if(KvM == M){
            ++bmCount;
            --lmCount;
        }else{
            ++bhCount;
            --lhCount;
        }

        QMessageBox msgBox;
        msgBox.setText("M<K");
        msgBox.exec();
    }
    //feltétel, hogy a klikk után nem lesz több K mint M


    this->ui->lcdNumber->display(lmCount);
    this->ui->lcdNumber_2->display(lhCount);
    this->ui->lcdNumber_3->display(bmCount);
    this->ui->lcdNumber_4->display(bhCount);
    this->ui->lcdNumber_5->display(rmCount);
    this->ui->lcdNumber_6->display(rhCount);
    if (this->ui->lst_boat->count()==0){
        this->ui->fromBoToLeft->setEnabled(false);
        this->ui->exit->setEnabled(false);
    }

}

void mzProb::on_fromRighttoBo_clicked()
{
    QString KvM = this->ui->lst_right->currentItem()->text();

    if(KvM == M){
        --rmCount;
        ++bmCount;
    }else{
        --rhCount;
        ++bhCount;

    }
    int bCount = this->ui->lst_boat->count();
    int kValue = this->ui->k->value();

    if(bCount < kValue && ( bmCount == 0 || bmCount >= bhCount) && (rmCount >= rhCount || rmCount == 0)){ //feltétel, hogy a klikk után nem lesz több K mint M
       this->ui->lst_boat->addItem(this->ui->lst_right->currentItem()->clone());
       delete this->ui->lst_right->currentItem();
       counter++;
       this->ui->Display->display(counter);
    }else{
        if (KvM == M){
            ++rmCount;
            --bmCount;
        }else{
            ++rhCount;
            --bhCount;
        }

        QMessageBox msgBox;
        msgBox.setText("A megadottnál többen lennének a csónakban! vagy M<K");
        msgBox.exec();
    }

    this->ui->lcdNumber->display(lmCount);
    this->ui->lcdNumber_2->display(lhCount);
    this->ui->lcdNumber_3->display(bmCount);
    this->ui->lcdNumber_4->display(bhCount);
    this->ui->lcdNumber_5->display(rmCount);
    this->ui->lcdNumber_6->display(rhCount);
    if (this->ui->lst_right->count() == 0) this->ui->fromRighttoBo->setEnabled(false);
}

void mzProb::on_surrender_clicked()
{
    this->ui->groupBox->setEnabled(true);
    counter = 0;
    this->ui->lst_left->clear();
    this->ui->lst_boat->clear();
    this->ui->lst_right->clear();
    this->ui->Display->display(0);
}

void mzProb::on_lst_left_pressed(const QModelIndex &index)
{
    this->ui->lst_left->count() == 0 ? this->ui->enter->setEnabled(false) : this->ui->enter->setEnabled(true);
}


void mzProb::on_lst_boat_pressed(const QModelIndex &index)
{
    if (this->ui->lst_boat->count() == 0){
        this->ui->exit->setEnabled(false);
        this->ui->fromBoToLeft->setEnabled(false);
    }else{
        this->ui->exit->setEnabled(true);
        this->ui->fromBoToLeft->setEnabled(true);
    }
}

void mzProb::on_lst_right_pressed(const QModelIndex &index)
{
    this->ui->lst_right->count() == 0 ? this->ui->fromRighttoBo->setEnabled(false) : this->ui->fromRighttoBo->setEnabled(true);
}
