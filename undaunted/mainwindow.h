#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board.h"
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_1_clicked();
    void on_prevButton_clicked();
    void on_nextButton_clicked();

private:
    Ui::MainWindow *ui;
    board* nboard = nullptr;
    board* pboard = nullptr;
    void showerror();
    bool isValid(const QString& name, QString &errorMsg);

    QString selectedMapPath;
    QStringList mapFiles;
    int currentMapIndex = 0;

    QGraphicsScene* mapScene = nullptr;
    QGraphicsScene* screen = nullptr;

    void loadMapList();
    void renderMap(QString path);

    bool eventFilter(QObject* obj, QEvent* event);
};
#endif // MAINWINDOW_H
