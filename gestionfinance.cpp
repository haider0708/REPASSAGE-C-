#include "gestionfinance.h"
#include "ui_gestionfinance.h"
#include "etab.h"
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
#include <etab.h>
#include <QDate>
#include <QDateTimeEdit>
//#include <arduino.h>




gestionfinance::gestionfinance(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::gestionfinance)
{


    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());
    ui->ajout_id->setValidator(new QIntValidator(1,1000,this)); // id
    ui->mod_id->setValidator(new QIntValidator(1,1000,this)); // id mod
    ui->ajout_prix->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
    ui->supp_id->setValidator(new QIntValidator(1,1000,this)); //supp id
    ui->mod_prix->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
    ui->ajout_cin->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
    ui->mod_cin->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));

}





gestionfinance::~gestionfinance()
{
    delete ui;
}

//ajout
void gestionfinance::on_pushButton_clicked()
{
 etab f ;
 f.set_id(ui->ajout_id->text());
 f.set_nom(ui->ajout_prix->text());
 f.set_adress(ui->ajout_cin->text());

 bool ajout= f.ajouter(f);
 if(ajout)
    {
        ui->tableView->setModel(f.afficher());
        QMessageBox::information(nullptr, QObject::tr("etab ajouter"),
                    QObject::tr("etab ajouter.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
    else
        QMessageBox::critical(nullptr, QObject::tr("etab non ajouter"),
                    QObject::tr("etab non ajouter.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

//supprimer
void gestionfinance::on_pushButton_5_clicked()
{
    etab p ;
    int id=ui->supp_id->text().toInt();
    bool supprime= e.supprimer(id);
    if(supprime)
       {
           QMessageBox::information(nullptr, QObject::tr("etab supprimer"),
                       QObject::tr("etab supprimer.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(e.afficher());



   }
       else
           QMessageBox::critical(nullptr, QObject::tr("etab non supprimer"),
                       QObject::tr("etab non supprimer.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}




//modifier

void gestionfinance::on_pushButton_3_clicked()
{
    etab f ;
    f.set_id(ui->mod_id->text());
    f.set_nom(ui->mod_prix->text());
    f.set_adress(ui->mod_cin->text());
    bool modif= f.modifier(f);
    if(modif)
       {
           ui->tableView->setModel(f.afficher());
           QMessageBox::information(nullptr, QObject::tr("etab modifier"),
                       QObject::tr("etab modifier.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("etab non modifier"),
                       QObject::tr("etab non modifier.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}


//pdf
void gestionfinance::on_pushButton_8_clicked()
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
                                "<h1>Liste des etabs</h1>"

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
void gestionfinance::on_pushButton_9_clicked()
{

  ui->tableView->setModel(e.trierref());


}
void gestionfinance::on_pushButton_10_clicked()
{

  ui->tableView->setModel(e.trie());


}



void gestionfinance::on_pushButton_6_clicked()
{
statistique *s = new statistique(this);
s->show();



}


//rechercher
void gestionfinance::on_pushButton_12_clicked()
{
    etab f ;
    int id=ui->lineEdit_R->text().toInt();
     ui->tableView->setModel(f.Rechercher(id));
     int type=ui->lineEdit_R->text().toInt();
     ui->tableView->setModel(f.Rechercher(type));





}
//best offer
/*
void gestionfinance::on_pushButton_10_clicked()
{
    Bestoffer *bo = new Bestoffer(this);
    bo->show();







}
*/
//Reset
void gestionfinance::on_pushButton_13_clicked()
{
   ui->tableView->setModel(e.afficher());
}
void gestionfinance::on_pushButton_11_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT prix FROM etab WHERE ID = 10");
    query.bindValue(":ID",e.get_id());
    int prix = -1;
    prix = query.value(0).toInt();
    qDebug() << " PRIX:" << prix;

}
