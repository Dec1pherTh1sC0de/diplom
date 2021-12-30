#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//Задание стиля окна
mtdcls->styleWindows(this,341,241);

//Задане стиля PinCodeWidget
mtdcls->stylePincodeWidget(this->ui->PinCodeWidget,this->ui->EnterPinCodePushButton,this->ui->CloseButton,this->ui->ShowPinButton,this->ui->PinCodeLineEdit, this->ui->ChangePinStart);

//Задане стилей AutorizationWidget
mtdcls->styleAutorizationWidget(this->ui->AutorizationWidget,this->ui->EnterPushButton,this->ui->LoginLineEdit,this->ui->PasswordLineEdit,this->ui->CloseButton_3,this->ui->ConnectWidgetButton, this->ui->ShowPassButton);

//Задане стилей ConnectionWidget
mtdcls->styleConnectionWidget(this->ui->ConnectionWidget,this->ui->ConnectBDButton, this->ui->ConnectBDButton_2, this->ui->RefreshConnection,this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit,this->ui->CloseButton_4,this->ui->GoToAutorizationWidget);

//Задание стилей BlockWindowWidget
mtdcls->styleBlockWindowWidget(this->ui->BlockWindow,this->ui->EnterPinCodePushButton_2,this->ui->ShowPinButton_2,this->ui->PinCodeLineEdit_2);

//Задание стиля HorizontalWidget
mtdcls->horizontalWidget(this->ui->HorizontalWidget, this->ui->SettingButton);

//Задание стиля виджету смены пинкода
mtdcls->changePinCode(this->ui->ChangePinCode,this->ui->NazadIzNastroek_2,this->ui->EnterPinCodePushButton_3,this->ui->ShowPinButton_3,this->ui->PinCodeLineEdit_3, this->ui->EnterPinCodePushButton_4, this->ui->NazadIzNastroek_3);

//Задание стиля виджета настроек
mtdcls->nastroyki(this->ui->Nastroyki,this->ui->NazadIzNastroek,this->ui->ChangePincodeSetting, this->ui->ChangePincodeSetting_2);

//Задание стиля виджету смены авторизационных данных
mtdcls->changeAvtorization(this->ui->ChangeAvtoeization, this->ui->ShowPassButton_2, this->ui->NazadKNastroykam, this->ui->EnterPushButton_2, this->ui->EnterPushButton_3, this->ui->LoginLineEdit_2, this->ui->PasswordLineEdit_2);
//Скрытие виджетов перед запуском и открытие виджета пинкода
mtdcls->hideFirstWidget(this->ui->AutorizationWidget,this->ui->ConnectionWidget, this->ui->BlockWindow, this->ui->FillWindow, this->ui->HorizontalWidget, this->ui->ChangePinCode, this->ui->Nastroyki, this->ui->ChangeAvtoeization);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Выбор модели таблицы пинкода
void MainWindow::modelPin()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("pincod");
    this->model->select();
}

//Выбор модели таблицы подключения
void MainWindow::modelConnection()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("connect");
    this->model->select();
}

//Выбор модели таблицы авторизации
void MainWindow::modelAutorize()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("autorize");
    this->model->select();
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

//Смена данных подключения к БД
void MainWindow::on_ConnectBDButton_clicked()
{
    if(this->ui->BDNameEdit->text() != "" && this->ui->HostEdit->text() != "" && this->ui->UserNameEdit->text() != "" && this->ui->PasswEdit->text() != "")
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

        //Вызов окна об удачной смене данных
        mtdcls->successChangeData(this);

        //Скрытие виджета подключения
        mtdcls->hideConnectWidget(this->ui->ConnectionWidget,this->ui->AutorizationWidget);
    }
    else
    {
        //Вызов окна заполните все поля
        mtdcls->enterAllLineEdit(this);
    }
}

