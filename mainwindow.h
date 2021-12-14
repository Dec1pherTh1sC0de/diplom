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

//Библиотека для работы с кнопками
#include <QPushButton>

//Библиотека для работы с LineEdit
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

//Создаем методы и объявляем переменные для перетаскивания окна мышкой
//--------------------------------------------
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
private:
    QPoint mLastMousePosition;
    bool mMoving;
//--------------------------------------------

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    Ui::MainWindow *ui;

    //Стиль кнопок
    void styleButton(QPushButton* button);

    //Стиль кнопки с картинкой внутри
    void styleTransparentButton(QPushButton* button, const QString &str);

    //Стиль LineEdit
    void styleLineEdit(QLineEdit* lineEdit);

    //Создаем и подключаем объекты для работы с БД
    QSqlDatabase sdb;
    QSqlQuery *query;
    QSqlTableModel *model;
private slots:

    void on_ConnectBDButton_clicked();
    void on_EnterPinCodePushButton_clicked();
};
#endif // MAINWINDOW_H
