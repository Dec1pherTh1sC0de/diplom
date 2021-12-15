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
};

#endif // METODCLASS_H
