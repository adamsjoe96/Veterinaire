#ifndef CREATION_H
#define CREATION_H

#include <QDialog>
#include<QtWidgets>

namespace Ui {
class Creation;
}

class Creation : public QDialog
{
    Q_OBJECT

public:
    explicit Creation(QWidget *parent = 0);
    ~Creation();

private:
    Ui::Creation *ui;
private:
    void initialize(); /*
                        *créé les dossiers de l'application qui contiendont les differents fichiers
                        * les dossiers sont les suivants:
                        * Dossier Client
                        * Dossier Personnel
                        * Dossier Archive
                        * Dossier Animal
                        * posséde un fichier avec nom de tous les clients
                        * pareil pour le personnel
                        * pareil pour les animaux
                        */
public slots:
    void on_enregistrerC_clicked(); /*
                        * enregistre un client dans le dossier correspondant
                        * crée un fichier donnée personnelle sur le client
                        * crée un dossier sur ses animaux
                        */
    void on_enregistrerP_clicked(); /*
                           * pareil que le saveClient
                           * mais sans les animaux
                           */
//    void on_annulerC_clicked();
//    void on_annulerP_clicked();
};

#endif // CREATION_H
