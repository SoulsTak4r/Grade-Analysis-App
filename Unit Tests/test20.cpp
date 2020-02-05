
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 20")
{
	Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ -6666666, -7777654, -72376, 0, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C2("CS", "Programming Practicum", 211, 34, "Rehan",
		/*A-F*/ 11234, 456, 734, 38, 1234,
		/*I,S,U,W,NR*/ 2, 125, 88888, 34, 1);
    
    Course C3("CS", "Software Design", 342, 15, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C4("ME", "Fluid Mechanics", 342, 03, "David He",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 991239, 191299, 0, 0);
    
    Course C5("ME", "Intro to ThermoDynamaics", 251, 11, "David",
		/*A-F*/ 45, 12, 1235, 31248, 1235,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Course C6("CE", "Computer Engineering", 111, 03, "Kevin",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 176, 1234, 0, 0);
    
	Course C7("BIOE", "Bio ENG", 342, 57, "Carla Wu",
		/*A-F*/ 935619, 349347, 31234, 38, 0,
		/*I,S,U,W,NR*/ 99, -8, 555, 214, 1);
    
    Course C8("ECE", "Data Mining", 342, 43, "McCarty",
		/*A-F*/ 0, 345, 32, 976, 0,
		/*I,S,U,W,NR*/ 2, 0, 76, 0, 1);
    
	Course C9("IE", "Probabilty", 342, 11, "David",
		/*A-F*/ 2149, 153, 12836, 78, 17465,
		/*I,S,U,W,NR*/ 2, 1234, 134, 12394, 1);
    
    Course C10("ENG", "Intro to ENG", 342, 156, "Daizan",
		/*A-F*/ 19, 36, 13, 0, 0,
		/*I,S,U,W,NR*/ 36, 986, 0, 0, 1);
    
	Course C11("CS", "Computer Design", 362, 44, "Troy",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 10, 0, 0, -38, 11);
    
    Course C12("CS", "Computer Algorithms", 401, 02, "DasGupta",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C13("CME", "Chemical ENG", 342, 02, "David",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C14("CS", "Machine Organization", 261, 04, "Theys",
		/*A-F*/ 6666, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 91724632, 0);
    
	Course C15("ME", "Fundamental Theroms", 333, 97, "David",
		/*A-F*/ 45, 12, 1235, 31248, 1235,
		/*I,S,U,W,NR*/ 86, 0, 0, 99, 14);
    
    Course C16("CE", "Electronics Engineering", 342, 22, "Rehana",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C17("BIOE", "Bio Chemical", 442, 79, "Kevin Wu",
		/*A-F*/ 9356, 349347, 31234, 38, 0,
		/*I,S,U,W,NR*/ 99, 18, 555, 214, 1);
    
    Course C18("ECE", "Data Intro", 101, 43, "Shery",
		/*A-F*/ 0, 345, 32, 976, 0,
		/*I,S,U,W,NR*/ 2, 98, 0, 0, 1);
    
	Course C19("IE", "Stats for Scientist", 111, 11, "Alan",
		/*A-F*/ 2149, 153, 12836, 78, 17465,
		/*I,S,U,W,NR*/ 2, 1234, 134, 12394, 1);
    
    Course C20("ENG", "Intro to Depts", 100, 116, "Daizan",
		/*A-F*/ 0, 0, 961, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C21("CS", "Network security", 484, 70, "Rehan",
		/*A-F*/ 39, 3156, 86, 38, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Course C22("CS", "System Programming", 361, 11, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C23("CME", "Intro to Chemical", 345, 05, "David",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 0, 0, 0, 1);

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
	
    

	int DFW;
	int N;
	double avg = GetDFWRate(U, DFW, N);
    
    REQUIRE(DFW ==  91853413);
    REQUIRE(N == 93617336);
    
	REQUIRE(avg == Approx(98.1158));
    
    
    
    
	
    

}