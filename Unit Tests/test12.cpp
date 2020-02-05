
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 12")
{
	vector<Course> co;
	Course C("CS", "Data Structures", 251, 03, "Dasgupta",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
	Course C2("ME", "Fluid Mechanics", 483, 24, "Kevin Fu",
		/*A-F*/ 101, 67, 48, 38, 32,
		/*I,S,U,W,NR*/ 2, 34, 5, 8, 1);
    Course C3("IE", "Probability and Stats", 345, 887, "David He",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    Course C4("CE", "Fluid Mechanics", 277, 11, "Troy",
		/*A-F*/ 234, 4567, 21324, 38, 198,
		/*I,S,U,W,NR*/ 67, 125, 23, 45, 34);

	Dept D("CS");
	Dept D2("ME");
    Dept D3("IE");
    Dept D4("CE");

	D.Courses.push_back(C);
	D2.Courses.push_back(C2);
    D3.Courses.push_back(C3);
    D4.Courses.push_back(C4);


	College U("ENG");

	U.Depts.push_back(D);
	U.Depts.push_back(D2);
    U.Depts.push_back(D3);
    U.Depts.push_back(D4);
    
	string n = "Da";

	co = FindCourses(U, n);
    REQUIRE(co.size() == 2);
    REQUIRE(co.empty() == false);
    
    REQUIRE(co[0].Dept == "CS");
    REQUIRE(co[0].Title == C.Title);
    REQUIRE(co[0].Number == C.Number);
    REQUIRE(co[0].Instructor == C.Instructor);
    REQUIRE(co[0].Section == C.Section);
    REQUIRE(co[0].getGradingType() == Course::Letter);
    
    REQUIRE(co[1].Dept == "IE");
    REQUIRE(co[1].Title == C3.Title);
    REQUIRE(co[1].Number == C3.Number);
    REQUIRE(co[1].Instructor == C3.Instructor);
    REQUIRE(co[1].Section == C3.Section);
    REQUIRE(co[1].getGradingType() == Course::Unknown);
    
    
}