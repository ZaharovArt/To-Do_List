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

void show_menu();
void add_Delo();
void dell_Delo();
void edit_Delo();
void find_Delo();
void show_Delo();
void sort_Delo();

struct delo
{
   char name[20];
   int prior;
   char descript[50];
   char date[20];

};

int main()
{
    setlocale(LC_ALL, "russian");
    using namespace std;



    delo* dela = new delo[1];

    dela[0] = { "Работа ", 10," Прибыть на работу к 9-00", 17 / 03 / 2023 };

    int menu = 0;
    do {
        show_menu();
        cin >> menu;
        system("cls");
        switch (menu)
        {
        case 1:
            add_Delo();
            break;
        case 2:
            dell_Delo();
            break;
        case 3:
            edit_Delo();
            break;
        case 4:
            find_Delo();
            break;
        case 5:
            show_Delo();
            break;
        case 6:
            sort_Delo();
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
void add_Delo(delo * d) {



};