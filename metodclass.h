#ifndef METODCLASS_H
#define METODCLASS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

//Библиотека для работы с кнопками
#include <QPushButton>

//Библиотека для работы с LineEdit
#include <QLineEdit>

//Библиотека для скругления окна
#include <QPainterPath>
#include <QRect>

//Библиотеки для размещения окна по центру при запуске
#include <QDesktopWidget>
#include <QPoint>
#include <QApplication>

//Библиотека для работы с мессэджбоксами
#include <QMessageBox>

//Библиотека для перетаскивания окна курсором мыши
#include <QMouseEvent>

//Библиотека для работы с tableView
#include <QTableView>

//Библиотека для работы с заблюриванием окна
#include <QGraphicsBlurEffect>

class metodClass
{

public:
    metodClass();

    //Метод для стилей кнопки
    void styleButton(QPushButton* button);

    //Метод для стилей LineEdit
    void styleLineEdit(QLineEdit* lineEdit);

    //Стиль кнопки с картинкой внутри
    void styleTransparentButton(QPushButton* button, const QString &str);

    //Скругление углов окна
    void skryglenie(QMainWindow* window);

    //Размещение окна по центру при запуске
    void centerScreen(QMainWindow* window);

    //Вызов окна с предупреждением перед закрытием окна
    void closeEvent(QMainWindow* window);

    //Вызов окна с предупреждением об ошибке подключения
    void connectError(QMainWindow* window);

    //Задает параметры окна
    void styleWindows(QMainWindow *window, qint32 x, qint32 y);

    //Задание стилей виджетов
    void stylePincodeWidget(QWidget *window, QPushButton *btn, QPushButton *transp, QLineEdit *lnedit);
    void styleAutorizationWidget(QWidget *window, QPushButton *enter, QLineEdit *login, QLineEdit *password, QPushButton *close, QPushButton *connct);
    void styleConnectionWidget(QWidget *window, QPushButton *connect, QLineEdit *Bdname, QLineEdit *host, QLineEdit *user, QLineEdit *pass, QPushButton *close, QPushButton *goToAut);

    //Скрытие виджетов входа
    void enterWidgetHide(QWidget *pin, QWidget *aut, QWidget *con);

    //Стиль таблицы
    void styleTableView(QTableView *table);

    //Стиль основного рабочего окна
    void styleWorkWindow();

    //Заблюривание окна
    void blurWindow(QMainWindow *window);

    //Отблюривание окна
    void unblurWindow(QMainWindow *window);

    //Скрытие виджета подключения
    void hideConnectWidget(QWidget *widget, QWidget *widget2);

    //Скрытие виджета пинкода
    void hidePincodeWidget(QWidget *widget, QWidget *widget2);

    //Открытие виджета подключения
    void showConnectWidget(QWidget *widget, QWidget *widget2);

    //Переход назад на виджет авторизации
    void goToAutWidget(QWidget *widget, QWidget *widget2);
};

#endif // METODCLASS_H
