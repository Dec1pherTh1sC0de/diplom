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
mtdcls->stylePincodeWidget(this->ui->PinCodeWidget,this->ui->EnterPinCodePushButton,this->ui->CloseButton,this->ui->PinCodeLineEdit);

//Задане стилей AutorizationWidget
mtdcls->styleAutorizationWidget(this->ui->AutorizationWidget,this->ui->EnterPushButton,this->ui->LoginLineEdit,this->ui->PasswordLineEdit,this->ui->CloseButton_3,this->ui->ConnectWidgetButton);

//Задане стилей ConnectionWidget
mtdcls->styleConnectionWidget(this->ui->ConnectionWidget,this->ui->ConnectBDButton,this->ui->BDNameEdit,this->ui->HostEdit,this->ui->UserNameEdit,this->ui->PasswEdit,this->ui->CloseButton_4,this->ui->GoToAutorizationWidget);

//Скрытие виджетов перед запуском и открытие виджета пинкода
mtdcls->hideFirstWidget(this->ui->AutorizationWidget,this->ui->ConnectionWidget);

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
    //Подключение к мини БД
    mindb->ccMiniDB();

    //Выбираем таблицу для модели
    modelPin();

    //Принимаем значение пинкода из БД и передаем его в переменную
    QString z = model->data(model->index(0, 1)).toString();

    //Проверяем пинкод
    if(encryptcls->checkPin(this->ui->PinCodeLineEdit->text(),keyPAS,z) == "1")
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

                //Задание стиля таблицы
                mtdcls->styleTableView(this->ui->tableView);

                //Скрытие виджетов входа
                mtdcls->enterWidgetHide(this->ui->PinCodeWidget, this->ui->AutorizationWidget, this->ui->ConnectionWidget);
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

