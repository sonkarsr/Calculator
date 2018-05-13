#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>


#include <QDebug>
double firstNum;
bool userISTypingsecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plusmainus,SIGNAL(released()),this,SLOT(unary_opretion_pressed()));
    connect(ui->pushButton_percentage,SIGNAL(released()),this,SLOT(unary_opretion_pressed()));
    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_opretion_pressed()));
    connect(ui->pushButton_sub,SIGNAL(released()),this,SLOT(binary_opretion_pressed()));
    connect(ui->pushButton_multply,SIGNAL(released()),this,SLOT(binary_opretion_pressed()));
    connect(ui->pushButton_div,SIGNAL(released()),this,SLOT(binary_opretion_pressed()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);
    ui->pushButton_multply->setCheckable(true);
    ui->pushButton_div->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if((ui->pushButton_add->isChecked()||ui->pushButton_sub->isChecked()||ui->pushButton_multply->isChecked()||ui->pushButton_div->isChecked())&& (!userISTypingsecondNumber))
{

        labelNumber = button->text().toDouble();
        userISTypingsecondNumber = true;
        newLabel = QString::number(labelNumber,'g',15);
}

    else {
        if(ui->label->text().contains('.') && button->text()=="0"){
            newLabel = ui->label->text() + button->text();
        }
        else
        {

            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);

        }

    }



            ui->label->setText(newLabel);

}

void MainWindow::on_pushButton_point_pressed()
{
    ui->label->setText(ui->label->text()+'.');
}
void MainWindow::unary_opretion_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if(button->text()=="+/-"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel  = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
    if(button->text()== "%"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel  = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_clear_pressed()
{
ui->pushButton_add->setChecked(false);

ui->pushButton_sub->setChecked(false);

ui->pushButton_multply->setChecked(false);

ui->pushButton_div->setChecked(false);

userISTypingsecondNumber = false;
ui->label->setText("0");

}
void MainWindow::on_pushButton_equal_released()
{
    double labelNumber,secondNum;
    QString newLabel;
    secondNum = ui->label->text().toDouble();

    if(ui->pushButton_add->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_add->setChecked(false);
    }

    else if(ui->pushButton_sub->isChecked()){
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_sub->setChecked(false);

    }

    else if(ui->pushButton_multply->isChecked()){
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_multply->setChecked(false);
    }

    else if(ui->pushButton_div->isChecked()){
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_div->setChecked(false);

    }
    userISTypingsecondNumber = false;

}
void MainWindow::binary_opretion_pressed(){
    QPushButton *button = (QPushButton*)sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);
}
