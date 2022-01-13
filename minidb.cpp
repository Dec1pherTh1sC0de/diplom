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

//Добавление данных в группу
void miniDB::addDataGrup(QString Gruppa, QString Kurator, QString NomerCuratora, QString Starosta, QString NomerStarosty)
{
    //Вставка новых данных
    QSqlQuery b_query;
    b_query.prepare("INSERT INTO gruppy (Id, Gruppa, Kurator, NomerCuratora, Starosta, NomerStarosty) "
            "VALUES (null, ?, ?, ?, ?, ?)");
    b_query.addBindValue(Gruppa);
    b_query.addBindValue(Kurator);
    b_query.addBindValue(NomerCuratora);
    b_query.addBindValue(Starosta);
    b_query.addBindValue(NomerStarosty);
    b_query.exec();
}

//Добавление студента
void miniDB::addData(QString Specialnost, QString Formaobuch, QString Obooso, QString Kurs, QString NumberOfGroup, QString Budget, QString AdresObshagi, QString Pol, QString Familia, QString Imya, QString Otchestvo, QString DataRojdenia, QString PassData, QString SredniyBallPosleSchool, QString Inyaz, QString MobilniyTel, QString Oblast, QString Gorod, QString Rayon, QString AdresProjiv, QString SredniyBall, QString Celevik, QString Roditeli, QString MestoRaboty, QString Ligoty, QString Primechanie, QString Otchislen, QString DataZachisleniya, QString DataOtchislenya)
{
    //Вставка новых данных
    QSqlQuery b_query;
    b_query.prepare("INSERT INTO ycheniki (Specialnost, Formaobuch, Obooso, Kurs, NumberOfGroup, Budget, AdresObshagi, Pol, Familia, Imya, Otchestvo, DataRojdenia, PassData, SredniyBallPosleSchool, Inyaz, MobilniyTel, Oblast, Gorod, Rayon, AdresProjiv, SredniyBall, Celevik, Roditeli, MestoRaboty, Ligoty, Primechanie, Otchislen, DataZachisleniya, DataOtchislenya) "
            "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    b_query.addBindValue(Specialnost);
    b_query.addBindValue(Formaobuch);
    b_query.addBindValue(Obooso);
    b_query.addBindValue(Kurs);
    b_query.addBindValue(NumberOfGroup);
    b_query.addBindValue(Budget);
    b_query.addBindValue(AdresObshagi);
    b_query.addBindValue(Pol);
    b_query.addBindValue(Familia);
    b_query.addBindValue(Imya);
    b_query.addBindValue(Otchestvo);
    b_query.addBindValue(DataRojdenia);
    b_query.addBindValue(PassData);
    b_query.addBindValue(SredniyBallPosleSchool);
    b_query.addBindValue(Inyaz);
    b_query.addBindValue(MobilniyTel);
    b_query.addBindValue(Oblast);
    b_query.addBindValue(Gorod);
    b_query.addBindValue(Rayon);
    b_query.addBindValue(AdresProjiv);
    b_query.addBindValue(SredniyBall);
    b_query.addBindValue(Celevik);
    b_query.addBindValue(Roditeli);
    b_query.addBindValue(MestoRaboty);
    b_query.addBindValue(Ligoty);
    b_query.addBindValue(Primechanie);
    b_query.addBindValue(Otchislen);
    b_query.addBindValue(DataZachisleniya);
    b_query.addBindValue(DataOtchislenya);
    b_query.exec();
}

//Подсчет контингента
void miniDB::addKontengent(QString a, QString b, QString d, QString e, QString f, QString g)
{
    //Удаление старых данных
    QSqlQuery a_query;
    a_query.exec("DELETE FROM kontengent");

    //Вставка новых данных
    QSqlQuery b_query;
    b_query.prepare("INSERT INTO kontengent (Id, VsegoGirl, VsegoBoy, Vsego, Platniki, Cheleviki, Budjetniki) "
            "VALUES (null, ?, ?, ?, ?, ?, ?)");
    b_query.addBindValue(a);
    b_query.addBindValue(b);
    b_query.addBindValue(d);
    b_query.addBindValue(e);
    b_query.addBindValue(f);
    b_query.addBindValue(g);
    b_query.exec();
}
