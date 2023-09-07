#include "statistique.h"
#include "ui_statistique.h"
#include "ui_mainwindow.h"
#include<iostream>
#include "mainwindow.h"
#include "facture.h"
#include"gestioneleve.h"



statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}
// bleu
int statistique::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from FACTURE where genre = 'masculin' ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}
//vert
int statistique::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from FACTURE where genre = 'feminin' ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}


void statistique::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
    QPainter painter(this);
    QRectF size=QRectF(350,150,this->width()-700,this->width()-700);

    painter.setBrush(Qt::red);

    painter.drawPie(size,0,16*y);
    ui->label_2->setText("+10") ;
    painter.setBrush(Qt::white);
    ui->label_3->setNum(q2) ;
    painter.drawPie(size,16*y,16*m);
    ui->label_4->setText("-10") ;
    ui->label_6->setNum(q3) ;


}

