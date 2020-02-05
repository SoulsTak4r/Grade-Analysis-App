#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 28", "[Dept: DFW]")
{
    //   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor

    
    //With all DFW and N
    Course C("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 11111111, 13.8, 19.0, 10.5, 1345, 
           /*I,S,U,W,NR*/ 1234, 1234, 1234, 1245, 234);
              
    // Mixer-> everything
    Course C2("IE", "Game Theory", 474, 07, "David", 
           /*A-F*/ 111, 183.9, 87.9, 13.9, 18.5, 
           /*I,S,U,W,NR*/ 1234, 1234, 1234, 1245, 234);
    //only A's and B's with S and U
    Course C3("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 12.3, 45, 21, 0, 0, 
           /*I,S,U,W,NR*/ 1234, 1234, 1234, 1245, 234);
    //A's without S
    Course C4("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 123.8, 14.9, 123.88, 0, 0, 
           /*I,S,U,W,NR*/ 1234, 1234, 1234, 1245, 234);
    //DFW with S
    Course C5("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 0, 0, 0, 1.24, 14.9, 
           /*I,S,U,W,NR*/ 1234, 1234, 1234, 1245, 234);
    //DFW without S
    Course C6("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 0, 0, 0, 13.8, 15.9, 
           /*I,S,U,W,NR*/ 1234, 1234, 1234, 1245, 234);
    
    Course C7("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 0, 0, 1345.33, 0, 0, 
           /*I,S,U,W,NR*/ 1234, 1234, 1234, 1245, 234);
    
    Course C8("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 20, 10, 10, 10, 20, 
           /*I,S,U,W,NR*/ 1234, 1234, 1234, 1245, 234);
    
    Course C9("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 1, 20, 20, 12, 12, 
           /*I,S,U,W,NR*/ 1234, 1234, 1234, 1245, 234);
    
    
   
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
    
    int DFW;
    int N;
    
    double avg = GetDFWRate(D, DFW, N);
    
    
    
    
    REQUIRE(C.getGradingType() == Course::Letter);
    REQUIRE(C2.getGradingType() == Course::Letter);
    REQUIRE(C3.getGradingType() == Course::Letter);
    REQUIRE(C4.getGradingType() == Course::Letter);
    REQUIRE(C5.getGradingType() == Course::Letter);
    REQUIRE(C6.getGradingType() == Course::Letter);
    REQUIRE(C7.getGradingType() == Course::Letter);
    REQUIRE(C8.getGradingType() == Course::Letter);
    REQUIRE(C9.getGradingType() == Course::Letter);
    
    
    REQUIRE(DFW == 12688);
    REQUIRE(N == 11125976);
    REQUIRE(avg == Approx(0.11403));
}
