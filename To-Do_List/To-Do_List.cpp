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
#include <string>
#include<cmath>
#include<ctime>
#include<cstring>
#include< sstream >
#include<conio.h>
#include <iomanip>
#include <fstream>


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

using namespace std;


void show_menu();
void show_find();
void show_sort();
void add_Delo(delo*& d, int& size);
void dell_Delo(delo*& d, int& size, int n_delo);
void edit_Delo(delo*& d, int n_delo);
void find_Delo(delo*& d, int& size);
void show_Delo(delo*& d, int n_delo);
void show_spisok_Del(delo* d, int size);
void sort_Delo(delo*& d, int& size);
void save_file(delo*& d, int size);


using namespace std;

int main()
{
    system("chcp 1251>nul");
    setlocale(LC_ALL, "russian");
    int size = 3;

    delo* dela = new delo[size];

    dela[0] = { "Уборка",8,"кухня, комната, санузел", 17,3,10.00 };
    dela[1] = { "Готовка",9,"первое, второе, компот", 18,4,11.00 };
    dela[2] = { "Ремонт",9,"штукатурка, шпаклевка, покраска", 19,5,12.00 };

    int menu = 0;
    do {
        system("cls");
        show_menu();
        cout << endl;
        cout << "Выберите нужный пункт меню: ";
        cin >> menu;
        system("cls");

        switch (menu)
        {
        case 1:

            add_Delo(dela, size);
          
            break;
        case 2:
            show_spisok_Del(dela, size);
            cout << "Выберите дело для удаления :";
            int dell_delo;
            cin >> dell_delo;
            dell_Delo(dela, size, dell_delo);
           
            break;
        case 3:
            show_spisok_Del(dela, size);
            cout << "Выберите дело для изменения :";
            int n_delo;
            cin >> n_delo;
            edit_Delo(dela, n_delo-1);
            
            break;
        case 4:
            show_find();

            find_Delo(dela, size);
            break;
        case 5:
            show_spisok_Del(dela, size);
            system("pause");
            break;
        case 6:
            sort_Delo(dela,size);

            break;
        case 7:
            save_file(dela, size);
            system("cls");
            cout << "Список дел сохранен в файл To_Do_List.txt";
            cout << "\n\n";
            system("pause");
            break;
        default:
            break;
        }

    } while (menu != 8);

}

void show_menu() {
    std::cout << "[1]  Добавление дел." << std::endl;
    std::cout << "[2]  Удаление дел." << std::endl;
    std::cout << "[3]  Редактирование дел." << std::endl;
    std::cout << "[4]  Поиск дел." << std::endl;
    std::cout << "[5]  Отображение списка дел." << std::endl;
    std::cout << "[6]  Отсортировать список дел." << std::endl;
    std::cout << "[7]  Сохранить в файл." << std::endl;
    std::cout << "[8]  Выход." << std::endl;
};
void show_edit() {
    std::cout << "[1]  Изменение наименования." << std::endl;
    std::cout << "[2]  Изменение приоритета." << std::endl;
    std::cout << "[3]  Изменение описания." << std::endl;
    std::cout << "[4]  Изменение дня." << std::endl;
    std::cout << "[5]  Изменение месяца." << std::endl;
    std::cout << "[6]  Изменение времени." << std::endl;
    std::cout << "[7]  Выход в главное меню." << std::endl;
};

void show_find() {
    std::cout << "[1]  Поиск по имени." << std::endl;
    std::cout << "[2]  Поиск по приоритету." << std::endl;
    std::cout << "[3]  Поиск по описанию." << std::endl;
    std::cout << "[4]  Поиск по дню." << std::endl;
    std::cout << "[5]  Поиск по месяцу." << std::endl;
    std::cout << "[6]  Поиск по времени." << std::endl;
    std::cout << "[7]  Выход в главное меню." << std::endl;
};

void show_sort() {
    std::cout << "[1]  Сортировка по приоритету." << std::endl;
    std::cout << "[2]  Сортировка по дате." << std::endl;
    std::cout << "[3]  Выход в главное меню." << std::endl;
}