//Проверка пинкода для открытия авторизации
void MainWindow::on_EnterPinCodePushButton_clicked()
{
    //Подключение к мини БД
    mindb->ccMiniDB();

    //Выбираем таблицу для модели
    modelPin();

    //Принимаем значение пинкода из БД и передаем его в переменную
    pin = model->data(model->index(0, 1)).toString();

    //Проверяем пинкод
    if(encryptcls->checkPin(this->ui->PinCodeLineEdit->text(),keyPAS,pin) == "1")
    {
        //Скрытие виджета пинкода
        mtdcls->hidePincodeWidget(this->ui->PinCodeWidget,this->ui->AutorizationWidget);

        //Выбираем таблицу для модели
        modelConnection();

        //Присваивание переменным значений полей
        QString a = model->data(model->index(0, 1)).toString();
        QString b = model->data(model->index(0, 2)).toString();
        QString c = model->data(model->index(0, 3)).toString();
        QString d = model->data(model->index(0, 4)).toString();

        //Расшифровка значений переменных
        QString a1 = encryptcls->stringDecrypt(a,keyPAS);
        QString b1 = encryptcls->stringDecrypt(b, keyPAS);
        QString c1 = encryptcls->stringDecrypt(c, keyPAS);
        QString d1 = encryptcls->stringDecrypt(d, keyPAS);

        //Заполнение полей данными
        this->ui->BDNameEdit->setText(a1);
        this->ui->HostEdit->setText(b1);
        this->ui->UserNameEdit->setText(c1);
        this->ui->PasswEdit->setText(d1);
    }
    else
    {
        //Вызов окна с ошибкой пинкода
        mtdcls->pinError(this);
    }
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
        //Выбор модели таблицы авторизации
        modelAutorize();

        //Присваивание переменным значение полей
        QString z = model->data(model->index(0, 1)).toString();
        QString z1 = model->data(model->index(0, 2)).toString();

        //Проверяем логин
        if(encryptcls->checkPin(this->ui->LoginLineEdit->text(),keyPAS,z) == "1")
        {
            //Проверяем пароль
            if(encryptcls->checkPin(this->ui->PasswordLineEdit->text(),keyPAS,z1) == "1")
            {
                //Отображение таблицы
                model = new QSqlTableModel(this,sdb);
                model->setTable("autorize");
                model->select();
                ui->tableView->setModel(model);

                //Задание стиля окна
                mtdcls->styleWindows(this,800,600);

                //Принимаем значение текущих размеров окна и передаем их в переменные
                oldHeigt = 800;
                oldWeigt = 600;

                //Присваивание ширины окна переменной
                shirina = 800;

                //Задание стиля таблицы
                mtdcls->styleTableView(this->ui->tableView, this->width(), this->height());
                this->ui->tableView->horizontalHeader()->show();
                this->ui->tableView->verticalHeader()->show();

                //Скрытие виджетов входа
                mtdcls->enterWidgetHide(this->ui->PinCodeWidget, this->ui->AutorizationWidget, this->ui->ConnectionWidget);

                //Метод показа верхнего виджета
                mtdcls->gorizontalWidget(this->ui->HorizontalWidget);

                //Метод отображения кнопок управления главным окном
                mtdcls->buttonWinWidget(this, this->ui->ButtonWidget,this->ui->BlockFormButton, this->ui->SvernutButton,this->ui->RazvernutButton, this->ui->CloseButton_5);

                //Показ верхнего виджета
                this->ui->HorizontalWidget->show();
            }
            else
            {
                mtdcls->passError(this);
            }
        }
        else
        {
            mtdcls->loginError(this);
        }
    }
    else
    {
        //Вывод окна с сообщением об ошибке
        mtdcls->connectError(this);
    }
}

//Применить данные подключения
void MainWindow::on_ConnectBDButton_2_clicked()
{
     if(this->ui->BDNameEdit->text() != "" && this->ui->HostEdit->text() != "" && this->ui->UserNameEdit->text() != "" && this->ui->PasswEdit->text() != "")
     {
         //Скрытие виджета подключения
         mtdcls->hideConnectWidget(this->ui->ConnectionWidget,this->ui->AutorizationWidget);
     }
     else
     {
         //Вызов окна заполните все поля
         mtdcls->enterAllLineEdit(this);
     }
}

