#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 13")
{
	ParseCourse("CS,251,187,0,0,0,0,0,0,0,0,0,0,0,Lillis");


	Course C = ParseCourse("CS,251,187,0,0,0,0,0,0,0,0,0,0,0,Lillis");

    
	REQUIRE(C.Instructor == "Lillis");
    REQUIRE(C.Title == "0");
    REQUIRE(C.Dept == "CS");
    
    REQUIRE(C.Section == 187);
    REQUIRE(C.Number == 251);
    
    REQUIRE(C.NumA == 0);
    REQUIRE(C.NumB == 0);
    REQUIRE(C.NumC == 0);
    REQUIRE(C.NumD == 0);
    REQUIRE(C.NumF == 0);
    
    REQUIRE(C.NumI == 0);
    REQUIRE(C.NumS == 0);
    REQUIRE(C.NumU == 0);
    REQUIRE(C.NumW == 0);
    REQUIRE(C.NumNR == 0);
    
}
