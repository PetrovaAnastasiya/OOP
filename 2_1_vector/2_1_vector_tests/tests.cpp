#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "pch.h"
#include "2_1_vector\Header.h"

TEST_CASE("")
{
	vector<double> tVector = {9, 5, 6, 2};
	vector<double> dVector = {-9, -5, -6, 0};
	vector<double> r1Vector = {2, 5 / 4.5, 6 / 4.5, 2 / 4.5};
	vector<double> r2Vector = { -9 / 4.5, -5 / 4.5, -6 / 4.5, 0 / 4.5 };

	CHECK(findMax(tVector) == 9);
	CHECK(findMax(dVector) == 0);
	
	processVector(tVector, 4.5);
	CHECK(tVector == r1Vector);
	processVector(dVector, 4.5);
	CHECK(dVector == r2Vector);

	CHECK(sortVector(dVector) == true);
	CHECK(sortVector(tVector) == true);
}