//Обновить данные подключения
void MainWindow::on_RefreshConnection_clicked()
{
    //Выбираем таблицу для модели
    modelConnection();

    //Присваивание переменным значений полей
    QString a = model->data(model->index(0, 1)).toString();
    QString b = model->data(model->index(0, 2)).toString();
    QString c = model->data(model->index(0, 3)).toString();
    QString d = model->data(model->index(0, 4)).toString();

    //Расшифровка значений переменных
    QString a1 = encryptcls->stringDecrypt(a,keyPAS);
    QString b1 = encryptcls->stringDecrypt(b, keyPAS);
    QString c1 = encryptcls->stringDecrypt(c, keyPAS);
    QString d1 = encryptcls->stringDecrypt(d, keyPAS);

    //Заполнение полей данными
    this->ui->BDNameEdit->setText(a1);
    this->ui->HostEdit->setText(b1);
    this->ui->UserNameEdit->setText(c1);
    this->ui->PasswEdit->setText(d1);
}

//Показать пинкод
void MainWindow::on_ShowPinButton_pressed()
{
    mtdcls->showPassPin(this->ui->PinCodeLineEdit);

    //Изображение открытого замка
    mtdcls->styleTransparentButton(this->ui->ShowPinButton,"icon/document-decrypt-2.ico");
}

//Спрятать пинкод
void MainWindow::on_ShowPinButton_released()
{
    mtdcls->hidePassPin(this->ui->PinCodeLineEdit);

    //Изображение закрытого замка
    mtdcls->styleTransparentButton(this->ui->ShowPinButton,"icon/document-encrypt-2.ico");
}

//Показать пароль
void MainWindow::on_ShowPassButton_pressed()
{
    mtdcls->showPassPin(this->ui->PasswordLineEdit);

    //Изображение открытого замка
    mtdcls->styleTransparentButton(this->ui->ShowPassButton,"icon/document-decrypt-2.ico");
}

//Спрятать пароль
void MainWindow::on_ShowPassButton_released()
{
    mtdcls->hidePassPin(this->ui->PasswordLineEdit);

    //Изображение закрытого замка
    mtdcls->styleTransparentButton(this->ui->ShowPassButton,"icon/document-encrypt-2.ico");
}

//Кнопка закрытия формы
void MainWindow::on_CloseButton_5_clicked()
{
    mtdcls->closeEvent(this);
}

//Сворачивание окна
void MainWindow::on_SvernutButton_clicked()
{
    this->showMinimized();
}

//Разворачивание окна
void MainWindow::on_RazvernutButton_clicked()
{
    if(ifmax == 0)
    {
        //Передаем что окно максимизированно
        ifmax = 1;

        //Максимизируем окно
        mtdcls->maximizeWindow(this);

        //Задание стиля таблицы
        mtdcls->styleTableView(this->ui->tableView, this->width(), this->height());

        //Центрация виджета
        mtdcls->centerWidget(this->width(),this->height(),this->ui->BlockWindow);

        //Метод отображения кнопок управления главным окном
        mtdcls->buttonWinWidget(this, this->ui->ButtonWidget,this->ui->BlockFormButton, this->ui->SvernutButton,this->ui->RazvernutButton, this->ui->CloseButton_5);
    }
    else
    {
        //Передаем что окно прежних размеров
        ifmax = 0;

        //Задание стиля окна со старыми размерами
        mtdcls->styleWindows(this,oldHeigt,oldWeigt);

        //Центрация виджета
        mtdcls->centerWidget(this->width(),this->height(),this->ui->BlockWindow);

        //Задание стиля таблицы
        mtdcls->styleTableView(this->ui->tableView, this->width(), this->height());
        this->ui->tableView->horizontalHeader()->show();
        this->ui->tableView->verticalHeader()->show();

        //Метод отображения кнопок управления главным окном
        mtdcls->buttonWinWidget(this, this->ui->ButtonWidget,this->ui->BlockFormButton, this->ui->SvernutButton,this->ui->RazvernutButton, this->ui->CloseButton_5);
    }
}

//Блокировка рабочего окна
void MainWindow::on_BlockFormButton_clicked()
{

    //Заполнение окна
    this->ui->FillWindow->show();
    this->ui->FillWindow->setStyleSheet("background-color: #212121; border-style: outset; border-width: 0px; border-radius: 10px;");
    this->ui->FillWindow->setGeometry(0,0,this->width(),this->height());

    //Показ виджета блокировки
    this->ui->BlockWindow->show();

    //Поднятие виджета на передний план
    this->ui->BlockWindow->raise();

    //Центрирование виджета
    mtdcls->centerWidget(this->width(),this->height(),this->ui->BlockWindow);

}

