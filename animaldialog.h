#ifndef ANIMALDIALOG_H
#define ANIMALDIALOG_H

//#include<QWidget>
#include<QLineEdit>
#include<QComboBox>
#include<QPushButton>
#include<QDialog>
#include"owner.h"
#include"veterinaireinterface.h"

class Animal;

class AnimalDialog : public QDialog
{
    Q_OBJECT

public:
    AnimalDialog(VeterinaireInterface *parent);
public:
    Owner *getPropri();
    QString getMaladie() const;
    QString getTreatment() const;
    int getRace() const;
    int getStatus () const;
private:
    QLineEdit *name;
    QLineEdit *propri;
    QLineEdit *maladie;
    QLineEdit *traitement;
    QComboBox *race;
    QComboBox *status;
    Animal *animal;
private:
    void clear() const;
private slots:
    void confirm();
    void rejet();
signals:
    animalComplete();
    sendAnimal(Animal* animal);
    sendOwner(Owner *owner);
};

#endif // ANIMALDIALOG_H
