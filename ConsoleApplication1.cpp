#include <iostream>
#include "common.cpp"
#include "pw1.cpp"
#include "pw2.cpp"
#include "pw3.cpp"
#include "pw4.cpp"
#include <Windows.h>
#include <conio.h>


using namespace std;

void listChoice(int current) {
    setTextColor(6 - (current == 1 ? 5 : 0));
    cout << "[1] ";
    setTextColor(15);
    cout << "Практическая работа #1." << '\n';
    setTextColor(6 - (current == 2 ? 5 : 0));
    cout << "[2] ";
    setTextColor(15);
    cout << "Практическая работа #2." << '\n';
    setTextColor(6 - (current == 3 ? 5 : 0));
    cout << "[3] ";
    setTextColor(15);
    cout << "Практическая работа #3." << '\n';
    setTextColor(6 - (current == 4 ? 5 : 0));
    cout << "[4] ";
    setTextColor(15);
    cout << "Практическая работа #4." << '\n';
    setTextColor(4 - (current == 5 ? 3 : 0));
    cout << "[ESC] ";
    setTextColor(15);
    cout << "Выход из программы." << '\n';
}


int main()
{
    setlocale(0, "");
    int currentNum = 1;
    listChoice(currentNum);
    while (TRUE) {
        int input = _getch();
        input = (input == 224 ? _getch() : input);
        if (input == 80 || input == 77) {
            system("cls");
            currentNum += 1;
            currentNum = currentNum == 6 ? 1 : currentNum;
            listChoice(currentNum);
        }
        else if (input == 72 || input == 75) {
            system("cls");
            currentNum -= 1;
            currentNum = currentNum == 0 ? 5 : currentNum;
            listChoice(currentNum);
        }
        else if (input >= 49 && input <= 52) {
            system("cls");
            currentNum = input - 48;
            listChoice(currentNum);
            break;
        }
        else if (input == 13) {
            if (currentNum != 5)
                break;
            else
                return 0;
        }
        else if (input == 27) {
            return 0;
        }
    }
    setlocale(LC_ALL, "C");
    system("cls");
    switch (currentNum) {
        case 1:
            pw1();
            break;
        case 2:
            pw2();
            break;
        case 3:
            pw3();
            break;
        case 4:
            pw4();
    }
    system("cls");
    main();
}
