﻿#include <iostream>
#include <conio.h>
#include "Tasks.h"
#include "Examples.h"
#include "TTask2.h"
using namespace std;

void MenuTask2()
{
    int select;
    do
    {
        TEncryption encrypt;
        TDecryption decrypt;
        cout << "\t \t \t Select option " << endl;
        cout << " 1.  Encrypt " << endl;
        cout << " 2.  Decryption " << endl;
        cout << " 0.  Exit " << endl;
        cin >> select;
        system("cls");
        switch (select)
        {
        case 1:
            system("cls");
            encrypt.InputTextConsole();
            encrypt.PrintText();
            encrypt.Encrypt();
            encrypt.PrintCript();
            encrypt.SaveCriptToFile();
            break;
        case 2:
            //system("cls");
            decrypt.InputCriptFromFile();
            decrypt.Decrypt();
            decrypt.PrintDecrypt();
            decrypt.SaveDecriptToFile();
            break;
        }
    } while (select != 0);
    system("cls");
}

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
    system("cls");
    MenuTask2();
}


