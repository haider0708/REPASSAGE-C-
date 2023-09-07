#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestionfinance.h"
#include "gestioneleve.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    gestionfinance *gf;
      gf= new gestionfinance(this);
       gf->show();
}
void MainWindow::on_pushButton_1_clicked()
{
    gestioneleve *ge;
      ge= new gestioneleve(this);
       ge->show();
}
