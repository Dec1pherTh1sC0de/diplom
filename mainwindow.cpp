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
mtdcls->horizontalWidget(this->ui->HorizontalWidget, this->ui->SettingButton, this->ui->Dannye, this->ui->Dannye_2, this->ui->lineEdit_25);

//Задание стиля виджету смены пинкода
mtdcls->changePinCode(this->ui->ChangePinCode,this->ui->NazadIzNastroek_2,this->ui->EnterPinCodePushButton_3,this->ui->ShowPinButton_3,this->ui->PinCodeLineEdit_3, this->ui->EnterPinCodePushButton_4, this->ui->NazadIzNastroek_3);

//Задание стиля виджета настроек
mtdcls->nastroyki(this->ui->Nastroyki,this->ui->NazadIzNastroek,this->ui->ChangePincodeSetting, this->ui->ChangePincodeSetting_2, this->ui->EnableRedaktion, this->ui->DisableRedaktion_2);

//Задание стиля виджету смены авторизационных данных
mtdcls->changeAvtorization(this->ui->ChangeAvtoeization, this->ui->ShowPassButton_2, this->ui->NazadKNastroykam, this->ui->EnterPushButton_2, this->ui->EnterPushButton_3, this->ui->LoginLineEdit_2, this->ui->PasswordLineEdit_2);

//Скрытие виджетов перед запуском и открытие виджета пинкода
mtdcls->hideFirstWidget(this->ui->AutorizationWidget,this->ui->ConnectionWidget, this->ui->BlockWindow, this->ui->FillWindow, this->ui->HorizontalWidget, this->ui->ChangePinCode, this->ui->Nastroyki, this->ui->ChangeAvtoeization);

//Запрет редактирования таблицы
this->ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

//Скрытие виджета добавления студента
this->ui->AddStudent->hide();

//Скрытие виджета показа данных
this->ui->ShowData->hide();

//Скрытие виджета с действиями
this->ui->Deystviya->hide();

//Задание стиля виджету показа данных
mtdcls->showDataWidget(this->ui->ShowData,this->ui->StudentButton, this->ui->StudentButton_2, this->ui->StudentButton_3, this->ui->NazadKNastroykam_2);

//Задание стиля виджету действий
mtdcls->deystviyaWidget(this->ui->Deystviya,this->ui->DeleteZapis, this->ui->Dobavit, this->ui->DobaviStroku, this->ui->StudentButton_8, this->ui->NazadKNastroykam_3, this->ui->StudentButton_9, this->ui->StudentButton_12);

//Задание стиля виджету добавления
mtdcls->addWidgetStyle(this->ui->AddStudent,this->ui->pushButton_7, this->ui->pushButton_8, this->ui->lineEdit, this->ui->lineEdit_10, this->ui->lineEdit_11, this->ui->lineEdit_2, this->ui->lineEdit_3, this->ui->lineEdit_4, this->ui->lineEdit_5, this->ui->lineEdit_6, this->ui->lineEdit_7, this->ui->lineEdit_8, this->ui->lineEdit_9, this->ui->comboBox, this->ui->comboBox_2, this->ui->comboBox_3, this->ui->comboBox_4, this->ui->comboBox_5, this->ui->comboBox_6, this->ui->comboBox_7, this->ui->comboBox_8, this->ui->comboBox_9, this->ui->comboBox_10, this->ui->comboBox_11, this->ui->comboBox_13, this->ui->dateEdit, this->ui->dateEdit_4, this->ui->doubleSpinBox, this->ui->doubleSpinBox_2);

//Задание стиля виджету добавления группы
mtdcls->styleAddGruppa(this->ui->AddGruppa, this->ui->pushButton_9, this->ui->pushButton_10, this->ui->lineEdit_12, this->ui->lineEdit_13, this->ui->lineEdit_14, this->ui->lineEdit_15, this->ui->lineEdit_16);

//Скрытие виджета добавления группы
this->ui->AddGruppa->hide();

//Скрытие виджета отчисления
this->ui->Otchislenie->hide();

//Задание стияля виджету отчисления
mtdcls->styleOthicslit(this->ui->Otchislenie, this->ui->dateEdit_5, this->ui->lineEdit_17, this->ui->StudentButton_10, this->ui->NazadKNastroykam_4);

//Скрытие виджета перевода
this->ui->Perevod->hide();

//Задание стиля виджету перевода
mtdcls->stylePerevod(this->ui->Perevod, this->ui->dateEdit_6, this->ui->comboBox_12, this->ui->comboBox_14, this->ui->comboBox_15, this->ui->comboBox_16, this->ui->lineEdit_18, this->ui->lineEdit_19, this->ui->lineEdit_20, this->ui->lineEdit_21, this->ui->lineEdit_22, this->ui->lineEdit_23, this->ui->lineEdit_24, this->ui->StudentButton_11, this->ui->NazadKNastroykam_5);

//Скрытие виджета о приказах
this->ui->Prikazy->hide();

//Задание стиля виджету приказов
mtdcls->stylePrikazy(this->ui->Prikazy, this->ui->OneBtn, this->ui->TwoBTN, this->ui->ThreBtn, this->ui->NazadIzNastroek_4);

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

//Выбор модели специальности
void MainWindow::modelSpecialnost()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("specialnost");
    this->model->select();
}

//Выбор модели для общежития
void MainWindow::modelObshaga()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("obshaga");
    this->model->select();
}

//Выбор модели для ин.яз
void MainWindow::modelInyaz()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("inyaz");
    this->model->select();
}

//Выбор модели для формы обучения
void MainWindow::modelForma()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("formaobuch");
    this->model->select();
}

//Выбор модели обоосо
void MainWindow::modelObo()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("obooso");
    this->model->select();
}

//Выбор модели курса
void MainWindow::modelKurs()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("kurs");
    this->model->select();
}

//Выбор модели бюджета
void MainWindow::modeelBudget()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("budjet");
    this->model->select();
}

//Выбор модели пол
void MainWindow::modelPol()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("pol");
    this->model->select();
}

//Выбор модели целевика
void MainWindow::modelCelevik()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("celevik");
    this->model->select();
}

//Выбор модели ученики
void MainWindow::modelYchenik()
{
    //Выбираем таблицу БД
    this->model = new QSqlTableModel(this,this->sdb);
    this->model->setTable("ycheniki");
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

//Разрешить редактирование таблицы
void MainWindow::on_EnableRedaktion_clicked()
{
    this->ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
    this->ui->Nastroyki->hide();
    this->ui->FillWindow->hide();
}

//Запретить редактирование таблицы
void MainWindow::on_DisableRedaktion_2_clicked()
{
    this->ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->Nastroyki->hide();
    this->ui->FillWindow->hide();
}

//Открытие виджета для работы с данными
void MainWindow::on_Dannye_clicked()
{
    //Заполнение окна
    this->ui->FillWindow->show();
    this->ui->FillWindow->setStyleSheet("background-color: #212121; border-style: outset; border-width: 0px; border-radius: 10px;");
    this->ui->FillWindow->setGeometry(0,0,this->width(),this->height());

    //Вызов виджета
    this->ui->ShowData->show();

    //Поднятие виджета на передний план
    this->ui->ShowData->raise();

    //Центрирование виджета
    mtdcls->centerWidget(this->width(),this->height(),this->ui->ShowData);
}

//Назад к программе
void MainWindow::on_NazadKNastroykam_2_clicked()
{
    this->ui->ShowData->hide();
    this->ui->FillWindow->hide();
}

//Показ таблицы со студентами
void MainWindow::on_StudentButton_clicked()
{
    //Скрытие виджета
    this->ui->ShowData->hide();
    this->ui->FillWindow->hide();

    //Подключаем БД
    QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);
    if(a == "1")
    {
        //Отображение таблицы
        model = new QSqlTableModel(this,sdb);
        model->setTable("ycheniki");
        model->select();
        ui->tableView->setModel(model);

        tablica = 1;
    }
}

