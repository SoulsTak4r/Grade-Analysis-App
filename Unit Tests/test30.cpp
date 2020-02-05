#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 30", "[Dept: DFW]")
{
    //   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor

    
    //With all DFW and N
    Course C("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 14, 2154, 224, 4, 213, 
           /*I,S,U,W,NR*/ 4, 2154, 224, 4, 213);
              
    
    
    

    int DFW;
    int N;
    
    double avg = GetDFWRate(C, DFW, N);
    
    
    REQUIRE(C.getGradingType() == Course::Letter);
    REQUIRE(DFW ==  221);
    REQUIRE(N == 2613);
    
    REQUIRE(avg == Approx(8.4577));
}
