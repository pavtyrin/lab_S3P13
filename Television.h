#ifndef TELEVISION_H
#define TELEVISION_H

#include <iostream>

using namespace std;

class Television
{
    private:
        bool power;
        int volume;
        int channel;
        int brightness;

    public:
        Television() : power(false), volume(50), channel(1), brightness(50) {}

        void ChangePower()
        {
            power = !power;
            cout << endl;
            cout << "Телевизор " << (power ? "включен." : "выключен.") << endl;
        }

        void IncreaseVolume()
        {
            if (power && volume < 100)
            {
                volume++;
                cout << endl;
                cout << "Громкость увеличена: " << volume << endl;
            }
            else if (!power)
            {
                cout << endl;
                cout << "Телевизор выключен. Невозможно изменить громкость.\n";
            }
        }

        void DecreaseVolume()
        {
            if (power && volume > 0)
            {
                volume--;
                cout << endl;
                cout << "Громкость уменьшена: " << volume << endl;
            }
            else if (!power)
            {
                cout << endl;
                cout << "Телевизор выключен. Невозможно изменить громкость.\n";
            }
        }

        void ChangeChannel(int newChannel)
        {
            if (power && newChannel >= 1 && newChannel <= 100)
            {
                channel = newChannel;
                cout << endl;
                cout << "Канал изменен на: " << channel << endl;
            }
            else if (power && (newChannel <= 1 || newChannel >= 100))
            {
                cout << endl;
                cout << "Невозможно перейти на введенный канал. Максимальный номер канала - 100, минимальный - 1.\n";
            }
            else if (!power)
            {
                cout << endl;
                cout << "Телевизор выключен. Невозможно изменить канал.\n";
            }
        }

        void SetBrightness(int level)
        {
            if (power && level >= 0 && level <= 100)
            {
                brightness = level;
                cout << endl;
                cout << "Яркость установлена: " << brightness << endl;
            }
            else if (power && (level <= 0 || level >= 100))
            {
                cout << endl;
                cout << "Невозможно установить введенный уровень. Максимальный уровень яркости - 100, минимальный - 0.\n";
            }
            else if (!power)
            {
                cout << endl;
                cout << "Телевизор выключен. Невозможно изменить яркость.\n";
            }
        }

        void DisplayState() const
        {
            cout << endl;
            cout << "Состояние телевизора: " << (power ? "включен" : "выключен") << "\n";

        if (power)
        {
            cout << "Громкость: " << volume << "\n";
            cout << "Канал: " << channel << "\n";
            cout << "Яркость: " << brightness << "\n";
        }
    }
};

#endif