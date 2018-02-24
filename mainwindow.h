#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include<QVBoxLayout>
#include<QSqlDatabase>

class QString;

enum UserClass{
   veterinaire,
    stagiare,
    secretaire,
    client
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:

    Q_ENUM(UserClass)
    void setUserClass(UserClass userclass);
    UserClass const getUserClass();
    QString getUser();
    QString getPass();
    bool shown();
    void showModal();
public slots:
    void on_creerCompte_clicked();
    void on_connecter_clicked();

signals:
private:
    Ui::MainWindow *ui;
     QSqlDatabase db;
     UserClass m_userClass;
     QEventLoop m_loop;

protected:
      void closeEvent(QCloseEvent *event);

};

#endif // MAINWINDOW_H
