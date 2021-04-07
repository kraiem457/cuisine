#include "repas.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
#include <QString>
#include<QDate>
#include <QMessageBox>
repas::repas()
{

}
repas::repas(QString Nomr,QString typer,QString heurer,QString categorier)
{
    this->Nomr=Nomr;
    this->typer=typer;
    this->heurer=heurer;
    this->categorier=categorier;

}

QString repas:: getNomr()
{
    return Nomr;
}

QString repas:: gettyper()
{
    return typer;
}
QString repas:: getheurer()
{
    return heurer;
}
QString repas:: getcategorier()
{
    return categorier;
}


void repas::setNomr(QString Nomr )
{
    this->Nomr=Nomr;
}
void repas::settyper(QString typer)
{
    this->typer=typer;
}
/*void Enfant::setdate_naissance(QDate date_naissance)
{
    this->date_naissance=date_naissance;

}*/

void repas::setheurer(QString heurer)
{
    this->heurer=heurer;

}
void repas::setcategorier(QString categorier)
{
    this->categorier=categorier;

}


 bool repas::Ajouter_rapas()
 {

     QSqlQuery query;

          query.prepare("INSERT INTO REPAS (Nomr,typer,heurer,categorier) "
                        "VALUES (:Nomr,:typer,:heurer,:categorier)");
          query.bindValue(":Nomr",Nomr);
          query.bindValue(":typer",typer);
           query.bindValue(":heurer", heurer);
          query.bindValue(":categorier",categorier);
       return query.exec();

 }
 QSqlQueryModel *repas::afficher_repas()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM REPAS");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nomr"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("typer"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("heurer"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorier"));
         return model;
 }
/*  QSqlQueryModel* afficher_id()
{
      QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM enfant ORDER BY id");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom"));
           // model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_naissance"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat_psycologique"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("talent"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("sexe"));
            return model;
  }*/







bool repas::Supprime_repas(QString Nomr)
{
    QSqlQuery query;
         query.prepare("delete from REPAS where Nomr=:Nomr");
         query.bindValue(0, Nomr);
      return query.exec();
}


bool repas::modifier_repas(QString Nomr)
{

QSqlQuery query;




query.prepare("UPDATE REPAS SET Nomr=:Nomr,typer=:typer,heurer=:heurer,categorier=:categorier WHERE Nomr=:Nomr;");

     query.bindValue(":Nomr",Nomr);
     query.bindValue(":typer",typer);
     query.bindValue(":heurer",heurer);
     query.bindValue(":categorier",categorier);
      return    query.exec();
}

