#include "veterinaireInterface.h"
#include"vetodelegate.h"
#include"animaldialog.h"
#include"owner.h"
#include"animal.h"
#include<iostream>
#include<cassert>
#include"mainwindow.h"
#include<QQuickView>
#include<QQmlEngine>
#include<QSqlError>

//VeterinaireInterface::VeterinaireInterface(QWidget *parent) : QMainWindow(parent)
VeterinaireInterface::VeterinaireInterface(const QString username, const QString pass): QMainWindow(), m_username{username}, m_pass{pass}, db{}
{
    m_textEdit = new QTextEdit;
    QWidget *widget = new QWidget;
//    widget->adjustSize();

 /*   QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    topFiller->setFixedSize(300, 80);
    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);*/
    animaux = new QPushButton(tr("Animals"));
    animaux->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    QQmlEngine engine;
//    QQmlComponent component(&engine, QUrl::fromLocalFile("../qml/Kalendar.qml"));
//    QObject *kalendar = component.create();

//    QQuickView view(engine, Q_NULLPTR);
   // view.setSource(QUrl::fromLocalFile("../Veterinaire/qml/Kalendar.qml"));
//    view.show();
//    QObject *kalendar = view.rootObject();


    animaux->setFont(QFont("Helvetica", 12, 9));

//            ("Times", 9, QFont::Bold));
    animaux->setStatusTip(tr("List of Animals"));
    animaux->setMaximumWidth(150);
    connect(animaux, &QPushButton::clicked, this, &VeterinaireInterface::loadContain);
    kalender= new QPushButton(tr("Calender"));
    kalender->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    kalender->setMaximumWidth(150);
    kalender->setStatusTip(tr("Calendar of appointments"));
    kalender->setFont(QFont("Helvetica", 12, 9));
//    connect(kalender, &QPushButton::clicked, &engine, QQmlEngine::);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(animaux);
    layout->addWidget(kalender);
    gLayout = new QGridLayout();
    gLayout->addLayout(layout, 0, 0);
    gLayout->addWidget(m_textEdit, 0, 2);
    table = new QTableView;
    gLayout->addWidget(table, 0, 1);
//    m_textEdit->setPlainText("");
    widget->setLayout(gLayout);
    setCentralWidget(widget);
    createAction();
    createMenu();
//    createDockWindows();
    createToolBAr();

    createStatusBar();
    setWindowTitle("Veterinaire");
    setMinimumSize(700, 600);
    delegate = new VetoDelegate;
    /*connect(delegate,
            &VetoDelegate::sendData,
            this,
            &VeterinaireInterface::updateText);*/
    selectionModel = new QItemSelectionModel;
    connect(selectionModel, &QItemSelectionModel::currentChanged, this, &VeterinaireInterface::updateText);
    connect(this, &VeterinaireInterface::sendText, this, &VeterinaireInterface::affiche);
//    connect(animal, SIGNAL(clicked(bool)), this, SLOT(loadContain());
}

 void VeterinaireInterface::affiche(QString &s)
 {
     auto it = std::find_if(std::begin(delegate->getListAnimal()), std::end(delegate->getListAnimal()),  [&s](Animal *animal )
     { return animal->getName() == s; } );
     assert( it != std::end(delegate->getListAnimal()) );
     Animal *p = *it;
     assert( p != nullptr );

     m_textEdit->setPlainText("je uis");
     QModelIndex topLeft;
         QModelIndex bottomRight;
         QItemSelection toggleSelection;

     topLeft = selectionModel->model()->index(1, 0, QModelIndex());
         bottomRight = selectionModel->model()->index(2, 0, QModelIndex());
         toggleSelection.select(topLeft, bottomRight);
     selectionModel->select(toggleSelection, QItemSelectionModel::Toggle);
 }

void VeterinaireInterface::createStatusBar()
{
    QString message = tr("Bienvenue chez nous les Veterinaires");
    QStatusBar *status = statusBar();
    status->showMessage(message);
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(173, 235, 241));
    status->setPalette(palette);
    status->setFont(QFont("Times", 9, QFont::Bold));
}

void VeterinaireInterface::updateText(const QModelIndex &current,const QModelIndex & previous)

