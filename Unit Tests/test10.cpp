
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 10")
{
	vector<Course> co;
	Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C2("CS", "Intro to CS", 289, 03, "Rilius",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 4765, 45, 0, 0);
    Course C3("CS", "Intro to Data Science", 418, 14, "Rillis",
		/*A-F*/ 2345, 1430, 33469, 66666, 450123,
		/*I,S,U,W,NR*/ 47, 0, 0, 0, 20);

	Dept D("CS");
	D.Courses.push_back(C);
    D.Courses.push_back(C2);
    D.Courses.push_back(C3);
	string n = "Ri";
    

	co = FindCourses(D, n);
    
    REQUIRE(co.empty() == false);
    
    REQUIRE(co[0].Title == C2.Title);
    REQUIRE(co[0].Number == C2.Number);
    REQUIRE(co[0].Instructor == C2.Instructor);
    REQUIRE(co[0].getGradingType() == Course::Satisfactory);
    
    
    REQUIRE(co[1].Title == C3.Title);
    REQUIRE(co[1].Number == C3.Number);
    REQUIRE(co[1].Instructor == C3.Instructor);
    REQUIRE(co[1].getGradingType() == Course::Letter);
    
    

}