#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 25")
{
    
    Course C("CS", "Data Structures", 251, 01, "Lillis", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 14, 14, 0, 0);
              
    Course C2("IE", "Game Theory", 474, 07, "David", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 14, 14, 0, 0);
    
    Course C3("ME", "Fluid Mechanics", 277, 19, "Kong", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 10, 14, 14, 0, 0);
    
    Course C4("CE", "Computer Engineering", 126, 14, "Jackson", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    Course C5("BIOE", "Bio Engineering", 264, 32, "Stephan", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 14, 14, 0, 0);
    
    Course C6("CME", "Chemical Engineering", 301, 87, "Demon", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 14, 14, 0, 0);
    
    Course C7("BIO CME", "Bio Chemical", 401, 23, "Klaus", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 14, 14, 0, 0);
    
    Dept D("CS");
    Dept D2("IE");
    Dept D3("ME");
    Dept D4("CE");
    Dept D5("BIOE");
    Dept D6("CME");
    Dept D7("BIO CME");
    
    D.Courses.push_back(C);
    D2.Courses.push_back(C2);
    D3.Courses.push_back(C3);
    D4.Courses.push_back(C4);
    D5.Courses.push_back(C5);
    D6.Courses.push_back(C6);
    D7.Courses.push_back(C7);
    
    College U("Engineering");
    
    U.Depts.push_back(D);
    U.Depts.push_back(D2);
    U.Depts.push_back(D3);
    U.Depts.push_back(D4);
    U.Depts.push_back(D5);
    U.Depts.push_back(D6);
    U.Depts.push_back(D7);
    
    
    
    
    
    int DFW ;
    int N ;
    
    double avg = GetDFWRate(U, DFW, N);
    
    REQUIRE(C.getGradingType() == Course::Satisfactory);
    REQUIRE(C2.getGradingType() == Course::Satisfactory);
    REQUIRE(C3.getGradingType() == Course::Satisfactory);
    REQUIRE(C4.getGradingType() == Course::Unknown);
    REQUIRE(C5.getGradingType() == Course::Satisfactory);
    REQUIRE(C6.getGradingType() == Course::Satisfactory);
    REQUIRE(C7.getGradingType() == Course::Satisfactory);
    REQUIRE(DFW ==  0);
    REQUIRE(N == 0);
    REQUIRE(avg == Approx(0.0));
}
