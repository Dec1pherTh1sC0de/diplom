#include "metodclass.h"

metodClass::metodClass()
{

}

//Метод для задания стиля кнопке
void metodClass::styleButton(QPushButton *button)
{
    button->setStyleSheet
            (
                "QPushButton{background-color: #00CED7; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px; min-width: 10em;}"
                "QPushButton:hover{background: #6BF4FF; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px; min-width: 10em;}"
                "QPushButton:pressed{background-color: #00ADB5; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px; min-width: 10em;}"
                "QPushButton:released{background-color: #00CED7; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px; min-width: 10em;}"
            );
}

//Метод для задания стиля lineEdit
void metodClass::styleLineEdit(QLineEdit *lineEdit)
{
    lineEdit->setStyleSheet("background-color: #EEEEEE; border-style: outset; border-width: 0px; border-radius: 5px; border-color: beige; font: 12px; min-width: 10em;");
}

//Метод для задания прозрачной кнопки с картинкой
void metodClass::styleTransparentButton(QPushButton *button, const QString &str)
{
    //Установка вида курсора
    button->setCursor(QCursor(Qt::PointingHandCursor));


    button->setStyleSheet
            (
                "QPushButton{border : 0; border-radius: 20px; padding: 5px; background: transparent;}"
                "QPushButton:hover{border : 0; background: #484D54; border-radius: 20px; padding: 5px;}"
                "QPushButton:pressed{background: transparent; border : 0; border-radius: 20px; padding: 5px;}"
                "QPushButton:released{background: transparent; border : 0; border-radius: 20px; padding: 5px;}"
            );

    //Установка картинки в кнопку
    QPixmap pixmap = str;
    QIcon ButtonIcon(pixmap);
    button->setIcon(ButtonIcon);
    button->setIconSize(pixmap.rect().size());
    button->resize(48,48);
    button->setText(NULL);

}

//Метод для скругления краев окна
void metodClass::skryglenie(QMainWindow *window)
{
    //Скругление краев окна
    QPainterPath painPath;
    painPath.addRoundedRect(window->rect(), 10, 10, Qt::AbsoluteSize);
    window->setMask(painPath.toFillPolygon().toPolygon());
}

//Метод для размещения окна по центру при запуске
void metodClass::centerScreen(QMainWindow *window)
{
    QRect desktopRect = QApplication::desktop()->availableGeometry(window);
    QPoint center = desktopRect.center();
    window->move(center.x()-window->width()*0.5, center.y()-window->height()*0.5);
}

//Вызов диалога при закрытии формы на крестик
void metodClass::closeEvent(QMainWindow *window)
{
    //Заблюривание окна
    blurWindow(window);

    QMessageBox::StandardButton questions = QMessageBox::information(window,"Выход","Вы действительно хотите выйти из программы?",QMessageBox::Yes | QMessageBox::No);
    if(questions ==QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
        //Отблюривание окна
        unblurWindow(window);
    }
}

//Вызов окна с предупреждением об ошибке подключения
void metodClass::connectError(QMainWindow *window)
{
    //Заблюривание окна
    blurWindow(window);

    QMessageBox::StandardButton information = QMessageBox::information(window,"Ошибка","Проверьте подключение",QMessageBox::Ok);
    if(information == QMessageBox::Ok)
    {
        //Отблюривание окна
        unblurWindow(window);
    }
}

//Метод для задания параметров окна
void metodClass::styleWindows(QMainWindow *window, qint32 x,  qint32 y)
{
        //Изменение размеров окна
        window->resize(x,y);

        //Скругление краев окна
        skryglenie(window);

        //Установка цвета окна
        window->setStyleSheet("background-color: #393E46;");

        //Запрет на изменение размеров окна и установка дефолтных размеров
        //window->setFixedSize(QSize(x, y));

        //Скрывает заголовок окна
        window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

        //Размещение окна по центру при запуске
        centerScreen(window);
}

