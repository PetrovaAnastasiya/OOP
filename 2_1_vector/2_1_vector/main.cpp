#include "Header.h"
#include "pch.h"

int main()
{
	vector<double> inVector;
	double max;
	double divider;
	readVector(inVector);
	max = findMax(inVector);
	divider = max * 0.5;
	if (divider != 0)
	{
		processVector(inVector, divider);
		sortVector(inVector);
		printVector(inVector);
	}
	else
		cout << "Error! Division by 0" << endl;
}