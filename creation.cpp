#include "creation.h"
#include "ui_creation.h"
#include "mainwindow.h"

Creation::Creation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Creation)
{
    ui->setupUi(this);
    initialize();
//    connect(ui->, SIGNAL(clicked(bool)))
}

Creation::~Creation()
{
    delete ui;
}

void Creation::initialize()
{
    QDir *root = new QDir("../Veterinaire"); // C:/Users/adams/Desktop/qtprojekt/Veterinaire
    if(root->mkdir("Dossier Client"))
    {
        QMessageBox::information(this, "confirmation", tr("le dossier a été créé"));
    }
//    else
//        QMessageBox::critical(this, "pas de dossier", "le dossier n'a pas été créé");
    root->mkdir("Dossier Personnel");
    root->mkdir("Dossier Animal");
    root->mkdir("Dossier Archives");
    QFile *file = new QFile("../Veterinaire/Client.txt");
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    file->close();
    file -> setFileName("../Veterinaire/Personnel.txt");
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    file->close();
    file -> setFileName("../Veterinaire/Animaux.txt");
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    file ->close();
}

void Creation::on_enregistrerC_clicked()
{
    QFile *file = new QFile("../Veterinaire/Dossier Client/" + ui->nomLineEditC->text() + ".txt");
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream in(file);   
    in << ui->nomLineEditC->text() << "\n";
    in << ui ->prenomLineEditC->text() << "\n";
    in << ui->nomDUtilisateur->text() << "\n";
    in << ui ->adresseLineEditC->text() << "\n";
    in << ui->telephoneLineEditC->text() +"\n";
    in << ui -> mobileLineEditC->text() + "\n";
    in << ui->listGenreC->currentText() + "\n";
    file->close();
    QFile *client = new QFile("../Veterinaire/Client.txt");
    client->open(QIODevice::WriteOnly | QIODevice::Text);
    in.setDevice(client);
    in << ui->nomLineEditC->text() << "\n";
    client->close();

}

void Creation::on_enregistrerP_clicked()
{
    QFile *file = new QFile("../Veterinaire/Dossier Personnel/" + ui->nomDUtilisateurLineEdit->text() + ".txt");
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream in(file);
    in << "Genre: " << ui->listGenre->currentText() + "\n";
    in << "Titre: " << ui -> titreComboBox->currentText() + "\n";
    in << "Nom: " << ui->nomLineEdit->text() << "\n";
    in <<"Prenom: " << ui ->prenomLineEdit->text() << "\n";
    in <<"Adresse: " << ui ->adresseLineEdit->text() << "\n";
    in <<"Telephone: " <<  ui->telephoneLineEdit->text() +"\n";
    in << "Mobile: " << ui -> mobileLineEdit->text() + "\n";
    file->close();
    QFile *personnel = new QFile("../Veterinaire/Personnel.txt");
    personnel->open(QIODevice::WriteOnly | QIODevice::Text);
    in.setDevice(personnel);
    in << ui->nomLineEdit->text() << "\n";
    personnel->close();

}
