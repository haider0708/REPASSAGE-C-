#ifndef GESTIONFINANCE_H
#define GESTIONFINANCE_H
#include<QMessageBox>
#include <QMainWindow>
#include <QObject>
#include <etab.h>
#include<QTableView>
#include<statistique.h>
//#include<arduino.h>

QT_BEGIN_NAMESPACE
namespace Ui { class gestionfinance; }
QT_END_NAMESPACE

class gestionfinance : public QMainWindow
{
    Q_OBJECT

public:
    gestionfinance(QWidget *parent = nullptr);
    ~gestionfinance();

private slots:
    void update_label();
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::gestionfinance *ui;
    Ui::statistique *st;
    etab e ;
    QByteArray data; // variable contenant les données reçues
    //Arduino A; // objet temporaire
};

#endif // GESTIONFINANCE_H
