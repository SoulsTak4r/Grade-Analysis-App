#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test 26")
{

    //   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor

	Course C = ParseCourse("CS,251,07,Data Structures,28,50,38,41,96,0,13,0,0,22,Lillis");
    Course C2 = ParseCourse("CS,342,11,Software Design,43,32,7,0,0,0,3,0,0,12,Bell");
    
    Course C3 = ParseCourse("ME,251,07,Fluid Mechanics,28,50,38,41,96,0,13,0,0,22,Lilander");
    Course C4 = ParseCourse("ME,342,23,Prof Development,43,32,7,0,0,0,3,0,0,12,Bello");
    
    Course C5 = ParseCourse("CE,251,07,Intro to Computer,28,50,38,41,96,0,13,0,0,22,Liexy");
    Course C6 = ParseCourse("CE,342,05,Computer Design,43,32,7,0,0,0,3,0,0,12,Bender");
    
    Course C7 = ParseCourse("IE,251,07,Intro to Stats,28,50,38,41,96,0,13,0,0,22,livly");
    Course C8 = ParseCourse("IE,342,54,Probability and Stat,43,32,7,0,0,0,3,0,0,12,Beck");
    
    Course C9 = ParseCourse("BIOE,251,07,Intro to BIOE,50,38,41,96,0,13,0,0,0,22,Lijing");
    Course C10 = ParseCourse("BIOE,342,16,Bio Chemical,32,7,0,0,0,3,0,0,0,12,Beed");
    
    Course C11 = ParseCourse("ENG,251,07,Intro to Engineering,28,50,38,41,96,0,13,0,0,22,liling");
    Course C12 = ParseCourse("ENG,342,33,Communication,43,32,7,0,0,0,3,0,0,12,Bester");
    
    Course C13 = ParseCourse("DN,251,07,Intro to Dentist,50,38,41,96,0,13,0,0,0,22,Lifer");
    Course C14 = ParseCourse("DN,342,96,Intro to Carvical,32,7,0,0,0,3,0,0,0,12,Beders");
    
    Course C15 = ParseCourse("AA,251,07,Intro to African American,28,50,38,41,96,0,13,0,0,22,liking");
    Course C16 = ParseCourse("AA,342,54,Social Problems,43,32,7,0,0,0,3,0,0,12,Benter");
    
    Course C17 = ParseCourse("TS,251,07,Intro to Tennis,50,38,41,96,0,13,0,0,0,22,Liker");
    Course C18 = ParseCourse("TS,342,63,Body and Tennis,32,7,0,0,0,3,0,0,0,12,Beko");
    
    Course C19 = ParseCourse("PHY,251,07,Intro to Physics,28,50,38,41,96,0,13,0,0,22,lioing");
    Course C20 = ParseCourse("PHY,342,63,Magnetic and Gravity,43,32,7,0,0,0,3,0,0,12,Becki");
    
    Course C21 = ParseCourse("HIST,251,07,History of Chicago,50,38,41,96,0,13,0,0,0,22,Lioly");
    Course C22 = ParseCourse("HIST,342,12,Modern America,32,7,0,0,0,3,0,0,0,12,Bewder");
    
    Course C23 = ParseCourse("GEO,251,07,Intro to Geo,50,38,41,96,0,13,0,0,0,22,Lifer");
    Course C24 = ParseCourse("GEO,342,31,Intro to Earth,32,7,0,0,0,3,0,0,0,12,Beller");
    
    Course C25 = ParseCourse("JAP,251,07,Intro to Japanese,28,50,38,41,96,0,13,0,0,22,liking");
    Course C26 = ParseCourse("JAP,342,84,Socially,43,32,7,0,0,0,3,0,0,12,Bending");
    
    Course C27 = ParseCourse("KO,251,07,Intro to Korea,50,38,41,96,0,13,0,0,0,22,Liker");
    Course C28 = ParseCourse("KO,342,43,Intro to South Korea,32,7,0,0,0,3,0,0,0,12,Befks");
    
    Course C29 = ParseCourse("LAT,251,07,Intro to LAtin,28,50,38,41,96,0,13,0,0,22,lioing");
    Course C30 = ParseCourse("LAT,342,47,Intro to Swedish,43,32,7,0,0,0,3,0,0,12,Beus");
    
    Course C31 = ParseCourse("NEU,251,07,Intro to Neuro science,50,38,41,96,0,13,0,0,0,22,Lioly");
    Course C32 = ParseCourse("NEU,342,85,Intro to brain,32,7,0,0,0,3,0,0,0,12,Becket");
    
    
    Dept D("CS");          
    Dept D2("ME");
    Dept D3("CE");
    Dept D4("IE");
    Dept D5("BIOE");
    Dept D6("ENG");
    Dept D7("DN");
    Dept D8("AA");
    Dept D9("TS");
    Dept D10("PHY");
    Dept D11("HIST");
    Dept D12("GEO");
    Dept D13("KO");
    Dept D14("LAT");
    Dept D15("NEU");
    Dept D16("JA");
    
    D.Courses.push_back(C);
    D.Courses.push_back(C2);
    D2.Courses.push_back(C3);
    D2.Courses.push_back(C4);
    D3.Courses.push_back(C5);
    D3.Courses.push_back(C6);
    D4.Courses.push_back(C7);
    D4.Courses.push_back(C8);
    D5.Courses.push_back(C9);
    D5.Courses.push_back(C10);
    D6.Courses.push_back(C11);
    D6.Courses.push_back(C12);
    D7.Courses.push_back(C13);
    D7.Courses.push_back(C14);
    D8.Courses.push_back(C15);
    D8.Courses.push_back(C16);
    D9.Courses.push_back(C17);
    D9.Courses.push_back(C18);
    D10.Courses.push_back(C19);
    D10.Courses.push_back(C20);
    D11.Courses.push_back(C21);
    D11.Courses.push_back(C22);
    
    D12.Courses.push_back(C23);
    D12.Courses.push_back(C24);
    D13.Courses.push_back(C25);
    D13.Courses.push_back(C26);
    D14.Courses.push_back(C27);
    D14.Courses.push_back(C28);
    D15.Courses.push_back(C29);
    D15.Courses.push_back(C30);
    D16.Courses.push_back(C31);
    D16.Courses.push_back(C32);
    
    
    College U("Engineering");
    U.Depts.push_back(D);
    U.Depts.push_back(D2);
    U.Depts.push_back(D3);
    U.Depts.push_back(D4);
    U.Depts.push_back(D5);
    U.Depts.push_back(D6);
    U.Depts.push_back(D7);
    U.Depts.push_back(D8);
    U.Depts.push_back(D9);
    U.Depts.push_back(D10);
    U.Depts.push_back(D11);
    U.Depts.push_back(D12);
    U.Depts.push_back(D13);
    U.Depts.push_back(D14);
    U.Depts.push_back(D15);
    U.Depts.push_back(D16);
    
    
    vector<Course> found = FindCourses(U, 342);
    
    REQUIRE(found.empty() == false);
    REQUIRE(found.size() == 16);
    
    /*
    for(int i=0; i < found.size()-1; i++)
    {
        if(found[i].Dept > found[i+1].Dept)
        {
            REQUIRE(false);
        }
        else
        {
            REQUIRE(true);
        }
    }
    
    for(int i=0; i < found.size()-1; i++)
    {
        if(found[i].Number > found[i+1].Number)
        {
            REQUIRE(false);
        }
        else
        {
            REQUIRE(true);
        }
    }
    for(int i=0; i < found.size()-1; i++)
    {
        if(found[i].Section > found[i].Section)
        {
            REQUIRE(false);
        }
        else
        {
            REQUIRE(true);
        }
    }
    */
    
    
    Course a = found[0];
    Course b = found[1];
    Course c = found[2];
    Course d = found[3];
    Course e = found[4];
    Course f = found[5];
    Course g = found[6];
    Course h = found[7];
    Course i = found[8];
    Course j = found[9];
    Course k = found[10];
    Course l = found[11];
    Course m = found[12];
    Course n = found[13];
    Course o = found[14];
    Course p = found[15];
    
    REQUIRE(a.Dept == "AA");
    REQUIRE(a.Number == 342);
    REQUIRE(a.Section == 54);
    
    REQUIRE(b.Dept == "BIOE");
    REQUIRE(b.Number == 342);
    REQUIRE(b.Section == 16);
    
    REQUIRE(c.Dept == "CE");
    REQUIRE(c.Number == 342);
    REQUIRE(c.Section == 5);
    
    REQUIRE(d.Dept == "CS");
    REQUIRE(d.Number == 342);
    REQUIRE(d.Section == 11);
    
    REQUIRE(e.Dept == "DN");
    REQUIRE(e.Number == 342);
    REQUIRE(e.Section == 96);
    
    REQUIRE(f.Dept == "ENG");
    REQUIRE(f.Number == 342);
    REQUIRE(f.Section == 33);
    
    REQUIRE(g.Dept == "GEO");
    REQUIRE(g.Number == 342);
    REQUIRE(g.Section == 31);
    
    REQUIRE(h.Dept == "HIST");
    REQUIRE(h.Number == 342);
    REQUIRE(h.Section == 12);
    
    REQUIRE(i.Dept == "IE");
    REQUIRE(i.Number == 342);
    REQUIRE(i.Section == 54);
    
    REQUIRE(j.Dept == "JAP");
    REQUIRE(j.Number == 342);
    REQUIRE(j.Section == 84);
    
    REQUIRE(k.Dept == "KO");
    REQUIRE(k.Number == 342);
    REQUIRE(k.Section == 43);
    
    REQUIRE(l.Dept == "LAT");
    REQUIRE(l.Number == 342);
    REQUIRE(l.Section == 47);
    
    REQUIRE(m.Dept == "ME");
    REQUIRE(m.Number == 342);
    REQUIRE(m.Section == 23);
    
    REQUIRE(n.Dept == "NEU");
    REQUIRE(n.Number == 342);
    REQUIRE(n.Section == 85);
    
    REQUIRE(o.Dept == "PHY");
    REQUIRE(o.Number == 342);
    REQUIRE(o.Section == 63);
    
    REQUIRE(p.Dept == "TS");
    REQUIRE(p.Number == 342);
    REQUIRE(p.Section == 63);
    
    
    
    
}
