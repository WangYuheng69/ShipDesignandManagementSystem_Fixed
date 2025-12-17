#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    database::getConnnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString userIuputtype;
    if(ui->radioButtonone->isChecked())
    {
        userIuputtype = "Designer";               //设计师
    }
    else
    {
        if(ui->radioButtontwo->isChecked())
        {
            userIuputtype = "Project Manager";   //项目经理
        }
        else
        {
            userIuputtype = "Approver";          //审批员
        }
    }
    QString userInputNumber = ui->InputNumber->text();
    QString userInputPassword = ui->InputPassword->text();
    //解决编码不一致
    //qDebug()<<"用户输入的ID:"+userInputNumber;
    //qDebug()<<"输入的密码:"+userInputPassword;
    qDebug() << "[login] id:" << userInputNumber;
    qDebug() << "[login] password:" << userInputPassword;
    qDebug()<<"用户身份:"+userIuputtype;


    if(ui->radioButtontwo->isChecked())
    {
        QSqlQuery sql;
        sql.prepare("select * from manager where managerid = :userInputNumber");
        sql.bindValue(":userInputNumber",userInputNumber);
        sql.exec();
        QString userNumber;
        QString userPassword;//还有其他的列！！
        while(sql.next())
        {
            userNumber = sql.value("managerid").toString();//mysql数据库的字段名不要有大写字母
            userPassword = sql.value("password").toString();
        }
        qDebug()<<"数据库找到的ID:"+userNumber;
        qDebug()<<"数据库找到的密码:"+userPassword;
        sql.clear();
        if(userInputNumber == userNumber&&userInputPassword == userPassword)
        {
            qDebug()<<"登录成功！！";
            //跳转界面
            this->~MainWindow();
            //this->close();
            managerpage * w = new managerpage();
            w->show();
            qDebug()<<"进入项目经理管理界面";
        }
        else
        {
            //qDebug()<<"输入的ID或密码错误！！";
        }
    }
    else if(ui->radioButtonone->isChecked())
    {
        QSqlQuery sql;
        sql.prepare("select * from designer where designerid = :userInputNumber");
        sql.bindValue(":userInputNumber",userInputNumber);
        sql.exec();
        QString userNumber;
        QString userPassword;
        while(sql.next())
        {
            userNumber = sql.value("designerid").toString();
            userPassword = sql.value("password").toString();
        }
        qDebug()<<"数据库找到的ID:"+userNumber;
        qDebug()<<"数据库找到的密码:"+userPassword;
        sql.clear();
        if(userInputPassword == userPassword && userInputNumber == userNumber)
        {
            qDebug()<<"登录成功！！";
            this->~MainWindow();
            //this->close();
            designerpage * w = new designerpage();
            w->show();
            qDebug()<<"进入项目经理管理界面";
        }
        else
        {
            //qDebug()<<"输入的ID或密码错误！！";
        }
    }
    else if(ui->radioButtonthreee->isChecked())
    {
        QSqlQuery sql;
        sql.prepare("select * from approver where approverid = :userInputNumber");
        sql.bindValue(":userInputNumber",userInputNumber);
        sql.exec();
        QString userNumber;
        QString userPassword;
        while(sql.next())
        {
            userNumber = sql.value("approverid").toString();
            userPassword = sql.value("password").toString();
        }
        qDebug()<<"数据库找到的ID:"+userNumber;
        qDebug()<<"数据库找到的密码:"+userPassword;
        sql.clear();
        if(userInputPassword == userPassword && userInputNumber == userNumber)
        {
            qDebug()<<"登录成功！！";
            this->~MainWindow();
            //this->close();
            approverpage * w = new approverpage();
            w->show();
            qDebug()<<"进入项目经理管理界面";
        }
        else
        {
            //qDebug()<<"输入的ID或密码错误！！";
        }
    }

}


//void MainWindow::on_pushButton_clicked()
//{
//    // role select
//    QString userIuputtype;
//    if (ui->radioButtonone->isChecked()) {
//        userIuputtype = "Designer";
//    } else if (ui->radioButtontwo->isChecked()) {
//        userIuputtype = "Project Manager";
//    } else if (ui->radioButtonthreee->isChecked()) {
//        userIuputtype = "Approver";
//    } else {
//        qDebug() << "[login] no role selected, abort.";
//        return;
//    }

