
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 21")
{
	Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 83, 238, 2173, 9, 837,
		/*I,S,U,W,NR*/ 1864, 0, 0, 0, 0);
    
    Course C2("CS", "Programming Practicum", 211, 34, "Rehan",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Course C3("CS", "Software Design", 342, 15, "David",
		/*A-F*/ 763, 128, 273, 865, 837,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C4("ME", "Fluid Mechanics", 342, 03, "David He",
		/*A-F*/ 263, 8, 273, 65, 837,
		/*I,S,U,W,NR*/ 0, 45, 76, 0, 0);
    
    Course C5("ME", "Intro to ThermoDynamaics", 251, 11, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 49, 19, 0, 0);
    
    Course C6("CE", "Computer Engineering", 111, 03, "Kevin",
		/*A-F*/ 0, 1238, 0, 9, 0,
		/*I,S,U,W,NR*/ 0, 25, 13, 0, 0);
    
	Course C7("BIOE", "Bio ENG", 342, 57, "Carla Wu",
		/*A-F*/ 1263, 1238, -173, 9865, 837,
		/*I,S,U,W,NR*/ 1, 0, 34, 0, 0);
    
    Course C8("ECE", "Data Mining", 342, 43, "McCarty",
		/*A-F*/ 1263, 12, 2173, 965, 837,
		/*I,S,U,W,NR*/ 1263, 36, 78, 98, 97);
    
	Course C9("IE", "Probabilty", 342, 11, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 12, 199, 377, 234, 98);
    
    Course C10("ENG", "Intro to ENG", 342, 156, "Daizan",
		/*A-F*/ 0, 1238, 0, 9865, 0,
		/*I,S,U,W,NR*/ 0, 266, 324, 0, 0);
    
	Course C11("CS", "Computer Design", 362, 44, "Troy",
		/*A-F*/ 873, 1238, 2173, 65, 837,
		/*I,S,U,W,NR*/ 0, 22, 1, 0, 0);
    
    Course C12("CS", "Computer Algorithms", 401, 02, "DasGupta",
		/*A-F*/ 333, 333, 333, 333, 333,
		/*I,S,U,W,NR*/ 0, 333, 333, 0, 0);
    
	Course C13("CME", "Chemical ENG", 342, 02, "David",
		/*A-F*/ 871, 1238, 213, 98, 837,
		/*I,S,U,W,NR*/ 0, 12, 12, 0, 0);
    
    Course C14("CS", "Machine Organization", 261, 04, "Theys",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 1, 12, 0, 0);
    
	Course C15("ME", "Fundamental Theroms", 333, 97, "David",
		/*A-F*/ 0, 38, 21, 0, 837,
		/*I,S,U,W,NR*/ 123, 12, 12, 0, 0);
    
    Course C16("CE", "Electronics Engineering", 342, 22, "Rehana",
		/*A-F*/ 8, 38, 0, 986, 0,
		/*I,S,U,W,NR*/ 0, 0, 12, 0, 0);
    
	Course C17("BIOE", "Bio Chemical", 442, 79, "Kevin Wu",
		/*A-F*/ -1, -1, -1, -1, -1,
		/*I,S,U,W,NR*/ 0, 4, 12, 0, 0);
    
    Course C18("ECE", "Data Intro", 101, 43, "Shery",
		/*A-F*/ 871, 123, 213, 986, 837,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C19("IE", "Stats for Scientist", 111, 11, "Alan",
		/*A-F*/ 3, 12, -23, 985, 837,
		/*I,S,U,W,NR*/ 0,130, 2342, 0, 0);
    
    Course C20("ENG", "Intro to Depts", 100, 116, "Daizan",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 187, 13, 0, 0);
    
	Course C21("CS", "Network security", 484, 70, "Rehan",
		/*A-F*/ 87, 12, 3, 98, 837,
		/*I,S,U,W,NR*/ 17, 12, 234, 49, 36);
    
    Course C22("CS", "System Programming", 361, 11, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 98, 56, 0, 0);
    
	Course C23("CME", "Intro to Chemical", 345, 05, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);

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
	
    
    GradeStats b = GetGradeDistribution(U);

	REQUIRE(b.PercentA == Approx(11.8881));
    REQUIRE(b.PercentB == Approx(12.6906));
    REQUIRE(b.PercentC == Approx(13.6159));
    REQUIRE(b.PercentD == Approx(44.8299));
    REQUIRE(b.PercentF == Approx(16.9753));
    REQUIRE(b.N == 56199);
    
    

}