//Показ таблицы с группами
void MainWindow::on_StudentButton_2_clicked()
{
    //Скрытие виджета
    this->ui->ShowData->hide();
    this->ui->FillWindow->hide();

    //Подключаем БД
    QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);
    if(a == "1")
    {
        //Отображение таблицы
        model = new QSqlTableModel(this,sdb);
        model->setTable("gruppy");
        model->select();
        ui->tableView->setModel(model);

        tablica = 2;
    }
}

//Показ контингента
void MainWindow::on_StudentButton_3_clicked()
{
    //Подключаем БД
    QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);
    if(a == "1")
    {
        //Отображение таблицы
        model = new QSqlTableModel(this,sdb);
        model->setTable("ycheniki");
        model->select();

        //Переменные принимающие значения из запросов
        QString girl;
        QString boy;
        QString vsego;
        QString platniki;
        QString cheleviki;
        QString budget;

        //Количество всех девушек
        QSqlQuery a_query;
        a_query.prepare("SELECT COUNT(*) FROM ycheniki WHERE Pol='Ж'");
        a_query.exec();
        if (a_query.next()) {
            girl = a_query.value(0).toString();
        }

        //Количество всех парней
        QSqlQuery b_query;
        b_query.prepare("SELECT COUNT(*) FROM ycheniki WHERE Pol='М'");
        b_query.exec();
        if (b_query.next()) {
            boy = b_query.value(0).toString();
        }

        //Количество всех
        QSqlQuery c1_query;
        c1_query.prepare("SELECT COUNT(*) FROM ycheniki WHERE Otchislen=''");
        c1_query.exec();
        if (c1_query.next()) {
            vsego = c1_query.value(0).toString();
        }

        //Количество платников
        QSqlQuery d_query;
        d_query.prepare("SELECT COUNT(*) FROM ycheniki WHERE Budget='Комерч'");
        d_query.exec();
        if (d_query.next()) {
            platniki = d_query.value(0).toString();
        }

        //Количество целевиков
        QSqlQuery e_query;
        e_query.prepare("SELECT COUNT(*) FROM ycheniki WHERE Celevik='Да'");
        e_query.exec();
        if (e_query.next()) {
            cheleviki = e_query.value(0).toString();
        }

        //Количество бюджетников
        QSqlQuery f_query;
        f_query.prepare("SELECT COUNT(*) FROM ycheniki WHERE Budget='Бюджет'");
        f_query.exec();
        if (f_query.next()) {
            budget = f_query.value(0).toString();
        }

        //Отображение таблицы
        model = new QSqlTableModel(this,sdb);
        model->setTable("kontengent");
        model->select();

        //Запись данных о контингенте
        mindb->addKontengent(girl, boy, vsego, platniki, cheleviki, budget);


    }

    //Отображение таблицы
    model = new QSqlTableModel(this,sdb);
    model->setTable("kontengent");
    model->select();
    ui->tableView->setModel(model);

    tablica = 3;

    //Скрытие виджета
    this->ui->ShowData->hide();
    this->ui->FillWindow->hide();
}

//Добавить запись
void MainWindow::on_Dobavit_clicked()
{
    //Добавление данных в таблицу с учениками
    if(tablica == 1)
    {
        //Подключаем БД
        QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);
        if(a == "1")
        {
            //Выбираем таблицу для модели
            modelSpecialnost();
            //Специальности
            QSqlQuery query("SELECT Specialnost FROM specialnost", sdb);
            if(query.isActive())
            {
               while(query.next())
                {
                   this->ui->comboBox->addItem(query.value(0).toString());
                }
            }

            //Выбираем таблицу для модели
            modelObshaga();
            //Адрес общежития
            QSqlQuery query1("SELECT Adress FROM obshaga", sdb);
            if(query1.isActive())
            {
               while(query1.next())
                {
                   this->ui->comboBox_6->addItem(query1.value(0).toString());
                }
            }

            //Выбираем таблицу для модели
            modelInyaz();
            //Ин.яз
            QSqlQuery query2("SELECT Yazik FROM inyaz", sdb);
            if(query1.isActive())
            {
               while(query2.next())
                {
                   this->ui->comboBox_8->addItem(query2.value(0).toString());
                }
            }

            //Выбираем таблицу для модели
            modelForma();
            //Форма обучения
            QSqlQuery query3("SELECT Formaobuch FROM formaobuch", sdb);
            if(query3.isActive())
            {
               while(query3.next())
                {
                   this->ui->comboBox_2->addItem(query3.value(0).toString());
                }
            }

            //Выбираем таблицу для модели
            modelObo();
            //ОБО\ОСО
            QSqlQuery query4("SELECT Obooso FROM obooso", sdb);
            if(query4.isActive())
            {
               while(query4.next())
                {
                   this->ui->comboBox_3->addItem(query4.value(0).toString());
                }
            }

            //Выбираем таблицу для модели
            modelKurs();
            //Курс
            QSqlQuery query5("SELECT Kurs FROM kurs", sdb);
            if(query5.isActive())
            {
               while(query5.next())
                {
                   this->ui->comboBox_4->addItem(query5.value(0).toString());
                }
            }

            //Выбираем таблицу для модели
            modeelBudget();
            //Бюджет или комерч
            QSqlQuery query6("SELECT Budjet FROM budjet", sdb);
            if(query6.isActive())
            {
               while(query6.next())
                {
                   this->ui->comboBox_5->addItem(query6.value(0).toString());
                }
            }

            //Выбираем таблицу для модели
            modelPol();
            //Пол
            QSqlQuery query7("SELECT Pol FROM pol", sdb);
            if(query7.isActive())
            {
               while(query7.next())
                {
                   this->ui->comboBox_7->addItem(query7.value(0).toString());
                }
            }

            //Область
            ui->comboBox_9->addItem("",0);
            ui->comboBox_9->addItem("Брестская",1);
            ui->comboBox_9->addItem("Витебская",2);
            ui->comboBox_9->addItem("Гомельская",3);
            ui->comboBox_9->addItem("Гродненская",4);
            ui->comboBox_9->addItem("Минская",5);
            ui->comboBox_9->addItem("Могилевская",6);

            //Выбираем таблицу для модели
            modelCelevik();
            //Целевик
            QSqlQuery query8("SELECT Celevik FROM celevik", sdb);
            if(query8.isActive())
            {
               while(query8.next())
                {
                   this->ui->comboBox_13->addItem(query8.value(0).toString());
                }
            }

            //Скрытие виджета
            this->ui->Deystviya->hide();
            this->ui->tableView->hide();
            this->ui->FillWindow->hide();
            this->ui->HorizontalWidget->hide();

            //Показ виджета добавления студента
            this->ui->AddStudent->show();

            //Центрирование виджета
            mtdcls->styleAddWidget(this->ui->AddStudent,this->width(),this->height());
        }
    }

    //Добавление данных в таблицу с кураторами
    if(tablica == 2)
    {
        //Подключаем БД
        QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);
        if(a == "1")
        {
            //Скрытие виджета
            this->ui->Deystviya->hide();
            this->ui->tableView->hide();
            this->ui->FillWindow->hide();
            this->ui->HorizontalWidget->hide();

            //Показ виджета добавления студента
            this->ui->AddGruppa->show();

            //Центрирование виджета
            mtdcls->centerWidget(this->width(),this->height(), this->ui->AddGruppa);
        }
    }
}

