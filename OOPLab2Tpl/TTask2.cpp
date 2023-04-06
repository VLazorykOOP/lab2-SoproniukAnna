#include "TTask2.h"
#include <iostream>
#include <fstream>


unsigned short TEncryption::pbit(unsigned char c)
{
	unsigned char mask = 1;
	unsigned short b = 0;
	for (int i = 0; i < 8; i++)
		b ^= (c >> i) & mask; //	b = b ^ ((c >> i) & mask);
	return b;
}

unsigned short TEncryption::pbit(unsigned short row, unsigned short col)
{
	unsigned short mask = 1, b = 0;
	while (row != 0)
	{
		b ^= row & mask;
		row >>= 1; // row = row >> 1;
	}
	while (col != 0)
	{
		b ^= col & mask;
		col >>= 1; // row = row >> 1;
	}

	return b;
}

TEncryption::TEncryption()
{
	for (int i = 0; i < CountRow; i++)
		for (int j = 0; j < CountCol; j++)
			this->text[i][j] = ' ';
}

TEncryption::~TEncryption(){}

void TEncryption::InputTextConsole()
{
	std::cin.ignore(1,'\0');
	std::cout << "Input text:" << std::endl;
	for (int i = 0; i < CountRow; i++)
	{
		std::cin.getline(this->text[i], CountCol);
		std::cout << std::endl;
	}

	for (int i = 0; i < CountRow; i++)
	{
		int j = 0;
		for (j = 0; j < CountCol; j++)
			if (this->text[i][j] == '\0')
				break;
		for (; j < CountCol; j++)
			this->text[i][j] = '*'; // '*';
	}
}

void TEncryption::InputTextFromFile()
{
}

void TEncryption::SaveCriptToFile()
{
}

void TEncryption::PrintText()
{
	for (int i = 0; i < CountRow; i++)
	{
		for (int j = 0; j < CountCol; j++)
			std::cout << this->text[i][j];
		std::cout << std::endl;
	}
}

void TEncryption::PrintCript()
{
	for (int i = 0; i < CountRow * CountCol; i++)
		std::cout << this->cript[i] << " ";
	std::cout << std::endl;
}

/*
� ���� 0 - 3 ������� ������� ASCII - ���� �������(4 ���),
� ���� 4 - 5 ����������� ����� ����� �����(2 ���),
� ���� 6 - 9 ������� ����� � �����(4 ���),
� ���� 10 - 13 ������ ������� ASCII - ���� �������(4 ���),
14 �� � �� ������� ���� 4 - 9 (1 ��)
15 �� - �� ������� ���� �������(1 ��)
*/

void TEncryption::Encrypt()
{
	unsigned short tmp = 0;
	for (unsigned short i = 0; i < CountRow; i++)
		for (unsigned short j = 0; j < CountCol; j++)
		{
			tmp = this->pbit(this->text[i][j]);
			tmp <<= 1;
			tmp |= this->pbit(i, j);
			tmp <<= 4;
			tmp |= this->text[i][j] >> 4;
			tmp <<= 4;
			tmp |= j;
			tmp <<= 2;
			tmp |= i;
			tmp <<= 4;
			tmp |= this->text[i][j] & 15;
			this->cript[i * CountCol + j] = tmp;
		}
}
