#ifndef GESTIONELEVE_H
#define GESTIONELEVE_H
#include<QMessageBox>
#include <QMainWindow>
#include <QObject>
#include <facture.h>
#include<QTableView>
#include<statistique.h>
//#include<arduino.h>

QT_BEGIN_NAMESPACE
namespace Ui { class gestioneleve; }
QT_END_NAMESPACE

class gestioneleve : public QMainWindow
{
    Q_OBJECT

public:
    gestioneleve(QWidget *parent = nullptr);
    ~gestioneleve();

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
    Ui::gestioneleve *ui;
    Ui::statistique *st;
    facture f ;
    QByteArray data; // variable contenant les données reçues
    //Arduino A; // objet temporaire
};
#endif // GESTIONELEVE_H
