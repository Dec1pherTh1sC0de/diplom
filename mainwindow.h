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

//Библиотеки для работы с PDF
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QApplication>

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

    //Переменная хранящая сессионный пин
    QString pin = "";

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

    int row;//Номер активной строки

    //Выбор модели таблицы пинкод
    void modelPin();

    //Выбор модели таблицы подключения
    void modelConnection();

    //Выбор модели таблицы авторизации
    void modelAutorize();

    //Выбор модели специальности
    void modelSpecialnost();

    //Выбор модели для общежитий
    void modelObshaga();

    //Выбор модели для ин.яз
    void modelInyaz();

    //Выбираем модель формы обучения
    void modelForma();

    //Выбираем модель Обоосо
    void modelObo();

    //Выбор модели курса
    void modelKurs();

    //Выбор модели бюджета
    void modeelBudget();

    //Выбор модели пола
    void modelPol();

    //Выбор модели целевика
    void modelCelevik();

    //Выбор модели ученики
    void modelYchenik();

    //Какая таблица выбранна 1-ученики, 2-грууппы.
    int tablica;


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
    void on_BlockFormButton_clicked();
    void on_EnterPinCodePushButton_2_clicked();
    void on_ShowPinButton_2_pressed();
    void on_ShowPinButton_2_released();
    void on_SettingButton_clicked();
    void on_NazadIzNastroek_clicked();
    void on_ChangePincodeSetting_clicked();
    void on_NazadIzNastroek_2_clicked();
    void on_ShowPinButton_3_pressed();
    void on_ShowPinButton_3_released();
    void on_EnterPinCodePushButton_3_clicked();
    void on_EnterPinCodePushButton_4_clicked();
    void on_ChangePinStart_clicked();
    void on_NazadIzNastroek_3_clicked();
    void on_ChangePincodeSetting_2_clicked();
    void on_NazadKNastroykam_clicked();
    void on_ShowPassButton_2_pressed();
    void on_ShowPassButton_2_released();
    void on_EnterPushButton_2_clicked();
    void on_EnterPushButton_3_clicked();
    void on_EnableRedaktion_clicked();
    void on_DisableRedaktion_2_clicked();
    void on_Dannye_clicked();
    void on_NazadKNastroykam_2_clicked();
    void on_StudentButton_clicked();
    void on_StudentButton_2_clicked();
    void on_StudentButton_3_clicked();
    void on_Dobavit_clicked();
    void on_DeleteZapis_clicked();
    void on_NazadKNastroykam_3_clicked();
    void on_Dannye_2_clicked();
    void on_pushButton_8_clicked();
    void on_comboBox_9_currentIndexChanged(int index);
    void on_pushButton_7_clicked();
    void on_DobaviStroku_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_StudentButton_9_clicked();
    void on_NazadKNastroykam_4_clicked();
    void on_StudentButton_10_clicked();
    void on_StudentButton_8_clicked();
    void on_NazadKNastroykam_5_clicked();
    void on_StudentButton_11_clicked();
    void on_lineEdit_25_textEdited(const QString &arg1);
    void on_StudentButton_12_clicked();
    void on_NazadIzNastroek_4_clicked();
    void on_OneBtn_clicked();
    void on_TwoBTN_clicked();
    void on_ThreBtn_clicked();
};
#endif // MAINWINDOW_H
