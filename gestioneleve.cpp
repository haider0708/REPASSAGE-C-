#include "gestioneleve.h"
#include "ui_gestioneleve.h"
#include "facture.h"
#include <QApplication>
#include <QMessageBox>
#include <QTableView>
#include <QIntValidator>
#include <QtPrintSupport/QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>
#include <QComboBox>
#include <facture.h>
#include <QDate>
#include <QDateTimeEdit>
//#include <arduino.h>




gestioneleve::gestioneleve(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::gestioneleve)
{


    ui->setupUi(this);
    ui->tableView->setModel(f.afficher());
    ui->ajout_id->setValidator(new QIntValidator(1,1000,this)); // id
    ui->mod_id->setValidator(new QIntValidator(1,1000,this)); // id mod
    ui->ajout_prix->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
    ui->supp_id->setValidator(new QIntValidator(1,1000,this)); //supp id
    ui->mod_prix->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
    ui->ajout_cin->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
    ui->mod_cin->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
    ui->ajout_type->addItem("MASCULIN");
    ui->ajout_type->addItem("FEMININ");
    ui->ajout_libelle->addItem("1er");
    ui->ajout_libelle->addItem("2eme");
    ui->ajout_libelle->addItem("3eme");
    ui->mod_type->addItem("MASCULIN");
    ui->mod_type->addItem("FEMININ");
    ui->mod_libelle->addItem("1er");
    ui->mod_libelle->addItem("2eme");
    ui->mod_libelle->addItem("3eme");

}





gestioneleve::~gestioneleve()
{
    delete ui;
}

//ajout
void gestioneleve::on_pushButton_clicked()
{
 facture f ;
 f.set_id(ui->ajout_id->text());
 f.set_prix(ui->ajout_prix->text());
 f.set_type(ui->ajout_type->currentText());
 f.set_libelle(ui->ajout_libelle->currentText());
 f.set_date(ui->ajout_date->text());
 f.set_cin(ui->ajout_cin->text());

 bool ajout= f.ajouter(f);
 if(ajout)
    {
        ui->tableView->setModel(f.afficher());
        QMessageBox::information(nullptr, QObject::tr("FACTURE ajouter"),
                    QObject::tr("FACTURE ajouter.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
    else
        QMessageBox::critical(nullptr, QObject::tr("FACTURE non ajouter"),
                    QObject::tr("FACTURE non ajouter.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

//supprimer
void gestioneleve::on_pushButton_5_clicked()
{
    facture p ;
    int id=ui->supp_id->text().toInt();
    bool supprime= f.supprimer(id);
    if(supprime)
       {
           QMessageBox::information(nullptr, QObject::tr("FACTURE supprimer"),
                       QObject::tr("FACTURE supprimer.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(f.afficher());



   }
       else
           QMessageBox::critical(nullptr, QObject::tr("FACTURE non supprimer"),
                       QObject::tr("FACTURE non supprimer.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}




//modifier

void gestioneleve::on_pushButton_3_clicked()
{
    facture f ;
    f.set_id(ui->mod_id->text());
    f.set_prix(ui->mod_prix->text());
    f.set_type(ui->mod_type->currentText());
    f.set_libelle(ui->mod_libelle->currentText());
    f.set_date(ui->mod_date->text());
    f.set_cin(ui->mod_cin->text());
    bool modif= f.modifier(f);
    if(modif)
       {
           ui->tableView->setModel(f.afficher());
           QMessageBox::information(nullptr, QObject::tr("FACTURE modifier"),
                       QObject::tr("FACTURE modifier.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("FACTURE non modifier"),
                       QObject::tr("FACTURE non modifier.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}


//pdf
void gestioneleve::on_pushButton_8_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tableView->model()->rowCount();
                    const int columnCount =ui->tableView->model()->columnCount();


                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("eleve")
                            <<  "</head>\n"
                            "<body bgcolor=#F2E7D5 link=#393E46>\n"
                                "<h1>Liste des Factures</h1>"

                                "<table border=0 cellspacing=5 cellpadding=5>\n";

                    // headers
                        out << "<thead><tr bgcolor=#F2E7D5>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableView->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tableView->isColumnHidden(column)) {
                                       QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n"
                               "</body>\n"
                               "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);
            //QTextDocument document;
            //document.setHtml(html);
            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:\\Users\\haydar\\Desktop\\pdf.pdf");
            document->print(&printer);

}
//tri
void gestioneleve::on_pushButton_9_clicked()
{

  ui->tableView->setModel(f.trierref());


}
void gestioneleve::on_pushButton_10_clicked()
{

  ui->tableView->setModel(f.trie());


}



void gestioneleve::on_pushButton_6_clicked()
{
statistique *s = new statistique(this);
s->show();



}


//rechercher
void gestioneleve::on_pushButton_12_clicked()
{
    facture f ;
    int id=ui->lineEdit_R->text().toInt();
     ui->tableView->setModel(f.Rechercher(id));
     int type=ui->lineEdit_R->text().toInt();
     ui->tableView->setModel(f.Rechercher(type));





}
//best offer
/*
void gestioneleve::on_pushButton_10_clicked()
{
    Bestoffer *bo = new Bestoffer(this);
    bo->show();







}
*/
//Reset
void gestioneleve::on_pushButton_13_clicked()
{
   ui->tableView->setModel(f.afficher());
}
void gestioneleve::on_pushButton_11_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT prix FROM facture WHERE ID = 10");
    query.bindValue(":ID",f.get_id());
    int prix = -1;
    prix = query.value(0).toInt();
    qDebug() << " PRIX:" << prix;

}
