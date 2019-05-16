#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

bool readVector(vector<double>& rVector);
bool sortVector(vector<double>& sVector);
double findMax(vector<double>& inVector);
void processVector(vector<double>& inVector, double divider);
void printVector(vector<double>& inVector);