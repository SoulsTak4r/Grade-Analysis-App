
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 17")
{
	Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ -6666666, -7777654, -72376, 0, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C2("CS", "Programming Practicum", 211, 34, "Rehan",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C3("CS", "Software Design", 342, 15, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C4("ME", "Fluid Mechanics", 342, 03, "David He",
		/*A-F*/ 45, 12, 1235, 31248, 1235,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C5("ME", "Intro to ThermoDynamaics", 251, 11, "David",
		/*A-F*/ 45, 12, 1235, 31248, 1235,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C6("CE", "Computer Engineering", 111, 03, "Kevin",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, -14, 13, 0, 0);
    
	Course C7("BIOE", "Bio ENG", 100, 57, "Carla Wu",
		/*A-F*/ -935619, -349347, 31234, 38, 0,
		/*I,S,U,W,NR*/ 99, -8, 555, 214, 1);
    
    Course C8("ECE", "Data Mining", 345, 43, "McCarty",
		/*A-F*/ 0, 345, 32, 976, 0,
		/*I,S,U,W,NR*/ 2, -98, 0, 0, 1);
    
	Course C9("IE", "Probabilty", 342, 11, "David",
		/*A-F*/ 2149, 153, 12836, 78, 17465,
		/*I,S,U,W,NR*/ 2, 1234, 134, 12394, 1);
    
    Course C10("ENG", "Intro to ENG", 600, 156, "Daizan",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
	Course C11("CS", "Computer Design", 362, 44, "Troy",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C12("CS", "Computer Algorithms", 401, 02, "DasGupta",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C13("CME", "Chemical ENG", 345, 02, "David",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C14("CS", "Machine Organization", 261, 04, "Theys",
		/*A-F*/ -6666666, -7777654, -72376, 0, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
	Course C15("ME", "Fundamental Theroms", 333, 97, "David",
		/*A-F*/ 45, 12, 1235, 31248, 1235,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C16("CE", "Electronics Engineering", 342, 22, "Rehana",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, -14, 13, 0, 0);
    
	Course C17("BIOE", "Bio Chemical", 442, 79, "Kevin Wu",
		/*A-F*/ -935619, -349347, 31234, 38, 0,
		/*I,S,U,W,NR*/ 99, -8, 555, 214, 1);
    
    Course C18("ECE", "Data Intro", 101, 43, "Shery",
		/*A-F*/ 0, 345, 32, 976, 0,
		/*I,S,U,W,NR*/ 2, -98, 0, 0, 1);
    
	Course C19("IE", "Stats for Scientist", 111, 11, "Alan",
		/*A-F*/ 2149, 153, 12836, 78, 17465,
		/*I,S,U,W,NR*/ 2, 1234, 134, 12394, 1);
    
    Course C20("ENG", "Intro to Depts", 100, 116, "Daizan",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
	Course C21("CS", "Network security", 484, 70, "Rehan",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C22("CS", "System Programming", 361, 11, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C23("CME", "Intro to Chemical", 345, 05, "David",
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
    D.Courses.push_back(C2);
    D.Courses.push_back(C3);
    D.Courses.push_back(C11);
    D.Courses.push_back(C12);
    D.Courses.push_back(C14);
    D.Courses.push_back(C21);
    D.Courses.push_back(C22);
    
	D2.Courses.push_back(C4);
    D2.Courses.push_back(C5);
    D2.Courses.push_back(C15);
    
    D3.Courses.push_back(C6);
    D3.Courses.push_back(C16);
    
    D4.Courses.push_back(C7);
    D4.Courses.push_back(C17);
    
    D5.Courses.push_back(C8);
    D5.Courses.push_back(C18);
    
    D6.Courses.push_back(C9);
    D6.Courses.push_back(C19);
    
    D7.Courses.push_back(C10);
    D7.Courses.push_back(C20);
    
    D10.Courses.push_back(C13);
    D10.Courses.push_back(C23);
	


	College U("ENG");

	U.Depts.push_back(D);
    U.Depts.push_back(D2);
    U.Depts.push_back(D3);
    U.Depts.push_back(D4);
    U.Depts.push_back(D5);
    U.Depts.push_back(D6);
    U.Depts.push_back(D7);
    U.Depts.push_back(D10);
	
    

    
    
    vector<Course> co = FindCourses(U, "D");
    
    
    REQUIRE(co.empty() == false);
    REQUIRE(co.size() == 11);
    
    REQUIRE(co[0].Dept == "ENG");
    REQUIRE(co[0].Title == C20.Title);
    REQUIRE(co[0].Number == C20.Number);
    REQUIRE(co[0].Instructor == C20.Instructor);
    REQUIRE(co[0].Section == C20.Section);
    REQUIRE(co[0].getGradingType() == Course::Letter);
    
    REQUIRE(co[1].Dept == "ENG");
    REQUIRE(co[1].Title == C10.Title);
    REQUIRE(co[1].Number == C10.Number);
    REQUIRE(co[1].Instructor == C10.Instructor);
    REQUIRE(co[1].Section == C10.Section);
    REQUIRE(co[1].getGradingType() == Course::Letter);
    
    REQUIRE(co[2].Dept == "CS");
    REQUIRE(co[2].Title == C12.Title);
    REQUIRE(co[2].Number == C12.Number);
    REQUIRE(co[2].Instructor == C12.Instructor);
    REQUIRE(co[2].Section == C12.Section);
    REQUIRE(co[2].getGradingType() == Course::Unknown);
    
    REQUIRE(co[3].Dept == "ME");
    REQUIRE(co[3].Title == C5.Title);
    REQUIRE(co[3].Number == C5.Number);
    REQUIRE(co[3].Instructor == C5.Instructor);
    REQUIRE(co[3].Section == C5.Section);
    REQUIRE(co[3].getGradingType() == Course::Letter);
    
    REQUIRE(co[4].Dept == "ME");
    REQUIRE(co[4].Title == C15.Title);
    REQUIRE(co[4].Number == C15.Number);
    REQUIRE(co[4].Instructor == C15.Instructor);
    REQUIRE(co[4].Section == C15.Section);
    REQUIRE(co[4].getGradingType() == Course::Letter);
    
    REQUIRE(co[5].Dept == "IE");
    REQUIRE(co[5].Title == C9.Title);
    REQUIRE(co[5].Number == C9.Number);
    REQUIRE(co[5].Instructor == C9.Instructor);
    REQUIRE(co[5].Section == C9.Section);
    REQUIRE(co[5].getGradingType() == Course::Letter);
    
    REQUIRE(co[6].Dept == "CS");
    REQUIRE(co[6].Title == C3.Title);
    REQUIRE(co[6].Number == C3.Number);
    REQUIRE(co[6].Instructor == C3.Instructor);
    REQUIRE(co[6].Section == C3.Section);
    REQUIRE(co[6].getGradingType() == Course::Unknown);
    
    REQUIRE(co[7].Dept == "CME");
    REQUIRE(co[7].Title == C13.Title);
    REQUIRE(co[7].Number == C13.Number);
    REQUIRE(co[7].Instructor == C13.Instructor);
    REQUIRE(co[7].Section == C13.Section);
    REQUIRE(co[7].getGradingType() == Course::Letter);
    
    REQUIRE(co[8].Dept == "CME");
    REQUIRE(co[8].Title == C23.Title);
    REQUIRE(co[8].Number == C23.Number);
    REQUIRE(co[8].Instructor == C23.Instructor);
    REQUIRE(co[8].Section == C23.Section);
    REQUIRE(co[8].getGradingType() == Course::Letter);
    
    
    REQUIRE(co[9].Dept == "CS");
    REQUIRE(co[9].Title == C22.Title);
    REQUIRE(co[9].Number == C22.Number);
    REQUIRE(co[9].Instructor == C22.Instructor);
    REQUIRE(co[9].Section == C22.Section);
    REQUIRE(co[9].getGradingType() == Course::Unknown);
    
    REQUIRE(co[10].Dept == "ME");
    REQUIRE(co[10].Title == C4.Title);
    REQUIRE(co[10].Number == C4.Number);
    REQUIRE(co[10].Instructor == C4.Instructor);
    REQUIRE(co[10].Section == C4.Section);
    REQUIRE(co[10].getGradingType() == Course::Letter);
    
}