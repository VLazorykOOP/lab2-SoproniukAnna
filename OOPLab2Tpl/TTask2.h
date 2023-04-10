#pragma once

const int CountRow = 4;
const int CountCol = 16;

class TEncryption
{
private:
	char text[CountRow][CountCol]{};
	unsigned short cript[CountRow * CountCol]{};

	unsigned short pbit(unsigned char c);
	unsigned short pbit(unsigned short row, unsigned short col);
public:
	TEncryption();
	~TEncryption();
	void InputTextConsole();
	void SaveCriptToFile();
	void PrintText();
	void PrintCript();
	void Encrypt();
};

class TDecryption
{
private:
	unsigned short cript[CountRow * CountCol]{};
	char text[CountRow][CountCol]{};
public:
	TDecryption();
	~TDecryption();
	void InputCriptFromFile();
	void PrintDecrypt();
	void SaveDecriptToFile();
	void Decrypt();
};