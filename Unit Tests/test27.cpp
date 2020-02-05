#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 27")
{
    
    //   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor

	Course C = ParseCourse("CS,251,07,Data Structures,28,50,38,41,96,0,13,0,0,22,Lillis");
    Course C2 = ParseCourse("CS,342,11,Software Design,43,32,7,0,0,0,3,0,0,12,Bell");
    
    Course C3 = ParseCourse("CS,251,07,Fluid Mechanics,28,50,38,41,96,0,13,0,0,22,Lilander");
    Course C4 = ParseCourse("CS,342,23,Prof Development,43,32,7,0,0,0,3,0,0,12,Bello");
    
    Course C5 = ParseCourse("CS,251,07,Intro to Computer,28,50,38,41,96,0,13,0,0,22,Liexy");
    Course C6 = ParseCourse("CS,342,05,Computer Design,43,32,7,0,0,0,3,0,0,12,Bender");
    
    Course C7 = ParseCourse("CS,251,07,Intro to Stats,28,50,38,41,96,0,13,0,0,22,livly");
    Course C8 = ParseCourse("CS,342,54,Probability and Stat,43,32,7,0,0,0,3,0,0,12,Beck");
    
    Course C9 = ParseCourse("CS,251,07,Intro to BIOE,50,38,41,96,0,13,0,0,0,22,Lijing");
    Course C10 = ParseCourse("CS,342,16,Bio Chemical,32,7,0,0,0,3,0,0,0,12,Beed");
    
    Dept D("CS");  
    D.Courses.push_back(C);
    D.Courses.push_back(C2);
    D.Courses.push_back(C3);
    D.Courses.push_back(C4);
    D.Courses.push_back(C5);
    D.Courses.push_back(C6);
    D.Courses.push_back(C7);
    D.Courses.push_back(C8);
    D.Courses.push_back(C9);
    D.Courses.push_back(C10);
    
    
    vector<Course> found = FindCourses(D, 342);
    
    REQUIRE(found.empty() == false);
    REQUIRE(found.size() == 5);
    
    
    
    Course a = found[0];
    Course b = found[1];
    Course c = found[2];
    Course d = found[3];
    Course e = found[4];
    
    REQUIRE(a.Dept == "CS");
    REQUIRE(a.Number == 342);
    REQUIRE(a.Section == 5);
    
    REQUIRE(b.Dept == "CS");
    REQUIRE(b.Number == 342);
    REQUIRE(b.Section == 11);
    
    REQUIRE(c.Dept == "CS");
    REQUIRE(c.Number == 342);
    REQUIRE(c.Section == 16);
    
    REQUIRE(d.Dept == "CS");
    REQUIRE(d.Number == 342);
    REQUIRE(d.Section == 23);
    
    REQUIRE(e.Dept == "CS");
    REQUIRE(e.Number == 342);
    REQUIRE(e.Section == 54);
    
    
    
    
    
}



