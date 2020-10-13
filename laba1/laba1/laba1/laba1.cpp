#include <iostream>
#include <fstream>

using namespace std;

struct datetime
{

    int year,
        month,
        day,
        hour,
        minute,
        second;


    void Show()
    {
        cout << endl << "Сейчас: " << day << "." << month << "." << year << " Время: " << hour << ":" << minute << ":" << second << endl;
    }


    //Метод, переводящий дату на следующий день
    void Next_date()
    {
        day++; //Добавляем день

        //Проверяем случаи с високосными годами, концами месяцев и конца года

        if (day > 28)
        {
            if ((day == 29) && (month == 2) && (year % 4 != 0))
            {
                day = 1;
                month++;

            }
            else if ((day == 30) && (month == 2))
            {
                day = 1;
                month++;
            }
            else if (day == 31)
            {
                if ((month != 3) && (month != 5) && (month != 7) && (month != 8) && (month != 10) && (month != 12))
                {
                    day = 1;
                    month++;

                    if (month > 12)
                    {
                        month = 1;
                        year++;

                    }

                }

            }
            else if (day > 31)
            {
                day = 1;
                month++;

                if (month > 12)
                {
                    month = 1;
                    year++;
                }

            }

        }
    }


    //Метод, возвращающий дату на день назад
    void Prev_date()
    {
        day--; //День назад

        //Весокосный год
        if (day == 0)
        {
            if ((month == 3) && (year % 4 != 0))
            {
                day = 28;
                month--;
            }
            else if ((month == 3) && (year % 4 == 0))
            {
                day = 29;
                month--;
            }
            else if ((month - 1 == 3) || (month - 1 == 5) || (month - 1 == 7) || (month - 1 == 8) || (month - 1 == 10) || (month - 1 == 0))
            {
                day = 31;
                month--;

                if (month == 0)
                {
                    month = 12;
                    year--;
                }

            }
            else
            {
                day = 30;
                month--;
            }

        }

    }

};



int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    ifstream fin("nabers.txt");
    if (!fin.is_open())
        cout << "Файл не был отрыт!" << endl;

    datetime temp;
    int n = 0;

    while (!fin.eof())
    {

        fin >> temp.day >> temp.month >> temp.year >> temp.hour >> temp.minute >> temp.second;
        n++;
    }

    fin.close();

    //Создаём днамически массив по найденному количеству записей
    datetime* DT;
    DT = new datetime[n];

    fin.open("nabers.txt");

    int i = 0;

    while (!fin.eof())
    {
        //Считываем каждую дату в отдельный элемент массива, где каждый элемент является объектов дата-время
        fin >> DT[i].day >> DT[i].month >> DT[i].year >> DT[i].hour >> DT[i].minute >> DT[i].second;
        i++;
    }

    //Вывод на экран
    cout << "Запись из файла" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << endl << i + 1 << ". Дата: " << DT[i].day << "." << DT[i].month << "." << DT[i].year;
        DT[i].Next_date();
        cout << " --- Следующая дата: " << DT[i].day << "." << DT[i].month << "." << DT[i].year;
        DT[i].Prev_date();
        DT[i].Prev_date();
        cout << " --- Предыдущая дата: " << DT[i].day << "." << DT[i].month << "." << DT[i].year;
        DT[i].Next_date();
        cout << endl;
    }


    //Выполняем задание варианта 4
    cout << endl << endl << "Вариант №9" << endl;
    int next_month = 0;
    int prev_month = 1;

    for (int i = 0; i < n; i++)
    {
        DT[i].Next_date();
        next_month = DT[i].month;
        DT[i].Prev_date();
        DT[i].Prev_date();
        prev_month = DT[i].month;
        DT[i].Next_date();

        if (next_month == prev_month)
        {
            cout << endl << i + 1 << ". Дата: " << DT[i].day << "." << DT[i].month << "." << DT[i].year;
            DT[i].Next_date();
            cout << " --- Следующая дата: " << DT[i].day << "." << DT[i].month << "." << DT[i].year;
            DT[i].Prev_date();
            DT[i].Prev_date();
            cout << " --- Предыдущая: дата " << DT[i].day << "." << DT[i].month << "." << DT[i].year;
            DT[i].Next_date();
            cout << endl;
        }
    }

    return 0;
}
