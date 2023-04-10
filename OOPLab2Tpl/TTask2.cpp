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
			this->text[i][j] = ' '; // '*';
	}
}

void TEncryption::SaveCriptToFile()
{
	std::ofstream fout("Cript.bin", std::ios_base::binary);
	if (fout.fail()) return;

	for (int i = 0; i < CountRow * CountCol; i++)
		fout << this->cript[i] << " ";
	fout.close(); 
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
у бітах 0 - 3 молодша частина ASCII - коду символу(4 біти),
у бітах 4 - 5 знаходиться номер рядка букви(2 біти),
у бітах 6 - 9 позиція букви у рядку(4 біти),
у бітах 10 - 13 старша частина ASCII - коду символу(4 біти),
14 біт – біт парності полів 4 - 9 (1 біт)
15 біт - біт парності коду символу(1 біт)
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
			tmp |= (this->text[i][j] >> 4);
			tmp <<= 4;
			tmp |= j;
			tmp <<= 2;
			tmp |= i;
			tmp <<= 4;
			tmp |= this->text[i][j] & 15;
			this->cript[i * CountCol + j] = tmp;
		}
}






TDecryption::TDecryption(){}

TDecryption::~TDecryption(){}

void TDecryption::InputCriptFromFile()
{
	std::ifstream fin("Cript.bin", std::ios_base::binary);
	if (fin.fail()) return;
	for (int i = 0; i < CountRow * CountCol; i++)
		fin >> this->cript[i];
	fin.close();
	for (int i = 0; i < CountRow * CountCol; i++)
		std::cout << this->cript[i] << " ";
	std::cout << std::endl;
}

void TDecryption::PrintDecrypt()
{
	for (int i = 0; i < CountRow; i++)
	{
		for (int j = 0; j < CountCol; j++)
			std::cout << this->text[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void TDecryption::SaveDecriptToFile()
{
	std::ofstream fout("Decript.txt");
	if (fout.fail()) return;

	for (int i = 0; i < CountRow; i++)
		for (int j = 0; j < CountCol; j++)
			fout << this->text[i][j];
	fout << std::endl;
	fout.close();
}

/*
у бітах 10 - 13 старша частина ASCII - коду символу(4 біти),
у бітах 0 - 3 молодша частина ASCII - коду символу(4 біти),
*/
void TDecryption::Decrypt()
{
	for (unsigned short i = 0; i < CountRow; i++)
		for (unsigned short j = 0; j < CountCol; j++)
		{
			unsigned short tmp = this->cript[i * CountCol + j];
			this->text[i][j] = (((tmp >> 10) & 15) <<4) | tmp & 15;
		}
}
