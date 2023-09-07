#include "etab.h"
#include "etab.h"
#include <QDate>

etab::etab()
{
    _id="";
    _nom="";
    _adress="";

}

void etab::set_id(QString n)
{
    _id=n;
}
void etab::set_nom(QString n)
{
    _nom=n;
}
void etab::set_adress(QString n)
{
    _adress=n;
}


QString etab::get_id()
{
    return _id;
}
QString etab::get_nom()
{
    return _nom;
}
QString etab::get_adress()
{
    return _adress;
}

bool etab::ajouter(etab e)
{
  QSqlQuery query;
  query.prepare("INSERT INTO etab (ID , NOM , ADRESS ) VALUES (:ID, :NOM, :ADRESS)");
  query.bindValue(":ID",e.get_id());
  query.bindValue(":NOM",e.get_nom());
  query.bindValue(":ADRESS",e.get_adress());
  /*QDate DAT = QDate::currentDate();
  query.bindValue(":DAT", DAT.toString("yyyy-MM-dd"));*/
  return query.exec();


}
bool etab::supprimer(int id)
{
  QSqlQuery query ;
  QString res = QString::number(id);
  query.prepare("delete from etab where ID= :ID");
  query.bindValue(":ID",res);
  return query.exec();

}

QSqlQueryModel * etab::afficher()
{
 QSqlQueryModel * model = new QSqlQueryModel();
 model->setQuery("select * from etab ");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESS"));
 return model;
}

QSqlQueryModel * etab::trierref()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from etab order by ID ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESS"));
    return model;
}
QSqlQueryModel * etab::trie()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from etab order by ID DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESS"));
    return model;
}

bool etab::modifier(etab e)
{
  QSqlQuery query;
  query.prepare("update etab set NOM= :NOM, ADRESS = :ADRESS where ID= :ID");
  query.bindValue(":ID",e.get_id());
  query.bindValue(":NOM",e.get_nom());
  query.bindValue(":ADRESS",e.get_adress());
  return query.exec();

}
QSqlQueryModel * etab::Rechercher(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from etab where ID = :ID");
    query.bindValue(":ID",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESS"));
    return model;
}



