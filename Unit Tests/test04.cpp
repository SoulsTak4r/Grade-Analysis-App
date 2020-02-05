#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 04", "[College: DFW]")
{
    Course C("CS", "Data Structures", 251, 07, "Lillis", 23, 40, 32, 38, 0, 
                0, 0, 0, 0, 3);
    
    Course C2("CE", "Intro To CE", 101, 04, "Hayes", 67, 38, 11, 7, 0, 
                1, 59, 0, 0, 3);
    
    Dept D("CS");
    Dept D2("CE");
    D.Courses.push_back(C);
    D2.Courses.push_back(C2);
    
    College b("ENG");
    b.Depts.push_back(D);
    b.Depts.push_back(D2);
    
    int DFW;
    int N;
    
    double avg = GetDFWRate(b, DFW, N);
    REQUIRE(DFW ==  45);
    REQUIRE(N == 256);
    
    REQUIRE(avg == Approx(17.5781));
    
    
}
