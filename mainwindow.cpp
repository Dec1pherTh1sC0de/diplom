#include "mainwindow.h"
#include "ui_mainwindow.h"

//Библиотеки для работы с БД
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlTableModel>

//Библиотека для дебага в консоль
#include<QtDebug>

#include <QtCore>

#include <QMainWindow>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//--------Подключение к базе на сервере------------------------------------
    //Подключение к базе данных
    QString dbName = "student";//название базы данных
    QString host = "127.0.0.1:3306";//название хоста
    QString usr = "root";//имя пользователя
    QString pwd = "password";//пароль
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setUserName(usr);
    db.setPassword(pwd);
    if (!db.open())
       {
           qDebug() << "Что-то пошло не так!"; //Oповещение о неудаче
       }
       else
       {
           qDebug() << "Успех"; //Оповещение о успехе подключения
       }
//------------------------------------------------------------------------

//-----------Задание первоначальных параметров окна------------------------
    //Изменение размеров окна
    resize(341,241);

    //Скругление краев окна
    mtdcls->skryglenie(this);

    //Установка цвета окна
    this->setStyleSheet("background-color: #393E46;");

    //Запрет на изменение размеров окна и установка дефолтных размеров
    this->setFixedSize(QSize(341, 241));

    //Скрывает заголовок окна
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    //Размещение окна по центру при запуске
    mtdcls->centerScreen(this);

//---------------------------------------------------------------------------

//----------Задане стилей PinCodeWidget-------------------------------------
    this->ui->PinCodeWidget->setGeometry(0,0,341,241);

    //Изменения стиля кнопки входа
    mtdcls->styleButton(this->ui->EnterPinCodePushButton);

    //Изменение стилей LineEdit
    mtdcls->styleLineEdit(this->ui->PinCodeLineEdit);

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    mtdcls->styleTransparentButton(this->ui->CloseButton, "icon/window-close-2.ico");
//--------------------------------------------------------------------------

//----------Задане стилей AutorizationWidget-------------------------------------
     this->ui->AutorizationWidget->setGeometry(0,0,341,241);

     //Изменения стиля кнопки входа
     mtdcls->styleButton(this->ui->EnterPushButton);

     //Изменение стилей LineEdit
     mtdcls->styleLineEdit(this->ui->LoginLineEdit);
     mtdcls->styleLineEdit(this->ui->PasswordLineEdit);

     //Скрытие виджеа автороизации
     this->ui->AutorizationWidget->hide();
     //Применение стиля кнопки закратия, а так же передача пути картинки в метод
     mtdcls->styleTransparentButton(this->ui->CloseButton_3, "icon/window-close-2.ico");
     mtdcls->styleTransparentButton(this->ui->ConnectWidgetButton, "icon/db.ico");
//--------------------------------------------------------------------------

//----------Задане стилей ConnectionWidget-------------------------------------
     this->ui->ConnectionWidget->setGeometry(0,0,341,241);

     //Изменения стиля кнопки входа
     mtdcls->styleButton(this->ui->ConnectBDButton);

     //Изменение стилей LineEdit
     mtdcls->styleLineEdit(this->ui->BDNameEdit);
     mtdcls->styleLineEdit(this->ui->HostEdit);
     mtdcls->styleLineEdit(this->ui->UserNameEdit);
     mtdcls->styleLineEdit(this->ui->PasswEdit);

     //Скрытие виджеа подключения
     this->ui->ConnectionWidget->hide();
     //Применение стиля кнопки закратия, а так же передача пути картинки в метод
     mtdcls->styleTransparentButton(this->ui->CloseButton_4, "icon/window-close-2.ico");
     mtdcls->styleTransparentButton(this->ui->GoToAutorizationWidget, "icon/arrow-left.ico");
//--------------------------------------------------------------------------
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
void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        const QPointF delta = event->globalPos() - mLastMousePosition;
        move(delta.toPoint());
        event->accept();
    }
}
//-----------------------------------------------------------------------

//Проверка подключения к БД
void MainWindow::on_ConnectBDButton_clicked()
{
    //Скрытие виджета подключения
    this->ui->ConnectionWidget->hide();
}

//Проверка пинкода для открытия авторизации
void MainWindow::on_EnterPinCodePushButton_clicked()
{
    this->ui->PinCodeWidget->hide();
    this->ui->AutorizationWidget->show();
}

//Открытие виджета подключения
void MainWindow::on_ConnectWidgetButton_clicked()
{
    this->ui->ConnectionWidget->show();
    this->ui->AutorizationWidget->hide();
}

//Переход назад на виджет авторизации
void MainWindow::on_GoToAutorizationWidget_clicked()
{
    this->ui->ConnectionWidget->hide();
    this->ui->AutorizationWidget->show();
}

//Закрытие окна пинкода
void MainWindow::on_CloseButton_clicked()
{
    //Вызов метода закрытия окна
    mtdcls->closeEvent(this);
}

//Закрытие окна авторизации
void MainWindow::on_CloseButton_3_clicked()
{
    //Вызов метода закрытия окна
    mtdcls->closeEvent(this);
}

//Закрытие окна подключения
void MainWindow::on_CloseButton_4_clicked()
{
    //Вызов метода закрытия окна
    mtdcls->closeEvent(this);
}

