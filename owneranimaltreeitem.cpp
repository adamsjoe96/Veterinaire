#include "owneranimaltreeitem.h"
#include<QtWidgets>

/*OwnerAnimalTreeItem::OwnerAnimalTreeItem(const QList<QVariant> &data, OwnerAnimalTreeItem *parent)
{
    m_itemData = data;
    m_parentItem=parent;
}
OwnerAnimalTreeItem::OwnerAnimalTreeItem()
{}

OwnerAnimalTreeItem::~OwnerAnimalTreeItem()
{
    qDeleteAll(m_childItems);
}

void OwnerAnimalTreeItem::appendChild(OwnerAnimalTreeItem *item)
{
    m_childItems.append(item);
}
 bool OwnerAnimalTreeItem::hasChildren()
 {
    return m_childItems.size() != 0;
 }

OwnerAnimalTreeItem *OwnerAnimalTreeItem::child(int row)
{
    if(hasChildren() && row<m_childItems.size())
        return m_childItems.value(row);
    else
        return OwnerAnimalTreeItem();
}
int OwnerAnimalTreeItem::childCount() const
{
    return m_childItems.size();
}

int OwnerAnimalTreeItem::columnCount() const
{
    return m_itemData.count();
}

QVariant OwnerAnimalTreeItem::data(int column) const
{
    return m_itemData.value(column);
}
int OwnerAnimalTreeItem::row() const
{
    if(m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<OwnerAnimalTreeItem*>(this));
    else return 0;
}

OwnerAnimalTreeItem *OwnerAnimalTreeItem::parentItem()
{
  return m_parentItem;
}*/
