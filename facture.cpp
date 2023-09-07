#include "facture.h"
#include <QDate>

facture::facture()
{
    _id="";
    _type="";
    _libelle="";
    _prix="";
    _date="";
    _cin="";

}

void facture::set_id(QString n)
{
    _id=n;
}
void facture::set_type(QString n)
{
    _type=n;
}
void facture::set_libelle(QString n)
{
    _libelle=n;
}
void facture::set_prix(QString n)
{
    _prix=n;
}
void facture::set_date(QString n)
{
    _date=n;
}
void facture::set_cin(QString n)
{
    _cin=n;
}

QString facture::get_id()
{
    return _id;
}
QString facture::get_type()
{
    return _type;
}
QString facture::get_libelle()
{
    return _libelle;
}
QString facture::get_prix()
{
    return _prix;
}
QString facture::get_date()
{
    return _date;
}
QString facture::get_cin()
{
    return _cin;
}
bool facture::ajouter(facture f)
{
  QSqlQuery query;
  query.prepare("INSERT INTO FACTURE (ID , NOM , PRENOM ,GENRE,DAT ,CLASS) VALUES (:ID, :NOM, :PRENOM, :GENRE, :DAT, :CLASS)");
  query.bindValue(":ID",f.get_id());
  query.bindValue(":NOM",f.get_cin());
  query.bindValue(":PRENOM",f.get_prix());
  query.bindValue(":GENRE",f.get_type());
  query.bindValue(":DAT",f.get_date());
  query.bindValue(":CLASS",f.get_libelle());
  /*QDate DAT = QDate::currentDate();
  query.bindValue(":DAT", DAT.toString("yyyy-MM-dd"));*/
  return query.exec();


}
bool facture::supprimer(int id)
{
  QSqlQuery query ;
  QString res = QString::number(id);
  query.prepare("delete from facture where ID= :ID");
  query.bindValue(":ID",res);
  return query.exec();

}

QSqlQueryModel * facture::afficher()
{
 QSqlQueryModel * model = new QSqlQueryModel();
 model->setQuery("select * from FACTURE ");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("GENRE"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("CLASSE"));
 return model;
}

QSqlQueryModel * facture::trierref()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from facture order by ID ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CLASSE"));
    return model;
}
QSqlQueryModel * facture::trie()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from facture order by ID DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CLASSE"));
    return model;
}

bool facture::modifier(facture f)
{
  QSqlQuery query;
  query.prepare("update facture set GENRE= :GENRE, PRENOM = :PRENOM, CLASS= :CLASS, DAT= :DAT, NOM= :NOM where ID= :ID");
  query.bindValue(":ID",f.get_id());
  query.bindValue(":GENRE",f.get_type());
  query.bindValue(":PRENOM",f.get_prix());
  query.bindValue(":CLASS",f.get_libelle());
  query.bindValue(":DAT",f.get_date());
  query.bindValue(":NOM",f.get_cin());
  return query.exec();

}
QSqlQueryModel * facture::Rechercher(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from facture where ID = :ID");
    query.bindValue(":ID",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("LIBELLE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE"));
    return model;
}