//Удалить запись
void MainWindow::on_DeleteZapis_clicked()
{
    //Удаление данных из таблицы учеников
    if(tablica == 1)
    {
        //Удаление
        model = new QSqlTableModel(this,sdb);
        model->setTable("ycheniki");
        model->select();
        model->removeRow(this->ui->tableView->currentIndex().row());

        //Обновление таблицы
        model->submitAll();

        //Отображение данных
        model->select();
        this->ui->tableView->setModel(model);

        //Назад к программе
        this->ui->Deystviya->hide();
        this->ui->FillWindow->hide();
    }
    //Удаление данных из таблицы группы
    if(tablica == 2)
    {
        //Удаление
        model = new QSqlTableModel(this,sdb);
        model->setTable("gruppy");
        model->select();
        model->removeRow(this->ui->tableView->currentIndex().row());

        //Обновление таблицы
        model->submitAll();

        //Отображение данных
        model->select();
        this->ui->tableView->setModel(model);

        //Назад к программе
        this->ui->Deystviya->hide();
        this->ui->FillWindow->hide();
    }
}

//Назад к программе
void MainWindow::on_NazadKNastroykam_3_clicked()
{
    this->ui->Deystviya->hide();
    this->ui->FillWindow->hide();
}

//Открыть виджет действий
void MainWindow::on_Dannye_2_clicked()
{
    //Заполнение окна
    this->ui->FillWindow->show();
    this->ui->FillWindow->setStyleSheet("background-color: #212121; border-style: outset; border-width: 0px; border-radius: 10px;");
    this->ui->FillWindow->setGeometry(0,0,this->width(),this->height());

    //Вызов виджета
    this->ui->Deystviya->show();

    //Поднятие виджета на передний план
    this->ui->Deystviya->raise();

    //Центрирование виджета
    this->ui->Deystviya->setGeometry((this->width()*0.5)-170.5,(this->height()*0.5)-120.5,341,281);
}

//Отмена добавления
void MainWindow::on_pushButton_8_clicked()
{
    this->ui->AddStudent->hide();
    this->ui->tableView->show();
    this->ui->HorizontalWidget->show();

    //Отчистка полей
        this->ui->comboBox->clear();
        this->ui->comboBox->clear();
        this->ui->comboBox_2->clear();
        this->ui->comboBox_3->clear();
        this->ui->comboBox_4->clear();
        this->ui->lineEdit_10->clear();
        this->ui->comboBox_5->clear();
        this->ui->comboBox_6->clear();
        this->ui->comboBox_7->clear();
        this->ui->lineEdit->clear();
        this->ui->lineEdit_2->clear();
        this->ui->lineEdit_3->clear();
        this->ui->dateEdit->clear();
        this->ui->dateEdit_4->clear();
        this->ui->lineEdit_4->clear();
        this->ui->doubleSpinBox_2->clear();
        this->ui->comboBox_8->clear();
        this->ui->lineEdit_6->clear();
        this->ui->comboBox_9->clear();
        this->ui->comboBox_10->clear();
        this->ui->comboBox_11->clear();
        this->ui->lineEdit_5->clear();
        this->ui->doubleSpinBox->clear();
        this->ui->lineEdit_7->clear();
        this->ui->lineEdit_8->clear();
        this->ui->lineEdit_11->clear();
        this->ui->lineEdit_9->clear();
        this->ui->comboBox_13->clear();

    //Отображение таблицы
    model = new QSqlTableModel(this,sdb);
    model->setTable("ycheniki");
    model->select();
    ui->tableView->setModel(model);
}

