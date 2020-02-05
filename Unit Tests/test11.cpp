
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 11")
{
	Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ -6666666, -7777654, -72376, 0, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
	Course C2("ME", "Fluid Mechanics", 469, 03, "David",
		/*A-F*/ 45, 12, 1235, 31248, 1235,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C3("CE", "Computer Engineering", 111, 03, "Shery",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, -14, 13, 0, 0);
    
	Course C4("BIOE", "Bio ENG", 100, 57, "Carla Wu",
		/*A-F*/ -935619, -349347, 31234, 38, 0,
		/*I,S,U,W,NR*/ 99, -8, 555, 214, 1);
    
    Course C5("ECE", "Data Mining", 345, 43, "Asad",
		/*A-F*/ 0, 345, 32, 976, 0,
		/*I,S,U,W,NR*/ 2, -98, 0, 0, 1);
    
	Course C6("IE", "Probabilty", 111, 11, "David",
		/*A-F*/ 2149, 153, 12836, 78, 17465,
		/*I,S,U,W,NR*/ 2, 1234, 134, 12394, 1);
    
    Course C7("ENG", "Intro to ENG", 600, 156, "Faizan",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
	Course C8("CS", "Fluid Mechanics", 139, 34, "Rehan",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C9("CS", "Software Design", 11, 15, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C10("CME", "Chemical ENG", 345, 02, "David",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);

	Dept D("CS");
	Dept D2("ME");
    Dept D3("CE");
    Dept D4("BIOE");
    Dept D5("ECE");
    Dept D6("IE");
    Dept D7("ENG");
    Dept D10("CME");
	
	D.Courses.push_back(C);
    D.Courses.push_back(C8);
    D.Courses.push_back(C2);
	D2.Courses.push_back(C9);
    D3.Courses.push_back(C3);
    D4.Courses.push_back(C5);
    D5.Courses.push_back(C4);
    D6.Courses.push_back(C6);
    D7.Courses.push_back(C10);
    D10.Courses.push_back(C7);


	College U("ENG");

	U.Depts.push_back(D);
    U.Depts.push_back(D2);
    U.Depts.push_back(D3);
    U.Depts.push_back(D4);
    U.Depts.push_back(D5);
    U.Depts.push_back(D6);
    U.Depts.push_back(D7);
    U.Depts.push_back(D10);
	
    

	vector<Course> foundCourses = FindCourses(U, 1);
    REQUIRE(foundCourses.empty() == true);
    REQUIRE(foundCourses.size() == 0);
    
    //Course g = foundCourses[0];
    
    //REQUIRE(g.Dept == "CS");
    
    
    
   
	
    

}