
int pw1() {
    SetConsoleOutputCP(CP_UTF8); // Верное отображение русского языка
    cout << "Выберите нужное действие:" << '\n';
    setTextColor(1);
    cout << "[1] ";
    setTextColor(15);
    cout << "Вывести, сколько памяти занимает каждый из типов данных." << '\n';
    setTextColor(1);
    cout << "[2] ";
    setTextColor(15);
    cout << "Вывести двоичное представление целого числа." << '\n';
    setTextColor(1);
    cout << "[3] ";
    setTextColor(15);
    cout << "Вывести двоичное представление числа с типом float." << '\n';
    setTextColor(1);
    cout << "[4] ";
    setTextColor(15);
    cout << "Вывести двоичное представление числа с типом double." << '\n';
    setTextColor(1);
    cout << "[5] ";
    setTextColor(4);
    cout << "Закрыть программу." << '\n';
    setTextColor(15);
    cout << '\n';
    cout << "Введите число от 1 до 5: ";

    int chosenCase;
    cin >> chosenCase;
    if (notCorrectInput())
        return 0;
    switch (chosenCase) {
        case 1:  // Сколко места занимают типы данных
            cout << "Int - " << sizeof(int) << '\n';
            cout << "Short Int - " << sizeof(short) << '\n';
            cout << "Long Int - " << sizeof(long) << '\n';
            cout << "Float - " << sizeof(float) << '\n';
            cout << "Double - " << sizeof(double) << '\n';
            cout << "Long Double - " << sizeof(long double) << '\n';
            cout << "Char - " << sizeof(char) << '\n';
            cout << "Bool - " << sizeof(bool) << '\n';
            break;
        case 2:   // Перевод инт в 2ую сс
            int number;
            cout << "Введите число с типом Integer: ";
            cin >> number;
            if (notCorrectInput())
                return 0;
            unsigned int mask;
            mask = 1 << 31;
            for (int i = 1; i <= 32; i++) {
                setTextColor(15);
                if (i == 1)
                    setTextColor(4);
                putchar(number & mask ? '1' : '0');
                number <<= 1;
            }
            cout << '\n';
            break;
        case 3:   // Перевод флоат в 2ую сс
            union {
                int tool;
                float numberFloat;
            };
            mask = 1 << 31;
            cout << "Введите число с типом Float: ";
            cin >> numberFloat;
            if (notCorrectInput())
                return 0;
            for (int i = 1; i <= 32; i++){
                if (i == 1)
                    setTextColor(4);
                else if (i > 1 and i < 10)
                    setTextColor(2);
                else
                    setTextColor(15);
                putchar(tool & mask ? '1' : '0');
                tool <<= 1;
            }
            cout << '\n';
            break;
        case 4:  // Перевод дабл в 2ую сс
            union {
                int tools[2];
                double numberDouble;
            };
            mask = 1 << 31;
            cout << "Введите число с типом Double: ";
            cin >> numberDouble;
            if (notCorrectInput())
                return 0;
            for (int i = 2; i >= 1; i--){
                for (int j = 1; j <= 32; j++){
                    if (j + 32 * (2 - i) == 1)
                        setTextColor(4);
                    else if (j + 32 * (2 - i) > 1 and j + 32 * (2 - i) < 13)
                        setTextColor(2);
                    else
                        setTextColor(15);
                    putchar(tools[i - 1] & mask ? '1' : '0');
                    tools[i - 1] <<= 1;
                }
            }
            cout << '\n';
            break;
        case 5:   // Выход из программы
            return 0;
        default:  // Неверный ввод
            setTextColor(4);
            cout << '\n' << "Вы ввели неверное значение." << '\n' << endl;
            setTextColor(15);
    }

    if (isRestartNeeded()) {
        cout << '\n' << "Перезапуск программы..." << '\n' << '\n';
        // Остановка времени на 2с
        double nowTime;
        nowTime = time(0);
        while(time(0) - nowTime != 2) { }
        // Перезапуск программы
        pw1();
    } else { // Выход  из программы
        return 0;
    }
}