//Смена заполнение городами при выборе области
void MainWindow::on_comboBox_9_currentIndexChanged(int index)
{
    //Области
        QString brestskaya = "Брестская";
        QString vitebskaya = "Витебская";
        QString gomelskaya = "Гомельская";
        QString grodnenskaya = "Гродненская";
        QString minskaya = "Минская";
        QString mogilevskaya = "Могилевская";

        //Присваивание переменной выбранного значения
        QString oblast =ui->comboBox_9->itemText(index);

        //Брестская
        if(oblast == brestskaya)
        {
            //Города
            ui->comboBox_10->clear();
            ui->comboBox_11->clear();
            ui->comboBox_10->addItem("",0);
            ui->comboBox_10->addItem("Брест",1);
            ui->comboBox_10->addItem("Барановичи",2);
            ui->comboBox_10->addItem("Пинск",3);
            ui->comboBox_10->addItem("Кобрин",4);
            ui->comboBox_10->addItem("Берёза",5);
            ui->comboBox_10->addItem("Лунинец",6);
            ui->comboBox_10->addItem("Ивацевичи",7);
            ui->comboBox_10->addItem("Пружаны",8);
            ui->comboBox_10->addItem("Иваново",9);
            ui->comboBox_10->addItem("Дрогичин",10);
            ui->comboBox_10->addItem("Ганцевичи",11);
            ui->comboBox_10->addItem("Жабинка",12);
            ui->comboBox_10->addItem("Микашевичи",13);
            ui->comboBox_10->addItem("Белоозёрск",14);
            ui->comboBox_10->addItem("Столин",15);
            ui->comboBox_10->addItem("Малорита",16);
            ui->comboBox_10->addItem("Ляховичи",17);
            ui->comboBox_10->addItem("Каменец",18);
            ui->comboBox_10->addItem("Давид-Городок",19);
            ui->comboBox_10->addItem("Высокое",20);
            ui->comboBox_10->addItem("Коссово",21);

            //Районы
            ui->comboBox_11->addItem("",0);
            ui->comboBox_11->addItem("Барановичский",1);
            ui->comboBox_11->addItem("Берёзовский",2);
            ui->comboBox_11->addItem("Брестский",3);
            ui->comboBox_11->addItem("Брест - Ленинский",4);
            ui->comboBox_11->addItem("Брест - Московский",5);
            ui->comboBox_11->addItem("Ганцевичский",6);
            ui->comboBox_11->addItem("Дрогичинский",7);
            ui->comboBox_11->addItem("Жабинковский",8);
            ui->comboBox_11->addItem("Ивановский",9);
            ui->comboBox_11->addItem("Ивацевичский",10);
            ui->comboBox_11->addItem("Каменецкий",11);
            ui->comboBox_11->addItem("Кобринский",12);
            ui->comboBox_11->addItem("Лунинецкий",13);
            ui->comboBox_11->addItem("Ляховичский",14);
            ui->comboBox_11->addItem("Малоритский",15);
            ui->comboBox_11->addItem("Пинский",16);
            ui->comboBox_11->addItem("Пружанский",17);
            ui->comboBox_11->addItem("Столинский",18);
        }
        //Витебская
        if(oblast == vitebskaya)
        {
            //Города
            ui->comboBox_10->clear();
            ui->comboBox_11->clear();
            ui->comboBox_10->addItem("",0);
            ui->comboBox_10->addItem("Витебск",1);
            ui->comboBox_10->addItem("Орша",2);
            ui->comboBox_10->addItem("Новополоцк",3);
            ui->comboBox_10->addItem("Полоцк",4);
            ui->comboBox_10->addItem("Поставы",5);
            ui->comboBox_10->addItem("Глубокое",6);
            ui->comboBox_10->addItem("Лепель",7);
            ui->comboBox_10->addItem("Новолукомль",8);
            ui->comboBox_10->addItem("Городок",9);
            ui->comboBox_10->addItem("Барань",10);
            ui->comboBox_10->addItem("Толочин",11);
            ui->comboBox_10->addItem("Браслав",12);
            ui->comboBox_10->addItem("Чашники",13);
            ui->comboBox_10->addItem("Миоры",14);
            ui->comboBox_10->addItem("Дубровно",15);
            ui->comboBox_10->addItem("Сенно",16);
            ui->comboBox_10->addItem("Верхнедвинск",17);
            ui->comboBox_10->addItem("Докшицы",18);
            ui->comboBox_10->addItem("Дисна",19);

            //Районы
            ui->comboBox_11->addItem("",0);
            ui->comboBox_11->addItem("Бешенковичский",1);
            ui->comboBox_11->addItem("Браславский",2);
            ui->comboBox_11->addItem("Верхнедвинский",3);
            ui->comboBox_11->addItem("Витебский",4);
            ui->comboBox_11->addItem("Витебск - Железнодорожный",5);
            ui->comboBox_11->addItem("Витебск - Первомайский",6);
            ui->comboBox_11->addItem("Витебск - Октябрьский",7);
            ui->comboBox_11->addItem("Глубокский",8);
            ui->comboBox_11->addItem("Городокский",9);
            ui->comboBox_11->addItem("Докшицкий",10);
            ui->comboBox_11->addItem("Дубровенский",11);
            ui->comboBox_11->addItem("Лепельский",12);
            ui->comboBox_11->addItem("Лиозненский",13);
            ui->comboBox_11->addItem("Миорский",14);
            ui->comboBox_11->addItem("Оршанский",15);
            ui->comboBox_11->addItem("Полоцкий",16);
            ui->comboBox_11->addItem("Поставский",17);
            ui->comboBox_11->addItem("Россонский",18);
            ui->comboBox_11->addItem("Сенненский",19);
            ui->comboBox_11->addItem("Толочинский",20);
            ui->comboBox_11->addItem("Ушачский",21);
            ui->comboBox_11->addItem("Чашникский",22);
            ui->comboBox_11->addItem("Шарковщинский",23);
            ui->comboBox_11->addItem("Шумилинский",24);
        }
        //Гомельская
        if(oblast == gomelskaya)
        {
            //Города
            ui->comboBox_10->clear();
            ui->comboBox_11->clear();
            ui->comboBox_10->addItem("",0);
            ui->comboBox_10->addItem("Гомель",1);
            ui->comboBox_10->addItem("Мозырь",2);
            ui->comboBox_10->addItem("Жлобин",3);
            ui->comboBox_10->addItem("Светлогорск",4);
            ui->comboBox_10->addItem("Речица",5);
            ui->comboBox_10->addItem("Калинковичи",6);
            ui->comboBox_10->addItem("Рогачёв",7);
            ui->comboBox_10->addItem("Добруш",8);
            ui->comboBox_10->addItem("Житковичи",9);
            ui->comboBox_10->addItem("Хойники",10);
            ui->comboBox_10->addItem("Петриков",11);
            ui->comboBox_10->addItem("Ельск",12);
            ui->comboBox_10->addItem("Буда-Кошелёво",13);
            ui->comboBox_10->addItem("Наровля",14);
            ui->comboBox_10->addItem("Ветка",15);
            ui->comboBox_10->addItem("Чечерск",16);
            ui->comboBox_10->addItem("Василевичи",17);
            ui->comboBox_10->addItem("Туров",18);

            //Районы
            ui->comboBox_11->addItem("",0);
            ui->comboBox_11->addItem("Брагинский",1);
            ui->comboBox_11->addItem("Буда-Кошелевский",2);
            ui->comboBox_11->addItem("Ветковский",3);
            ui->comboBox_11->addItem("Гомельский",4);
            ui->comboBox_11->addItem("Гомель - Новебелицкий",5);
            ui->comboBox_11->addItem("Гомель - Советский",6);
            ui->comboBox_11->addItem("Гомель - Центральный",7);
            ui->comboBox_11->addItem("Добрушский",8);
            ui->comboBox_11->addItem("Ельский",9);
            ui->comboBox_11->addItem("Житковичский",10);
            ui->comboBox_11->addItem("Жлобинский",11);
            ui->comboBox_11->addItem("Калинковичский",12);
            ui->comboBox_11->addItem("Кормянский",13);
            ui->comboBox_11->addItem("Лельчицкий",14);
            ui->comboBox_11->addItem("Лоевский",15);
            ui->comboBox_11->addItem("Мозырский",16);
            ui->comboBox_11->addItem("Наровлянский",17);
            ui->comboBox_11->addItem("Октябрьский",18);
            ui->comboBox_11->addItem("Петриковский",19);
            ui->comboBox_11->addItem("Речицкий",20);
            ui->comboBox_11->addItem("Рогачевский",21);
            ui->comboBox_11->addItem("Светлогорский",22);
            ui->comboBox_11->addItem("Хойникский",23);
            ui->comboBox_11->addItem("Чечерский",24);
        }
        //Гродненская
        if(oblast == grodnenskaya)
        {
            //Города
            ui->comboBox_10->clear();
            ui->comboBox_11->clear();
            ui->comboBox_10->addItem("",0);
            ui->comboBox_10->addItem("Гродно",1);
            ui->comboBox_10->addItem("Лида",2);
            ui->comboBox_10->addItem("Слоним",3);
            ui->comboBox_10->addItem("Волковыск",4);
            ui->comboBox_10->addItem("Сморгонь",5);
            ui->comboBox_10->addItem("Новогрудок",6);
            ui->comboBox_10->addItem("Мосты",7);
            ui->comboBox_10->addItem("Щучин",8);
            ui->comboBox_10->addItem("Ошмяны",9);
            ui->comboBox_10->addItem("Скидель",10);
            ui->comboBox_10->addItem("Берёзовка",11);
            ui->comboBox_10->addItem("Островец",12);
            ui->comboBox_10->addItem("Ивье",13);
            ui->comboBox_10->addItem("Дятлово",14);
            ui->comboBox_10->addItem("Свислочь",15);

            //Районы
            ui->comboBox_11->addItem("",0);
            ui->comboBox_11->addItem("Берестовицкий",1);
            ui->comboBox_11->addItem("Волковысский",2);
            ui->comboBox_11->addItem("Вороновский",3);
            ui->comboBox_11->addItem("Гродненский",4);
            ui->comboBox_11->addItem("Гродно - Ленинский",5);
            ui->comboBox_11->addItem("Гродно - Октябрьский",6);
            ui->comboBox_11->addItem("Дятловский",7);
            ui->comboBox_11->addItem("Зельвенский",8);
            ui->comboBox_11->addItem("Ивьевский",9);
            ui->comboBox_11->addItem("Кореличский",10);
            ui->comboBox_11->addItem("Лидский",11);
            ui->comboBox_11->addItem("Мостовский",12);
            ui->comboBox_11->addItem("Новогрудский",13);
            ui->comboBox_11->addItem("Островецкий",14);
            ui->comboBox_11->addItem("Ошмянский",15);
            ui->comboBox_11->addItem("Свислочский",16);
            ui->comboBox_11->addItem("Слонимский",17);
            ui->comboBox_11->addItem("Сморгонский",18);
            ui->comboBox_11->addItem("Щучинский",19);
        }
        //Минская
        if(oblast == minskaya)
        {
            //Города
            ui->comboBox_10->clear();
            ui->comboBox_11->clear();
            ui->comboBox_10->addItem("",0);
            ui->comboBox_10->addItem("Минск",1);
            ui->comboBox_10->addItem("Борисов",2);
            ui->comboBox_10->addItem("Солигорск",3);
            ui->comboBox_10->addItem("Молодечно",4);
            ui->comboBox_10->addItem("Жодино",5);
            ui->comboBox_10->addItem("Слуцк",6);
            ui->comboBox_10->addItem("Вилейка",7);
            ui->comboBox_10->addItem("Дзержинск",8);
            ui->comboBox_10->addItem("Марьина Горка",9);
            ui->comboBox_10->addItem("Столбцы",10);
            ui->comboBox_10->addItem("Смолевичи",11);
            ui->comboBox_10->addItem("Несвиж",12);
            ui->comboBox_10->addItem("Заславль",13);
            ui->comboBox_10->addItem("Фаниполь",14);
            ui->comboBox_10->addItem("Березино",15);
            ui->comboBox_10->addItem("Любань",16);
            ui->comboBox_10->addItem("Старые Дороги",17);
            ui->comboBox_10->addItem("Логойск",18);
            ui->comboBox_10->addItem("Клецк",19);
            ui->comboBox_10->addItem("Воложин",20);
            ui->comboBox_10->addItem("Узда",21);
            ui->comboBox_10->addItem("Червень",22);
            ui->comboBox_10->addItem("Копыль",23);
            ui->comboBox_10->addItem("Крупки",24);
            ui->comboBox_10->addItem("Мядель",25);

            //Районы
            ui->comboBox_11->addItem("",0);
            ui->comboBox_11->addItem("Березинский",1);
            ui->comboBox_11->addItem("Борисовский",2);
            ui->comboBox_11->addItem("Вилейский",3);
            ui->comboBox_11->addItem("Воложинский",4);
            ui->comboBox_11->addItem("Дзержинский",5);
            ui->comboBox_11->addItem("Клецкий",6);
            ui->comboBox_11->addItem("Копыльский",7);
            ui->comboBox_11->addItem("Крупский",8);
            ui->comboBox_11->addItem("Логойский",9);
            ui->comboBox_11->addItem("Любанский",10);
            ui->comboBox_11->addItem("Минский",11);
            ui->comboBox_11->addItem("Минск - Заводской",12);
            ui->comboBox_11->addItem("Минск - Ленинский",13);
            ui->comboBox_11->addItem("Минск - Московский",14);
            ui->comboBox_11->addItem("Минск - Октябрьский",15);
            ui->comboBox_11->addItem("Минск - Партизанский",16);
            ui->comboBox_11->addItem("Минск - Первомайский",17);
            ui->comboBox_11->addItem("Минск - Советский",18);
            ui->comboBox_11->addItem("Минск - Фрунзенский",19);
            ui->comboBox_11->addItem("Минск - Центральный",20);
            ui->comboBox_11->addItem("Молодечненский",21);
            ui->comboBox_11->addItem("Мядельский",22);
            ui->comboBox_11->addItem("Несвижский",23);
            ui->comboBox_11->addItem("Пуховичский",24);
            ui->comboBox_11->addItem("Слуцкий",25);
            ui->comboBox_11->addItem("Смолевичский",26);
            ui->comboBox_11->addItem("Солигорский",27);
            ui->comboBox_11->addItem("Стародорожский",28);
            ui->comboBox_11->addItem("Столбцовский",29);
            ui->comboBox_11->addItem("Узденский",30);
            ui->comboBox_11->addItem("Червенский",31);
        }
        //Могилевская
        if(oblast == mogilevskaya)
        {
            //Города
            ui->comboBox_10->clear();
            ui->comboBox_11->clear();
            ui->comboBox_10->addItem("",0);
            ui->comboBox_10->addItem("Могилёв",1);
            ui->comboBox_10->addItem("Бобруйск",2);
            ui->comboBox_10->addItem("Горки",3);
            ui->comboBox_10->addItem("Осиповичи",4);
            ui->comboBox_10->addItem("Кричев",5);
            ui->comboBox_10->addItem("Быхов",6);
            ui->comboBox_10->addItem("Климовичи",7);
            ui->comboBox_10->addItem("Шклов",8);
            ui->comboBox_10->addItem("Костюковичи",9);
            ui->comboBox_10->addItem("Чаусы",10);
            ui->comboBox_10->addItem("Мстиславль",11);
            ui->comboBox_10->addItem("Белыничи",12);
            ui->comboBox_10->addItem("Кировск",13);
            ui->comboBox_10->addItem("Чериков",14);
            ui->comboBox_10->addItem("Славгород",15);
            ui->comboBox_10->addItem("Круглое",16);
            ui->comboBox_10->addItem("Кличев",17);

            //Районы
            ui->comboBox_11->addItem("",0);
            ui->comboBox_11->addItem("Белыничский",1);
            ui->comboBox_11->addItem("Бобруйский",2);
            ui->comboBox_11->addItem("Бобруйск - Ленинский",3);
            ui->comboBox_11->addItem("Бобруйск - Первомайский",4);
            ui->comboBox_11->addItem("Быховский",5);
            ui->comboBox_11->addItem("Глусский",6);
            ui->comboBox_11->addItem("Горецкий",7);
            ui->comboBox_11->addItem("Дрибинский",8);
            ui->comboBox_11->addItem("Кировский",9);
            ui->comboBox_11->addItem("Климовичский",10);
            ui->comboBox_11->addItem("Кличевский",11);
            ui->comboBox_11->addItem("Костюковичский",12);
            ui->comboBox_11->addItem("Краснопольский",13);
            ui->comboBox_11->addItem("Кричевский",14);
            ui->comboBox_11->addItem("Круглянский",15);
            ui->comboBox_11->addItem("Могилевский",16);
            ui->comboBox_11->addItem("Могилев - Ленинский",17);
            ui->comboBox_11->addItem("Могилев - Октябрьский",18);
            ui->comboBox_11->addItem("Мстиславский",19);
            ui->comboBox_11->addItem("Осиповичский",20);
            ui->comboBox_11->addItem("Славгородский",21);
            ui->comboBox_11->addItem("Хотимский",22);
            ui->comboBox_11->addItem("Чаусский",23);
            ui->comboBox_11->addItem("Чериковский",24);
            ui->comboBox_11->addItem("Шкловский",25);
        }
}

