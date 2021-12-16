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

//Задание стиля окна
mtdcls->styleWindows(this,341,241);

//Задане стиля PinCodeWidget
mtdcls->stylePincodeWidget(this->ui->PinCodeWidget,this->ui->EnterPinCodePushButton,this->ui->CloseButton,this->ui->PinCodeLineEdit);

//Задане стилей AutorizationWidget
mtdcls->styleAutorizationWidget(this->ui->AutorizationWidget,this->ui->EnterPushButton,this->ui->LoginLineEdit,this->ui->PasswordLineEdit,this->ui->CloseButton_3,this->ui->ConnectWidgetButton);

//Задане стилей ConnectionWidget
mtdcls->styleConnectionWidget(this->ui->ConnectionWidget,this->ui->ConnectBDButton,this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit,this->ui->CloseButton_4,this->ui->GoToAutorizationWidget);

//Скрытие виджетов
this->ui->AutorizationWidget->hide();
this->ui->ConnectionWidget->hide();
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
    this->ui->AutorizationWidget->show();
}

//Проверка пинкода для открытия авторизации
void MainWindow::on_EnterPinCodePushButton_clicked()
{
    //Подключение к мини БД
    mindb->ccMiniDB();

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

//Вход в программу
void MainWindow::on_EnterPushButton_clicked()
{
    //Подключаем БД
    mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);

    //Отображение таблицы
    model = new QSqlTableModel(this,sdb);
    model->setTable("oblast");
    model->select();
    ui->tableView->setModel(model);

    //Задание стиля окна
    mtdcls->styleWindows(this,800,600);

    //Задание стиля таблицы
    mtdcls->styleTableView(this->ui->tableView);

    //Скрытие виджетов входа
    mtdcls->enterWidgetHide(this->ui->PinCodeWidget, this->ui->AutorizationWidget, this->ui->ConnectionWidget);

}

