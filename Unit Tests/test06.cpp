#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 06")
{
	Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C2("CS", "Software Design", 342, 07, "Bell",
		/*A-F*/ 33, 40, 48, 20, 3,
		/*I,S,U,W,NR*/ 7, 45, 0, 0, 4);

	Dept D("CS");
	D.Courses.push_back(C);
    D.Courses.push_back(C2);

	GetGradeDistribution(D);

	GradeStats b = GetGradeDistribution(D);

	REQUIRE(b.PercentA == Approx(19.3308));
    REQUIRE(b.PercentB == Approx(28.2527));
    REQUIRE(b.PercentC == Approx(29.7397));
    REQUIRE(b.PercentD == Approx(21.5613));
    REQUIRE(b.PercentF == Approx(1.11524));
            


}