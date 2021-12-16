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
    QMessageBox::StandardButton questions = QMessageBox::information(window,"Выход","Вы действительно хотите выйти из программы?",QMessageBox::Yes | QMessageBox::No);
    if(questions ==QMessageBox::Yes)
    {
        QApplication::quit();
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
void metodClass::stylePincodeWidget(QWidget *window, QPushButton *btn, QPushButton *transp, QLineEdit *lnedit)
{
    window->setGeometry(0,0,341,241);

    //Изменения стиля кнопки входа
    styleButton(btn);

    //Изменение стилей LineEdit
    styleLineEdit(lnedit);

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    styleTransparentButton(transp, "icon/window-close-2.ico");
}

//Метод для задания стиля виджета авторизации
void metodClass::styleAutorizationWidget(QWidget *window, QPushButton *enter, QLineEdit *login, QLineEdit *password, QPushButton *close, QPushButton *connct)
{
    window->setGeometry(0,0,341,241);

    //Изменения стиля кнопки входа
    styleButton(enter);

    //Изменение стилей LineEdit
    styleLineEdit(login);
    styleLineEdit(password);

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    styleTransparentButton(close, "icon/window-close-2.ico");
    styleTransparentButton(connct, "icon/db.ico");
}

//Метод для задания стиля виджета подключения
void metodClass::styleConnectionWidget(QWidget *window, QPushButton *connect, QLineEdit *Bdname, QLineEdit *host, QLineEdit *user, QLineEdit *pass, QPushButton *close, QPushButton *goToAut)
{
    window->setGeometry(0,0,341,241);

    //Изменения стиля кнопки входа
    styleButton(connect);

    //Изменение стилей LineEdit
    styleLineEdit(Bdname);
    styleLineEdit(host);
    styleLineEdit(user);
    styleLineEdit(pass);

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    styleTransparentButton(close, "icon/window-close-2.ico");
    styleTransparentButton(goToAut, "icon/arrow-left.ico");
}

//Скрытие виджетов входа
void metodClass::enterWidgetHide(QWidget *pin, QWidget *aut, QWidget *con)
{
   pin->hide();
   aut->hide();
   con->hide();
}

//Стиль tableView
void metodClass::styleTableView(QTableView *table)
{
    table->setGeometry(0,0,400,400);

    //Установка цвета таблицы
    table->setStyleSheet("background-color: #FFFFFF;");
}
