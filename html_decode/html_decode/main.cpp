#include "Header.h"
#include "pch.h"

// основная программа
int main()
{
	string inputStr;
	getline(cin, inputStr);
	HtmlDecode(inputStr);
}