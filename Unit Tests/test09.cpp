#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 09")
{
	vector<Course> co;
    
	Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C2("CS", "Machine Organization", 251, 10, "Theys",
		/*A-F*/ 50, 43, 22, 24, 4,
		/*I,S,U,W,NR*/ 3, 77, 0, 0, 2);
    
    

	Dept D("CS");
	D.Courses.push_back(C);
    D.Courses.push_back(C2);
	int cn = 251;
    

	co = FindCourses(D, cn);
	
	
    REQUIRE(co.empty() == false);
    
    REQUIRE(co[0].Number == 251);
    REQUIRE(co[0].Section == 03);
    REQUIRE(co[1].Number == C2.Number);
    REQUIRE(co[1].Section == C2.Section);
    
    
}