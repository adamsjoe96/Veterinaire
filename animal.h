#ifndef ANIMAL_H
#define ANIMAL_H

#include"owner.h"
#include<QWidget>

enum Race{
    chien = 1,
    chat,
    oiseau,
    canard,
    lion,
    ourse,
    autre
};

enum Status_Treatment{
    en_cours =1,
    termine,
    none,
    en_attente
};

class Animal: public Etre
{

public:
    Animal(QString name, Owner *owner, QString disease, QString treatment, int race);
    Animal();
    Animal(QString name): Etre() {m_name= name;}
signals:

public slots:

public:
    QString getName() const Q_DECL_OVERRIDE;
    Owner *getOwner() const;
    QString getDisease() const;
    QString getTreatment() const;
    Race getRace() const;
    Type getType()const Q_DECL_OVERRIDE{return type;}
    Status_Treatment getStatus() const;
    void setName(QString name) Q_DECL_OVERRIDE;
    void setOwner(Owner *owner);
    void setRace(Race race);
    void setRace(QString race);
    void setDisease(QString disease);
    void setTreatment(QString treatment);
    void setStatus(Status_Treatment status);
    QString printRace();
    QString printStatus();
//    bool operator==(Animal const& ob);
    bool hasChildren() Q_DECL_OVERRIDE{return false;}
private:
    QString m_name;
    Owner *m_owner;
    QString m_disease;
    QString m_treatment;
    Race m_race;
    Status_Treatment m_status;
    Type type{Type::Animal};


};


#endif // ANIMAL_H
