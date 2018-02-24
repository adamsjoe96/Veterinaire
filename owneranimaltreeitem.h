#ifndef OWNERANIMALTREEITEM_H
#define OWNERANIMALTREEITEM_H

#include"conteneur.hpp"
/*class OwnerAnimalTreeItem
{
public:
    explicit OwnerAnimalTreeItem(const QList<QVariant> &data, OwnerAnimalTreeItem *parent=0);
    OwnerAnimalTreeItem();
    ~OwnerAnimalTreeItem();
public:
    void appendChild(OwnerAnimalTreeItem *item);
    OwnerAnimalTreeItem *child(int row); // renvoi l'enfant à la ligne donné en loccurence ce sera un animal
    int childCount() const; // renvoi le nombre de fils
    int columnCount() const; // determine le nombre de propriété de l'item
    QVariant data(int column) const;
                                      *les propriétés de l'item sont stockées
                                      *  sous forme de longue liste de variant
                                      *  cette fonction reverra la donnée x
                                      * à la position column
                                      * ceci présume bien sur pour mon cas que
                                      * je sache pertinement bien comment
                                      * l'ordre de l'envoi des données lors de
                                      * la construction de l'item
                                      * plus précisémet du QList<Variant>
                                      *
    int row() const; // retourne à quel position se trouve l'item dans l'arbre
    OwnerAnimalTreeItem *parentItem(); // retourne le parent de l'animal s'il en a un
     bool hasChildren();
private:
    QList<OwnerAnimalTreeItem*> m_childItems; // contient la liste des fils
    QList<QVariant> m_itemData; // contient l'ensemble des propriétés de l'item
    OwnerAnimalTreeItem *m_parentItem; // parent de l'item


};*/

#endif // OWNERANIMALTREEITEM_H
