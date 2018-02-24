#include "vetodelegate.h"
#include"animal.h"
#include"owner.h"
#include"algorithm"
#include<cassert>
#include<QtWidgets>

VetoDelegate::VetoDelegate(QList<Animal*> animal, QObject *parent): QStyledItemDelegate(parent)
{
   VetoDelegate::m_animal= animal;
}

VetoDelegate::VetoDelegate(QObject *parent) : QStyledItemDelegate(parent)
{}

QWidget *VetoDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

//    QDialog *splitter = new QDialog(parent);
//    return splitter;
    Q_UNUSED(index);
    Q_UNUSED(option);
    Q_UNUSED(parent);
}
void VetoDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    /*auto it = std::find_if(std::begin(VetoDelegate::m_animal), std::end(VetoDelegate::m_animal),  [&index](Animal *animal )
    { return animal->getName() == index.data().toString(); } );

    assert( it != std::end(VetoDelegate::m_animal) );
    Animal *p = *it;
    assert( p != nullptr );
    QLabel *label = new QLabel(p->getName());
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
//    editor->setLayout(layout);
    emit sendData(p->getName());*/
    Q_UNUSED(index);
    Q_UNUSED(editor);
}
void VetoDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    Q_UNUSED(model);
    Q_UNUSED(index);
    Q_UNUSED(editor);
}
void VetoDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex & index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    editor->setGeometry(60, 40, 300, 150);
}

QList<Animal*> VetoDelegate::getListAnimal()
{
    return VetoDelegate::m_animal;
}
QList<Owner *> VetoDelegate::getListOwner()
{
    return VetoDelegate::m_owner;
}

void VetoDelegate::setListAnimal(QList<Animal*> animal)
{
    VetoDelegate::m_animal=animal;
}

QList<Animal*> VetoDelegate::m_animal;
QList<Owner*> VetoDelegate::m_owner;

















ModelTest::ModelTest(QObject *parent) : QStyledItemDelegate(parent)
{
}

QWidget *ModelTest::createEditor(QWidget *parent, const QStyleOptionViewItem &/*option*/, const QModelIndex &/*index*/) const
{

    QDialog *splitter = new QDialog(parent);
//    QComboBox *combox = new QComboBox(parent);

    return splitter;
//    return combox;

}
void ModelTest::setEditorData(QWidget *editor, const QModelIndex &/*index*/) const
{
    QStringList list;
    QStringList list2;
    list<< "cameroun" << "tchad" << "congo";
    list2 << "ivoire" << "argent" << "pain";
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *parent1 = new QStandardItem("Pays");
    for(int row =0; row<3; ++row)
    {
        parent1->appendRow(new QStandardItem(static_cast<QString>(list.at(row))));
    }
    QStandardItem *parent2 = new QStandardItem("Monnaie");
    for(int row =0; row<3; ++row)
    {
        parent2->appendRow(new QStandardItem(static_cast<QString>(list2.at(row))));
    }
    model->setItem(0, 0, parent1);
    model->setItem(1, 0, parent2);
    QTreeView *tree = new QTreeView();
    QHBoxLayout *hlayout = new QHBoxLayout;
    QVBoxLayout * vlayout = new QVBoxLayout;
    QPushButton *fermer = new QPushButton("Fermer");
    hlayout->addWidget(new QPushButton("Valider"));
    hlayout->addWidget(fermer);
    vlayout->addWidget(tree);
    vlayout->addLayout(hlayout);
    vlayout->addWidget(new QLabel("JACK"));
    editor->setLayout(vlayout);
    tree->setModel(model);
}
void ModelTest::setModelData(QWidget */*editor*/, QAbstractItemModel */*model*/, const QModelIndex &/*index*/) const
{

}
void ModelTest::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex & /*index*/ ) const
{
    Q_UNUSED(option);
    editor->setGeometry(60, 40, 300, 150);
}

