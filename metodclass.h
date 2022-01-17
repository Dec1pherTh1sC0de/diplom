#ifndef METODCLASS_H
#define METODCLASS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

//Библиотека для работы с кнопками
#include <QPushButton>

//Библиотека для работы с LineEdit
#include <QLineEdit>

//Библиотека для работы с комбобоксами
#include <QComboBox>

//Библиотека для работы со спинбоксами
#include <QDoubleSpinBox>

//Библиотека для работы с dateEdit
#include <QDateEdit>

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
    void stylePincodeWidget(QWidget *window, QPushButton *btn, QPushButton *transp, QPushButton *show, QLineEdit *lnedit, QPushButton *setting);
    void styleAutorizationWidget(QWidget *window, QPushButton *enter, QLineEdit *login, QLineEdit *password, QPushButton *close, QPushButton *connct, QPushButton *showPass);
    void styleConnectionWidget(QWidget *window, QPushButton *connect, QPushButton *connect2, QPushButton *refresh, QLineEdit *Bdname, QLineEdit *host, QLineEdit *user, QLineEdit *pass, QPushButton *close, QPushButton *goToAut);
    void styleBlockWindowWidget(QWidget *window, QPushButton *enter, QPushButton *showPass, QLineEdit *lineEdit);
    void changePinCode(QWidget *window,QPushButton *nazad, QPushButton *enter, QPushButton *showPass, QLineEdit *lineEdit, QPushButton *smenapina, QPushButton *nazad2);
    void horizontalWidget(QWidget *window, QPushButton *first, QPushButton *first1, QPushButton *first2, QLineEdit *line);
    void nastroyki(QWidget *window,QPushButton *nazad, QPushButton *button, QPushButton *button2, QPushButton *button3, QPushButton *button4);
    void changeAvtorization(QWidget *window, QPushButton *showPass, QPushButton *nazad, QPushButton *proverit, QPushButton *smenit, QLineEdit *login, QLineEdit *password);
    void showDataWidget(QWidget *window, QPushButton *stud, QPushButton *grup, QPushButton *konteng, QPushButton *nazad);
    void deystviyaWidget(QWidget *window, QPushButton *add, QPushButton *addpust, QPushButton *del, QPushButton *createotch, QPushButton *nazad, QPushButton *d, QPushButton *e);
    void addWidgetStyle(QWidget *window, QPushButton *nazad, QPushButton *addzapis, QLineEdit *familiya, QLineEdit *imya, QLineEdit *othcestvo, QLineEdit *passport, QLineEdit *adrespropiski, QLineEdit *telefon, QLineEdit *roditeli, QLineEdit *mestoraboty, QLineEdit *ligoty, QLineEdit *primechanie, QLineEdit *op, QComboBox *a, QComboBox *b, QComboBox *c,  QComboBox *d, QComboBox *e, QComboBox *f, QComboBox *g, QComboBox *h, QComboBox *i, QComboBox *j, QComboBox *k, QComboBox *l, QDateEdit *m,  QDateEdit *n, QDoubleSpinBox *o, QDoubleSpinBox *p);
    void styleOthicslit(QWidget *window, QDateEdit *date, QLineEdit *line, QPushButton *btn, QPushButton *nazad);
    void stylePerevod(QWidget *window, QDateEdit *date, QComboBox *spec, QComboBox *formobuch, QComboBox *kurs, QComboBox *budget, QLineEdit *grupp,QLineEdit *line, QLineEdit *a, QLineEdit *b, QLineEdit *c, QLineEdit *d, QLineEdit *e, QPushButton *perevod, QPushButton *nazad);
    void stylePrikazy(QWidget *window, QPushButton *a, QPushButton *b, QPushButton *c, QPushButton *nazad);

    //Скрытие виджетов входа
    void enterWidgetHide(QWidget *pin, QWidget *aut, QWidget *con);

    //Стиль таблицы
    void styleTableView(QTableView *table, qint32 x, qint32 y);

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

    //Скрытие виджетов перед запуском и открытие виджета пинкода
    void hideFirstWidget(QWidget *widget, QWidget *widget2, QWidget *widget3, QWidget *widget4, QWidget *widget5, QWidget *widget6, QWidget *widget7, QWidget *widget8);

    //Вызов окна неверного пина
    void pinError(QMainWindow *window);

    //Вызов окна неверного логина
    void loginError(QMainWindow *window);

    //Вызов окна неверного пароля
    void passError(QMainWindow *window);

    //Вызов окна ошибке при первоначальной смене пинкода
    void firstVhangePin(QMainWindow *window);

    //Вызов окна об удачной смене данных
    void successChangeData(QMainWindow *window);

    //Вызов окна заполните все поля
    void enterAllLineEdit(QMainWindow *window);

    //Вызов окна заполните поле
    void enterLineEdit(QMainWindow *window);

    //Метод показа пароля или пинкода
    void showPassPin(QLineEdit *lineEdit);

    //Метод спрятать пароль или пинкод
    void hidePassPin(QLineEdit *lineEdit);

    //Метод горизонтального виджета
    void gorizontalWidget(QWidget *window);

    //Метод показа виджета кнопок
    void buttonWinWidget(QMainWindow *window, QWidget *widget,QPushButton *block, QPushButton *svernut, QPushButton *razvernut, QPushButton *close);

    //Максимизация окна
    void maximizeWindow(QMainWindow *window);

    //Центрирование виджета
    void centerWidget(qint32 x, qint32 y, QWidget *widget);

    //Заблюривание виджета
    void blurWidget(QWidget *window);

    //Отблюривание виджета
    void unblurWidget(QWidget *window);

    //Стиль виджета добавления
    void styleAddWidget(QWidget *window, qint32 x, qint32 y);

    //Метод стиля комбобокса
    void styleCombobox(QComboBox *cmb);

    //Метод стиля dateEdit
    void styleDateEdit(QDateEdit *dte);

    //Метод стиля doubleSpinBox
    void styleDoubleSpin(QDoubleSpinBox *dsp);

    //Стиль виджета добавления группы
    void styleAddGruppa(QWidget *window, QPushButton *otmen, QPushButton *add, QLineEdit *gr, QLineEdit *kurator, QLineEdit *number, QLineEdit *star, QLineEdit *numstar);

};

#endif // METODCLASS_H
