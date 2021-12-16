#include "minidb.h"

miniDB::miniDB()
{

}

//Метод создания минидб
void miniDB::ccMiniDB()
{
    //Инициализация Базы данных
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("minidb.sqlite");
    //Проверка подключения БД
    if (!dbase.open())
    {
        qDebug() << "Что-то пошло не так!";
    }

    QSqlQuery a_query;

    //Создание таблицы с данными авторизации
    QString str = "CREATE TABLE pincod ("
                    "ID integer PRIMARY KEY NOT NULL, "
                    "`Пароль` VARCHAR(255)"
                    ");";
    bool a = a_query.exec(str);
    if (!a)
    {
        qDebug() << "Видимо таблица уже созданна";
    }

    //Создание таблицы с данными подключения
    QString str1 = "CREATE TABLE connect ("
                    "ID integer PRIMARY KEY NOT NULL, "
                    "`dbName` VARCHAR(255), "
                    "`host` VARCHAR(255), "
                    "`usr` VARCHAR(255), "
                    "`pwd` VARCHAR(255)"
                    ");";
    bool b = a_query.exec(str1);
    if (!b)
    {
        qDebug() << "Видимо таблица уже созданна";
    }
}

//Метод для подключения базы данных
void miniDB::database(QLineEdit *strdbName, QLineEdit *strhost, QLineEdit *strusr, QLineEdit *strpwd)
{
    QString dbName = strdbName->text();
    QString host = strhost->text();
    QString usr = strusr->text();
    QString pwd = strpwd->text();
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(host);//название хоста
        db.setUserName(usr);//имя пользователя
        db.setPassword(pwd);//пароль
        db.setDatabaseName(dbName);//название базы данных
        if (db.open())
           {
               qDebug() << "Успех"; //Оповещение о успехе подключения
           }
           else
           {
               qDebug() << "Что-то пошло не так!"; //Oповещение о неудаче
           }
}
