#include "ingrediant.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
#include <QString>
#include<QDate>
#include <QMessageBox>
ingrediant::ingrediant()
{

}

ingrediant::ingrediant(QString noming,QString duree_consomation,QString type,QString prix,QString valeur_alimentaire)
{
    this->noming=noming;
    this->duree_consomation=duree_consomation;
    this->type=type;
    this->prix=prix;
     this->valeur_alimentaire=valeur_alimentaire;
}

QString ingrediant:: getnoming()
{
    return noming;
}

QString ingrediant:: getduree_consomation()
{
    return duree_consomation;
}
QString ingrediant:: gettype()
{
    return type;
}
QString ingrediant:: getprix()
{
    return prix;
}
QString ingrediant:: getvaleur_alimentaire()
{
    return valeur_alimentaire;
}

void ingrediant::setnoming(QString noming )
{
    this->noming=noming;
}
void ingrediant::setduree_consomation(QString duree_consomation)
{
    this->duree_consomation=duree_consomation;
}
/*void Enfant::setdate_naissance(QDate date_naissance)
{
    this->date_naissance=date_naissance;

}*/

void ingrediant::settype(QString type)
{
    this->type=type;

}
void ingrediant::setprix(QString prix)
{
    this->prix=prix;

}
void ingrediant::setvaleur_alimentaire(QString valeur_alimentaire)
{
    this->valeur_alimentaire=valeur_alimentaire;

}








 bool ingrediant::Ajouter()
 {

     QSqlQuery query;

          query.prepare("INSERT INTO INGREDIANT (noming,duree_consomation,type,prix ,valeur_alimentaire) "
                        "VALUES (:noming,:duree_consomation,:type,:prix,:valeur_alimentaire)");
          query.bindValue(":noming",noming);
          query.bindValue(":duree_consomation",duree_consomation);
           query.bindValue(":type", type);
          query.bindValue(":prix",prix);
          query.bindValue(":valeur_alimentaire",valeur_alimentaire);

       return query.exec();

 }
 QSqlQueryModel *ingrediant::afficher()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM INGREDIANT");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("noming"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree_consomation"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("valeur_alimentaire"));
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







bool ingrediant::Supprime(QString noming)
{
    QSqlQuery query;
         query.prepare("delete from INGREDIANT where noming=:noming");
         query.bindValue(0, noming);
      return query.exec();
}


bool ingrediant::modifier(QString noming)
{

QSqlQuery query;




query.prepare("UPDATE INGREDIANT SET noming=:noming,duree_consomation=:duree_consomation,type=:type,prix=:prix,valeur_alimentaire=:valeur_alimentaire WHERE noming=:noming;");

     query.bindValue(":noming",noming);
     query.bindValue(":duree_consomation",duree_consomation);
     query.bindValue(":etat_psycologique",type);
     query.bindValue(":talent",prix);
     query.bindValue(":valeur_alimentaire", valeur_alimentaire );
return    query.exec();
}

void ingrediant ::rechercher(QTableView *table,QString cas )
  {
      QSqlQueryModel *model= new QSqlQueryModel();

      QSqlQuery *query=new QSqlQuery;

      query->prepare("SELECT * FROM INGREDIANT WHERE (noming LIKE '%"+cas+"%')");

      query->exec();
      model->setQuery(*query);
      table->setModel(model);
      table->show();
}