//Добавление записис студента
void MainWindow::on_pushButton_7_clicked()
{
    //Подключаем БД
    QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);
    if(a == "1")
    {
        //Добавление записи
        mindb->addData(this->ui->comboBox->currentText(),this->ui->comboBox_2->currentText(),this->ui->comboBox_3->currentText(),this->ui->comboBox_4->currentText(),this->ui->lineEdit_10->text(), this->ui->comboBox_5->currentText(), this->ui->comboBox_6->currentText(), this->ui->comboBox_7->currentText(), this->ui->lineEdit->text(), this->ui->lineEdit_2->text(), this->ui->lineEdit_3->text(), this->ui->dateEdit->text(), this->ui->lineEdit_4->text(), this->ui->doubleSpinBox_2->text(), this->ui->comboBox_8->currentText() ,this->ui->lineEdit_6->text(), this->ui->comboBox_9->currentText(), this->ui->comboBox_10->currentText(), this->ui->comboBox_11->currentText(), this->ui->lineEdit_5->text(), this->ui->doubleSpinBox->text(), this->ui->comboBox_13->currentText(), this->ui->lineEdit_7->text(), this->ui->lineEdit_8->text(), this->ui->lineEdit_11->text(), this->ui->lineEdit_9->text(), "", this->ui->dateEdit_4->text(), "");

            //Отчистка полей
            this->ui->comboBox->clear();
            this->ui->comboBox->clear();
            this->ui->comboBox_2->clear();
            this->ui->comboBox_3->clear();
            this->ui->comboBox_4->clear();
            this->ui->lineEdit_10->clear();
            this->ui->comboBox_5->clear();
            this->ui->comboBox_6->clear();
            this->ui->comboBox_7->clear();
            this->ui->lineEdit->clear();
            this->ui->lineEdit_2->clear();
            this->ui->lineEdit_3->clear();
            this->ui->dateEdit->clear();
            this->ui->dateEdit_4->clear();
            this->ui->lineEdit_4->clear();
            this->ui->doubleSpinBox_2->clear();
            this->ui->comboBox_8->clear();
            this->ui->lineEdit_6->clear();
            this->ui->comboBox_9->clear();
            this->ui->comboBox_10->clear();
            this->ui->comboBox_11->clear();
            this->ui->lineEdit_5->clear();
            this->ui->doubleSpinBox->clear();
            this->ui->lineEdit_7->clear();
            this->ui->lineEdit_8->clear();
            this->ui->lineEdit_11->clear();
            this->ui->lineEdit_9->clear();
            this->ui->comboBox_13->clear();

        //Скрытие виджета добавления
        this->ui->AddStudent->hide();
        this->ui->tableView->show();
        this->ui->HorizontalWidget->show();

        //Отображение таблицы
        model = new QSqlTableModel(this,sdb);
        model->setTable("ycheniki");
        model->select();
        ui->tableView->setModel(model);
    }
}

