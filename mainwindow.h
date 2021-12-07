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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

//Создаем методы и объявляем переменные для перетаскивания окна мышкой
//--------------------------------------------
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
private:
    QPoint mLastMousePosition;
    bool mMoving;
//--------------------------------------------

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    Ui::MainWindow *ui;

    //Создаем и подключаем объекты для работы с БД
    QSqlDatabase sdb;
    QSqlQuery *query;
    QSqlTableModel *model;
};
#endif // MAINWINDOW_H
