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
