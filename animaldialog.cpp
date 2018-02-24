#include "animaldialog.h"
#include"animal.h"
#include<QtWidgets>

AnimalDialog::AnimalDialog(VeterinaireInterface *parent) : QDialog()
{

    animal = new Animal;
//    QDialog *animalFrame = new QDialog(this, Qt::WindowTitleHint | Qt::WindowSystemMenuHint);
    setFixedSize(700, 400);
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowSystemMenuHint);
    setModal(true);
    setWindowTitle(tr("Nouvel Animal"));
    QPushButton *valider = new QPushButton(tr("Valider"));
    QPushButton *annuler = new QPushButton(tr("Annuler"));
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(annuler);
    hlayout->addWidget(valider);
    hlayout->addSpacing(40);
    QFormLayout *layout = new QFormLayout;
    name = new QLineEdit;
    name->setPlaceholderText("entrer le nom de l'animal");
    propri = new QLineEdit;
    propri->setPlaceholderText(tr("entrer le nom du propriètaire"));
    layout->addRow(tr("Name: "), name);
    layout->addRow(tr("Propriétaire: "), propri);
//    Status_Treatment m_status;
    maladie = new QLineEdit();
    layout ->addRow(tr("Maladie: "), maladie);
    traitement =  new QLineEdit;
    layout->addRow(tr("Traitement: "), traitement);
    race = new QComboBox;
    race->addItem("Chien");
    race->addItem("Chat");
    race->addItem("Oiseau");
    race->addItem("Canard");
    race->addItem("Lion");
    race->addItem("Ourse");
    race->addItem("Autre");
    layout->addRow(tr("Race: "), race);
    status = new QComboBox;
    status->addItem(tr("En attente"));
    status->addItem(tr("En Cours"));
    status->addItem(tr("Termine"));
    status->addItem(tr("None"));
    status->setEnabled(false);
    layout->addRow(tr("Etat Actuel: "), status);
    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addLayout(layout);
    vlayout->addSpacing(20);
    vlayout->addLayout(hlayout);
    setLayout(vlayout);
    connect(valider, &QPushButton::clicked, this, AnimalDialog::confirm);
    connect(valider, &QPushButton::clicked, this, AnimalDialog::close);
    connect(annuler, &QPushButton::clicked, this, AnimalDialog::rejet );
    connect(annuler, &QPushButton::clicked, this, AnimalDialog::close);
    connect(this ,&AnimalDialog::animalComplete, parent, &VeterinaireInterface::loadContain);
    connect(this, &AnimalDialog::sendAnimal, parent, &VeterinaireInterface::receptAnimal);
    connect(this, &AnimalDialog::sendOwner, parent, &VeterinaireInterface::receptOwner);
}

void AnimalDialog::confirm()
{
    bool conf{false};
    animal->setName(name->text());
    animal->setOwner(getPropri());
    animal->setDisease(getMaladie());
    animal->setTreatment(getTreatment());
//    animal->setRace(static_cast<Race>(race->currentIndex()));
    QFile *file = new QFile("../Veterinaire/Dossier Animal/" + animal->getName() + ".txt");
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QFile *file2 = new QFile("../Veterinaire/Animaux.txt");
    file2->open(QIODevice::Append | QIODevice::Text);
    QTextStream in(file);
    in << animal->getName() +"\n";
    in << animal->getOwner()->getName() + "\n";
    in << animal->getDisease() + "\n";
    in << animal->getTreatment()+ "\n";
    in << animal->getRace() << "\n";
    in << animal->getStatus()<< "\n";
    file->close();
    in.setDevice(file2);
    in << animal->getName() + "\n";
    file2->close();
    QDir *root = new QDir("../Veterinaire/Dossier Client");
    root->mkdir(animal->getOwner()->getName());
//    root->setCurrent("../Veterinaire/Dossier Client/"+animal.getOwner().name());
    file->setFileName("../Veterinaire/Dossier Client/"+animal->getOwner()->getName()+"/Animal.txt");
    in.setDevice(file);
    if(file->open(QIODevice::Append | QIODevice::Text))
    {
        in<< animal->getName() +"\n";
        file->close();
    }
    else
        QMessageBox::information(this, tr("Echec d'ajout de l'animal"), tr("impossible d'ouvrir le fichier client"));
    if(conf==true)
        QMessageBox::information(this, tr("Confirmation de creation"), tr("Vous avez ajouté un Animal"));
    clear();
    emit animalComplete();
    emit sendAnimal(animal);
}

void AnimalDialog::clear() const
{
    name->clear();
    propri->clear();
    maladie->clear();
    traitement->clear();
}

void AnimalDialog::rejet()
{
    clear();
    QMessageBox::warning(this, tr("Alert"), tr("Vous avez annuler"));
}

Owner *AnimalDialog::getPropri()
{
    QFile *file = new QFile("../Veterinaire/Dossier Client/"+propri->text()+"/"+propri->text()+".txt");
    Owner *proprio= new Owner;
    QStringList list;
    if(file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream out(file);
        while(!out.atEnd())
        {
            list << out.readLine();
        }
        proprio->setName(static_cast<QString>(list.at(0)));
        proprio->setSurname(static_cast<QString>(list.at(1)));
        proprio->setUser(static_cast<QString>(list.at(2)));
        proprio->setAdresse(static_cast<QString>(list.at(3)));
        proprio->setMail(static_cast<QString>(list.at(4)));
        proprio->setPhone(static_cast<QString>(list.at(5)));
        proprio->setMobile(static_cast<QString>(list.at(6)));
        proprio->setGenre(static_cast<QString>(list.at(7)));
    }
//    else
//        QMessageBox::warning(this, tr("Alert"), tr("Vous avez annuler"));
    emit sendOwner(proprio);
    return proprio;
}
QString AnimalDialog::getMaladie() const
{
    return maladie->text();
}
QString AnimalDialog::getTreatment() const
{
    return traitement->text();
}
int AnimalDialog::getRace() const
{
    return race->currentIndex();
}
int AnimalDialog::getStatus () const
{
    return status->currentIndex();
}
