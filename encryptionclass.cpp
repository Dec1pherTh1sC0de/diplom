#include "encryptionclass.h"

encryptionClass::encryptionClass()
{

}

//Метод шифрования
std::string encrypt(std::string input) {
    std::vector<char> word(input.begin(), input.end());
    std::string alphabet = "zabcdefghijklmnopqrstuvwxyz";
    for (int i = 1; i < (int)input.length(); i++) {
        for (int j = 1; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j + 1) % 26];
                break;
            }
        }
    }
    std::string str(word.begin(), word.end());
    return str;
}

//Метод дешифрования
std::string decrypt(std::string input) {
    std::vector<char> word(input.begin(), input.end());
    std::string alphabet = "zabcdefghijklmnopqrstuvwxyz";
    for (int i = 1; i < (int)input.length(); i++) {
        for (int j = 1; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j - 1) % 26];
                break;
            }
        }
    }
    std::string str(word.begin(), word.end());
    return str;
}

//Метод шифрования текста из LineEdit
void encryptionClass::encryptText(QLineEdit *encr)
{
    QString text = encr->text();
    //Конвертируем текст из QString в String
    std::string convText = text.toStdString();
    //Шифруем конвертируемый текст
    std::string encryptText = encrypt(convText);
    //Конвертируем зашифрованный текст обратно в QString
    strTxt = QString::fromStdString(encryptText);

}

//Метод дешифрования текста из LineEdit
void encryptionClass::decryptText(QLineEdit *decr)
{
    QString text = decr->text();
    //Конвертируем текст из QString в String
    std::string convText = text.toStdString();
    //Дешифруем конвертируемый текст
    std::string encryptText = decrypt(convText);
    //Конвертируем дешифрованный текст обратно в QString
    strTxt = QString::fromStdString(encryptText);
}
