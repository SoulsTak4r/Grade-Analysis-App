
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

#include "gradeutil.h"

#include "catch.hpp"

using namespace std;

TEST_CASE("Test 23")
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
    
    Course C24("CS", "Ted Talk", 261, 03, "Lillis",
		/*A-F*/ -6666666, -7777654, -72376, 0, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C25("CS", "Programming Practicum", 211, 34, "Rehan",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C26("CS", "Soft Engineering", 442, 15, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C27("ME", "Stats", 302, 03, "David He",
		/*A-F*/ 45, 12, 1235, 31248, 1235,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C28("ME", "Intro to Thermo", 211, 11, "David",
		/*A-F*/ 45, 12, 1235, 31248, 1235,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C29("CE", "Computer Mechanics", 191, 03, "Kevin",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, -14, 13, 0, 0);
    
	Course C30("BIOE", "Bio ENG", 100, 57, "Carla Wu",
		/*A-F*/ -935619, -349347, 31234, 38, 0,
		/*I,S,U,W,NR*/ 99, -8, 555, 214, 1);
    
    Course C31("ECE", "Data Mining", 345, 43, "McCarty",
		/*A-F*/ 0, 345, 32, 976, 0,
		/*I,S,U,W,NR*/ 2, -98, 0, 0, 1);
    
	Course C32("IE", "Stats for Science", 469, 11, "David",
		/*A-F*/ 2149, 153, 12836, 78, 17465,
		/*I,S,U,W,NR*/ 2, 1234, 134, 12394, 1);
    
    Course C33("ENG", "Intro to Logic", 610, 156, "Daizan",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
	Course C34("CS", "Computer Design", 362, 44, "Troy",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C35("CS", "Computer Algorithms 2", 501, 02, "DasGupta",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C36("CME", "Chemical", 340, 02, "David",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C37("CS", "Machine Organization", 261, 04, "Theys",
		/*A-F*/ -6666666, -7777654, -72376, 0, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
	Course C38("ME", "Fundamental Therom of Calculas", 181, 97, "David",
		/*A-F*/ 45, 12, 1235, 31248, 1235,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C39("CE", "Electronics Engineering", 342, 22, "Rehana",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, -14, 13, 0, 0);
    
	Course C40("BIOE", "Bio Chemical", 442, 79, "Kevin Wu",
		/*A-F*/ -935619, -349347, 31234, 38, 0,
		/*I,S,U,W,NR*/ 99, -8, 555, 214, 1);
    
    Course C41("ECE", "Data Intro", 101, 43, "Shery",
		/*A-F*/ 0, 345, 32, 976, 0,
		/*I,S,U,W,NR*/ 2, -98, 0, 0, 1);
    
	Course C42("IE", "Stats for Scientist", 111, 11, "Alan",
		/*A-F*/ 2149, 153, 12836, 78, 17465,
		/*I,S,U,W,NR*/ 2, 1234, 134, 12394, 1);
    
    Course C43("ENG", "Intro to Distric", 101, 116, "Daizan",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
	Course C44("CS", "Network security", 484, 70, "Rehan",
		/*A-F*/ 19, 36, 32, 38, 0,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C45("CS", "System Design", 461, 11, "David",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
	Course C46("CME", "Intro to Chemical Ind", 340, 05, "David",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C47("CME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C48("CME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C49("CME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C50("CME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C51("CME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C52("CME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C53("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C54("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C55("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C56("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C57("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C58("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C59("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C60("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C61("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C62("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C63("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C64("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    
    Course C65("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C66("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C67("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C68("ME", "Intro to Chemical Ind", 340, 05, "Did",
		/*A-F*/ 54, 313, 19, 9, 12,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C69("ME", "Intro to Chemical Ind", 340, 05, "Did",
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
    D.Courses.push_back(C24);
    D.Courses.push_back(C25);
    D.Courses.push_back(C26);
    D.Courses.push_back(C34);
    D.Courses.push_back(C35);
    D.Courses.push_back(C37);
    D.Courses.push_back(C44);
    D.Courses.push_back(C45);
    
    
    
	D2.Courses.push_back(C4);
    D2.Courses.push_back(C5);
    D2.Courses.push_back(C15);
    D2.Courses.push_back(C27);
    D2.Courses.push_back(C28);
    D2.Courses.push_back(C38);
    D2.Courses.push_back(C53);
    D2.Courses.push_back(C54);
    D2.Courses.push_back(C55);
    D2.Courses.push_back(C56);
    D2.Courses.push_back(C57);
    D2.Courses.push_back(C58);
    D2.Courses.push_back(C59);
    D2.Courses.push_back(C60);
    D2.Courses.push_back(C61);
    D2.Courses.push_back(C62);
    D2.Courses.push_back(C63);
    D2.Courses.push_back(C64);
    D2.Courses.push_back(C65);
    D2.Courses.push_back(C66);
    D2.Courses.push_back(C67);
    D2.Courses.push_back(C68);
    D2.Courses.push_back(C69);
    
    D3.Courses.push_back(C6);
    D3.Courses.push_back(C16);
    D3.Courses.push_back(C29);
    D3.Courses.push_back(C39);
    
    D4.Courses.push_back(C7);
    D4.Courses.push_back(C17);
    D4.Courses.push_back(C30);
    D4.Courses.push_back(C40);
    
    D5.Courses.push_back(C8);
    D5.Courses.push_back(C18);
    D5.Courses.push_back(C31);
    D5.Courses.push_back(C41);
    
    D6.Courses.push_back(C9);
    D6.Courses.push_back(C19);
    D6.Courses.push_back(C32);
    D6.Courses.push_back(C42);
    
    
    D7.Courses.push_back(C10);
    D7.Courses.push_back(C20);
    D7.Courses.push_back(C33);
    D7.Courses.push_back(C43);
    
    D10.Courses.push_back(C13);
    D10.Courses.push_back(C23);
    D10.Courses.push_back(C36);
    D10.Courses.push_back(C46);
    D10.Courses.push_back(C47);
    D10.Courses.push_back(C48);
    D10.Courses.push_back(C49);
    D10.Courses.push_back(C50);
	D10.Courses.push_back(C51);
    D10.Courses.push_back(C52);
    


	College U("ENG");

	U.Depts.push_back(D);
    U.Depts.push_back(D2);
    U.Depts.push_back(D3);
    U.Depts.push_back(D4);
    U.Depts.push_back(D5);
    U.Depts.push_back(D6);
    U.Depts.push_back(D7);
    U.Depts.push_back(D10);
	
    

    
    
    vector<Course> co = FindCourses(U, "Da");
    
    
    REQUIRE(co.empty() == false);
    REQUIRE(co.size() == 22);
    
    
        
    
    REQUIRE(co[0].Dept == "ENG");
    REQUIRE(co[0].Title == C20.Title);
    REQUIRE(co[0].Number == C20.Number);
    REQUIRE(co[0].Instructor == C20.Instructor);
    REQUIRE(co[0].Section == C20.Section);
    REQUIRE(co[0].getGradingType() == Course::Letter);
    
    REQUIRE(co[1].Dept == "ENG");
    REQUIRE(co[1].Title == C43.Title);
    REQUIRE(co[1].Number == C43.Number);
    REQUIRE(co[1].Instructor == C43.Instructor);
    REQUIRE(co[1].Section == C43.Section);
    REQUIRE(co[1].getGradingType() == Course::Letter);
    
    REQUIRE(co[2].Dept == "ENG");
    REQUIRE(co[2].Title == C10.Title);
    REQUIRE(co[2].Number == C10.Number);
    REQUIRE(co[2].Instructor == C10.Instructor);
    REQUIRE(co[2].Section == C10.Section);
    REQUIRE(co[2].getGradingType() == Course::Letter);
    
    REQUIRE(co[3].Dept == "ENG");
    REQUIRE(co[3].Title == C33.Title);
    REQUIRE(co[3].Number == C33.Number);
    REQUIRE(co[3].Instructor == C33.Instructor);
    REQUIRE(co[3].Section == C33.Section);
    REQUIRE(co[3].getGradingType() == Course::Letter);
    
    REQUIRE(co[4].Dept == "CS");
    REQUIRE(co[4].Title == C12.Title);
    REQUIRE(co[4].Number == C12.Number);
    REQUIRE(co[4].Instructor == C12.Instructor);
    REQUIRE(co[4].Section == C12.Section);
    REQUIRE(co[4].getGradingType() == Course::Unknown);
    
    REQUIRE(co[5].Dept == "CS");
    REQUIRE(co[5].Title == C35.Title);
    REQUIRE(co[5].Number == C35.Number);
    REQUIRE(co[5].Instructor == C35.Instructor);
    REQUIRE(co[5].Section == C35.Section);
    REQUIRE(co[5].getGradingType() == Course::Unknown);
    
    REQUIRE(co[6].Dept == "ME");
    REQUIRE(co[6].Title == C38.Title);
    REQUIRE(co[6].Number == C38.Number);
    REQUIRE(co[6].Instructor == C38.Instructor);
    REQUIRE(co[6].Section == C38.Section);
    REQUIRE(co[6].getGradingType() == Course::Letter);
    
    REQUIRE(co[7].Dept == "ME");
    REQUIRE(co[7].Title == C28.Title);
    REQUIRE(co[7].Number == C28.Number);
    REQUIRE(co[7].Instructor == C28.Instructor);
    REQUIRE(co[7].Section == C28.Section);
    REQUIRE(co[7].getGradingType() == Course::Letter);
    
    REQUIRE(co[8].Dept == "ME");
    REQUIRE(co[8].Title == C5.Title);
    REQUIRE(co[8].Number == C5.Number);
    REQUIRE(co[8].Instructor == C5.Instructor);
    REQUIRE(co[8].Section == C5.Section);
    REQUIRE(co[8].getGradingType() == Course::Letter);
    
    
    REQUIRE(co[9].Dept == "ME");
    REQUIRE(co[9].Title == C15.Title);
    REQUIRE(co[9].Number == C15.Number);
    REQUIRE(co[9].Instructor == C15.Instructor);
    REQUIRE(co[9].Section == C15.Section);
    REQUIRE(co[9].getGradingType() == Course::Letter);
    
    REQUIRE(co[10].Dept == "CME");
    REQUIRE(co[10].Title == C36.Title);
    REQUIRE(co[10].Number == C36.Number);
    REQUIRE(co[10].Instructor == C36.Instructor);
    REQUIRE(co[10].Section == C36.Section);
    REQUIRE(co[10].getGradingType() == Course::Letter);
    
    
    REQUIRE(co[11].Dept == "CME");
    REQUIRE(co[11].Title == C46.Title);
    REQUIRE(co[11].Number == C46.Number);
    REQUIRE(co[11].Instructor == C46.Instructor);
    REQUIRE(co[11].Section == C46.Section);
    REQUIRE(co[11].getGradingType() == Course::Letter);
    
    REQUIRE(co[12].Dept == "IE");
    REQUIRE(co[12].Title == C9.Title);
    REQUIRE(co[12].Number == C9.Number);
    REQUIRE(co[12].Instructor == C9.Instructor);
    REQUIRE(co[12].Section == C9.Section);
    REQUIRE(co[12].getGradingType() == Course::Letter);
    
    REQUIRE(co[13].Dept == "CS");
    REQUIRE(co[13].Title == C3.Title);
    REQUIRE(co[13].Number == C3.Number);
    REQUIRE(co[13].Instructor == C3.Instructor);
    REQUIRE(co[13].Section == C3.Section);
    REQUIRE(co[13].getGradingType() == Course::Unknown);
    
    REQUIRE(co[14].Dept == "CME");
    REQUIRE(co[14].Title == C13.Title);
    REQUIRE(co[14].Number == C13.Number);
    REQUIRE(co[14].Instructor == C13.Instructor);
    REQUIRE(co[14].Section == C13.Section);
    REQUIRE(co[14].getGradingType() == Course::Letter);
    
    REQUIRE(co[15].Dept == "CME");
    REQUIRE(co[15].Title == C23.Title);
    REQUIRE(co[15].Number == C23.Number);
    REQUIRE(co[15].Instructor == C23.Instructor);
    REQUIRE(co[15].Section == C23.Section);
    REQUIRE(co[15].getGradingType() == Course::Letter);
    
    REQUIRE(co[16].Dept == "CS");
    REQUIRE(co[16].Title == C22.Title);
    REQUIRE(co[16].Number == C22.Number);
    REQUIRE(co[16].Instructor == C22.Instructor);
    REQUIRE(co[16].Section == C22.Section);
    REQUIRE(co[16].getGradingType() == Course::Unknown);
    
    REQUIRE(co[17].Dept == "CS");
    REQUIRE(co[17].Title == C26.Title);
    REQUIRE(co[17].Number == C26.Number);
    REQUIRE(co[17].Instructor == C26.Instructor);
    REQUIRE(co[17].Section == C26.Section);
    REQUIRE(co[17].getGradingType() == Course::Unknown);
    
    REQUIRE(co[18].Dept == "CS");
    REQUIRE(co[18].Title == C45.Title);
    REQUIRE(co[18].Number == C45.Number);
    REQUIRE(co[18].Instructor == C45.Instructor);
    REQUIRE(co[18].Section == C45.Section);
    REQUIRE(co[18].getGradingType() == Course::Unknown);
    
    REQUIRE(co[19].Dept == "IE");
    REQUIRE(co[19].Title == C32.Title);
    REQUIRE(co[19].Number == C32.Number);
    REQUIRE(co[19].Instructor == C32.Instructor);
    REQUIRE(co[19].Section == C32.Section);
    REQUIRE(co[19].getGradingType() == Course::Letter);
    
    REQUIRE(co[20].Dept == "ME");
    REQUIRE(co[20].Title == C27.Title);
    REQUIRE(co[20].Number == C27.Number);
    REQUIRE(co[20].Instructor == C27.Instructor);
    REQUIRE(co[20].Section == C27.Section);
    REQUIRE(co[20].getGradingType() == Course::Letter);
    
    REQUIRE(co[21].Dept == "ME");
    REQUIRE(co[21].Title == C4.Title);
    REQUIRE(co[21].Number == C4.Number);
    REQUIRE(co[21].Instructor == C4.Instructor);
    REQUIRE(co[21].Section == C4.Section);
    REQUIRE(co[21].getGradingType() == Course::Letter);
    
    
}