#include<personnel.h>

Personnel::Personnel(QString genre, QString titre, QString nom,QString prenom,QString user,QString mail,QString adresse,QString telephone,QString mobile):

    m_genre{genre},
    m_titre{titre},
    m_nom{nom},
    m_prenom{prenom},
    m_user{user},
    m_mail{mail},
    m_adresse{adresse},
    m_telephone{telephone},
    m_mobile{mobile}
{}
