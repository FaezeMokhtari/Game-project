#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showMaximized();


}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_1_clicked()
{
    QString name1 = ui->lineEdit_2->text();
    QString name2 = ui->lineEdit->text();
    //player p1(name1);
    //player p2(name2);

    ui->stackedWidget->setCurrentIndex(2);
    // ui->label_9->setText(name1);
}

MainWindow::~MainWindow()
{
    delete ui;
}




