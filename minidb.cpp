#include "minidb.h"

miniDB::miniDB()
{

}

//Метод создания минидб
void miniDB::ccMiniDB()
{
    //Инициализация Базы данных
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("mindb");
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
    a_query.exec(str);

    //Создание таблицы с данными подключения
    QString str1 = "CREATE TABLE connect ("
                    "ID integer PRIMARY KEY NOT NULL, "
                    "`dbName` VARCHAR(255), "
                    "`host` VARCHAR(255), "
                    "`usr` VARCHAR(255), "
                    "`pwd` VARCHAR(255)"
                    ");";
    a_query.exec(str1);
}

//Метод для подключения базы данных
QString miniDB::database(QLineEdit *strdbName, QLineEdit *strhost, QLineEdit *strusr, QLineEdit *strpwd)
{
    QString error = "0";

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
          error = "1";
          return error;
       }
    return 0;
}

//Изменение строки подключения
void miniDB::changeConnect(QString dbName, QString host, QString usr, QString pwd)
{
    //Удаление старых данных
    QSqlQuery a_query;
    a_query.exec("DELETE FROM connect");

    //Вставка новых данных
    QSqlQuery b_query;
    b_query.prepare("INSERT INTO connect (ID, dbName, host, usr,pwd) "
            "VALUES (null, ?, ?, ?, ?)");
    b_query.addBindValue(dbName);
    b_query.addBindValue(host);
    b_query.addBindValue(usr);
    b_query.addBindValue(pwd);
    b_query.exec();
}

//Метод для смены пинкода
void miniDB::chengePin(QString pin)
{
    //Удаление старых данных
    QSqlQuery a_query;
    a_query.exec("DELETE FROM pincod");

    //Вставка новых данных
    QSqlQuery b_query;
    b_query.prepare("INSERT INTO pincod (ID, `Пароль`) "
            "VALUES (null, ?)");
    b_query.addBindValue(pin);
    b_query.exec();
}

//Метод смены авторизационных данных
void miniDB::changeAutorizeDataAdmin(QString login, QString password)
{
    //Удаление старых данных
    QSqlQuery a_query;
    a_query.exec("DELETE FROM autorize");

    //Вставка новых данных
    QSqlQuery b_query;
    b_query.prepare("INSERT INTO autorize (Id, Login, Pass) "
            "VALUES (null, ?, ?)");
    b_query.addBindValue(login);
    b_query.addBindValue(password);
    b_query.exec();
}
