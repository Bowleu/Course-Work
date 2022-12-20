#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
using namespace std;
void setTextColor(int textColorIndex);
bool isRestartNeeded(){ // Функция перезапуска программы
    cin.clear(); // Очистка ввода от ошибок
    cin.sync();
    cout << "Перезагрузить программу? [";
    setTextColor(2);
    cout << "Y";
    setTextColor(15);
    cout << "/";
    setTextColor(4);
    cout << "любой другой символ";
    setTextColor(15);
    cout << "] ";
    string answer;
    cin >> answer;
    if (answer == "y" || answer == "Y")
        return true;
    else
        return false;
}
void setTextColor(int textColorIndex) { // Смена цвета текста
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, (0 << 4) + textColorIndex);
}
bool notCorrectInput() { // Остановка программы при ошибочном вводе
    if (cin.fail()) {
        setTextColor(4);
        cout << "Введён неверный тип данных!" << endl;
        setTextColor(15);
        cout << "Программа будет завершена через 2 с.";
        double nowTime;
        nowTime = time(0);
        while (time(0) - nowTime != 2) {}
        return true;
    }
    return false;
}