//Разблокировать окно
void MainWindow::on_EnterPinCodePushButton_2_clicked()
{
    //Принимаем значение введенного пинкода
    QString entrPin = this->ui->PinCodeLineEdit_2->text();

    //Проверка правильности пинкода
    if(encryptcls->checkPin(entrPin,keyPAS,pin) == "1")
    {
        this->ui->BlockWindow->hide();
        this->ui->FillWindow->hide();
        this->ui->PinCodeLineEdit_2->clear();
    }
    else
    {
        mtdcls->pinError(this);
    }
}

//Показать пинкод
void MainWindow::on_ShowPinButton_2_pressed()
{
    mtdcls->showPassPin(this->ui->PinCodeLineEdit_2);

    //Изображение открытого замка
    mtdcls->styleTransparentButton(this->ui->ShowPinButton_2,"icon/document-decrypt-2.ico");
}

//Скрыть пинкод
void MainWindow::on_ShowPinButton_2_released()
{
    mtdcls->hidePassPin(this->ui->PinCodeLineEdit_2);

    //Изображение закрытого замка
    mtdcls->styleTransparentButton(this->ui->ShowPinButton_2,"icon/document-encrypt-2.ico");
}

//Вызов меню настроек
void MainWindow::on_SettingButton_clicked()
{
    //Заполнение окна
    this->ui->FillWindow->show();
    this->ui->FillWindow->setStyleSheet("background-color: #212121; border-style: outset; border-width: 0px; border-radius: 10px;");
    this->ui->FillWindow->setGeometry(0,0,this->width(),this->height());

    //Вызов виджета настроек
    this->ui->Nastroyki->show();

    //Поднятие виджета на передний план
    this->ui->Nastroyki->raise();

    //Центрирование виджета
    mtdcls->centerWidget(this->width(),this->height(),this->ui->Nastroyki);
}

//Закрыть виджет настроек
void MainWindow::on_NazadIzNastroek_clicked()
{
    this->ui->Nastroyki->hide();
    this->ui->FillWindow->hide();
}

//Смена пинкода
void MainWindow::on_ChangePincodeSetting_clicked()
{
    //Скрытие виджета настроек
    this->ui->Nastroyki->hide();

    //Показ виджета смены пинкода
    this->ui->ChangePinCode->show();

    //Отчистка поля пинкода
    this->ui->PinCodeLineEdit_3->clear();

    //Скрытие\показ кнопок
    this->ui->NazadIzNastroek_2->show();
    this->ui->NazadIzNastroek_3->hide();

    //Скрытие кнопки
    this->ui->EnterPinCodePushButton_4->hide();

    //Центрирование виджета
    mtdcls->centerWidget(this->width(),this->height(),this->ui->ChangePinCode);
}

//Назад к настройкам
void MainWindow::on_NazadIzNastroek_2_clicked()
{
    //Отчистка поля пинкода
    this->ui->PinCodeLineEdit_3->clear();

    //Изменяем  значения текста
    this->ui->label_14->setText("Ведите старый пинкод");

    //Скрываем предынущую кнопку
    this->ui->EnterPinCodePushButton_3->show();

    //Показываем кнопку смены пинкода
    this->ui->EnterPinCodePushButton_4->hide();

    //Скрытие виджета смены пинкода
    this->ui->ChangePinCode->hide();

    //Вызов меню настроек
    this->ui->Nastroyki->show();
}

//Показать пароль
void MainWindow::on_ShowPinButton_3_pressed()
{
    mtdcls->showPassPin(this->ui->PinCodeLineEdit_3);

    //Изображение открытого замка
    mtdcls->styleTransparentButton(this->ui->ShowPinButton_3,"icon/document-decrypt-2.ico");
}

//Скрыть пинкод
void MainWindow::on_ShowPinButton_3_released()
{
    mtdcls->hidePassPin(this->ui->PinCodeLineEdit_3);

    //Изображение закрытого замка
    mtdcls->styleTransparentButton(this->ui->ShowPinButton_3,"icon/document-encrypt-2.ico");
}

