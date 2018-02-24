#ifndef OWNERANIMALTREEMODEL_H
#define OWNERANIMALTREEMODEL_H

/*#include"conteneur.hpp"
#include<QAbstractItemModel>
#include<QWidget>
#include<QModelIndex>
class Etre;
class Owner;
class Animal;

class OwnerAnimalTreeModel : public QAbstractItemModel
{
public:
    OwnerAnimalTreeModel(QObject *parent = 0);
//    ~OwnerAnimalTreeModel(){delete rootItem;} // à cause du fait que j'ai moi meme définit ma classe d'item

public:
    QVariant data(const QModelIndex &index, int role)const Q_DECL_OVERRIDE; // renvoi  la donnée stockée en fonction du role
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &child) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
public:
    void appendRow(Owner *etre);
    void appendRow(Animal *etre);
private:
    Etre* rootItem;
};
*/

#include<QFile>
#include<QWidget>

class TestModel : public QWidget
{
    Q_OBJECT
public:
    Test();
};


















#endif // OWNERANIMALTREEMODEL_H

