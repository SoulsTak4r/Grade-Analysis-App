
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 07")
{
	Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 23, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C2("ME", "Fluid Mechanics", 101, 12, "Alan",
		/*A-F*/ 32, 58, 43, 14, 5,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);


	Dept D("CS");
    Dept D2("ME");
	D.Courses.push_back(C);
    D2.Courses.push_back(C2);

	College clg("ENG");
	clg.Depts.push_back(D);
    clg.Depts.push_back(D2);

	GetGradeDistribution(clg);

	GradeStats b = GetGradeDistribution(clg);

	REQUIRE(b.PercentA == Approx(19.5729));
    REQUIRE(b.PercentB == Approx(33.4519));
    REQUIRE(b.PercentC == Approx(26.6903));
    REQUIRE(b.PercentD == Approx(18.5053));
    REQUIRE(b.PercentF == Approx(1.77935));




}