{
    auto it = std::find_if(std::begin(delegate->getListAnimal()), std::end(delegate->getListAnimal()),  [&current](Animal *animal )
    { return animal->getName() == current.data().toString(); } );

    assert( it != std::end(delegate->getListAnimal()) );
    Animal *p = *it;
    assert( p != nullptr );

    m_textEdit->setPlainText("je suis");
}

void VeterinaireInterface::loadContain()
{
   QStringList list = getAnimalList();
   delegate->setListAnimal(createOriginalAnimal());
   const QFont newFont("Lucida", 10, 1, true);
   QStandardItemModel *model = new QStandardItemModel();
   for(int row = 0; row<list.size(); ++row)
   {
       model->setItem(row, 0, new QStandardItem(static_cast<QString>(list.at(row))));
   }
   model->setHeaderData(0, Qt::Horizontal, QVariant("Liste des Animaux"));
   table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   valueRect = gLayout->cellRect(0, 1);
   table->setColumnWidth(1, valueRect.width()-table->columnWidth(0));
   table->setGridStyle(Qt::SolidLine);
   table->setModel(model);
   table->setFont(newFont);
   table->verticalHeader()->hide();
   table->horizontalHeader()->setStretchLastSection(true);
   selectionModel = table->selectionModel();
   QModelIndex indexElementSelectionne = selectionModel->currentIndex();
   QVariant elementSelectionne = model->data(indexElementSelectionne, Qt::DisplayRole);
   emit(elementSelectionne.toString());

//   setCentralWidget(table);
}
QStringList VeterinaireInterface::getAnimalList()
{
//     QString list;
    QStringList list;
    QFile *file = new QFile("../Veterinaire/Animaux.txt");
    if(file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream out(file);
        while(!out.atEnd())
        {
            list += out.readLine();
        }
    }
    else
        QMessageBox::information(this,tr("Fichier introuvable"), tr("le Fichier n'a pas pu etre ouvert"));
    return list;
}

void VeterinaireInterface::createToolBAr()
{
    tool = new QToolBar(this);
    tool->setAllowedAreas(Qt::TopToolBarArea | Qt::LeftToolBarArea);
    if(tool->allowedAreas()==Qt::LeftToolBarArea)
        tool->setOrientation(Qt::Vertical);
    else
        tool->setOrientation(Qt::Horizontal);
    addToolBar(Qt::TopToolBarArea, tool);
    tool->addAction(newAct);
    tool->addAction(newAppAct);
    tool->addAction(openDirAct);
    QWidget *widget = new QWidget;
    widget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    tool->addWidget(widget);
    tool->addAction(quitter);
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(102, 84, 84));
    tool->setPalette(palette);

}

void VeterinaireInterface::createAction()
{
    const QIcon newActIcon= QIcon::fromTheme("document-new", QIcon("C:/Users/adams/Desktop/FileIcon/chien.ico"));
    const QIcon newAppActIcon= QIcon::fromTheme("document-new", QIcon("C:/Users/adams/Desktop/FileIcon/rdvg.jpg"));
    const QIcon openDirActIcon= QIcon::fromTheme("document-new", QIcon("C:/Users/adams/Desktop/FileIcon/openFile.png"));
    const QIcon quitterIcon = QIcon::fromTheme("document-new", QIcon("C:/Users/adams/Desktop/FileIcon/closeBlue.jpg"));
    newAct = new QAction(newActIcon, tr("&Ajouter"), this);
    newAct->setShortcut(QKeySequence::New);
    newAct->setStatusTip(tr("Ajouter un nouvel Animal"));
    connect(newAct, &QAction::triggered, new AnimalDialog(this), &AnimalDialog::show);
    newAppAct = new QAction(newAppActIcon, tr("&Nouveau"), this);
    newAppAct->setShortcut(QKeySequence::New);
    newAppAct->setStatusTip(tr("Nouveau Rendez vous"));
    connect(newAppAct, &QAction::triggered, this, &VeterinaireInterface::newAppointment);
    openDirAct = new QAction(openDirActIcon, tr("&Ouvrir"), this);
    openDirAct ->setStatusTip(tr("ouvrir le dossier d'un client"));
    openDirAct->setShortcut(QKeySequence::Open);
    connect(openDirAct, &QAction::triggered, this, &VeterinaireInterface::openDir);
    printDirAct = new QAction(tr("&Imprimer"), this);
    printDirAct->setShortcut(QKeySequence::Print);
    printDirAct->setStatusTip(tr("Imprimer le dossier du client"));
    printDirAct->setEnabled(false);
    connect(printDirAct, &QAction::triggered, this, &VeterinaireInterface::printDir);
    helpAct = new QAction("?", this);
    helpAct->setShortcut(QKeySequence::HelpContents);
    helpAct->setStatusTip(tr("Obtenez l'aide au sujet de l'application"));
    helpAct->setEnabled(false);
    connect(helpAct, &QAction::triggered, this, &VeterinaireInterface::help);
    aboutAct = new QAction(tr("A&bout"), this);
//    aboutAct->setShortcut(QKeySequence::New);
    aboutAct->setStatusTip(tr("A propos"));
    connect(aboutAct, &QAction::triggered, this, &VeterinaireInterface::about);
    quitter = new QAction(quitterIcon, tr("Quitter"), this);
    quitter->setShortcut(QKeySequence::Quit);
    connect(quitter, &QAction::triggered, this, &VeterinaireInterface::close);
//    connect(quitter, &QAction::triggered, new MainWindow(), &MainWindow::show);
}

