#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "creation.h"
#include"veterinaireinterface.h"
#include<QSqlError>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), m_userClass{UserClass::veterinaire}, m_loop{}
{
    ui->setupUi(this);
    this->setHidden(true);
    this->setWindowModality(Qt::ApplicationModal);
//    QVBoxLayout *layout = new QVBoxLayout;
//    QSpacerItem *spacer = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//    QSpacerItem *spacer2 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//    layout->addItem(spacer);
//    layout -> addWidget(ui->connecter);
//    layout-> addWidget(ui->quitter);
//    RRlayout->addItem(spacer2);
//    ui->layout->setAlignment(ui->connecter, Qt::AlignCenter);
//    ui->layout->setAlignment(ui->quitter, Qt::AlignCenter);
//    connect(ui->creerCompte, SIGNAL(clicked(bool)), this, SLOT(creation()));
//    connect(ui->connecter, SIGNAL(clicked(bool)), this, SLOT(createVetoInterface()));
//    connect(ui->connecter, SIGNAL(clicked(bool)), this, SLOT(close()));
//    connect(ui->connecter, SIGNAL(clicked(bool)), this, SLOT(connected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connecter_clicked()
{
    /*
     * Configuration à faire pour connecter un utilisateur
     */
    setUserClass(UserClass::veterinaire);
    VeterinaireInterface veto(getUser(), getPass());

}
void MainWindow::on_creerCompte_clicked()
{
    Creation compte;
    compte.show();
}
void MainWindow::setUserClass(UserClass userclass)
{
    m_userClass= userclass;
}

UserClass const MainWindow::getUserClass()
{
    return m_userClass;
}

QString MainWindow::getUser()
{
   return ui->utilisateurLineEdit->text();
}
QString MainWindow::getPass()
{
    return ui->motDePasseLineEdit->text();
}

bool MainWindow::shown()
{
   this->show();
   return true;
}
void MainWindow::showModal()
{
    show();
    m_loop.exec();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    m_loop.exit();
}

