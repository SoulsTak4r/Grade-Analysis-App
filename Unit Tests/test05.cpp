#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 05")
{
    Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);

	GetGradeDistribution(C);
	GradeStats b = GetGradeDistribution(C);

	REQUIRE(b.PercentA == Approx(15.2));
    REQUIRE(b.PercentB == Approx(28.8));
	REQUIRE(b.PercentC == Approx(25.6));
	REQUIRE(b.PercentD == Approx(30.4));
	REQUIRE(b.PercentF == Approx(0.0));
}