//Добавление пустой строки
void MainWindow::on_DobaviStroku_clicked()
{
    //Добавление пустой строки в таблицу с учениками
    if(tablica == 1)
    {
        //Подключаем БД
        QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);
        if(a == "1")
        {
            //Добавление записи
            mindb->addData("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");

            //Скрытие виджета
            this->ui->Deystviya->hide();
            this->ui->FillWindow->hide();

            //Отображение таблицы
            model = new QSqlTableModel(this,sdb);
            model->setTable("ycheniki");
            model->select();
            ui->tableView->setModel(model);
        }
    }

    //Добавление пустой строки в таблицу в группами
    if(tablica == 2)
    {
        //Подключаем БД
        QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);
        if(a == "1")
        {
            //Добавление записи
            mindb->addDataGrup("","","","","");

            //Скрытие виджета
            this->ui->Deystviya->hide();
            this->ui->FillWindow->hide();

            //Отображение таблицы
            model = new QSqlTableModel(this,sdb);
            model->setTable("gruppy");
            model->select();
            ui->tableView->setModel(model);
        }
    }
}

//Отмена добавления группы
void MainWindow::on_pushButton_9_clicked()
{
    //Скрытие виджета добавления
    this->ui->AddGruppa->hide();
    this->ui->tableView->show();
    this->ui->HorizontalWidget->show();

    //Отчситка полей
    this->ui->lineEdit_12->clear();
    this->ui->lineEdit_13->clear();
    this->ui->lineEdit_14->clear();
    this->ui->lineEdit_15->clear();
    this->ui->lineEdit_16->clear();

    //Отображение таблицы
    model = new QSqlTableModel(this,sdb);
    model->setTable("gruppy");
    model->select();
    ui->tableView->setModel(model);
}

//Добавление данных группы
void MainWindow::on_pushButton_10_clicked()
{
    //Подключаем БД
    QString a =  mindb->database(this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit);
    if(a == "1")
    {
        mindb->addDataGrup(this->ui->lineEdit_12->text(), this->ui->lineEdit_13->text(), this->ui->lineEdit_14->text(), this->ui->lineEdit_15->text(), this->ui->lineEdit_16->text());

        //Скрытие виджета добавления
        this->ui->AddGruppa->hide();
        this->ui->tableView->show();
        this->ui->HorizontalWidget->show();

        //Отчситка полей
        this->ui->lineEdit_12->clear();
        this->ui->lineEdit_13->clear();
        this->ui->lineEdit_14->clear();
        this->ui->lineEdit_15->clear();
        this->ui->lineEdit_16->clear();

        //Отображение таблицы
        model = new QSqlTableModel(this,sdb);
        model->setTable("gruppy");
        model->select();
        ui->tableView->setModel(model);
    }
}

