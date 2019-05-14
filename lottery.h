#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFont>
#include <QSizePolicy>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class Lottery : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lottery(QWidget *parent = 0);

    QLabel *label[7];

    ~Lottery();

private slots:


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
