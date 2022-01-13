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

    //Метод добавления данных по группам
    void addDataGrup(QString Gruppa, QString Kurator, QString NomerCuratora, QString Starosta, QString NomerStarosty);

    //Метод добавления данных о студенте
    void addData(QString Specialnost, QString Formaobuch,QString Obooso,QString Kurs,QString NumberOfGroup,QString Budget,QString AdresObshagi,QString Pol,QString Familia,QString Imya,QString Otchestvo,QString DataRojdenia,QString PassData,QString SredniyBallPosleSchool,QString Inyaz,QString MobilniyTel,QString Oblast,QString Gorod,QString Rayon,QString AdresProjiv,QString SredniyBall,QString Celevik,QString Roditeli,QString MestoRaboty,QString Ligoty,QString Primechanie,QString Otchislen,QString DataZachisleniya,QString DataOtchislenya);

    //Добавление контенгента
    void addKontengent(QString a, QString b, QString d, QString e, QString f, QString g);
};

#endif // MINIDB_H
