#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlError>
#include "src/database.h"
#include "src/managerpage.h"
#include "src/designerpage.h"
#include "src/approverpage.h"

QT_BEGIN_NAMESPACE
namespace Ui {                         //ui指针
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    database myDatabase;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void try_login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    managerpage* managerWindow = nullptr;
    designerpage* designerWindow = nullptr;
    approverpage* approverWindow = nullptr;

};
#endif // MAINWINDOW_H
