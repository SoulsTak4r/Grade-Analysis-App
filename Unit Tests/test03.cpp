#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 03", "[Dept: DFW]")
{
    
    Course C("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 14, 39, 48, 32, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
              
    Course C2("IE", "Game Theory", 474, 07, "David", 
           /*A-F*/ 40, 32, 13, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
    
    Dept D("CS");
    Dept D2("IE");
    D.Courses.push_back(C);
    D2.Courses.push_back(C2);
    
    
    int DFW = 0;
    int N = 0;
    
    double avg = GetDFWRate(D, DFW, N);
    REQUIRE(DFW ==  32);
    REQUIRE(N == 133);
    
    REQUIRE(avg == Approx(24.0601));
}