void add_Delo(delo*& d, int& size) {

    setlocale(LC_ALL, "russian");

    delo* d_temp = new delo[size + 1];

    for (int i = 0; i < size; i++)
    {
        d_temp[i] = d[i];
    }

    cin.getline(d_temp[size].name, 100);
    cout << " Введите название задачи: ";
    cin.getline(d_temp[size].name, 100);

    do {  
        cout << " Введите приоритет (1-10): ";
        cin >> d_temp[size].prior;
    } while (d_temp[size].prior < 0 || d_temp[size].prior >10);

    cin.getline(d_temp[size].descript, 100);
    cout << " Введите описаие задачи: ";
    cin.getline(d_temp[size].descript, 100);

    do {
    cout << " Введите день: ";
    cin >> d_temp[size].date_delo.day;
    } while (d_temp[size].date_delo.day < 0 || d_temp[size].date_delo.day >31);

    do {
    cout << " Введите месяц: ";
    cin >> d_temp[size].date_delo.month;
    } while (d_temp[size].date_delo.month < 0 || d_temp[size].date_delo.month >12);

    do {
    cout << " Введите время (чч.мм) : ";
    cin >> d_temp[size].date_delo.time;
    } while (d_temp[size].date_delo.time < 0 || d_temp[size].date_delo.time >25);

    delete[] d;
    size++;
    d = d_temp;


}

void dell_Delo(delo*& d, int& size, int n_delo) {

    delo* d_temp = new delo[size - 1];
    for (int i = 0; i < n_delo - 1; i++) {
        d_temp[i] = d[i];
    }
    for (int i = n_delo - 1; i < size - 1; i++) {
        d_temp[i] = d[i + 1];
    }
    delete[] d;
    size--;
    d = d_temp;

};

void show_Delo(delo*& d, int n_delo) {

 
    cout << "N "
        << setw(20) << left << "Название"
        << setw(10) << "Приор-т"
        << setw(40) << "Описание"
        << setw(6) << "День"
        << setw(6) << "Месяц"
        << setw(6) << "Время" << endl;
    cout << "____________________________________________________________________________________________" << endl;

    cout << n_delo+1 << " "
        << setw(20) << left << d[n_delo].name
        << setw(10) << d[n_delo].prior
        << setw(40) << d[n_delo].descript
        << setw(6) << d[n_delo].date_delo.day
        << setw(6) << d[n_delo].date_delo.month
        << setw(6) << setprecision(2) << fixed << d[n_delo].date_delo.time << endl;

    cout << endl;

}

void show_spisok_Del(delo* d, int size) {

    cout << "N "
        << setw(20) << left << "Название"
        << setw(10) << "Приор-т"
        << setw(40) << "Описание"
        << setw(6) << "День"
        << setw(6) << "Месяц"
        << setw(6) <<"Время"<< endl;
    cout << "____________________________________________________________________________________________" << endl;

    for (int i = 0; i < size; i++) {
            cout << i + 1 << " " 
            << setw(20) << left << d[i].name
            << setw(10) << d[i].prior
            << setw(40) << d[i].descript
            << setw(6) << d[i].date_delo.day
            << setw(6) << d[i].date_delo.month
            << setw(6) << setprecision(2) << fixed << d[i].date_delo.time << endl;
    }

    cout << endl;
}

void edit_Delo(delo*& d, int n_delo) {

    int pole;

    do {
        system("cls");
        show_edit();
        cout << endl;
        show_Delo(d, n_delo);
        cout << "Выберите нужный пункт: ";
        cin >> pole;

        system("cls");

        switch (pole)
        {
        case 1:

            cin.getline(d[n_delo].name, 100);
            cout << " Введите название задачи: ";
            cin.getline(d[n_delo].name, 100);
        
            break;
        case 2:
            do {
                cout << " Введите приоритет (1-10): ";
                cin >> d[n_delo].prior;
            } while (d[n_delo].prior<0 || d[n_delo].prior>10);
            break;
        case 3:
            cin.getline(d[n_delo].descript, 100);
            cout << " Введите описаие задачи: ";
            cin.getline(d[n_delo].descript, 100);
            
            break;
        case 4:
            do {
                cout << " Введите день: ";
                cin >> d[n_delo].date_delo.day;
            } while (d[n_delo].date_delo.day<0|| d[n_delo].date_delo.day>31);
            
            break;
        case 5:
            do {
                cout << " Введите месяц: ";
                cin >> d[n_delo].date_delo.month;
            } while (d[n_delo].date_delo.month < 0 || d[n_delo].date_delo.month>12);
           
            break;
        case 6:
            do {
                cout << " Введите время: ";
                cin >> d[n_delo].date_delo.time;
            } while (d[n_delo].date_delo.time < 0 || d[n_delo].date_delo.time>25);
            break;

        default:
            break;
        }

    } while (pole != 7);

}

