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
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    0.  Exit \n";
}

int main()
{
    cout << "OOP. Template for laboratory work #2.\n";

    int select;
    do {
        system("cls");
        MainMenu();
        cin >> select;

        switch (select) 
        {
        case 1: 
            task1();   
            break;
        case 2: 
            task2();
            break;
        case 3: 
            task3();
            break;
        case 4: 
            task4();
            break;
	    }
        cout << " Press any key and enter\n";
    } while (select != 0);

    return 0;
}

