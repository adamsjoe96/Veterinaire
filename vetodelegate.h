#ifndef VETODELEGATE_H
#define VETODELEGATE_H

#include <QStyledItemDelegate>
#include<QWidget>
class Owner;
class Animal;
class VetoDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    VetoDelegate(QList<Animal*> animal, QObject *parent = 0);
    VetoDelegate(QObject *parent = 0);

public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex & index ) const Q_DECL_OVERRIDE;
    QList<Animal *> getListAnimal();
    static QList<Owner*> getListOwner();
    void setListAnimal(QList<Animal*> animal);
private:
    static QList<Animal*> m_animal;
    static QList<Owner*> m_owner;
signals:
    void sendData(QString s)const ;
};


class ModelTest : public QStyledItemDelegate

{
    Q_OBJECT
public:
    ModelTest(QObject *parent = 0);

public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex & index ) const override;
//    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

};

#endif // VETODELEGATE_H
