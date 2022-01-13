#include "metodclass.h"

metodClass::metodClass()
{

}

//Метод для задания стиля кнопке
void metodClass::styleButton(QPushButton *button)
{
    button->setStyleSheet
            (
                "QPushButton{background-color: #00CED7; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px;}"
                "QPushButton:hover{background: #6BF4FF; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px;}"
                "QPushButton:pressed{background-color: #00ADB5; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px;}"
                "QPushButton:released{background-color: #00CED7; border-style: outset; border-width: 0px; border-radius: 10px; border-color: beige; font: bold 12px;}"
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
void metodClass::stylePincodeWidget(QWidget *window, QPushButton *btn, QPushButton *transp, QPushButton *show, QLineEdit *lnedit, QPushButton *setting)
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
    styleTransparentButton(setting, "icon/run-build-2.ico");

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

//Задание стиля виджета блокировки окна
void metodClass::styleBlockWindowWidget(QWidget *window, QPushButton *enter, QPushButton *showPass, QLineEdit *lineEdit)
{
    window->setGeometry(0,0,341,241);

    window->setStyleSheet("background-color: #393E46; border-style: outset; border-width: 0px; border-radius: 10px;");

    //Изменения стиля кнопки входа
    styleButton(enter);

    //Изменение стилей LineEdit
    styleLineEdit(lineEdit);

    //Установка парольных символов для лайнедита
    hidePassPin(lineEdit);

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    styleTransparentButton(showPass, "icon/document-encrypt-2.ico");
}

//Метод смены пинкода
void metodClass::changePinCode(QWidget *window, QPushButton *nazad, QPushButton *enter, QPushButton *showPass, QLineEdit *lineEdit, QPushButton *smenapina, QPushButton *nazad2)
{
    window->setGeometry(0,0,341,241);

    window->setStyleSheet("background-color: #393E46; border-style: outset; border-width: 0px; border-radius: 10px;");

    //Изменения стиля кнопки входа
    styleButton(enter);
    styleButton(smenapina);

    //Изменение стилей LineEdit
    styleLineEdit(lineEdit);

    //Установка парольных символов для лайнедита
    hidePassPin(lineEdit);

    //Применение стиля кнопки закратия, а так же передача пути картинки в метод
    styleTransparentButton(showPass, "icon/document-encrypt-2.ico");

    //Применение стиля кнопки назад
    styleTransparentButton(nazad, "icon/arrow-left.ico");
    styleTransparentButton(nazad2, "icon/arrow-left.ico");
}

//Стиль горизонтального виджета
void metodClass::horizontalWidget(QWidget *window, QPushButton *first, QPushButton *first1, QPushButton *first2, QLineEdit *line)
{
    //Задание размеров виджета
     window->setGeometry(0,0,681,51);

     //Изменения стиля кнопки
     styleButton(first);
     styleButton(first1);
     styleButton(first2);

     //Изменение стилей LineEdit
     styleLineEdit(line);
}

//Задание стиля виджета настроек
void metodClass::nastroyki(QWidget *window, QPushButton *nazad, QPushButton *button, QPushButton *button2, QPushButton *button3, QPushButton *button4)
{
    window->setGeometry(0,0,341,241);

    window->setStyleSheet("background-color: #393E46; border-style: outset; border-width: 0px; border-radius: 10px;");

    //Изменения стиля кнопки входа
    styleButton(button);
    styleButton(button2);
    styleButton(button3);
    styleButton(button4);

    //Применение стиля кнопки назад
    styleTransparentButton(nazad, "icon/arrow-left.ico");
}

//Задание стиля виджета смены авторизационных данных
void metodClass::changeAvtorization(QWidget *window, QPushButton *showPass, QPushButton *nazad, QPushButton *proverit, QPushButton *smenit, QLineEdit *login, QLineEdit *password)
{
    window->setGeometry(0,0,341,241);

    window->setStyleSheet("background-color: #393E46; border-style: outset; border-width: 0px; border-radius: 10px;");

    //Изменения стиля кнопки входа
    styleButton(proverit);
    styleButton(smenit);

    //Изменение стилей LineEdit
    styleLineEdit(login);
    styleLineEdit(password);

    //Применение стиля кнопки назад
    styleTransparentButton(nazad, "icon/arrow-left.ico");

    //Применение стиля кнопки назад, а так же передача пути картинки в метод
    styleTransparentButton(showPass, "icon/document-encrypt-2.ico");
}

//Виджет показа БД
void metodClass::showDataWidget(QWidget *window, QPushButton *stud, QPushButton *grup, QPushButton *konteng, QPushButton *nazad)
{
    window->setGeometry(0,0,341,241);

    window->setStyleSheet("background-color: #393E46; border-style: outset; border-width: 0px; border-radius: 10px;");

    //Изменения стиля кнопки входа
    styleButton(stud);
    styleButton(grup);
    styleButton(konteng);

    //Применение стиля кнопки назад
    styleTransparentButton(nazad, "icon/arrow-left.ico");
}

//Метод стиля действий
void metodClass::deystviyaWidget(QWidget *window, QPushButton *add, QPushButton *addpust, QPushButton *del, QPushButton *createotch, QPushButton *nazad, QPushButton *d)
{
    window->setGeometry(0,0,341,341);

    window->setStyleSheet("background-color: #393E46; border-style: outset; border-width: 0px; border-radius: 10px;");

    //Изменения стиля кнопки входа
    styleButton(add);
    styleButton(addpust);
    styleButton(del);
    styleButton(createotch);
    styleButton(d);

    //Применение стиля кнопки назад
    styleTransparentButton(nazad, "icon/arrow-left.ico");
}

//Стиль виджета добавления студента
void metodClass::addWidgetStyle(QWidget *window, QPushButton *nazad, QPushButton *addzapis, QLineEdit *familiya, QLineEdit *imya, QLineEdit *othcestvo, QLineEdit *passport, QLineEdit *adrespropiski, QLineEdit *telefon, QLineEdit *roditeli, QLineEdit *mestoraboty, QLineEdit *ligoty, QLineEdit *primechanie, QLineEdit *op, QComboBox *a, QComboBox *b, QComboBox *c,  QComboBox *d, QComboBox *e, QComboBox *f, QComboBox *g, QComboBox *h, QComboBox *i, QComboBox *j, QComboBox *k, QComboBox *l, QDateEdit *m,  QDateEdit *n, QDoubleSpinBox *o, QDoubleSpinBox *p)
{
    window->setStyleSheet("background-color: #393E46; border-style: outset; border-width: 0px; border-radius: 10px;");

    //Изменения стиля кнопок
    styleButton(nazad);
    styleButton(addzapis);

    //Изменение стилей LineEdit
    styleLineEdit(familiya);
    styleLineEdit(imya);
    styleLineEdit(othcestvo);
    styleLineEdit(passport);
    styleLineEdit(adrespropiski);
    styleLineEdit(telefon);
    styleLineEdit(roditeli);
    styleLineEdit(mestoraboty);
    styleLineEdit(ligoty);
    styleLineEdit(primechanie);
    styleLineEdit(op);

    //Изменение стилей комбобокса
    styleCombobox(a);
    styleCombobox(b);
    styleCombobox(c);
    styleCombobox(d);
    styleCombobox(e);
    styleCombobox(f);
    styleCombobox(g);
    styleCombobox(h);
    styleCombobox(i);
    styleCombobox(j);
    styleCombobox(k);
    styleCombobox(l);

    //Изменение стиля dateEdit
    styleDateEdit(m);
    styleDateEdit(n);

    //Изменение стиля doubleSpin
    styleDoubleSpin(o);
    styleDoubleSpin(p);

}

//Стиль виджета отчисления студента
void metodClass::styleOthicslit(QWidget *window, QDateEdit *date, QLineEdit *line, QPushButton *btn, QPushButton *nazad)
{
    window->setGeometry(0,0,341,341);

    window->setStyleSheet("background-color: #393E46; border-style: outset; border-width: 0px; border-radius: 10px;");

    //Изменения стиля кнопки входа
    styleButton(btn);

    //Изменение стиля lineEdit
    styleLineEdit(line);

    //Изменение стиля DateEdit
    styleDateEdit(date);

    //Применение стиля кнопки назад
    styleTransparentButton(nazad, "icon/arrow-left.ico");
}

//Стиль виджета перевода студента
void metodClass::stylePerevod(QWidget *window, QDateEdit *date, QComboBox *spec, QComboBox *formobuch, QComboBox *kurs, QComboBox *budget, QLineEdit *grupp,QLineEdit *line, QLineEdit *a, QLineEdit *b, QLineEdit *c, QLineEdit *d, QLineEdit *e, QPushButton *perevod, QPushButton *nazad)
{
    window->setStyleSheet("background-color: #393E46; border-style: outset; border-width: 0px; border-radius: 10px;");

    //Изменения стиля кнопки
    styleButton(perevod);

    //Применение стиля кнопки назад
    styleTransparentButton(nazad, "icon/arrow-left.ico");

    //Изменение стиля lineEdit
    styleLineEdit(line);
    styleLineEdit(grupp);
    styleLineEdit(a);
    styleLineEdit(b);
    styleLineEdit(c);
    styleLineEdit(d);
    styleLineEdit(e);

    //Изменение стиля комбобокс
    styleCombobox(spec);
    styleCombobox(formobuch);
    styleCombobox(kurs);
    styleCombobox(budget);

    //Изменение стиля dateEdit
    styleDateEdit(date);
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
void metodClass::hideFirstWidget(QWidget *widget, QWidget *widget2, QWidget *widget3, QWidget *widget4, QWidget *widget5, QWidget *widget6, QWidget *widget7, QWidget *widget8)
{
    widget->hide();
    widget2->hide();
    widget3->hide();
    widget4->hide();
    widget5->hide();
    widget6->hide();
    widget7->hide();
    widget8->hide();
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

//Вызов окна ошибке при первоначальной смене пинкода
void metodClass::firstVhangePin(QMainWindow *window)
{
    //Заблюривание окна
    blurWindow(window);

    QMessageBox::StandardButton information = QMessageBox::information(window,"Ошибка","Введите пинкод прежде чем нажать на кнопку настроек",QMessageBox::Ok);
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

    QMessageBox::StandardButton information = QMessageBox::information(window,"Успех","Данные изменены и сохранены",QMessageBox::Ok);
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

//Вызов окна заполните поле
void metodClass::enterLineEdit(QMainWindow *window)
{
    //Заблюривание окна
    blurWindow(window);

    QMessageBox::StandardButton information = QMessageBox::information(window,"Внимание","Заполните поле",QMessageBox::Ok);
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
    window->setGeometry(10,0,551,51);
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

//Центрирование виджета
void metodClass::centerWidget(qint32 x, qint32 y, QWidget *widget)
{
    widget->setGeometry((x*0.5)-170.5,(y*0.5)-120.5,341,241);
}

//Заблюривание виджета
void metodClass::blurWidget(QWidget *window)
{
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(2);
    window->setGraphicsEffect(blur);
}

//Отблюривание виджета
void metodClass::unblurWidget(QWidget *window)
{
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(0);
    window->setGraphicsEffect(blur);
}

//Стиль виджета добавления
void metodClass::styleAddWidget(QWidget *window, qint32 x, qint32 y)
{
    window->setGeometry(10,53,x -20,y -62);
}

//Метод стиля комбобокса
void metodClass::styleCombobox(QComboBox *cmb)
{
    cmb->setStyleSheet
            (
                "QComboBox{background-color: #EEEEEE; border-style: outset; border-width: 0px; border-radius: 0px; border-color: beige; font: 12px;}"
            );
}

//Метод стиля dateEdit
void metodClass::styleDateEdit(QDateEdit *dte)
{
    dte->setStyleSheet
            (
                "QDateEdit{background-color: #EEEEEE; border-style: outset; border-width: 0px; border-radius: 0px; border-color: beige; font: 12px;}"
            );
}

//Метод стиля doubleSpinBox
void metodClass::styleDoubleSpin(QDoubleSpinBox *dsp)
{
    dsp->setStyleSheet
            (
                "QDoubleSpinBox{background-color: #EEEEEE; border-style: outset; border-width: 0px; border-radius: 0px; border-color: beige; font: 12px;}"
            );
}

//Виджет добавления группы
void metodClass::styleAddGruppa(QWidget *window, QPushButton *otmen, QPushButton *add, QLineEdit *gr, QLineEdit *kurator, QLineEdit *number, QLineEdit *star, QLineEdit *numstar)
{
    window->setGeometry(0,0,341,241);

    window->setStyleSheet("background-color: #393E46; border-style: outset; border-width: 0px; border-radius: 10px;");

    //Изменения стиля кнопок
    styleButton(otmen);
    styleButton(add);

    //Изменение стилей LineEdit
    styleLineEdit(gr);
    styleLineEdit(kurator);
    styleLineEdit(number);
    styleLineEdit(star);
    styleLineEdit(numstar);
}
