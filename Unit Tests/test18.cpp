#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 18")
{
    Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 666666, 0, 0, 10000, -150,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    Course C2("CE", "Data Structures", 308, 11, "David",
		/*A-F*/ 145, 346, 1459, 98, 150,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    Course C3("ME", "Data Structures", 211, 63, "kevin",
		/*A-F*/ -123, -45, 0, -46, -900,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    Course C4("ECE", "Data Structures", 489, 07, "Alan",
		/*A-F*/ 66, 478, 30, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    Course C5("BIOE", "Data Structures", 599, 12, "McCarty",
		/*A-F*/ 1234, 1234, -1234, 1234, 1234,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Course C6("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 666666, 66666, 66666, 66666, 666666,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Course C7("CE", "Intro to Computer", 342, 07, "Bell",
		/*A-F*/ 0, 0, 0, 0, 0,
            /*I,S,U,W,NR*/ 1394823, 44444, 44444, 2398247, 2308523);
    
    Course C8("ME", "Software Design", 211, 18, "Troy",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 762745, 837426724, 0, 0);
    
    Course C9("IE", "Probability", 342, 9, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Course C10("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 666666, 0, 0, 10000, -150,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    Course C11("CE", "Data Structures", 308, 11, "David",
		/*A-F*/ 145, 346, 1459, 98, 150,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    Course C12("ME", "Data Structures", 211, 63, "kevin",
		/*A-F*/ -123, -45, 0, -46, -900,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    Course C13("ECE", "Data Structures", 489, 07, "Alan",
		/*A-F*/ 66, 478, 30, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    Course C14("BIOE", "Data Structures", 599, 12, "McCarty",
		/*A-F*/ 1234, 1234, -1234, 1234, 1234,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Course C15("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 666666, 66666, 66666, 66666, 666666,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Course C16("CE", "Intro to Computer", 342, 07, "Bell",
		/*A-F*/ 0, 0, 0, 0, 0,
            /*I,S,U,W,NR*/ 1394823, 44444, 44444, 2398247, 2308523);
    
    Course C17("ME", "Software Design", 211, 18, "Troy",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 762745, 837426724, 0, 0);
    
    Course C18("IE", "Probability", 342, 9, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Dept D("CS");
    Dept D2("CE");
    Dept D3("ME");
    Dept D4("ECE");
    Dept D5("BIOE");
    Dept D6("IE");
    
    
    D.Courses.push_back(C);
    D.Courses.push_back(C6);
    D.Courses.push_back(C10);
    D.Courses.push_back(C15);
    
    D2.Courses.push_back(C2);
    D2.Courses.push_back(C7);
    D2.Courses.push_back(C11);
    D2.Courses.push_back(C16);
    
    D3.Courses.push_back(C3);
    D3.Courses.push_back(C8);
    D3.Courses.push_back(C12);
    D3.Courses.push_back(C17);
    
    D4.Courses.push_back(C4);
    D4.Courses.push_back(C13);
    
    D5.Courses.push_back(C5);
    D5.Courses.push_back(C14);
    
    D6.Courses.push_back(C9);
    D6.Courses.push_back(C18);
    
    College U("Engineering");
    
    U.Depts.push_back(D);
    U.Depts.push_back(D2);
    U.Depts.push_back(D3);
    U.Depts.push_back(D4);
    U.Depts.push_back(D5);
    U.Depts.push_back(D6);
    
    
    
	int DFW;
	int N;
	double avg = GetDFWRate(U, DFW, N);
    
    REQUIRE(DFW ==  1491796);
    REQUIRE(N == 4432640);
    
	REQUIRE(avg == Approx(33.6547));
}