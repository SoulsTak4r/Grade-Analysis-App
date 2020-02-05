#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("DFW")
{
    Course C("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 19, 36, 32, 38, 1,
		/*I,S,U,W,NR*/ 2, 125, 0, 0, 1);
    Course C2("CS", "Data Structures", 251, 03, "Lillis",
		/*A-F*/ 0, 0, 0, 0, 0,
		/*I,S,U,W,NR*/ 0, 0, 0, 0, 0);

	int DFW = 0;
	int N = 0;
	double avg = GetDFWRate(C, DFW, N);
    REQUIRE(DFW ==  39);
    REQUIRE(N == 126);
    REQUIRE(avg == Approx(30.9523));
    double avg2 = GetDFWRate(C2, DFW, N);
    REQUIRE(DFW ==  0);
    REQUIRE(N == 0);
    REQUIRE(avg2 == Approx(0.0));
}