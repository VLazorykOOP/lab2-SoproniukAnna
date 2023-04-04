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
	void InputTextFromFile();
	void SaveCriptToFile();
	void PrintText();
	void PrintCript();
	void Encrypt();
};

// TDecryption