//Проверка пинкода для дальнейшей его смены
void MainWindow::on_EnterPinCodePushButton_3_clicked()
{
    //Принимаем значение введенного пинкода
    QString entrPin = this->ui->PinCodeLineEdit_3->text();

    //Проверка правильности пинкода
    if(encryptcls->checkPin(entrPin,keyPAS,pin) == "1")
    {
        //Изменяем  значения текста
        this->ui->label_14->setText("Ведите новый пинкод");

        //Скрываем предынущую кнопку
        this->ui->EnterPinCodePushButton_3->hide();

        //Показываем кнопку смены пинкода
        this->ui->EnterPinCodePushButton_4->show();

        //Отчистка поля пинкода
        this->ui->PinCodeLineEdit_3->clear();

    }
    else
    {
        mtdcls->pinError(this);
    }
}

//Смена пинкода
void MainWindow::on_EnterPinCodePushButton_4_clicked()
{
    if(this->ui->PinCodeLineEdit_3->text() != "")
    {
        //Подключение к мини БД
        mindb->ccMiniDB();

        //Выбираем таблицу для модели
        modelPin();

        //Принимаем значение введенного пинкода
        QString entPinC = this->ui->PinCodeLineEdit_3->text();

        //Шифрование значений переменных
        QString entPinC1 = encryptcls->stringEncrypt(entPinC,keyPAS);

        //Смена пинкода
        mindb->chengePin(entPinC1);

        //Вызов окна об удачной смене данных
        mtdcls->successChangeData(this);

        //Принимаем значение пинкода из БД и передаем его в переменную
        pin = entPinC1;

        //Отчистка поля пинкода
        this->ui->PinCodeLineEdit_3->clear();

        //Изменяем  значения текста
        this->ui->label_14->setText("Ведите старый пинкод");

        //Скрываем предынущую кнопку
        this->ui->EnterPinCodePushButton_3->show();

        //Показываем кнопку смены пинкода
        this->ui->EnterPinCodePushButton_4->hide();

        //Скрытие виджета смены пинкода
        this->ui->ChangePinCode->hide();

        //Вызов меню настроек
        this->ui->Nastroyki->show();
    }
    else
    {
        //Вызов окна заполните поле
        mtdcls->enterLineEdit(this);
    }
}

//Смена пинкода в начале программы
void MainWindow::on_ChangePinStart_clicked()
{
    //Подключение к мини БД
    mindb->ccMiniDB();

    //Выбираем таблицу для модели
    modelPin();

    //Принимаем значение пинкода из БД и передаем его в переменную
    pin = model->data(model->index(0, 1)).toString();

    //Проверяем пинкод
    if(encryptcls->checkPin(this->ui->PinCodeLineEdit->text(),keyPAS,pin) == "1")
    {
        //Показ виджета смены пинкода
        this->ui->ChangePinCode->show();

        this->ui->NazadIzNastroek_2->hide();
        this->ui->NazadIzNastroek_3->show();

        //Скрытие кнопки
        this->ui->EnterPinCodePushButton_4->hide();

        //Центрирование виджета
        mtdcls->centerWidget(this->width(),this->height(),this->ui->ChangePinCode);
    }
    else
    {
        //Проверка на пустое поле
        if(this->ui->PinCodeLineEdit->text() == "")
        {
            //Вызов окна с ошибкой пинкода
            mtdcls->firstVhangePin(this);
        }
        else
        {
            //Вызов окна с ошибкой пинкода
            mtdcls->pinError(this);
        }
    }
}

//Назад к вводу пинкода
void MainWindow::on_NazadIzNastroek_3_clicked()
{
    //Скрытие виджета смены пинкода
    this->ui->ChangePinCode->hide();

    //Скрытие\показ кнопок
    this->ui->NazadIzNastroek_2->show();
    this->ui->NazadIzNastroek_3->hide();

    //Отчистка поля пинкода
    this->ui->PinCodeLineEdit->clear();
}

//Смена авторизационных данных
void MainWindow::on_ChangePincodeSetting_2_clicked()
{
    //Скрытие виджета настроек
    this->ui->Nastroyki->hide();

    //Показ виджета смены авторизационных данных
    this->ui->ChangeAvtoeization->show();

    //Задать полю свойство прятать пинкод
    mtdcls->hidePassPin(this->ui->PasswordLineEdit_2);

    //Прячем кнопки
    this->ui->EnterPushButton_3->hide();

    //Центрирование виджета
    mtdcls->centerWidget(this->width(),this->height(),this->ui->ChangeAvtoeization);
}

