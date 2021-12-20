#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Библиотеки для работы с БД
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlTableModel>

//Библиотека для работы с мышью
#include <QMouseEvent>

//Библиотека для дебага в консоль
#include<QtDebug>

//Классы с функционалом
#include <metodclass.h>
#include <encryptionclass.h>
#include <minidb.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

//Объявляем методы и переменные для перетаскивания окна мышкой
//--------------------------------------------
public:
     void mouseMoveEvent(QMouseEvent* event);
     void mousePressEvent(QMouseEvent* event);
     void mouseReleaseEvent(QMouseEvent* event);
public:
     QPoint mLastMousePosition;
     bool mMoving;
//--------------------------------------------

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    Ui::MainWindow *ui;

    //Переменная для работы с калассами
    metodClass *mtdcls;
    encryptionClass *encryptcls;
    miniDB *mindb;

    //Ключ
    QString keyPAS = "DzSkKhqMu6djTksHWWne4GWQJiEz5oZzRJdgSbkozXacwCrWDk";

    //Ширина формы
    qint32 shirina = 0;

    //Переменные запоминающие размеры окна
    qint32 oldHeigt = 0;
    qint32 oldWeigt = 0;

    //Переменная запоминающая развернуто окно на максимум или нет
    qint32 ifmax = 0;

    //Создаем и подключаем объекты для работы с БД
    QSqlDatabase sdb;
    QSqlQuery *query;
    QSqlTableModel *model;

    //Выбор модели таблицы пинкод
    void modelPin();

    //Выбор модели таблицы подключения
    void modelConnection();

    //Выбор модели таблицы авторизации
    void modelAutorize();

private slots:

    void on_ConnectBDButton_clicked();
    void on_EnterPinCodePushButton_clicked();
    void on_ConnectWidgetButton_clicked();
    void on_GoToAutorizationWidget_clicked();
    void on_CloseButton_clicked();
    void on_CloseButton_3_clicked();
    void on_CloseButton_4_clicked();
    void on_EnterPushButton_clicked();
    void on_ConnectBDButton_2_clicked();
    void on_RefreshConnection_clicked();
    void on_ShowPinButton_pressed();
    void on_ShowPinButton_released();
    void on_ShowPassButton_pressed();
    void on_ShowPassButton_released();
    void on_CloseButton_5_clicked();
    void on_SvernutButton_clicked();
    void on_RazvernutButton_clicked();
};
#endif // MAINWINDOW_H
