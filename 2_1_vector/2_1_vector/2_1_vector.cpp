#include "Header.h"
#include "pch.h"

bool readVector(vector<double>& rVector)
{
	double inputStr;
	while (cin >> inputStr)
	{
		rVector.push_back(inputStr);
	}
	return true;
}

bool sortVector(vector<double>& sVector)
{
	sort(sVector.begin(), sVector.end());
	return true;
}

double findMax(vector<double>& inVector)
{
	double elem = 0;
	elem = *max_element(inVector.begin(), inVector.end());
	return elem;
}

void processVector(vector<double>& inVector, double divider)
{
	transform(inVector.begin(), inVector.end(), inVector.begin(), [=](double inp) { return inp / divider; });
	/*for (int i = 0; i != inVector.size(); i++)
	{
		inVector[i] = inVector[i] / devider;
	}*/
}

void printVector(vector<double>& inVector)
{
	copy(inVector.begin(), inVector.end(), ostream_iterator<double>(cout, " "));
}

