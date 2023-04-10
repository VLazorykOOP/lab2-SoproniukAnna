// OOPLab2Tpl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"


/// @brief 
/// @return 


void MainMenu()
{
    int select;
    do
    {
        cout << "\t \t \t Main menu " << endl;
        cout << " 1.  Calculation of expressions using bitwise operations " << endl;
        cout << " 2.  Data encryption using bitwise operations " << endl;
        cout << " 0.  Exit " << endl;
        cin >> select;
        switch (select)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        }
    } while (select != 0);
    system("cls");
}

int main()
{
    MainMenu();
}

