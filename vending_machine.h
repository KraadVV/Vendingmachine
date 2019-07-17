#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H
#include <QMessageBox>
#include <QMainWindow>
#include <QString>

namespace Ui {
class vending_machine;
}

class vending_machine : public QMainWindow
{
    Q_OBJECT

public:
    explicit vending_machine(QWidget *parent = nullptr);
    ~vending_machine();
    void changeMoney(int n);
    int money {0};

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();



    void on_pbC_clicked();

    void on_pbP_clicked();

    void on_pbR_clicked();

    void on_pushButton_clicked();

private:
    Ui::vending_machine *ui;
};

#endif // VENDING_MACHINE_H
