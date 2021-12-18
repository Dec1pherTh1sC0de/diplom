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
    //Подключение к мини БД
    mindb->ccMiniDB();

    //Присваивание значений полей переменным
    QString a = this->ui->BDNameEdit->text();
    QString b = this->ui->HostEdit->text();
    QString c = this->ui->UserNameEdit->text();
    QString d = this->ui->PasswEdit->text();

    //Шифрование значений переменных
    QString a1 = encryptcls->stringEncrypt(a,keyPAS);
    QString b1 = encryptcls->stringEncrypt(b, keyPAS);
    QString c1 = encryptcls->stringEncrypt(c, keyPAS);
    QString d1 = encryptcls->stringEncrypt(d, keyPAS);

    //Смена данных подключения в миниБД
    mindb->changeConnect(a1,b1,c1,d1);

    //Скрытие виджета подключения
    mtdcls->hideConnectWidget(this->ui->ConnectionWidget,this->ui->AutorizationWidget);
}

//Проверка пинкода для открытия авторизации
void MainWindow::on_EnterPinCodePushButton_clicked()
{
    /*
    //Подключение к мини БД
    mindb->ccMiniDB();
    QString pin = this->ui->PinCodeLineEdit->text();
    QString a = encryptcls->stringEncrypt(pin, keyPAS);
    qDebug() << a;
    mindb->chengePin(a);
    */

    //Скрытие виджета пинкода
    mtdcls->hidePincodeWidget(this->ui->PinCodeWidget,this->ui->AutorizationWidget);
}

//Открытие виджета подключения
void MainWindow::on_ConnectWidgetButton_clicked()
{
    mtdcls->showConnectWidget(this->ui->ConnectionWidget, this->ui->AutorizationWidget);
}

//Переход назад на виджет авторизации
void MainWindow::on_GoToAutorizationWidget_clicked()
{
    mtdcls->goToAutWidget(this->ui->ConnectionWidget,this->ui->AutorizationWidget);
}

//Закрытие окна пинкода
void MainWindow::on_CloseButton_clicked()
{
    mtdcls->closeEvent(this);
}

//Закрытие окна авторизации
void MainWindow::on_CloseButton_3_clicked()
{
    mtdcls->closeEvent(this);
}

//Закрытие окна подключения
void MainWindow::on_CloseButton_4_clicked()
{
    mtdcls->closeEvent(this);
}

//Вход в программу
void MainWindow::on_EnterPushButton_clicked()
{
    //Подключаем БД
    QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);
    if(a == "1")
    {
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
    else
    {
        //Вывод окна с сообщением об ошибке
        mtdcls->connectError(this);
    }
}

