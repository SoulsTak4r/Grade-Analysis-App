#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 08")
{
    ParseCourse("BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington");


	Course C = ParseCourse("BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington");

    
	REQUIRE(C.Instructor == "Eddington");
    REQUIRE(C.Title == "Intro to Bioengineering");
    REQUIRE(C.Dept == "BIOE");
    
    REQUIRE(C.Section == 01);
    REQUIRE(C.Number == 101);
    
    REQUIRE(C.NumA == 22);
    REQUIRE(C.NumB == 8);
    REQUIRE(C.NumC == 2);
    REQUIRE(C.NumD == 1);
    REQUIRE(C.NumF == 0);
    
    REQUIRE(C.NumI == 1);
    REQUIRE(C.NumS == 0);
    REQUIRE(C.NumU == 0);
    REQUIRE(C.NumW == 5);
    REQUIRE(C.NumNR == 0);
    
    //REQUIRE(xxx.size() == 2);
    
    //Random.Courses.push_back
}
    