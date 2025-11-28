#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QRegularExpression>
#include "board.h"
#include <QMessageBox>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showMaximized();

    ui->errorLabel1->setStyleSheet("color: red;");
    ui->errorLabel2->setStyleSheet("color: red;");
    ui->errorLabel1->hide();
    ui->errorLabel2->hide();

    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, [this](const QString &){
        showerror();
    });

    connect(ui->lineEdit, &QLineEdit::textChanged, this, [this](const QString &){
        showerror();
    });


    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->game_2->setScene(scene);
    ui->game_2->setRenderHint(QPainter::Antialiasing);

    nboard = new board();

    setWindowState(windowState() | Qt::WindowMaximized);

}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_1_clicked()
{
    QString name1 = ui->lineEdit_2->text().trimmed();
    QString name2 = ui->lineEdit->text().trimmed();
    // player p1(name1);
    // player p2(name2);

    ui->pushButton_2->show();
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pushButton_2_clicked()
{
    QString file = QFileDialog::getOpenFileName(
        this, "Select Map", "C:/Users/Flower/Documents/GitHub/Game-project/undaunted", "Text Files (*.txt)"
        );
    if (file.isEmpty())
        return;

    nboard->pars(file);
    nboard->graphic(ui->game_2->scene());

    ui->pushButton_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete nboard;
}


bool MainWindow::isValid(const QString &name, QString &error)
{
    error.clear();

    if (name.isEmpty()) {
        error = "Name must not be empty.";
        return false;
    }

    if (!name[0].isLetter()) {
        error = "Name must start with a letter.";
        return false;
    }

    if (name.length() < 8) {
        error = "Name must be at least 8 characters long.";
        return false;
    }

    bool number = false;
    bool Upper = false;
    bool Lower = false;
    bool Special = false;

    for (int i = 0; i < name.length(); i++)
    {
        QChar ch = name[i];

        if (ch.isDigit())
            number = true;
        else if (ch.isUpper())
            Upper = true;
        else if (ch.isLower())
            Lower = true;
        else
            Special = true;
    }

    if (!number) {
        error = "Name must contain at least one number.";
        return false;
    }

    if (!Upper) {
        error = "Name must contain at least one uppercase letter.";
        return false;
    }

    if (!Lower) {
        error = "Name must contain at least one lowercase letter.";
        return false;
    }

    if (!Special) {
        error = "Name must contain at least one special character.";
        return false;
    }

    return true;
}


void MainWindow::showerror()
{
    QString name1 = ui->lineEdit->text();
    QString name2 = ui->lineEdit_2->text();

    QString error1, error2;

    bool player1 = isValid(name1, error1);
    bool player2 = isValid(name2, error2);

    if (!player1) {
        ui->errorLabel1->setText(error1);
        ui->errorLabel1->show();
    } else {
        ui->errorLabel1->hide();
    }

    if (!player2) {
        ui->errorLabel2->setText(error2);
        ui->errorLabel2->show();
    } else {
        ui->errorLabel2->hide();
    }

    ui->pushButton_1->setEnabled(player1 && player2);
}




