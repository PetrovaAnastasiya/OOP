#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const string ERR_NUM_ARG = "Usage: multmatrix.exe <matrix file1> <matrix file2>";
const string ERR_FILE_OPEN = "Error: file not opened";

const int SIZE = 3;

//засунуть матрицу в стракт и передать по ссылке

bool openFile(ifstream& file, string fileName)
{
	file.open(fileName);
	if (file.is_open())
		return true;
	else
	{
		return false;
	}
}

int printMatrix(int matrix[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

int readMatrix(ifstream& file, int matrix[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			file >> matrix[i][j];
		}
	}
	return 0;
	file.close();
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << ERR_NUM_ARG << endl;
		return 1;
	}

	const string FILE_IN_FIRST = argv[1];
	const string FILE_IN_SECOND = argv[2];

	int firstMatrix[SIZE][SIZE] = {};
	int secondMatrix[SIZE][SIZE] = {};
	int resultMatrix[SIZE][SIZE] = {};

	ifstream fileFirst;
	openFile(fileFirst, FILE_IN_FIRST);
	readMatrix(fileFirst, firstMatrix);

	ifstream fileSecond;
	openFile(fileSecond, FILE_IN_SECOND);
	readMatrix(fileSecond, secondMatrix);

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			resultMatrix[i][j] = 0;
			for (int k = 0; k < SIZE; k++)
				resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
		}

	if ((openFile(fileFirst, FILE_IN_FIRST)) || (openFile(fileFirst, FILE_IN_FIRST)))
		cout << ERR_FILE_OPEN << endl;
	else
		printMatrix(resultMatrix);

		/*if (openFile(fileFirst, FILE_IN_FIRST))
		printMatrix(firstMatrix);
	else
		cout << ERR_FILE_OPEN;

	if (openFile(fileSecond, FILE_IN_SECOND))
		printMatrix(secondMatrix);
	else
		cout << ERR_FILE_OPEN;
	*/
		return 0;
}
