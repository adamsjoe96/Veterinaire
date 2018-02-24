#include <QApplication>
#include "mainwindow.h"
#include"creation.h"
#include "veterinaireinterface.h"
#include"owneranimaltreemodel.h"


int main (int argc, char* argv[])
{
    QApplication app(argc, argv);
//    VeterinaireInterface fenetre;
    QApplication::setStyle(QStyleFactory::create("fusion"));
//    fenetre.show();
    VeterinaireInterface::connected("frankenstein", "frankenstein");
    MainWindow fenetre;
//    fenetre.hide();
//    fenetre.setWindowModality(Qt::ApplicationModal);
    fenetre.showModal();
    switch (fenetre.getUserClass()) {
    case veterinaire:
        VeterinaireInterface veto(fenetre.getUser(), fenetre.getPass());
//        VeterinaireInterface veto("frankenstein", "frankenstein");
        auto db = VeterinaireInterface::connected(fenetre.getUser(), fenetre.getPass());
        veto.setDb(db);
        veto.show();
//        this->close();
        break;
    }
     qApp->setStyleSheet("QLineEdit { background-color: #EFF5FB }");

    /*QWidget *widget = new QWidget;
//    OwnerAnimalTreeModel *model = new OwnerAnimalTreeModel;
    OwnerAnimalTreeModel model(widget); //= new OwnerAnimalTreeModel;
//    Animal A;
//    Animal *animal;
//    animal =&A;
//    model.appendRow(animal);
    QTreeView *view = new QTreeView(widget);
    view->setModel(&model);
    view->setWindowTitle(QObject::tr("Simple Tree Model"));
//    view.show();
    widget->show();*/

    return app.exec();
}
