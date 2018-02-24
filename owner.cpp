#include "owner.h"
#include<iostream>
#include<stdexcept>

Owner::Owner(Genre genre, QString name, QString surname, QString user, QString adresse, QString mail, QString phone, QString mobile): Etre()
{
     m_name = name;
     m_surname= surname;
     m_user= user;
     m_adresse= adresse;
     m_mail= mail;
     m_genre= genre;
     m_phone= phone;
     m_mobile= mobile;
}

Owner::Owner() : Etre(), m_name{"prop"}, m_surname{"surprop"}, m_user{"user"},m_adresse{"adresse"},m_mail{"mail"},m_genre{Genre::Homme},m_phone{"phone"},m_mobile{"mobile"}
{}

QString Owner::getName() const
{
    return m_name;
}

QList<Animal*> Owner::getListAnimal() const
{
    return m_animals;
}

void Etre::appendChild(Owner *owner)
{
    m_owner.append(owner);
}

QString Owner::surname() const
{
    return m_surname;
}
QString Owner::user() const
{
    return m_user;
}
QString Owner::adresse()const
{
    return m_adresse;
}
QString Owner::mail() const
{
    return m_adresse;
}
QString Owner::phone() const
{
   return m_phone;
}
QString Owner::mobile() const
{
    return m_mobile;
}
Genre Owner::genre() const
{
    return m_genre;
}


void Owner::setName(QString name)
{
    m_name = name;
}
void Owner::setSurname(QString surname)
{
    m_surname=surname;
}

/*void Owner::setUser(QString usr)
{
    try{
    m_user = usr;
    }catch (const std::bad_alloc &)
    {
        std::cerr<< "erreur";
    }
    catch (const std::exception &e)
        {
            std::cerr<< e.what();
        }
}*/

void Owner::setUser(QString usr)
{
    m_user=usr;
}

void Owner::setAdresse(QString adresse)
{
    m_adresse= adresse;
}

void Owner::setMail(QString mail)
{
    m_mail=mail;
}

void Owner::setPhone(QString phone)
{
    m_phone= phone;
}

void Owner::setMobile(QString mobile)
{
    m_mobile= mobile;
}

void Owner::setGenre(QString genre)
{
    if(genre=="Homme")
    m_genre = Genre::Homme;
    else
        m_genre = Genre::Femme;
}