void find_Delo(delo*& d, int &size) {

    char search[100];
    int find;
    
    do {
        
        system("cls");
        show_find();
        cout << endl;
        cout << "Выберите нужный пункт для поиска: ";
        cin >> find;
        system("cls");

        switch (find)
        {
        case 1:
            int count;
            count = 0;
            cin.getline(search, 100);
            cout << " Введите наименование: ";
            cin.getline(search, 100);
           
            for (int i = 0; i < size; i++) {
                if (strstr(d[i].name, search)) {
                    count++;
                    show_Delo(d, i);
                }
            }
            if (count == 0) {
                cout << "Дела с таким наименованием не найдено.";
                cout << endl;
            }
            system("pause");
            break;
        case 2:
            int count1;
            int par;
            count1 = 0;
            cout << " Введите приоритет: ";
            cin >> par;
            
            for (int i = 0; i < size; i++) {
                if ((d[i].prior == par)) {
                    count1++;
                    show_Delo(d, i);
                }
            }
            if (count1 == 0) {
                cout << "Дела с таким приоритетом не найдено.";
                cout << "\n\n";
            }
            system("pause");
            break;
        case 3:
            int count2;
            count2 = 0;
            cin.getline(search, 100);
            cout << " Введите описание: ";
            cin.getline(search, 100);
            
            for (int i = 0; i < size; i++) {
                if (strstr(d[i].descript, search)) {
                    count2++;
                    show_Delo(d, i);
                }
            }
            if (count2 == 0) {
                cout << "Дела с таким описанием не найдено.";
                cout << "\n\n";
            }
            system("pause");
            break;
        case 4:
            int count3;
            count3 = 0;
            int par2;
            cout << " Введите день: ";
            cin >> par2;
            
            for (int i = 0; i < size; i++) {
                if ((d[i].date_delo.day == par2)) {
                    count3++;
                    show_Delo(d, i);
                }
            }
            if (count3 == 0) {
                cout << "Дела с таким днем не найдено.";
                cout << "\n\n";
            }
            system("pause");
            break;

        case 5:
            int count4;
            count4 = 0;
            int par3;
            cout << " Введите месяц: ";
            cin >> par3;
            for (int i = 0; i < size; i++) {
                if ((d[i].date_delo.month == par3)) {
                    count4++;
                    show_Delo(d, i);
                }
            }
            if (count4 == 0) {
                cout << "Дела с таким месяцем не найдено.";
                cout << "\n\n";
            }
            system("pause");
            break;

        case 6:
            int count5;
            count5 = 0;
            float par_time;
            cout << " Введите время: ";
            cin >> par_time;
           
            for (int i = 0; i < size; i++) {
                if ((d[i].date_delo.time == par_time)) {
                    count5++;
                    show_Delo(d, i);
                }
            }
            if (count5 == 0) {
                cout << "Дела с таким временем не найдено.";
                cout << "\n\n";
            }
            system("pause");
            break;

        default:
            break;
        }

    } while (find != 7);

}

void sort_prior(delo*& d, int& size) {
    delo temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (d[j + 1].prior < d[j].prior) {
                temp = d[j + 1];
                d[j + 1] = d[j];
                d[j] = temp;
            }
        }
    }
}

void sort_date(delo*& d, int& size) {
    delo temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (d[j + 1].date_delo.month< d[j].date_delo.month && d[j + 1].date_delo.day < d[j].date_delo.day) {
                temp = d[j + 1];
                d[j + 1] = d[j];
                d[j] = temp;
            }
        }
    }

}


void sort_Delo(delo*& d, int& size) {
    int sort;

    do {
        system("cls");
        show_sort();
        cout << endl;
        cout << "Выберите нужный пункт: ";
        cin >> sort;
        system("cls");
        switch (sort)
        {
        case 1:
            sort_prior(d, size);
            system("cls");
            show_spisok_Del(d, size);
            system("pause");
            break;
        case 2:
            sort_date(d, size);
            system("cls");
            show_spisok_Del(d, size);
            system("pause");
            break;

        default:
            break;
        }

    } while (sort != 3);
}
void save_file(delo*& d, int size) {

    ofstream fout;
    fout.open("To_Do_List.txt");

    if (!fout.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        for (int i = 0; i < size; i++) {

            //fout << i+1<<" " << d[i].name << " " << d[i].prior << " " << d[i].descript << " " << d[i].date_delo.day << " " << d[i].date_delo.month << " " << d[i].date_delo.time;
            fout << i + 1 << " "
                << setw(20) << left << d[i].name
                << setw(10) << d[i].prior
                << setw(40) << d[i].descript
                << setw(6) << d[i].date_delo.day
                << setw(6) << d[i].date_delo.month
                << setw(6) << setprecision(2) << fixed << d[i].date_delo.time;
            fout << "\n";
        }
    }
        fout.close();
}