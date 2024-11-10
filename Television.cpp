#include <iostream>
#include <string>
#include "Television.h"

using namespace std;

void displayMenu()
{
    cout << "\nМеню:\n";
    cout << "1. Включить/выключить телевизор\n";
    cout << "2. Увеличить громкость\n";
    cout << "3. Уменьшить громкость\n";
    cout << "4. Сменить канал\n";
    cout << "5. Установить яркость\n";
    cout << "6. Показать текущее состояние\n";
    cout << "0. Выйти\n";
    cout << endl;
    cout << "Выберите действие: ";
}

int main()
{
    Television tv;

    cout << endl;
    cout << endl;
    tv.DisplayState();
    cout << endl;

    string choice;
    
    while (true) {
        displayMenu();   
        cin >> choice;

        if (choice == "1")
        {
            tv.ChangePower();
            continue;
        }

        if (choice == "2")
        {
            tv.IncreaseVolume();
            continue;
        }

        if (choice == "3")
        {
            tv.DecreaseVolume();
            continue;
        }

        if (choice == "4")
        {
            string input_channel;
            cout << endl;
            cout << "Введите номер канала (1-100): ";
            cin >> input_channel;
            try
            {
                int channel = stoi(input_channel);
                tv.ChangeChannel(channel);
            }
            catch (invalid_argument&)
            {
                cout << endl;
                cout << "Ошибка: номер канала должен быть числом. Возврат в главное меню.\n";
            }           
            continue;
        }

        if (choice == "5")
        {
            string input_brightness;
            cout << endl;
            cout << "Введите уровень яркости (0-100): ";
            cin >> input_brightness;
            try
            {
                int brightness = stoi(input_brightness);
                tv.SetBrightness(brightness);
            }
            catch (invalid_argument&)
            {
                cout << endl;
                cout << "Ошибка: уровень яркости должен быть числом. Возврат в главное меню.\n";
            }           
            continue;
        }

        if (choice == "6")
        {
            tv.DisplayState();
            continue;
        }

        if (choice == "0")
        {
            cout << endl;
            cout << "Выход из программы.\n";
            cout << endl;
            exit (0);
        }

        else
        {
            cout << endl;
            cout << "Неверный выбор. Попробуйте еще раз.\n";
            continue;
        }
    } 

    return 0;
}