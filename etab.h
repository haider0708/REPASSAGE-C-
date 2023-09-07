#ifndef ETAB_H
#define ETAB_H
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
#include<qmessagebox.h>
#include <QDateTimeEdit>

class etabData;

class etab
{
private:
    QString _id, _nom, _adress;

public:
    etab();
    void set_id(QString n);
    void set_nom(QString n);
    void set_adress(QString n);


    QString get_id();
    QString get_nom();
    QString get_adress();

    bool ajouter(etab f);
    bool supprimer(int id);
    QSqlQueryModel * afficher();
    QSqlQueryModel * trierref();
    QSqlQueryModel * trie();
    bool modifier(etab f);
    QSqlQueryModel * Rechercher(int id);
};
#endif // ETAB_H