void VeterinaireInterface::createMenu()
{
    animal = menuBar()->addMenu(tr("A&nimal"));
    animal->addAction(newAct);
    calendrier= menuBar()->addMenu(tr("&Calendrier"));
    calendrier->addAction(newAppAct);
    calendrier->addSeparator();
    calendrier->addAction(openDirAct);
    calendrier->addAction(printDirAct);
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAct);
    aboutMenu = menuBar()->addMenu(tr("About"));
    aboutMenu->addAction(aboutAct);

}

void VeterinaireInterface::createDockWindows()
{
//    QWidget *titlebar = new QWidget();
//    QWidget *titlebar2 = new QWidget(0);
    dock = new QDockWidget(m_textEdit);
//    dock -> setTitleBarWidget(titlebar);
    dock->setAllowedAreas(Qt::RightDockWidgetArea | Qt::TopDockWidgetArea);
    QLabel *Animaux = new QLabel("<b/>Animaux", dock);
    Animaux->setAlignment(Qt::AlignCenter);
//    dock->setWidget(Animaux);
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(Qt::blue));
    dock->setStyleSheet("background-color: #B0C4DE;");
    addDockWidget(Qt::RightDockWidgetArea, dock);
//    dock->setFloating(true);
    dock->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    /*dock = new QDockWidget(m_textEdit);
    dock->setTitleBarWidget(titlebar2);
    QLabel *Calendrier = new QLabel(tr("<b/>Calendrier"), this);
    Calendrier->setAlignment(Qt::AlignCenter);
    dock->setWidget(Calendrier);
    dock->setStyleSheet("background-color: #B0C4DE;");
    addDockWidget(Qt::RightDockWidgetArea, dock);
    this->setMouseTracking(true);
//    m_textEdit->setMouseTracking(true);
    connect(dock, SIGNAL(clicked()), this, SLOT(about()));
//    QString j{"je"};
//    m_textEdit->setPlainText(j);*/
}

void VeterinaireInterface::createDockButton()
{
//    animaux = new QButton()
}

/*void VeterinaireInterface::mousePressEvent(QMouseEvent *event)
{
    if(event->x() < 50 && event->y()< this->y()/2)
        m_textEdit->setPlainText(QString::number(this->y()));
}*/
void VeterinaireInterface::newAnimal()
{
//    AnimalDialog animal{};
}

void VeterinaireInterface::newAppointment()
{

}

void VeterinaireInterface::openDir()
{

}

void VeterinaireInterface::printDir()
{

}

void VeterinaireInterface::help()
{

}

void VeterinaireInterface::about()
{

}

void VeterinaireInterface::intialiaze()
{
    /*QDir *animal = new QFile("../Veterinaire/Dossier Animal");
    auto listAnimal = animal->entryList("*.txt");*/
}


