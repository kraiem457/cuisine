#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ingrediant.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include "repas.h"
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QSqlRecord>
#include <QDate>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //  ui->noming->setValidator(new QIntValidator(0,9999999,this));
      ui->tableView_aff->setModel(i.afficher());
      QPixmap pix("C:/Users/LENOVO/OneDrive/Documents/prestataire_service/5.png");
         int w=ui->label_13->width();
         int h=ui->label_13->height();
         ui->label_13->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

      }


MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_pushButton_2_clicked()
{
  QString noming=ui->noming->text();
       // QString date_naissance=ui->date_naissance->date();
        QString duree_consomation=ui->duree_consomation->text();
        QString type=ui->type->text();

        QString prix=ui->prix->text();
        QString valeur_alimentaire=ui->valeur_alimentaire->text();



         ingrediant i(noming,duree_consomation,type,prix,valeur_alimentaire);

        bool test=i.Ajouter();
      if(test)
       {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                     QObject::tr("ajout successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView_aff->setModel(i.afficher());

                 }
                     else
                         QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                     QObject::tr("ajout failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_m_clicked()
{
    QString noming=ui->noming->text();
         // QString date_naissance=ui->date_naissance->date();
          QString duree_consomation=ui->duree_consomation->text();
          QString type=ui->type->text();

          QString prix=ui->prix->text();
          QString valeur_alimentaire=ui->valeur_alimentaire->text();



          ingrediant i(noming,duree_consomation,type,prix,valeur_alimentaire);
           bool test=i.modifier(noming);
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                       QObject::tr("modify successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_aff->setModel(i.afficher());

                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                       QObject::tr("modify failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_s_clicked()
{
    {
         ingrediant i;
        i.setnoming(ui->lineEdit_s->text());
        bool test;
        test=i.Supprime(i.getnoming());
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                       QObject::tr("sup successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_aff->setModel(i.afficher());
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                       QObject::tr("sup failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ingrediant i("","","","","");
      // e.cleartable(ui->tableView_aff);
       QString cas =ui->lineEdit_r->text();
       i.rechercher(ui->tableView_aff,cas);

       if(ui->lineEdit_r->text().isEmpty())
       {
           ui->tableView_aff->setModel(i.afficher());
       }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString Nomr=ui->Nomr->text();
         // QString date_naissance=ui->date_naissance->date();
          QString typer=ui->typer->text();
          QString heurer=ui->heurer->text();

          QString categorier=ui->categorier->text();




           repas r(Nomr,typer,heurer,categorier);

          bool test=r.Ajouter_rapas();
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                       QObject::tr("ajout successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tableView_2->setModel(r.afficher_repas());

                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                       QObject::tr("ajout failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    QString Nomr=ui->Nomr->text();
         // QString date_naissance=ui->date_naissance->date();
          QString typer=ui->typer->text();
          QString heurer=ui->heurer->text();

          QString categorier=ui->categorier->text();




          repas r(Nomr,typer,heurer,categorier);
           bool test=r.modifier_repas(Nomr);
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                       QObject::tr("modify successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_2->setModel(r.afficher_repas());

                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                       QObject::tr("modify failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_7_clicked()
{
    {
         repas r;
        r.setNomr(ui->lineEdit_s_2->text());
        bool test;
        test=r.Supprime_repas(r.getNomr());
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                       QObject::tr("sup successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_2->setModel(r.afficher_repas());
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                       QObject::tr("sup failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


    }
}


void MainWindow::on_pushButton_8_clicked()

    {

        QSqlQueryModel model;
           model.setQuery("SELECT * FROM REPAS");

            QString html = "<table  border='1'> <thead> <tr> <th>#</th> <th>Nomr</th> <th>typer</th> <th>heurer</th> <th> categorier</th> </tr> </thead><tbody > ";


           for (int i = 0; i < model.rowCount(); ++i) {

               QString Nomr = model.record(i).value("Nomr").toString();
                        QString typer = model.record(i).value("typer").toString();
                                 QString heurer = model.record(i).value("heurer").toString();
                                  QString categorier = model.record(i).value("categorier").toString();


               QString name = model.record(i).value("nom_prenom").toString();
    html += "<tr > <td>"+Nomr+"</td> <td>"+typer+"</td> <td>"+heurer+"</td><td>"+categorier+"</tr>";
           }
        html+="</tbody></table>";

          QTextDocument document;
          document.setHtml(html);

          QPrinter printer(QPrinter::PrinterResolution);
          printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setOutputFileName("cuisine.pdf");

         document.print(&printer);

}
