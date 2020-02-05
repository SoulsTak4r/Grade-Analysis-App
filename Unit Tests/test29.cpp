#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 29", "[Dept: DFW]")
{
    //   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor

    
    //With all DFW and N
    Course C("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 111111111, 13.8, 19.0, 10.5, 1345, 
           /*I,S,U,W,NR*/ 0, 0, 0, 1234, 0);
              
    // Mixer-> everything
    Course C2("IE", "Game Theory", 474, 07, "David", 
           /*A-F*/ 124.8, 183.9, 87.9, 13.9, 18.5, 
           /*I,S,U,W,NR*/ 1928, 165.6, 875.1, 1826, 183);
    //only A's and B's with S and U
    Course C3("Lat", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 12.3, 45, 21, 0, 0, 
           /*I,S,U,W,NR*/ 1928, 165.6, 875.1, 1826, 183);
    //A's without S
    Course C4("Geo", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 123.8, 14.9, 123.88, 0, 0, 
           /*I,S,U,W,NR*/ 1928, 165.6, 875.1, 1826, 183);
    //DFW with S
    Course C5("BIOE", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 0, 0, 0, 1.24, 14.9, 
           /*I,S,U,W,NR*/ 1928, 165.6, 875.1, 1826, 183);
    //DFW without S
    Course C6("KO", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 0, 0, 0, 13.8, 15.9, 
           /*I,S,U,W,NR*/ 1928, 165.6, 875.1, 1826, 183);
    
    Course C7("JAP", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 0, 0, 1345.33, 0, 0, 
           /*I,S,U,W,NR*/ 1928, 165.6, 875.1, 1826, 183);
    
    Course C8("ME", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 1928, 165.6, 875.1, 1826, 183, 
           /*I,S,U,W,NR*/ 1928, 165.6, 875.1, 1826, 183);
    
    Course C9("CE", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 1928, 165.6, 875.1, 1826, 183, 
           /*I,S,U,W,NR*/ 1928, 165.6, 875.1, 1826, 183);
    
    
   
    Dept D("CS");
    Dept D2("IE"); 
    Dept D3("Lat");
    Dept D4("Geo"); 
    Dept D5("BIOE"); 
    Dept D6("Ko"); 
    Dept D7("Jap"); 
    Dept D8("ME");
    Dept D9("CE"); 
    
    
    
    
    D.Courses.push_back(C);
    D2.Courses.push_back(C2);
    D3.Courses.push_back(C3);
    D4.Courses.push_back(C4);
    D5.Courses.push_back(C5);
    D6.Courses.push_back(C6);
    D7.Courses.push_back(C7);
    D8.Courses.push_back(C8);
    D9.Courses.push_back(C9);
    
    College U("Eng");
    
    U.Depts.push_back(D);
    U.Depts.push_back(D2);
    U.Depts.push_back(D3);
    U.Depts.push_back(D4);
    U.Depts.push_back(D5);
    U.Depts.push_back(D6);
    U.Depts.push_back(D7);
    U.Depts.push_back(D8);
    U.Depts.push_back(D9);
    
    int DFW;
    int N;
    
    double avg = GetDFWRate(U, DFW, N);
    
    REQUIRE(DFW == 21289);
    REQUIRE(N == 111140445);
    
    
    REQUIRE(avg == Approx(0.01915));
}
