#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 15")
{
	Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ -666666, -66666, -66666, -66666, -666666,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Course C2("CE", "Intro to Computer", 342, 07, "Bell",
		/*A-F*/ 91, 193275019, 912, 4, 41,
            /*I,S,U,W,NR*/ 1394823, 44444, 44444, 2398247, 2308523);
    
    Course C3("ME", "Software Design", 211, 18, "Troy",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 762745, 837426724, 0, 0);
    
    Course C4("IE", "Probability", 342, 9, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);

	Dept D("CS");
    Dept D2("CE");
    Dept D3("ME");
    Dept D4("IE");
	D.Courses.push_back(C);
    D2.Courses.push_back(C2);
    D3.Courses.push_back(C3);
    D4.Courses.push_back(C4);
    

	GradeStats b = GetGradeDistribution(D);

	REQUIRE(b.PercentA == Approx(0.0));
    REQUIRE(b.PercentB == Approx(0.0));
    REQUIRE(b.PercentC == Approx(0.0));
    REQUIRE(b.PercentD == Approx(0.0));
    REQUIRE(b.PercentF == Approx(0.0));
            
    GradeStats a = GetGradeDistribution(D2);
    
    REQUIRE(a.PercentA == Approx(0.00004));
    REQUIRE(a.PercentB == Approx(99.9994));
    REQUIRE(a.PercentC == Approx(0.00047));
    REQUIRE(a.PercentD == Approx(0.000002));
    REQUIRE(a.PercentF == Approx(0.00002));
    
    GradeStats c = GetGradeDistribution(D3);
    
    REQUIRE(c.PercentA == Approx(0.0));
    REQUIRE(c.PercentB == Approx(0.0));
    REQUIRE(c.PercentC == Approx(0.0));
    REQUIRE(c.PercentD == Approx(0.0));
    REQUIRE(c.PercentF == Approx(0.0));
    
    GradeStats d = GetGradeDistribution(D4);
    
    REQUIRE(d.PercentA == Approx(0.0));
    REQUIRE(d.PercentB == Approx(0.0));
    REQUIRE(d.PercentC == Approx(0.0));
    REQUIRE(d.PercentD == Approx(0.0));
    REQUIRE(d.PercentF == Approx(0.0));


}