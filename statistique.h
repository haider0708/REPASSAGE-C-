#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QDialog>
//#include <QtCharts/QCategoryAxis>
//#include <QtCharts/QPieSeries>
//#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>

using namespace std;

namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
         int Statistique_partie2() ;
         int Statistique_partie3() ;
         int Statistique_partie4() ;
         int Statistique_partie5() ;
         int Statistique_partie6() ;
        void paintEvent(QPaintEvent *) ;

    ~statistique();

private:
    Ui::statistique *ui;
private slots :
};

#endif // STATISTIQUE_H
