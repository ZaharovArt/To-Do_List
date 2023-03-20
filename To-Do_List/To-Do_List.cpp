// To-Do_List.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//«Список дел».
//Приложение должно позволять :
//■ Добавление дел.У дела есть :
//• название;
//• приоритет;
//• описание;
//• дата, время исполнения.
//■ Удаление дел.
//■ Редактирование дел.
//■ Поиск дел по :
//• названию;
//• приоритету;
//• описанию;
//• дате и времени исполнения.
//■ Отображение списка дел :
//• на день;
//• на неделю;
//• на месяц.
//■ При отображении должна быть возможность сортировки :
//• по приоритету;
//• по дате и времени исполнения.

#include <iostream>
#include <string.h>
#include<cmath>
#include<ctime>
#include<cstring>
#include< sstream >
#include<conio.h>


struct date
{
    int day;
    int month;
    float time;
};

struct delo
{
    char name[256];
    int prior;
    char descript[256];
    date date_delo;
};



void show_menu();
void add_Delo(delo*& d, int &size);
void dell_Delo(delo* d, int &size);
void edit_Delo(delo* d, int &size);
void find_Delo(delo* d, int &size);
void show_Delo(delo* d, int size);
void sort_Delo(delo* d, int &size);


using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    int size=1;

    delo* dela = new delo[size];

    dela[0] = { "Работа", 10," Прибыть на работу к 9-00", 17,3,10.00};

    int menu = 0;

    do {
        show_menu();
        cin >> menu;
        system("cls");

        switch (menu)
        {
        case 1:
           
            add_Delo(dela,size);
            system("pause");
            break;
        case 2:
            //dell_Delo();
            break;
        case 3:
            //edit_Delo();
            break;
        case 4:
            //find_Delo();
            break;
        case 5:
            system("cls");
            show_Delo(dela, size);
            system("pause");
            break;
        case 6:
            //sort_Delo();
            break;

        default:
            break;
        }

    } while (menu != 7);
    
}

void show_menu() {
    std::cout << "[1]  Добавление дел." << std::endl;
    std::cout << "[2]  Удаление дел." << std::endl;
    std::cout << "[3]  Редактирование дел." << std::endl;
    std::cout << "[4]  Поиск дел." << std::endl;
    std::cout << "[5]  Отображение списка дел." << std::endl;
    std::cout << "[6]  Отсортировать список дел." << std::endl;
    std::cout << "[7]  Выход." << std::endl;
};

void add_Delo(delo*& d, int &size) {

    delo* d_temp = new delo[size + 1];

    for (size_t i = 0; i < size; i++)
    {
        d_temp[i] = d[i];
    }

    cin.getline(d_temp[size].name, 100);
    cout << " Введите название задачи: ";
    cin.getline(d_temp[size].name,100);

    cout << " Введите приоритет (1-10): ";
    cin >> d_temp[size].prior;

    cin.getline(d_temp[size].descript, 100);
    cout << " Введите описаие задачи: ";
    cin.getline(d_temp[size].descript, 100);
    cout << " Введите день: ";
    cin >> d_temp[size].date_delo.day;
    cout << " Введите месяц: ";
    cin >> d_temp[size].date_delo.month;
    cout << " Введите время: ";
    cin >> d_temp[size].date_delo.time;
    size++;
    d = d_temp;
    delete [] d_temp;

}

void dell_Delo(delo *d, int &size) {


    
    
};

void show_Delo(delo* d, int size) {

    cout << "N" << "\tНизвание" << "\tПриоритет" << "\tОписание" << "\tдень" << "\tмесяц" << "время\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "\t" << d[i].name << "\t" << d[i].prior << "\t" << d[i].descript << "\t" << d[i].date_delo.day << "\t" << d[i].date_delo.month << "\t"<< d[i].date_delo.time;
    }
    cout << endl;
    cout << "----------------------------------";
    cout << endl;
}

void edit_Delo(delo* d, int& size) {

    delo* d_temp = new delo[size + 1];

    for (int i = 0; i < size; i++)
    {
        d_temp[i] = d[i];
    }

    cout << " Введите название задачи: ";
    cin.getline(d_temp[size].name, 100);
    cout << " Введите приоритет (1-10): ";
    cin >> d_temp[size].prior;
    cout << " Введите описаие задачи: ";
    cin.getline(d_temp[size].descript, 100);
    cout << " Введите день: ";
    cin >> d_temp[size].date_delo.day;
    cout << " Введите месяц: ";
    cin >> d_temp[size].date_delo.month;
    cout << " Введите время: ";
    cin >> d_temp[size].date_delo.time;
    size++;
    d = d_temp;
    delete[] d_temp;

}

void find_Delo(delo* d, int& size) {

    delo* d_temp = new delo[size + 1];

    for (size_t i = 0; i < size; i++)
    {
        d_temp[i] = d[i];
    }

    cout << " Введите название задачи: ";
    cin.getline(d_temp[size].name,100);
    cout << " Введите приоритет (1-10): ";
    cin >> d_temp[size].prior;
    cout << " Введите описаие задачи: ";
    cin.getline(d_temp[size].descript, 100);
    cout << " Введите день: ";
    cin >> d_temp[size].date_delo.day;
    cout << " Введите месяц: ";
    cin >> d_temp[size].date_delo.month;
    cout << " Введите время: ";
    cin >> d_temp[size].date_delo.time;
    size++;
    d = d_temp;
    delete[] d_temp;

}
void sort_Delo(delo* d, int& size) {

    delo* d_temp = new delo[size + 1];

    for (size_t i = 0; i < size; i++)
    {
        d_temp[i] = d[i];
    }

    cout << " Введите название задачи: ";
    cin.getline(d_temp[size].name, 100);
    cout << " Введите приоритет (1-10): ";
    cin >> d_temp[size].prior;
    cout << " Введите описаие задачи: ";
    cin.getline(d_temp[size].descript, 100);
    cout << " Введите день: ";
    cin >> d_temp[size].date_delo.day;
    cout << " Введите месяц: ";
    cin >> d_temp[size].date_delo.month;
    cout << " Введите время: ";
    cin >> d_temp[size].date_delo.time;
    size++;
    d = d_temp;
    delete[] d_temp;

}