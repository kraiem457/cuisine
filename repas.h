#ifndef REPAS_H
#define REPAS_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QTableView>

class repas
{
public:
    repas();

   repas (QString,QString,QString,QString);

   QString getNomr();
   QString gettyper();
   QString getheurer();
   QString getcategorier();
    void setNomr(QString);
    void settyper(QString);
    void setheurer(QString);
    void setcategorier(QString);


    bool Ajouter_rapas();
    QSqlQueryModel* afficher_repas();
    //QSqlQueryModel* afficher_noming();
    bool Supprime_repas(QString);
    bool modifier_repas(QString);



    QSqlQueryModel* test();
private:

 QString Nomr,typer,heurer,categorier;

};



#endif // REPAS_H
