#include "lottery.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QObject>

Lottery::Lottery(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMinimumSize(800,480);
    this->setMaximumSize(800,480);
    this->setStyleSheet("QWidget#centralWidget{background-image: url(:/new/prefix1/lottery.jpg);}");
    ui->pushButton->setStyleSheet("background-color: rgb(255,00,00)");

   for(int i=0; i<7; i++)
   {
       label[i] = new QLabel(this);
       label[i]->setObjectName(QString("label_%1").arg(i));
       label[i]->setGeometry(40+100*i,200,80,80);
       if(i < 6)
           label[i]->setStyleSheet("background-color: rgb(255,00,00);border:2px solid#ff0000;border-radius:40px;");
       else
           label[i]->setStyleSheet("background-color: rgb(00,00,255);border:2px solid#0000ff;border-radius:40px;");
   }
}

Lottery::~Lottery()
{
    delete ui;
}

void Lottery::on_pushButton_clicked()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

     int red_num[6];
     for(int i=0; i<6; i++)
     {
         red_num[i] = qrand()%36;
         if(red_num[i] == 0)
         {
             i--;
             continue;
         }
         for(int j=i; j>0; j--)
         {
             if(red_num[j] == red_num[j-1])
             {
                 i -= 2;
                 break;
             }
             if(red_num[j] < red_num[j-1])
             {
                 int tmp = red_num[j];
                 red_num[j] = red_num[j-1];
                 red_num[j-1] = tmp;
             }
         }
     }

     int blue_num;
     while(1)
     {
         blue_num = qrand()%16;
         if(blue_num>0 && blue_num<16)
             break;
     }

     QFont font;
     font.setFamily("隶书");
     font.setBold(true);
     font.setPointSize(24);

    for(int i=0; i<7; i++)
    {
        QLabel *L = this->findChild<QLabel *>(QString("label_%1").arg(i));
        if(i < 6)
            L->setText(QString("%1").arg(red_num[i]));
        else
               L->setText(QString("%1").arg(blue_num));

        L->setAlignment(Qt::AlignCenter);
        L->setFont(font);
    }

}