//Метод для задания стиля виджета пинкода
void metodClass::stylePincodeWidget(QWidget *window, QPushButton *btn, QPushButton *transp, QPushButton *show, QLineEdit *lnedit)
{
    window->setGeometry(0,0,341,241);

    //Изменения стиля кнопки входа
    styleButton(btn);

    //Изменение стилей LineEdit
    styleLineEdit(lnedit);

    //Стиль ввода пароля
    lnedit->setEchoMode(QLineEdit::Password);

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    styleTransparentButton(transp, "icon/window-close-2.ico");
    styleTransparentButton(show,"icon/document-encrypt-2.ico");

}

//Метод для задания стиля виджета авторизации
void metodClass::styleAutorizationWidget(QWidget *window, QPushButton *enter, QLineEdit *login, QLineEdit *password, QPushButton *close, QPushButton *connct, QPushButton *showPass)
{
    window->setGeometry(0,0,341,241);

    //Изменения стиля кнопки входа
    styleButton(enter);

    //Изменение стилей LineEdit
    styleLineEdit(login);
    styleLineEdit(password);

    //Стиль ввода пароля
    password->setEchoMode(QLineEdit::Password);

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    styleTransparentButton(close, "icon/window-close-2.ico");
    styleTransparentButton(connct, "icon/db.ico");
    styleTransparentButton(showPass,"icon/document-encrypt-2.ico");
}

//Метод для задания стиля виджета подключения
void metodClass::styleConnectionWidget(QWidget *window, QPushButton *connect, QPushButton *connect2, QPushButton *refresh, QLineEdit *Bdname, QLineEdit *host, QLineEdit *user, QLineEdit *pass, QPushButton *close, QPushButton *goToAut)
{
    window->setGeometry(0,0,341,241);

    //Изменения стиля кнопки входа
    styleButton(connect);
    styleButton(connect2);

    //Изменение стилей LineEdit
    styleLineEdit(Bdname);
    styleLineEdit(host);
    styleLineEdit(user);
    styleLineEdit(pass);

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    styleTransparentButton(close, "icon/window-close-2.ico");
    styleTransparentButton(goToAut, "icon/arrow-left.ico");
    styleTransparentButton(refresh,"icon/view-refresh-5.ico");
}

//Скрытие виджетов входа
void metodClass::enterWidgetHide(QWidget *pin, QWidget *aut, QWidget *con)
{
   pin->hide();
   aut->hide();
   con->hide();
}

//Стиль tableView
void metodClass::styleTableView(QTableView *table, qint32 x, qint32 y)
{
    table->setGeometry(10,53,x -20,y -62);

    //Установка цвета таблицы и заголовков таблицы
    table->setStyleSheet(
                "QTableView{border : 0; border-radius: 10px; padding: 5px; background: transparent; background-color: #FFFFFF;}"
                "QHeaderView{background-color: #FFFFFF}"
                        );
}

//Заблюривание окна
void metodClass::blurWindow(QMainWindow *window)
{
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(2);
    window->setGraphicsEffect(blur);
}

//Отблюривание окна
void metodClass::unblurWindow(QMainWindow *window)
{
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(0);
    window->setGraphicsEffect(blur);
}

//Скрытие виджета подключения
void metodClass::hideConnectWidget(QWidget *widget, QWidget *widget2)
{
    widget->hide();
    widget2->show();
}

//Скрытие виджета пинкода
void metodClass::hidePincodeWidget(QWidget *widget, QWidget *widget2)
{
    widget->hide();
    widget2->show();
}

//Открытие виджета подключения
void metodClass::showConnectWidget(QWidget *widget, QWidget *widget2)
{
    widget->show();
    widget2->hide();
}

//Переход назад на виджет авторизации
void metodClass::goToAutWidget(QWidget *widget, QWidget *widget2)
{
    widget->hide();
    widget2->show();
}

//Скрытие виджетов перед запуском и открытие виджета пинкода
void metodClass::hideFirstWidget(QWidget *widget, QWidget *widget2)
{
    widget->hide();
    widget2->hide();
}

 //Вызов окна неверного пароля
