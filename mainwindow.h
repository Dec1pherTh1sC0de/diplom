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

#include <QMouseEvent>

//Класс с функционалом
#include <metodclass.h>

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

    //Переменная для работы с калассом metodClass
    metodClass *mtdcls;

    //Создаем и подключаем объекты для работы с БД
    QSqlDatabase sdb;
    QSqlQuery *query;
    QSqlTableModel *model;

private slots:

    void on_ConnectBDButton_clicked();
    void on_EnterPinCodePushButton_clicked();
    void on_ConnectWidgetButton_clicked();
    void on_GoToAutorizationWidget_clicked();
    void on_CloseButton_clicked();
    void on_CloseButton_3_clicked();
    void on_CloseButton_4_clicked();
};
#endif // MAINWINDOW_H
