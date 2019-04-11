#include "pch.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const string ERR_NUM_ARG = "Usage: multmatrix.exe <matrix file1> <matrix file2>";
const string ERR_FILE_OPEN = "Error: file not opened";

const int SIZE = 3;

struct MyMatrix
{
	double matrix_struct[SIZE][SIZE];
};

int openFile(ifstream& file, string fileName)
{
	file.open(fileName);
	if (file.is_open())
		return 0;
	else
	{
		return 1;
	}
}

int printMatrix(MyMatrix& matrix)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << fixed << setprecision(3) << matrix.matrix_struct[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

int readMatrix(ifstream& file, MyMatrix& matrix)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			file >> matrix.matrix_struct[i][j];
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

	MyMatrix firstMatrix = {};
	MyMatrix secondMatrix = {};
	MyMatrix resultMatrix = {};

	ifstream fileFirst;
	openFile(fileFirst, FILE_IN_FIRST);
	readMatrix(fileFirst, firstMatrix);

	ifstream fileSecond;
	openFile(fileSecond, FILE_IN_SECOND);
	readMatrix(fileSecond, secondMatrix);

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			resultMatrix.matrix_struct[i][j] = 0;
			for (int k = 0; k < SIZE; k++)
				resultMatrix.matrix_struct[i][j] += firstMatrix.matrix_struct[i][k] * secondMatrix.matrix_struct[k][j];
		}

	if ((openFile(fileFirst, FILE_IN_FIRST) == 0) && (openFile(fileSecond, FILE_IN_SECOND) == 0))
		printMatrix(resultMatrix);
	else
		cout << ERR_FILE_OPEN << endl;
	return 0;
}