//    // id + password
//    const QString userInputNumber = ui->InputNumber->text().trimmed();
//    const QString userInputPassword = ui->InputPassword->text().trimmed();

//    qDebug() << "[login] id:" << userInputNumber
//             << " password:" << userInputPassword
//             << " role:" << userIuputtype;

//    if (userInputNumber.isEmpty() || userInputPassword.isEmpty()) {
//        qDebug() << "[login] empty id or password, abort.";
//        return;
//    }

//    if (ui->radioButtontwo->isChecked()) {
//        // manager
//        QSqlQuery sql;
//        sql.prepare("select managerid, password from manager where managerid = :userInputNumber");
//        sql.bindValue(":userInputNumber", userInputNumber);
//        const bool ok = sql.exec();
//        if (!ok) {
//            qDebug() << "[db] query failed:" << sql.lastError().text();
//            return;
//        }

//        QString userNumber;
//        QString userPassword;
//        if (sql.next()) {
//            userNumber = sql.value("managerid").toString().trimmed();
//            userPassword = sql.value("password").toString().trimmed();
//        }
//        qDebug() << "[db] manager id:" << userNumber << " pwd:" << userPassword;

//        if (!userNumber.isEmpty() && userInputNumber == userNumber && userInputPassword == userPassword) {
//            qDebug() << "[login] manager success.";
//            if (!managerWindow) managerWindow = new managerpage();
//            managerWindow->setAttribute(Qt::WA_DeleteOnClose);
//            managerWindow->show();
//            this->hide();
//            qDebug() << "[nav] show manager window.";
//        } else {
//            qDebug() << "[login] manager account/password mismatch or not found.";
//        }
//    } else if (ui->radioButtonone->isChecked()) {
//        // designer
//        QSqlQuery sql;
//        sql.prepare("select designerid, password from designer where designerid = :userInputNumber");
//        sql.bindValue(":userInputNumber", userInputNumber);
//        const bool ok = sql.exec();
//        if (!ok) {
//            qDebug() << "[db] query failed:" << sql.lastError().text();
//            return;
//        }

//        QString userNumber;
//        QString userPassword;
//        if (sql.next()) {
//            userNumber = sql.value("designerid").toString().trimmed();
//            userPassword = sql.value("password").toString().trimmed();
//        }
//        qDebug() << "[db] designer id:" << userNumber << " pwd:" << userPassword;

//        if (!userNumber.isEmpty() && userInputNumber == userNumber && userInputPassword == userPassword) {
//            qDebug() << "[login] designer success.";
//            if (!designerWindow) designerWindow = new designerpage();
//            designerWindow->setAttribute(Qt::WA_DeleteOnClose);
//            designerWindow->show();
//            this->hide();
//            qDebug() << "[nav] show designer window.";
//        } else {
//            qDebug() << "[login] designer account/password mismatch or not found.";
//        }
//    } else if (ui->radioButtonthreee->isChecked()) {
//        // approver
//        QSqlQuery sql;
//        sql.prepare("select approverid, password from approver where approverid = :userInputNumber");
//        sql.bindValue(":userInputNumber", userInputNumber);
//        const bool ok = sql.exec();
//        if (!ok) {
//            qDebug() << "[db] query failed:" << sql.lastError().text();
//            return;
//        }

//        QString userNumber;
//        QString userPassword;
//        if (sql.next()) {
//            userNumber = sql.value("approverid").toString().trimmed();
//            userPassword = sql.value("password").toString().trimmed();
//        }
//        qDebug() << "[db] approver id:" << userNumber << " pwd:" << userPassword;

//        if (!userNumber.isEmpty() && userInputNumber == userNumber && userInputPassword == userPassword) {
//            qDebug() << "[login] approver success.";
//            if (!approverWindow) approverWindow = new approverpage();
//            approverWindow->setAttribute(Qt::WA_DeleteOnClose);
//            approverWindow->show();
//            this->hide();
//            qDebug() << "[nav] show approver window.";
//        } else {
//            qDebug() << "[login] approver account/password mismatch or not found.";
//        }
//    }
//}

