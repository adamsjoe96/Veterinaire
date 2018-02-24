#ifndef VETERINAIREINTERFACE_H
#define VETERINAIREINTERFACE_H

#include<QtWidgets>
#include<memory>
#include<QQmlComponent>
#include<QSqlDatabase>

class Animal;
class Owner;
class VetoDelegate;

class VeterinaireInterface : public QMainWindow
{
    Q_OBJECT
public:
    VeterinaireInterface(const QString username, const QString pass);
//    explicit VeterinaireInterface(QWidget *parent = 0);


signals:
    sendText(QString &s);

public:
//    virtual void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event)
    {
        QString label("X: " +QString::number(event->x()) + "Y: " +QString::number(event->y()));
        m_textEdit->setPlainText(label);
    }
     static QSqlDatabase connected(const QString &username, const QString &pass);



signals:
    update(); // signal qui sera déclenché par quelques fonction pour permettre la mise à jour des Listes et tout le reste
public slots:
    void intialiaze(); // se charge d'initialiser le textEdit avec les modéle et view
    void loadContain();
    void receptAnimal(Animal *animal);
    void receptOwner(Owner *owner);
    void affiche(QString &s);

private slots:
    void newAnimal();
    void newAppointment();
    void openDir();
    void printDir();
    void help();
    void about();
    void updateText(const QModelIndex &current, const QModelIndex &previous);

private:
    QMenu *animal;
    QMenu *calendrier;
    QMenu *helpMenu;
    QMenu *aboutMenu;
    QToolBar *tool;
    QAction *newAct;
    QAction *newAppAct;
    QAction *openDirAct;
    QAction *printDirAct;
    QAction *helpAct;
    QAction *aboutAct;
    QAction *quitter;
    QItemSelectionModel *selectionModel;
    VetoDelegate *delegate;
    QRect valueRect;
    QTableView *table;
    QTextEdit *m_textEdit;
    QDockWidget *dock;
    QPushButton *animaux;
    QPushButton *kalender;
    QGridLayout *gLayout;
    const QString m_username;
    const QString m_pass;
    QSqlDatabase db;

private:
    void createAction();
    void createDockWindows();
    void createMenu();
    void createToolBAr();
    void createDockButton();
    void createStatusBar();
//    QQmlComponent component;

public:
    Owner* getPropri(QString propri);
    QStringList getAnimalList();
    const QSqlDatabase& getDb() const;
    void setDb(QSqlDatabase m_db);
    void initializeApplication();
    QList<Animal *> createOriginalAnimal();
//    QList<Owner *> createOriginalOwner();
};

#endif // VETERINAIREINTERFACE_H
