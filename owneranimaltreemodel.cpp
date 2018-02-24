/*#include "owneranimaltreemodel.h"
#include"owner.h"
#include"animal.h"

OwnerAnimalTreeModel::OwnerAnimalTreeModel(QObject *parent): QAbstractItemModel(parent)
{}

QVariant OwnerAnimalTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
            return QVariant();
        Etre *element;
        if (role != Qt::DisplayRole)
            return QVariant();
        else
           {
                element = static_cast<Etre*> (index.internalPointer());
                return QVariant(element->getName());
           }
}

Qt::ItemFlags OwnerAnimalTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

int OwnerAnimalTreeModel::rowCount(const QModelIndex &parent) const
{
    if(static_cast<Etre*>(parent.internalPointer())->getType() == Type::Animal)
        return 0;
    else if (parent.isValid())
    {
        Owner *element= static_cast<Owner*>(parent.internalPointer());
        return element->getListAnimal().size();
    }
    else
        return 0;
}

QModelIndex OwnerAnimalTreeModel::index(int row, int column, const QModelIndex &parent)
            const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    if (!parent.isValid())
        return QModelIndex();
    else if(static_cast<Etre*>(parent.internalPointer())->getType() == Type::Owner)
         {
            Owner *element= static_cast<Owner*>(parent.internalPointer());
            return createIndex(row, column, element);
         }
    else
    {
        Owner *element= static_cast<Owner*>(parent.internalPointer());
         Animal *childItem = element->getListAnimal().at(row);
        if (childItem)
            return createIndex(row, column, childItem);
        else
            return QModelIndex();
    }
}

void OwnerAnimalTreeModel::appendRow(Owner *etre)
{
    rootItem->appendChild(etre);
}

void OwnerAnimalTreeModel::appendRow(Animal *etre)
{
    Owner ptr = etre->getOwner();
    auto i = rootItem->getListOwner();
    int j = i.indexOf(&ptr);
    if( j != -1)
         etre->getOwner().getListAnimal().append(etre);
    else
    {
        Owner owner = etre->getOwner();
       appendRow(&owner);
       owner.getListAnimal().append(etre);
    }
}

QModelIndex OwnerAnimalTreeModel::parent(const QModelIndex &child) const
{
    if (!child.isValid())
            return QModelIndex();
    if(static_cast<Etre*> (child.internalPointer())->getType()==Type::Animal)
    {
         Animal *etre = static_cast<Animal*> (child.internalPointer());
         Owner ptr = etre->getOwner();

        return createIndex(etre->getOwner().getListAnimal().indexOf(etre), 0, &ptr);
    }
    else
    {
        return QModelIndex();
    }
}

int OwnerAnimalTreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}
*/
