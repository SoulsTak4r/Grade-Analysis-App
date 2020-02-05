#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 16")
{
	Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 239587, 124796, 99999, 10000, 666666,
		/*I,S,U,W,NR*/ 123, 135, 1235, 2145, 88);
    
    Course C2("CS", "Software Design", 342, 07, "Bell",
		/*A-F*/ 100000, 1294874, 19284734, 7724630, 3289958,
		/*I,S,U,W,NR*/ 12, 45, 23, 67, 123);
    Course C3("ME", "Fluid Mechanics", 277, 198, "David",
		/*A-F*/ 2352, 4408, 104506, 7512439, 566666,
		/*I,S,U,W,NR*/ 33, 2345, 1234, 335, 87);
    Course C4("BIOE", "Intro to Bio Eng", 101, 14, "Kevin Yu",
		/*A-F*/ 12432598, 58327429, 682349, 1234859, 757320,
		/*I,S,U,W,NR*/ 24, 0, 48, 0, 0);
    Course C5("BIOS", "Population and community", 100, 155, "Alan",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);

	Dept D("CS");
	D.Courses.push_back(C);
    D.Courses.push_back(C2);
    D.Courses.push_back(C3);
    D.Courses.push_back(C4);
    D.Courses.push_back(C5);
    

	GetGradeDistribution(D);

	GradeStats b = GetGradeDistribution(D);

	REQUIRE(b.PercentA == Approx(11.1606));
    REQUIRE(b.PercentB == Approx(52.2028));
    REQUIRE(b.PercentC == Approx(17.6232));
    REQUIRE(b.PercentD == Approx(14.3997));
    REQUIRE(b.PercentF == Approx(4.61349));
            


}