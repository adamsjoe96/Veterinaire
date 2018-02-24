#include "animal.h"

Animal::Animal(QString name, Owner *owner, QString disease, QString treatment, int race) : Etre()
{
    m_name=name;
    m_owner=owner;
    m_disease=disease;
    m_treatment=treatment;
    m_race=static_cast<Race>(race);
    m_status=en_attente;
}

/*Animal::Animal(QString name, Owner owner, QString disease, QString treatment, QString race) : Etre(), m_name{name}, m_owner{owner}, m_disease{disease}, m_treatment{treatment}, m_status{en_attente}
{

    switch (race) {
    case 1: race= Race::chien; break;
    case 2: race= Race::chat; break;
    case 3: race= Race::oiseau; break;
    case 4: race= Race::canard; break;
    case 5: race= Race::; break;
    case 6: race= Race::; break;
    case 7: race= Race::; break;
    default:
        return "Chien";
    }
}*/

 Animal::Animal(): Etre(), m_name{"moi"}, m_owner{}, m_disease{"Malaria"}, m_treatment{"piqures"}, m_race{Race::chien}, m_status{en_attente}
 {}


QString Animal::getName() const
{
    return m_name;
}
Owner *Animal::getOwner() const
{
    return m_owner;
}
QString Animal::getDisease() const
{
    return m_disease;
}
QString Animal::getTreatment() const
{
    return m_treatment;
}
Race Animal::getRace() const
{
    return m_race;
}
Status_Treatment Animal::getStatus() const
{
    return m_status;
}

void Animal::setDisease(QString disease)
{
    m_disease= disease;
}

void Animal::setTreatment(QString treatment)
{
    m_treatment= treatment;
}

void Animal::setStatus(Status_Treatment status)
{
    m_status = status;
}

QString Animal::printRace()
{
    switch (static_cast<int>(m_race)) {
    case 1: return "Chien";
    case 2: return "Chat";
    case 3: return "Oiseau";
    case 4: return "Canard";
    case 5: return "Lion";
    case 6: return "Ourse";
    case 7: return "Autre";
    default:
        return "Chien";
    }
}

QString Animal::printStatus()
{
    switch (static_cast<int>(m_status)) {
    case 1: return "En Cours";
    case 2: return "Terminé";
    case 3: return "None";
    case 4: return "En Attente";
    default:
        return "None";
    }
}

 /*bool Animal::operator==( Animal const& ob)
 {
     return this->getName()==ob.getName();
 }*/

 void Animal::setName(QString name)
 {
     m_name=name;
 }

 void Animal::setOwner(Owner *owner)
 {
     m_owner=owner;
 }

 void Animal::setRace(Race race)
 {
     m_race=race;
 }

  void Animal::setRace(QString race)
  {
      if(race== "chien")
           m_race=Race::chien;
      else if (race=="chat")
          m_race=Race::chat;
      else if (race=="oiseau")
          m_race=Race::oiseau;
      else if (race=="canard")
         m_race=Race::canard;
      else if (race=="lion")
          m_race=Race::lion;
      else if (race=="ourse")
          m_race=Race::ourse;
      else
          m_race=Race::autre;
  }