void VeterinaireInterface::receptAnimal(Animal *animal)
{
    delegate->getListAnimal().append(animal);
}

void VeterinaireInterface::receptOwner(Owner *owner)
{
    delegate->getListOwner().append(owner);
}


void VeterinaireInterface::initializeApplication()
{
   createOriginalAnimal();
//   createOriginalOwner();
}
QList<Animal*> VeterinaireInterface::createOriginalAnimal()
{

        QStringList listAnimal;
        QFile *file = new QFile("../Veterinaire/Animaux.txt");
        if(file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            try{
            QTextStream out(file);
            while(!out.atEnd())
            {
                listAnimal << out.readLine();
            }
            file->close();
            QList<Animal*> m_animal;

            for(int i = 0; i<listAnimal.size(); ++i)
            {
                file->setFileName("../Veterinaire/Dossier Animal/"+static_cast<QString>(listAnimal.at(i))+".txt");
                if(file->open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    QStringList list;
                    while(!out.atEnd())
                    {
                        list << out.readLine();
                    }
                    for(int i= 0;i<list.size(); i++)
                    {
                        qDebug()<< "l'element est " << i << " est" << QString(list.at(i));
                    }
                    m_animal.append(new Animal(static_cast<QString>(list.at(0)),
                                               getPropri(static_cast<QString>(list.at(1))),
                                               static_cast<QString>(list.at(2)),
                                               static_cast<QString>(list.at(3)),
                                               static_cast<QString>(list.at(4)).toInt()));
                    file->close();
                }
                else
                    throw std::logic_error("un problème dans les listes est survenu");
            }
            return m_animal;
        }
        catch (const std::exception &e)
        {
            QMessageBox::warning(this, tr("Exception"), tr("un problème est survenu dans les fichiers"));
            std::cerr << e.what();
        }
    }
    else
       throw std::logic_error("le fichier spécifié est introuvable");
}

/*QList<Owner*> VeterinaireInterface::createOriginalOwner()
{
    return new QList<Owner*>();
}*/

Owner* VeterinaireInterface::getPropri(QString propri)
{
    QFile *file = new QFile("../Veterinaire/Dossier Client/"+propri+"/"+propri+".txt");
    QStringList list;
    Owner* proprio = new Owner;
    if(file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream out(file);
        while(!out.atEnd())
        {
            list += out.readLine();
        }
        proprio->setName(static_cast<QString>(list.at(0)));
        proprio->setSurname(static_cast<QString>(list.at(1)));
        proprio->setUser(static_cast<QString>(list.at(2)));
        proprio->setAdresse(static_cast<QString>(list.at(3)));
        proprio->setMail(static_cast<QString>(list.at(4)));
        proprio->setPhone(static_cast<QString>(list.at(5)));
        proprio->setMobile(static_cast<QString>(list.at(6)));
        proprio->setGenre(static_cast<QString>(list.at(7)));
        file->close();
    }
    return proprio;
}

QSqlDatabase VeterinaireInterface::connected(const QString& username, const QString& pass)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");//(base->currentText());
    db.setUserName(username);//(m_user->text());
    db.setPassword(pass);//(m_password->text());
    db.setDatabaseName("Driver={MySQL ODBC 5.3 ANSI Driver};server=localhost;database=praxis");
    bool ok = db.open();
    if(!ok)
    {
//        QMessageBox::critical(new QWidget(), "Status", db.lastError().text());
//        this->close();
        return db;
    }
    else
    {
//         QMessageBox::information(new QWidget(), "Status", "Connection Reussie");
         qDebug() << db.driverName();
         return db;
    }

}

const QSqlDatabase& VeterinaireInterface::getDb() const{
    return db;
}
void VeterinaireInterface::setDb(QSqlDatabase m_db){
    db=m_db;
}


/*void VeterinaireInterface::mouseMoveEvent(QMouseEvent *event)
{
    QString label("X: " +QString::number(event->x()) + "Y: " +QString::number(event->y()));
    m_textEdit->setPlainText(label);
}*/

/*QTextEdit* VeterinaireInterface::getLabel()
{
    return m_textEdit;
}*/


