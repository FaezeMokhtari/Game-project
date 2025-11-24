#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "board.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showMaximized();

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->game_2->setScene(scene);
    ui->game_2->setRenderHint(QPainter::Antialiasing);

    board* nboard = new board();
    nboard->graphic(scene,nboard->pars("C:/Users/Flower/Documents/GitHub/Game-project/undaunted/1.txt"));
    setWindowState(windowState() | Qt::WindowMaximized);

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




