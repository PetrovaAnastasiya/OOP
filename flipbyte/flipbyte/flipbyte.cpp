#include "pch.h"
#include <bitset>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

const string ERR_NUM_ARG = "Usage: flipbyte.exe <input byte>";
const string ERR_SIZE_NUM = "Error: not included in the range [0;255]";
const string ERR_PAR_BYTE = "Parameter error";

const int NUM_BIT = 8;
const int BASE = 10;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << ERR_NUM_ARG << endl;
		return 1;
	}

	int ctr = 0;
	while (argv[1][ctr])
	{
		if (isalpha(argv[1][ctr]))
		{
			cout << ERR_PAR_BYTE << endl;
			return 1;
		}
		ctr++;
	}

	int byte = stoi(argv[1]);

	if ((byte < 0) || (byte > 255))
	{
		cout << ERR_SIZE_NUM << endl;
		return 1;
	}

	bitset<NUM_BIT> bitVec(byte);
	string bitStrIn = bitVec.to_string();
	string bitStrOut;

	for (int i = 1; i <= NUM_BIT; i++)
		bitStrOut += bitStrIn[NUM_BIT - i];

	double outByte = 0;
	int j = NUM_BIT - 1;
	for (int i = 0; i < NUM_BIT; i++)
	{
		if (bitStrOut[i] == '1')
			outByte += pow(2, j);
		j--;	
	}

	cout << outByte << endl;

	return 0;
}
