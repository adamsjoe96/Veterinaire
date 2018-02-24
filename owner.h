#ifndef OWNER_H
#define OWNER_H

#include<QString>
#include<QList>
#include<memory>
#include"owner.hpp"
class Animal;


enum class Type{
    Owner=1,
    Animal
};

enum class Genre
{
    Homme =1,
    Femme
};
class Etre{
public:
    Etre(){}
    virtual ~Etre(){qDeleteAll(m_owner);}
public:
    virtual QString getName() const =0;
    virtual void setName(QString name) = 0;
    virtual Type getType()const = 0;
    void appendChild(Owner *owner);
    virtual bool hasChildren() =0;
    QList<Owner*> getListOwner(){return m_owner;}
private:
    QList<Owner*> m_owner;
};

class Owner : public Etre
{
public:

     Owner(Genre genre, QString name, QString surname, QString user, QString adresse, QString mail, QString phone, QString mobile);
//     ~Owner(){qDeleteAll(m_animals);}
     Owner();
public:

     QList<Animal*> getListAnimal() const;
     Type getType()const Q_DECL_OVERRIDE {return type;}
     bool hasChildren() Q_DECL_OVERRIDE{return m_animals.size()==0;}
public:
     QString getName() const Q_DECL_OVERRIDE;
     QString surname() const;
     QString user() const;
     QString adresse()const;
     QString mail() const;
     QString phone() const;
     QString mobile() const;
     Genre genre() const;
public:
     void setName(QString name) Q_DECL_OVERRIDE;
     void setSurname(QString surname);
     void setUser(QString usr);
     void setAdresse(QString adresse);
     void setMail(QString mail);
     void setPhone(QString phone);
     void setMobile(QString mobile );
     void setGenre(QString genre);
private:
     QString m_name;
     QString m_surname;
     QString m_user;
     QString m_adresse;
     QString m_mail;
     Genre m_genre;
     QString m_phone;
     QString m_mobile;
     Type type{Type::Owner};
    QList<Animal*> m_animals; // contient la liste des animaux du proprio
};

#endif // OWNER_H
