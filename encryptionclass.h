#ifndef ENCRYPTIONCLASS_H
#define ENCRYPTIONCLASS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

//Библиотеки для работы с шифрованием
#include <iostream>
#include <vector>
#include <QLineEdit>

class encryptionClass
{
public:
    encryptionClass();

    //Зашифровка
    void encryptText(QLineEdit *encr);

    //Расшифровка
    void decryptText(QLineEdit *decr);

    //Переменная принимающая значения
    QString strTxt;
};

#endif // ENCRYPTIONCLASS_H