//Отчисление студента
void MainWindow::on_StudentButton_9_clicked()
{
    //Заполнение окна
    this->ui->FillWindow->show();
    this->ui->FillWindow->setStyleSheet("background-color: #212121; border-style: outset; border-width: 0px; border-radius: 10px;");
    this->ui->FillWindow->setGeometry(0,0,this->width(),this->height());

    //Скрытие виджета действий
    this->ui->Deystviya->hide();

    //Вызов виджета
    this->ui->Otchislenie->show();

    //Поднятие виджета на передний план
    this->ui->Otchislenie->raise();

    //Центрирование виджета
    mtdcls->centerWidget(this->width(), this->height(), this->ui->Otchislenie);
}

//Назад из отчисления
void MainWindow::on_NazadKNastroykam_4_clicked()
{
    //Отчистка полей
    this->ui->lineEdit_17->clear();
    this->ui->dateEdit_5->clear();

    //Скрытие элементов
    this->ui->Otchislenie->hide();
    this->ui->Deystviya->show();
    this->ui->Deystviya->raise();
}

//Отчисление студента
void MainWindow::on_StudentButton_10_clicked()
{
    //Удаление данных из таблицы учеников
    if(tablica == 1)
    {
        //Получение данных из колонок выделенной строки строки
        model = new QSqlTableModel(this,sdb);
        model->setTable("ycheniki");
        model->select();

                QString a1 = model->data(model->index(this->ui->tableView->currentIndex().row(), 1)).toString();
                QString a2 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 2)).toString();
                QString a3 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 3)).toString();
                QString a4 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 4)).toString();
                QString a5 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 5)).toString();
                QString a6 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 6)).toString();
                QString a7 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 7)).toString();
                QString a8 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 8)).toString();
                QString a9 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 9)).toString();
                QString a10 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 10)).toString();
                QString a11 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 11)).toString();
                QString a12 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 12)).toString();
                QString a13 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 13)).toString();
                QString a14 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 14)).toString();
                QString a15 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 15)).toString();
                QString a16 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 16)).toString();
                QString a17 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 17)).toString();
                QString a18 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 18)).toString();
                QString a19 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 19)).toString();
                QString a20 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 20)).toString();
                QString a21 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 21)).toString();
                QString a22 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 22)).toString();
                QString a23 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 23)).toString();
                QString a24 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 24)).toString();
                QString a25 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 25)).toString();
                QString a26 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 26)).toString();
                QString a28 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 28)).toString();

                //Удаление
                model = new QSqlTableModel(this,sdb);
                model->setTable("ycheniki");
                model->select();
                model->removeRow(this->ui->tableView->currentIndex().row());

                //Обновление таблицы
                model->submitAll();

                //Вставка данных
                mindb->addData(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26 + " Номер приказа:" + this->ui->lineEdit_17->text(), "Да", a28, this->ui->dateEdit_5->text());

                //Отображение данных
                model->select();
                this->ui->tableView->setModel(model);

                //Отчистка полей
                this->ui->lineEdit_17->clear();
                this->ui->dateEdit_5->clear();

        //Назад к программе
        this->ui->Otchislenie->hide();
        this->ui->FillWindow->hide();
    }
}

//Перевод студента
void MainWindow::on_StudentButton_8_clicked()
{
    //Заполнение полей данными из БД
    if(tablica == 1)
    {
        //Заполнение окна
        this->ui->FillWindow->show();
        this->ui->FillWindow->setStyleSheet("background-color: #212121; border-style: outset; border-width: 0px; border-radius: 10px;");
        this->ui->FillWindow->setGeometry(0,0,this->width(),this->height());

        //Скрытие виджета действий
        this->ui->Deystviya->hide();

        //Вызов виджета
        this->ui->Perevod->show();

        //Поднятие виджета на передний план
        this->ui->Perevod->raise();

        //Центрирование виджета
        this->ui->Perevod->setGeometry((this->width()*0.5)-325,(this->height()*0.5)-170,651,351);

        //Выбираем таблицу для модели
        modelSpecialnost();

        //Специальности
        QSqlQuery query("SELECT Specialnost FROM specialnost", sdb);
        if(query.isActive())
        {
           while(query.next())
            {
               this->ui->comboBox_12->addItem(query.value(0).toString());
            }
        }

        //Выбираем таблицу для модели
        modelForma();
        //Форма обучения
        QSqlQuery query3("SELECT Formaobuch FROM formaobuch", sdb);
        if(query3.isActive())
        {
           while(query3.next())
            {
               this->ui->comboBox_14->addItem(query3.value(0).toString());
            }
        }

        //Выбираем таблицу для модели
        modelKurs();
        //Курс
        QSqlQuery query5("SELECT Kurs FROM kurs", sdb);
        if(query5.isActive())
        {
           while(query5.next())
            {
               this->ui->comboBox_15->addItem(query5.value(0).toString());
            }
        }

        //Выбираем таблицу для модели
        modeelBudget();
        //Бюджет или комерч
        QSqlQuery query6("SELECT Budjet FROM budjet", sdb);
        if(query6.isActive())
        {
           while(query6.next())
            {
               this->ui->comboBox_16->addItem(query6.value(0).toString());
            }
        }

        //Получение данных из колонок выделенной строки строки
        model = new QSqlTableModel(this,sdb);
        model->setTable("ycheniki");
        model->select();

                QString a1 = model->data(model->index(this->ui->tableView->currentIndex().row(), 1)).toString();
                QString a2 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 2)).toString();
                QString a4 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 4)).toString();
                QString a5 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 5)).toString();
                QString a6 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 6)).toString();

                //Заполняем этими данными поля
                this->ui->lineEdit_20->setText(a1);
                this->ui->lineEdit_21->setText(a2);
                this->ui->lineEdit_22->setText(a4);
                this->ui->lineEdit_23->setText(a5);
                this->ui->lineEdit_24->setText(a6);
    }
}

//Назад из перевода
void MainWindow::on_NazadKNastroykam_5_clicked()
{
    //Отчистка полей
    this->ui->lineEdit_18->clear();
    this->ui->lineEdit_19->clear();
    this->ui->lineEdit_20->clear();
    this->ui->lineEdit_21->clear();
    this->ui->lineEdit_22->clear();
    this->ui->lineEdit_23->clear();
    this->ui->lineEdit_24->clear();
    this->ui->dateEdit_6->clear();
    this->ui->comboBox_12->clear();
    this->ui->comboBox_14->clear();
    this->ui->comboBox_15->clear();
    this->ui->comboBox_16->clear();

    //Скрытие виджета действий
    this->ui->Perevod->hide();

    //Вызов виджета
    this->ui->Deystviya->show();

    //Поднятие виджета на передний план
    this->ui->Deystviya->raise();
}

