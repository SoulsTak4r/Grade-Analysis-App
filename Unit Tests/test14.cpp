#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 14")
{
    Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 666666, 0, 0, 10000, 150,
		/*I,S,U,W,NR*/ 0, 5, 6, 150, 0);

	int DFW;
	int N;
	
	double avg = GetDFWRate(C, DFW, N);
    REQUIRE(DFW ==  10300);
    REQUIRE(N == 676966);
    
	REQUIRE(avg == Approx(1.52149));
}