#ifndef INGREDIANT_H
#define INGREDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QTableView>

class ingrediant
{
public:
    ingrediant();


    ingrediant(QString,QString,QString,QString,QString);

   QString getnoming();
   QString getduree_consomation();
   QString gettype();
   QString getprix();
   QString getvaleur_alimentaire();
    void setnoming(QString);
    void setduree_consomation(QString);
    void settype(QString);
    void setprix(QString);
    void setvaleur_alimentaire(QString);

    bool Ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_noming();
    bool Supprime(QString);
    bool modifier(QString);
    bool reset();
      void rechercher(QTableView *table,QString cas );

    QSqlQueryModel* test();
private:

 QString noming,duree_consomation,type,prix,valeur_alimentaire;

};



#endif // INGREDIANT_H
