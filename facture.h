#ifndef FACTURE_H
#define FACTURE_H
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

class factureData;

class facture
{
private:
    QString _id, _type, _libelle, _prix, _date, _cin ;

public:
    facture();
    void set_id(QString n);
    void set_type(QString n);
    void set_libelle(QString n);
    void set_prix(QString n);
    void set_date(QString n);
    void set_cin(QString n);

    QString get_id();
    QString get_type();
    QString get_libelle();
    QString get_prix();
    QString get_date();
    QString get_cin();

    bool ajouter(facture f);
    bool supprimer(int id);
    QSqlQueryModel * afficher();
    QSqlQueryModel * trierref();
    QSqlQueryModel * trie();
    bool modifier(facture f);
    QSqlQueryModel * Rechercher(int id);
};

#endif // FACTURE_H
