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

class miniDB
{
public:
    miniDB();

    //Создаем и подключаем объекты для работы с бд
    QSqlDatabase sdb;
    QSqlQuery *query;
    QSqlTableModel *model;

    //Метод для подключения и создания miniDB
    void ccMiniDB();

    //Метод для подключение БД
    void database(QLineEdit *strdbName, QLineEdit *strhost, QLineEdit *strusr, QLineEdit *strpwd);
};

#endif // MINIDB_H
