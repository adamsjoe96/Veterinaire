#ifndef PERSONNEL_H
#define PERSONNEL_H

#include<QtWidgets>
#include"personnel.hpp"

class Personnel
{
public:
    Personnel() {}
    Personnel(QString genre, QString titre, QString nom,QString prenom,QString user,QString mail,QString adresse,QString telephone,QString mobile);

protected:
    QString m_genre;
    QString m_titre;
    QString m_nom;
    QString m_prenom;
    QString m_user;
    QString m_mail;
    QString m_adresse;
    QString m_telephone;
    QString m_mobile;
};




#endif // PERSONNEL_H
