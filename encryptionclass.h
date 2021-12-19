#ifndef ENCRYPTIONCLASS_H
#define ENCRYPTIONCLASS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

//Библиотеки для работы с шифрованием
#include <QLineEdit>

//Библиотека для работы с SQL
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtSql>

class encryptionClass
{
public:
    encryptionClass();

    //Создаем и подключаем объекты для работы с бд
    QSqlDatabase sdb;
    QSqlQuery *query;
    QSqlTableModel *model;

    //Кодирование строки
    QString stringEncrypt(QString strInput, QString strPassword);

    // Декодирование строки
    QString stringDecrypt(QString strInput, QString strPassword);

    //Метод проверки пинкода
    QString checkPin(QString pin, QString key, QString data);

};

#endif // ENCRYPTIONCLASS_H
