#ifndef MINIDB_H
#define MINIDB_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

//Библиотека для работы с SQL
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtSql>

//Библиотека с дебагом
#include <QtDebug>

//Библиотека для работы с LineEdit
#include <QLineEdit>

//Библиотека для работы с мессэджбоксами
#include <QMessageBox>

//Библиотека для работы с шифрованием
#include <encryptionclass.h>

class miniDB : QMainWindow
{
public:
    miniDB();

    //Создаем и подключаем объекты для работы с бд
    QSqlDatabase sdb;
    QSqlQuery *query;
    QSqlTableModel *model;

    //Номер активной строки
    int row;

    //Переменная для работы с калассами
    encryptionClass *encryptcls;

    //Метод для подключения и создания miniDB
    void ccMiniDB();

    //Метод для подключение БД
    QString database(QLineEdit *strdbName, QLineEdit *strhost, QLineEdit *strusr, QLineEdit *strpwd);

    //Метод для изменения строки подключения
    void changeConnect(QString dbName, QString host, QString usr, QString pwd);

    //Метод для смены пинкода
    void chengePin(QString pin);

    //Метод смены данных авторизации
    void changeAutorizeDataAdmin(QString login, QString password);
};

#endif // MINIDB_H
