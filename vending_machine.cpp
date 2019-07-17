#include "vending_machine.h"
#include "ui_vending_machine.h"
#include <QString>

vending_machine::vending_machine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vending_machine)
{
    ui->setupUi(this);
    ui->pbC->setDisabled(true);
    ui->pbP->setDisabled(true);
    ui->pbR->setDisabled(true);
}

vending_machine::~vending_machine()
{
    delete ui;
}
void vending_machine::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));
    ui->pbC->setEnabled(money>=100);
    ui->pbP->setEnabled(money>=150);
    ui->pbR->setEnabled(money>=200);

   //msg.information(nullptr, "title", "text");
}

void vending_machine::on_pb10_clicked()
{
    changeMoney(10);
}
void vending_machine::on_pb50_clicked()
{
    changeMoney(50);
}
void vending_machine::on_pb100_clicked()
{
    changeMoney(100);
}
void vending_machine::on_pb500_clicked()
{
    changeMoney(500);
}

void vending_machine::on_pbC_clicked()
{
    changeMoney(-100);
}

void vending_machine::on_pbP_clicked()
{
    changeMoney(-150);
}

void vending_machine::on_pbR_clicked()
{
    changeMoney(-200);
}

void vending_machine::on_pushButton_clicked()
{
    int cng10=0;
    int cng500=0;
    int cng100=0;
    int cng50=0;
    while(true)
    {

        if(money>=500)
        {
            money -= 500;
            cng500++;
            continue;
        }
        else if(money>=100)
        {
            money -= 100;
            cng100++;
            continue;
        }
        else if(money>=50)
        {
            money -= 50;
            cng50++;
            continue;
        }
        else if (money>=10)
        {
            money-=10;
            cng10++;
            continue;
        }
        else
        {
            changeMoney(0);
            break;
        }

    }
    QString output = QString::number(cng500).append(" (500 won), ");
    output += QString::number(cng100).append(" (100 won), ");
    output += QString::number(cng50).append(" (50 won), ");
    output += QString::number(cng10).append(" (10 won) returned");
    QMessageBox::information(nullptr,"change",output);
}
