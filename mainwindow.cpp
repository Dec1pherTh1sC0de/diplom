#include "mainwindow.h"
#include "ui_mainwindow.h"

//Библиотеки для работы с БД
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlTableModel>

//Библиотека для вывода мэседж бокса
#include <QMessageBox>

//Библиотека для скругления окна
#include <QPainterPath>

//Библиотека для дебага в консоль
#include<QtDebug>

//Библиотека для перетаскивания окна курсором мыши
#include <QMouseEvent>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Подключение к базе данных
    QString dbName = "student";//название базы данных
    QString host = "127.0.0.1";//название хоста
    QString usr = "root";//имя пользователя
    QString pwd = "password";//пароль
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName(dbName);
       db.setHostName(host);
       db.setUserName(usr);
       db.setPassword(pwd);
       if (!db.open())
       {
           qDebug() << "Успех"; //Оповещение о успехе подключения
       }
       else
       {
           qDebug() << "Что-то пошло не так!"; //Oповещение о неудаче
       }

       //Скругление краев окна
       QPainterPath painPath;
           painPath.addRoundedRect(rect(), 8, 8, Qt::AbsoluteSize);
           this->setMask(painPath.toFillPolygon().toPolygon());

    //Установка цвета окна
    this->setStyleSheet("background-color: #393E46;");

    //Запрет на изменение размеров окна и установка дефолтных размеров
    this->setFixedSize(QSize(800, 600));

    //Скрывает заголовок окна
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;

}


//Методы для перетаскивания окна мышкой
//----------------------------------------------------------------------
void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        this->move(this->pos() + (event->pos() - mLastMousePosition));
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}
//-----------------------------------------------------------------------