//Перевести студента
void MainWindow::on_StudentButton_11_clicked()
{
    //Удаление данных из таблицы учеников
    if(tablica == 1)
    {
        //Получение данных из колонок выделенной строки строки
        model = new QSqlTableModel(this,sdb);
        model->setTable("ycheniki");
        model->select();

                QString a3 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 3)).toString();
                QString a7 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 7)).toString();
                QString a8 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 8)).toString();
                QString a9 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 9)).toString();
                QString a10 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 10)).toString();
                QString a11 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 11)).toString();
                QString a12 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 12)).toString();
                QString a13 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 13)).toString();
                QString a14 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 14)).toString();
                QString a15 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 15)).toString();
                QString a16 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 16)).toString();
                QString a17 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 17)).toString();
                QString a18 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 18)).toString();
                QString a19 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 19)).toString();
                QString a20 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 20)).toString();
                QString a21 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 21)).toString();
                QString a22 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 22)).toString();
                QString a23 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 23)).toString();
                QString a24 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 24)).toString();
                QString a25 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 25)).toString();
                QString a26 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 26)).toString();
                QString a27 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 27)).toString();
                QString a28 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 28)).toString();
                QString a29 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 29)).toString();

                //Удаление
                model = new QSqlTableModel(this,sdb);
                model->setTable("ycheniki");
                model->select();
                model->removeRow(this->ui->tableView->currentIndex().row());

                //Обновление таблицы
                model->submitAll();

                //Вставка данных
                mindb->addData(this->ui->comboBox_12->currentText(),this->ui->comboBox_14->currentText(),a3,this->ui->comboBox_15->currentText(),this->ui->lineEdit_19->text(),this->ui->comboBox_16->currentText(),a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26 + "  |Номер приказа:" + this->ui->lineEdit_18->text() + "|" + "  Дата перевода:" + this->ui->dateEdit_6->text() + "|", a27, a28, a29);

                //Отображение данных
                model->select();
                this->ui->tableView->setModel(model);

                //Отчистка полей
                this->ui->lineEdit_18->clear();
                this->ui->lineEdit_19->clear();
                this->ui->lineEdit_20->clear();
                this->ui->lineEdit_21->clear();
                this->ui->lineEdit_22->clear();
                this->ui->lineEdit_23->clear();
                this->ui->lineEdit_24->clear();
                this->ui->dateEdit_6->clear();
                this->ui->comboBox_12->clear();
                this->ui->comboBox_14->clear();
                this->ui->comboBox_15->clear();
                this->ui->comboBox_16->clear();

        //Назад к программе
        this->ui->Otchislenie->hide();
        this->ui->FillWindow->hide();
    }
}

//Поиск
void MainWindow::on_lineEdit_25_textEdited(const QString &arg1)
{
    //Поиск по ученикам
    if(tablica == 1)
    {
        //Подключение к БД
            model = new QSqlTableModel(this,sdb);
            //Указываем таблицу
            model->setTable("ycheniki");
            model->select();
            QSortFilterProxyModel *proxy_model = new QSortFilterProxyModel();
            ui->tableView->setModel(proxy_model);
            proxy_model->setSourceModel(model);
            //Выбираем номер столбца для поиска, если же стоит значение -1, то будут выбранны все столбцы
            proxy_model->setFilterKeyColumn(-1);
            //Указываем значение для поиска, в нашем случае это переменная arg1
            proxy_model->setFilterFixedString(arg1);
    }

    //Поиск по группам
    if(tablica == 2)
    {
        //Подключение к БД
            model = new QSqlTableModel(this,sdb);
            //Указываем таблицу
            model->setTable("gruppy");
            model->select();
            QSortFilterProxyModel *proxy_model = new QSortFilterProxyModel();
            ui->tableView->setModel(proxy_model);
            proxy_model->setSourceModel(model);
            //Выбираем номер столбца для поиска, если же стоит значение -1, то будут выбранны все столбцы
            proxy_model->setFilterKeyColumn(-1);
            //Указываем значение для поиска, в нашем случае это переменная arg1
            proxy_model->setFilterFixedString(arg1);
    }
}

//Открытие формы для формирования документа
void MainWindow::on_StudentButton_12_clicked()
{
    if(tablica == 1)
    {
        this->ui->Deystviya->hide();

        this->ui->Prikazy->show();

        this->ui->Prikazy->raise();

        //Центрирование виджета
        mtdcls->centerWidget(this->width(), this->height(), this->ui->Prikazy);
    }
}

//Назад к действиям
void MainWindow::on_NazadIzNastroek_4_clicked()
{
    this->ui->Prikazy->hide();

    this->ui->Deystviya->show();

    this->ui->Deystviya->raise();
}

//Приказ об освобождении от занятий
void MainWindow::on_OneBtn_clicked()
{
    /*
    //Указываем имя или путь к файлу
    QFile File("prikaz/1.txt");

    //Открываем файл в режиме чтения
    File.open(QIODevice::ReadOnly);

    //Создаем входящий поток, из которого будут считываться данные, и связываем его с файлом
    QTextStream in(&File);

    //Считываем весь файл
    QString text = in.readAll();

    //Закрываем файл
    File.close();

    //Заменяем значения в тексте
    text.replace(QString("ou"), QString("o"));

    //Присваиваем текст из файла в переменную
    QString html = text;

    //Создаем файл из HTML
    QTextDocument document;
    document.setHtml(html);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("Готовые приказы/Приказ об освобождении от занятий.pdf");
    document.print(&printer);
    */
}

//Приказ об отчислении
void MainWindow::on_TwoBTN_clicked()
{
    //Указываем имя или путь к файлу
    QFile File("prikaz/2.txt");

    //Открываем файл в режиме чтения
    File.open(QIODevice::ReadOnly);

    //Создаем входящий поток, из которого будут считываться данные, и связываем его с файлом
    QTextStream in(&File);

    //Считываем весь файл
    QString text = in.readAll();

    //Закрываем файл
    File.close();

    //Получение данных из колонок выделенной строки строки
    model = new QSqlTableModel(this,sdb);
    model->setTable("ycheniki");
    model->select();

            QString a10 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 10)).toString();
            QString a11 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 11)).toString();
            QString a12 = model->data(this->model->index(this->ui->tableView->currentIndex().row(), 12)).toString();


    //Заменяем значения в тексте
    text.replace(QString("XXXXXX"), this->ui->dateEdit_5->text());
    text.replace(QString("XXXXX"), this->ui->lineEdit_17->text());
    text.replace(QString("XXXX"), a10+" "+a11+" "+a12);

    //Присваиваем текст из файла в переменную
    QString html = text;

    //Создаем файл из HTML
    QTextDocument document;
    document.setHtml(html);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("Готовые приказы/Приказ об отчислении.pdf");
    document.print(&printer);

    this->ui->Prikazy->hide();
    this->ui->FillWindow->hide();
}

//Приказ о том что студент обучается в УО
void MainWindow::on_ThreBtn_clicked()
{
    /*
    //Указываем имя или путь к файлу
    QFile File("prikaz/3.txt");

    //Открываем файл в режиме чтения
    File.open(QIODevice::ReadOnly);

    //Создаем входящий поток, из которого будут считываться данные, и связываем его с файлом
    QTextStream in(&File);

    //Считываем весь файл
    QString text = in.readAll();

    //Закрываем файл
    File.close();

    //Заменяем значения в тексте
    text.replace(QString("ou"), QString("o"));

    //Присваиваем текст из файла в переменную
    QString html = text;

    //Создаем файл из HTML
    QTextDocument document;
    document.setHtml(html);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("Готовые приказы/Приказ о том что студент обучается в УО.pdf");
    document.print(&printer);
    */
}

