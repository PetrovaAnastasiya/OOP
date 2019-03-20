#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
const string NOT_FOUND = "Text not found";
const string ERR_FILE_OPEN = "Error: file not opened";                       		

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << ERR_NUM_ARG << endl;
		return 1;
	}

	ifstream file;
	file.open(argv[1]);

	if (!file.is_open())
	{
		cout << ERR_FILE_OPEN;
		return 1;
	}

	bool flg = false;
	string str;
	int i = 1;
	while (!file.eof())
	{
		getline(file, str);
		if (str.find(argv[2]) != string::npos)
		{
			cout << i << endl;
			flg = true;
		}
		i++;
	};

	if (flg == false)
	{
		cout << NOT_FOUND;
		return 0;
	}

	file.close();
}
