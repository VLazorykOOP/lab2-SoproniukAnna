#include <iostream>
#include <conio.h>
#include "Tasks.h"
#include "Examples.h"
using namespace std;

void task1() 
{
    // Обчислення виразів з використанням побітових операцій
    // Calculation of expressions using bitwise operations 
    system("cls");
    cout << " Calculation of expressions using bitwise operations " << endl;
    int a, b, c, d;
    double Result;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    cout << "Input c: ";
    cin >> c;
    cout << "Input d: ";
    cin >> d;

    //1024 * b + ((d * 15 + 12 * a) / 512) - 4097 * c + d * 13;
    Result = (b << 10) + ((((d << 4) - d) + ((a << 3) + (a << 2))) >> 10) - ((c << 12) + c) + ((d << 3) + (d << 2) + d);
    cout << "Result: " << Result << endl;
    cout << endl;
}

void task2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations " << endl;
}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields " << endl;
}

void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields " << endl;
}


