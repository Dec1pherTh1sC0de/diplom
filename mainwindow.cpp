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

//Библиотеки для размещения окна по центру при запуске
#include <QDesktopWidget>
#include <QRect>
#include <QPoint>

//Библиотека для работы с кнопками
#include <QPushButton>

//Библиотека для работы с LineEdit
#include <QLineEdit>

//Библиотека для работы с мессэджбоксами
#include <QMessageBox>

//Библиотека для обработки закрытия окна
#include <QCloseEvent>

#include <QtCore>

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
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 10, 10, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

    //Установка цвета окна
    this->setStyleSheet("background-color: #393E46;");

    //Запрет на изменение размеров окна и установка дефолтных размеров
    this->setFixedSize(QSize(341, 241));

    //Скрывает заголовок окна
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    //Размещение окна по центру при запуске
    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    QPoint center = desktopRect.center();
    move(center.x()-width()*0.5, center.y()-height()*0.5);
//---------------------------------------------------------------------------

//----------Задане стилей PinCodeWidget-------------------------------------
    this->ui->PinCodeWidget->setGeometry(0,0,341,241);

    //Изменения стиля кнопки входа
    styleButton(this->ui->EnterPinCodePushButton);

    //Изменение стилей LineEdit
    styleLineEdit(this->ui->PinCodeLineEdit);

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    styleTransparentButton(this->ui->ClosePinButton, "icon/window-close-2.ico");
//--------------------------------------------------------------------------

//----------Задане стилей AutorizationWidget-------------------------------------
     this->ui->AutorizationWidget->setGeometry(0,0,341,241);

     //Изменения стиля кнопки входа
     styleButton(this->ui->EnterPushButton);

     //Изменение стилей LineEdit
     styleLineEdit(this->ui->LoginLineEdit);
     styleLineEdit(this->ui->PasswordLineEdit);

     //Скрытие виджеа автороизации
     this->ui->AutorizationWidget->hide();
//--------------------------------------------------------------------------

//----------Задане стилей ConnectionWidget-------------------------------------
     this->ui->ConnectionWidget->setGeometry(0,0,341,241);

     //Изменения стиля кнопки входа
     styleButton(this->ui->ConnectBDButton);

     //Изменение стилей LineEdit
     styleLineEdit(this->ui->BDNameEdit);
     styleLineEdit(this->ui->HostEdit);
     styleLineEdit(this->ui->UserNameEdit);
     styleLineEdit(this->ui->PasswEdit);

     //Скрытие виджеа подключения
     this->ui->ConnectionWidget->hide();
//--------------------------------------------------------------------------
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Метод для задания стиля lineEdit
void MainWindow::styleLineEdit(QLineEdit *lineEdit)
{
    lineEdit->setStyleSheet("background-color: #EEEEEE; border-style: outset; border-width: 0px; border-radius: 5px; border-color: beige; font: 12px; min-width: 10em;");
}

//Метод для задания прозрачной кнопки с картинкой
void MainWindow::styleTransparentButton(QPushButton *button, const QString &str)
{
    //Установка вида курсора
    button->setCursor(QCursor(Qt::PointingHandCursor));

    button->setStyleSheet
            (
                "QPushButton{border : 0; background: transparent;}"
                "QPushButton:hover{border : 0; background: transparent;}"
                "QPushButton:pressed{background: transparent; border : 0;}"
                "QPushButton:released{background: transparent; border : 0;}"
            );
    //Установка картинки в кнопку
    QPixmap pixmap = str;
    QIcon ButtonIcon(pixmap);
    button->setIcon(ButtonIcon);
    button->setIconSize(pixmap.rect().size());
    button->resize(48,48);
    button->setText(NULL);
}

//Метод для задания стилей кнопки
void MainWindow::styleButton(QPushButton *button)
{
    button->setStyleSheet
            (
                "QPushButton{background-color: #00CED7; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px; min-width: 10em;}"
                "QPushButton:hover{background: #6BF4FF; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px; min-width: 10em;}"
                "QPushButton:pressed{background-color: #00ADB5; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px; min-width: 10em;}"
                "QPushButton:released{background-color: #00CED7; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px; min-width: 10em;}"
            );
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
        const QPointF delta = event->globalPos() - mLastMousePosition;
        move(delta.toPoint());
        event->accept();
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