//Назад к настройкам
void MainWindow::on_NazadKNastroykam_clicked()
{
    //Скрытие виджета смены пинкода
    this->ui->ChangeAvtoeization->hide();

    //Вызов меню настроек
    this->ui->Nastroyki->show();

    //Отчистка полей
    this->ui->LoginLineEdit_2->clear();
    this->ui->PasswordLineEdit_2->clear();

    //Показываем кнопки
    this->ui->EnterPushButton_3->show();

    //Смена надписи лэйбла
    this->ui->label_18->setText("Введите старые данные");
}

//Показать пароль
void MainWindow::on_ShowPassButton_2_pressed()
{
    mtdcls->showPassPin(this->ui->PasswordLineEdit_2);

    //Изображение открытого замка
    mtdcls->styleTransparentButton(this->ui->ShowPassButton_2,"icon/document-decrypt-2.ico");
}

//Спрятать пинкод
void MainWindow::on_ShowPassButton_2_released()
{
    mtdcls->hidePassPin(this->ui->PasswordLineEdit_2);

    //Изображение закрытого замка
    mtdcls->styleTransparentButton(this->ui->ShowPassButton_2,"icon/document-encrypt-2.ico");
}

//Проверить авторизационные данные перед сменой
void MainWindow::on_EnterPushButton_2_clicked()
{
    //Подключаем БД
    QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);

    if(a == "1")
    {
        //Выбор модели таблицы авторизации
        modelAutorize();

        //Присваивание переменным значение полей
        QString z = model->data(model->index(0, 1)).toString();
        QString z1 = model->data(model->index(0, 2)).toString();

        //Проверяем на пустоту поля
        if(this->ui->LoginLineEdit_2->text() != "" && this->ui->PasswordLineEdit_2->text() != "")
        {
            //Проверяем логин
            if(encryptcls->checkPin(this->ui->LoginLineEdit_2->text(),keyPAS,z) == "1")
            {
                //Проверяем пароль
                if(encryptcls->checkPin(this->ui->PasswordLineEdit_2->text(),keyPAS,z1) == "1")
                {
                    //Смена надписи лэйбла
                    this->ui->label_18->setText("Введите новые данные");

                    //Показываем кнопки
                    this->ui->EnterPushButton_3->show();

                    //Отчищаем поля
                    this->ui->LoginLineEdit_2->clear();
                    this->ui->PasswordLineEdit_2->clear();
                }
                else
                {
                    //Неправильный пароль
                    mtdcls->passError(this);
                }
            }
            else
            {
                //Неправильный логин
                mtdcls->loginError(this);
            }
        }
        else
        {
            //Вызов окна заполните все поля
            mtdcls->enterAllLineEdit(this);
        }
    }
    else
    {
        //Вывод окна с сообщением об ошибке
        mtdcls->connectError(this);
    }
}

//Сменить авторизационные данные
void MainWindow::on_EnterPushButton_3_clicked()
{
    //Выбор модели таблицы авторизации
    modelAutorize();

    //Проверка на пустоту
    if(this->ui->LoginLineEdit_2->text() != "" && this->ui->PasswordLineEdit_2->text() != "")
    {
        //Присваиваем значения полей переменным
        QString a = this->ui->LoginLineEdit_2->text();
        QString b = this->ui->PasswordLineEdit_2->text();

        //Шифрование значений переменных
        QString a1 = encryptcls->stringEncrypt(a,keyPAS);
        QString b1 = encryptcls->stringEncrypt(b, keyPAS);

        //Меняем авторизационные данные
        mindb->changeAutorizeDataAdmin(a1,b1);

        //Вызов окна об успешной смене данных
        mtdcls->successChangeData(this);

        //Скрытие виджета смены пинкода
        this->ui->ChangeAvtoeization->hide();

        //Вызов меню настроек
        this->ui->Nastroyki->show();

        //Отчистка полей
        this->ui->LoginLineEdit_2->clear();
        this->ui->PasswordLineEdit_2->clear();

        //Показываем кнопки
        this->ui->EnterPushButton_3->show();

        //Смена надписи лэйбла
        this->ui->label_18->setText("Введите старые данные");
    }
    else
    {
        //Вызов окна заполните все поля
        mtdcls->enterAllLineEdit(this);
    }
}