void metodClass::pinError(QMainWindow *window)
{
    //Заблюривание окна
    blurWindow(window);

    QMessageBox::StandardButton information = QMessageBox::information(window,"Ошибка","Неверный пинкод",QMessageBox::Ok);
    if(information == QMessageBox::Ok)
    {
        //Отблюривание окна
        unblurWindow(window);
    }
}

 //Вызов окна неверного логина
void metodClass::loginError(QMainWindow *window)
{
    //Заблюривание окна
    blurWindow(window);

    QMessageBox::StandardButton information = QMessageBox::information(window,"Ошибка","Неверный логин",QMessageBox::Ok);
    if(information == QMessageBox::Ok)
    {
        //Отблюривание окна
        unblurWindow(window);
    }
}

//Вызов окна неверного пароля
void metodClass::passError(QMainWindow *window)
{
    //Заблюривание окна
    blurWindow(window);

    QMessageBox::StandardButton information = QMessageBox::information(window,"Ошибка","Неверный пароль",QMessageBox::Ok);
    if(information == QMessageBox::Ok)
    {
        //Отблюривание окна
        unblurWindow(window);
    }
}

//Вызов окна об удачной смене данных
void metodClass::successChangeData(QMainWindow *window)
{
    //Заблюривание окна
    blurWindow(window);

    QMessageBox::StandardButton information = QMessageBox::information(window,"Успех","Данные подключения изменены и сохранены",QMessageBox::Ok);
    if(information == QMessageBox::Ok)
    {
        //Отблюривание окна
        unblurWindow(window);
    }
}

//Вызов окна заполните все поля
void metodClass::enterAllLineEdit(QMainWindow *window)
{
    //Заблюривание окна
    blurWindow(window);

    QMessageBox::StandardButton information = QMessageBox::information(window,"Внимание","Заполните все поля",QMessageBox::Ok);
    if(information == QMessageBox::Ok)
    {
        //Отблюривание окна
        unblurWindow(window);
    }
}

//Метод показа пароля или пинкода
void metodClass::showPassPin(QLineEdit *lineEdit)
{
    //Стиль ввода пароля
    lineEdit->setEchoMode(QLineEdit::Normal);
}

//Метод спрятать пароль или пинкод
void metodClass::hidePassPin(QLineEdit *lineEdit)
{
    //Стиль ввода пароля
    lineEdit->setEchoMode(QLineEdit::Password);
}

//Метод горизонтального виджета
void metodClass::gorizontalWidget(QWidget *window)
{

    //Задание размещения виджета
    window->setGeometry(10,0,680,51);
}

//Метод показа виджета кнопок
void metodClass::buttonWinWidget(QMainWindow *window, QWidget *widget, QPushButton *block, QPushButton *svernut, QPushButton *razvernut, QPushButton *close)
{
    //Получение ширины окна
    qint32 winWidth = window->width();

    //Задание геометрии виджета
    widget->setGeometry(winWidth - 201,0,201,51);

    //Показать виджет
    widget->show();

    //Применение стия кнопки блкировки формы, а так же передача пути картинки в метод
    styleTransparentButton(block,"icon/document-encrypt-3.ico");

    //Применение стия кнопки свернуть, а так же передача пути картинки в метод
    styleTransparentButton(svernut,"icon/arrow-down.ico");

    //Применение стия кнопки развернуть, а так же передача пути картинки в метод
    styleTransparentButton(razvernut,"icon/arrow-up.ico");

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    styleTransparentButton(close, "icon/window-close-2.ico");
}

//Максимизация окна
void metodClass::maximizeWindow(QMainWindow *window)
{
   //Получение размеров экрана
   QRect desktopRect1 = QApplication::desktop()->availableGeometry(window);

   //Изменение размеров окна
   window->resize(desktopRect1.width(),desktopRect1.height());

   //Скругление краев окна
   skryglenie(window);

   //Установка цвета окна
   window->setStyleSheet("background-color: #393E46;");

   //Запрет на изменение размеров окна и установка дефолтных размеров
   //window->setFixedSize(QSize(x, y));

   //Скрывает заголовок окна
   window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

   //Размещение окна по центру при запуске
   centerScreen(window);

}
