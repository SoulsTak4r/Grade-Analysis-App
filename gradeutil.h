/*gradeutil.h*/

//
// Hamza Amjad
//
// 



#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iomanip>

using std::string;
using std::vector;


//
// class Course
//
class Course
{
private:
public:
	//
	// Types of course grading:
	//
	enum GradingType { Letter, Satisfactory, Unknown };

	//
	// Data members:
	//
	string  Dept;
	string  Title;
	int     Number;
	int     Section;
	string  Instructor;
	int     NumA, NumB, NumC, NumD, NumF, NumI, NumS, NumU, NumW, NumNR;

	//
	// Default constructor:
	//
	Course()
		: Dept("?"), Title("?"), Number(0), Section(0), Instructor("?"),
		NumA(0), NumB(0), NumC(0), NumD(0), NumF(0), NumI(0), NumS(0), NumU(0), NumW(0), NumNR(0)
	{ }

	// 
	// Parameterized constructor:
	//
	/*
	Course(string dept, string title, int number, int section, string instructor,
		int A, int B, int C, int D, int F, int I, int S, int U, int W, int NR)
		: Dept(dept), Title(title), Number(number), Section(section), Instructor(instructor),
		NumA(A), NumB(B), NumC(C), NumD(D), NumF(F), NumI(I), NumS(S), NumU(U), NumW(W), NumNR(NR)
	{ }*/

	Course(string dept, int number, string title, int section, string instructor,
		int A, int B, int C, int D, int F, int I, int S, int U, int W, int NR)
		: Dept(dept), Number(number), Title(title), Section(section), Instructor(instructor),
		NumA(A), NumB(B), NumC(C), NumD(D), NumF(F), NumI(I), NumS(S), NumU(U), NumW(W), NumNR(NR)
	{ }


	//
	// Methods:
	//
	GradingType getGradingType() const
	{
		// any letter grades?
		if ((this->NumA + this->NumB + this->NumC + this->NumD + this->NumF) > 0)
			return Letter;
		else if ((this->NumS + this->NumU) > 0)  // any S or U grades?
			return Satisfactory;
		else
			return Unknown;
	}

	int getNumStudents() const
	{
		int N = 0;

		// # students = # of grades that were assigned:
		N = this->NumA + this->NumB + this->NumC + this->NumD + this->NumF;

		if (N > 0)
		{
			// include any incompletes and "no reports":
			N = N + this->NumI + this->NumNR;
			return N;
		}

		// no grades assigned, so perhaps it was graded S/U:
		N = this->NumS + this->NumU;

		if (N > 0)
		{
			// include any incompletes and "no reports":
			N = N + this->NumI + this->NumNR;
			return N;
		}

		// if we get here, no grades were submitted, so # of
		// students = # of incompletes and "no reports":
		N = this->NumI + this->NumNR;
		return N;
	}

};


//
// class Dept
//
// Contains the name of the department (e.g. "CS"), and a vector
// of all the courses taught in the department.
//
class Dept
{
private:
public:
	//
	// Data members:
	//
	string         Name;
	int numOfCourses;
	int A, B, C, D, F, W, NR, I, S, U;
	
	vector<Course> Courses;

	//
	// Default constructor:
	//
	Dept()
		: Name("?")
	{ }

	//
	// Parameterized constructor:
	//
	Dept(string name)
		: Name(name), numOfCourses(0), A(0), B(0), C(0), D(0), F(0), W(0), NR(0), I(0), S(0), U(0)
	{ }
	int returnNums()
	{
		return A + B + C + D + F + S + NR + I + U + W;
	}
	int returnNumCourses ()
	{
		return numOfCourses;
	}
	int getnumstudents() {
		int K = 0;
		for (auto a : this->Courses) {
			
				K += a.getNumStudents();
			
		}
		return K;
	}
	int getNumCourses()
	{
		int count = 0;
		for (auto C : this->Courses)
		{
			count++;
		}
		return count;
	}

};


//
// class College
//
// Contains the name of the college (e.g. "Engineering"), and a vector
// of all the departments in the college.
//
class College
{
private:
public:
	//
	// Data members:
	//  
	string        Name;
	string		Semester;
	int			Year;
	vector<Dept>  Depts;

	//
	// Default constructor:
	//
	College()
		: Name("?"), Semester("?"), Year(0)
	{ }

	//
	// Parameterized constructor:
	//
	College(string name, string semester, int year)
		: Name(name), Semester(semester), Year(year)
	{ }
	int getnumstudents() {
		int count = 0;
		for (auto D : this->Depts) 
		{

			for (auto C : D.Courses) {

				count += C.getNumStudents();
			}
		}
		return count;
	}
	int getNumcourses()
	{
		int count = 0;
		for (auto D : this->Depts)
		{
			for (auto C : D.Courses)
			{
				count++;
			}
		}
		return count;
	}
};


//
// class GradeStats
//
// Holds data about grade distributions for a course, department, or college.
//
class GradeStats
{
private:
public:
	//
	// Data members:
	//
	int    N;  // total # of grades assigned:
	int    NumA, NumB, NumC, NumD, NumF;  // number of A's, B's, etc.
	double PercentA, PercentB, PercentC, PercentD, PercentF;  // percentage of A's, B's, etc.

	//
	// Default constructor:
	//
	GradeStats()
		: N(0), NumA(0), NumB(0), NumC(0), NumD(0), NumF(0),
		PercentA(0.0), PercentB(0.0), PercentC(0.0), PercentD(0.0), PercentF(0.0)
	{ }

	//
	// Parameterized constructor:
	//
	GradeStats(int n, int numA, int numB, int numC, int numD, int numF,
		double percentA, double percentB, double percentC, double percentD, double percentF)
		: N(n), NumA(numA), NumB(numB), NumC(numC), NumD(numD), NumF(numF),
		PercentA(percentA), PercentB(percentB), PercentC(percentC), PercentD(percentD), PercentF(percentF)
	{ }

};


//
// API:
//

// 
// ParseCourse:
//
// Parses a CSV (comma-separated values) line into a Course
// object, which is then returned.  The given line must have
// the following format:
//
//   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
//
// Example:
//   BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington
//
// Note the lack of spaces, except perhaps in the title.
// If the given line does not have this format, the behavior 
// of the function is undefined (it may crash, it may throw
// an exception, it may return).
//
Course ParseCourse(string csvline);
College ParseCollege(string csvline);

//
// GetDFWRate:
//
// Returns the DFW rate as a percentage for a given course, 
// department, or college.  For a course whose grading type 
// is defined as Course::Letter, the DFW rate is defined as
// 
//   # of D grades + F grades + Withdrawals
//   -------------------------------------- * 100.0
//   # of A, B, C, D, F grades + Withdrawls
//
// The numerator is returned via the reference parameter DFW;
// the denominator is returned via the reference parameter N.
// If the course grading type is not Course::Letter, the DFW
// rate is 0.0, and parameters DFW and N are set to 0.  
//
// When computed for a dept or college, all courses of type 
// Course::Letter are considered in computing an overall DFW 
// rate for the dept or college.  The reference parameters 
// DFW and N are also computed across the dept or college.
//
double GetDFWRate(const Course& c, int& DFW, int& N);
double GetDFWRate(const Dept& dept, int& DFW, int& N);
double GetDFWRate(const College& college, int& DFW, int& N);

//
// GetGradeDistribution
//
// Returns an object containing the grade distribution for a given
// course, dept or college.  For a course whose grading type is
// defined as Course::Letter, the grade distribution is defined by
// the following values:
//
//   N: the # of A, B, C, D, F grades
//   NumA, NumB, NumC, NumD, NumF: # of A, B, C, D, F grades
//   PercentA, PercentB, PercentC, PercentD, PercentF: % of A, B, 
//     C, D, F grades.  Example: PercentA = NumA / N * 100.0
//
// If the course grading type is not Course::Letter, all values
// are 0.  When computed for a dept or college, all courses of
// type Course::Letter are considered in computing an overall 
// grade distribution for the dept or college.
//
GradeStats GetGradeDistribution(const Course& c);
GradeStats GetGradeDistribution(const Dept& dept);
GradeStats GetGradeDistribution(const College& college);

//
// FindCourses(dept, courseNumber)
//
// Searches the courses in the department for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, and returned in
// ascending order by section number.
//
vector<Course> FindCourses(const Dept& dept, int courseNumber);

//
// FindCourses(dept, instructorPrefix)
//
// Searches the courses in the department for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".
//
// If none are found, then the returned vector is empty.  If 
// one or more courses are found, copies of the course objects
// are returned in a vector, with the courses appearing in 
// ascending order by course number.  If two courses have the 
// same course number, they are given in ascending order by 
// section number.  Note that courses are NOT sorted by instructor
// name.
//
vector<Course> FindCourses(const Dept& dept, string instructorPrefix)
{
	vector<Course>  courses;

	//
	// looking for 1 or more courses that match --- or start with ---
	// the given instrutor name:
	//
	size_t len = instructorPrefix.size();

	for (const Course& course : dept.Courses)
	{
		if (course.Instructor.substr(0, len) == instructorPrefix)  // match:
		{
			courses.push_back(course);
		}
	}

	//
	// sort the vector, first by course number then by section number:
	//
	if (courses.size() > 1)  // not required, just a tiny optimization:
	{
		sort(courses.begin(), courses.end(),
			[=](const Course& c1, const Course& c2)
		{
			if (c1.Number < c2.Number)
				return true;
			else if (c1.Number > c2.Number)
				return false;
			else // equal, determine by section number:
				if (c1.Section < c2.Section)
					return true;
				else
					return false;
		}
		);
	}

	return courses;

}


//
// FindCourses(college, courseNumber)
//
// Searches for all courses in the college for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by department, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, int courseNumber)
{
	vector<Course>  courses;

	for (const Dept& D : college.Depts)
	{
		for (const Course& co : D.Courses)
		{
			if (co.Number == courseNumber)
			{
				courses.push_back(co);

				

			}
		}
	}
	if (courses.size() > 1)
	{
		sort(courses.begin(), courses.end(), [](Course C, Course C2)
		{

			if (C.Dept == C2.Dept)
			{
				if (C.Number < C2.Number)
				{
					return true;
				}
				else
				{
					if (C.Number == C2.Number)
					{
						return C.Section < C2.Section;
					}
				}
			}
			return C.Dept < C2.Dept;

		}

		);
	}

	return courses;
}

//
// FindCourses(college, instructorPrefix)
//
// Searches all the courses in the college for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by instructor, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, string instructorPrefix)
{
	vector<Course>  courses;

	size_t len = instructorPrefix.length();

	for (const Dept& D : college.Depts)
	{
		for (const Course& co : D.Courses)
		{
			if (co.Instructor.substr(0, len) == instructorPrefix)
			{
				courses.push_back(co);
				
			}
		}
	}
	if (courses.size() > 1)
	{
		sort(courses.begin(), courses.end(), [](Course C, Course C2)
		{

			if (C.Instructor == C2.Instructor)
			{
				if (C.Number < C2.Number)
				{
					return true;
				}
				else
				{
					if (C.Number == C2.Number)
					{
						return C.Section < C2.Section;
					}
				}
			}
			return C.Instructor < C2.Instructor;
		}
		);
	}
	return courses;
}



vector<Course> FindUnknown(const Dept& dept)
{
	vector<Course> courses;
	for (const Course& co : dept.Courses)
	{
		if (co.getGradingType() == Course::Unknown)
		{
			courses.push_back(co);
			
		}
	}
	if (courses.size() > 1)
	{
		sort(courses.begin(), courses.end(), [](Course C, Course C2)
		{
			if (C.Number == C2.Number)
				return C.Section < C2.Section;
			return C.Number < C2.Number;
		});
	}

	return courses;
}
vector<Course> FindUnknown(const College& clg)
{
	vector<Course> courses;
	for (const Dept& D : clg.Depts)
	{
		for (const Course& C : D.Courses)
		{
			if (C.getGradingType() == Course::Unknown)
			{
				courses.push_back(C);
				
			}
		}
	}
	if (courses.size() > 1)
	{
		sort(courses.begin(), courses.end(), [](Course C, Course C2)
		{
			if (C.Dept == C2.Dept)
			{
				if (C.Number < C2.Number)
				{
					return true;
				}
				else
				{
					if (C.Number == C2.Number)
					{
						return C.Section < C2.Section;
					}
				}
			}
			return C.Dept < C2.Dept;
		});
	}
	return courses;
}


/*
	Threshold(const Dept& dept, double hold)

	Checks the user threshold in Dept
	sorts in decending order by dwf rate and ascending order by course number and section number

	returns the vector



*/
vector<Course> Threshold(const Dept& dept, double hold)
{
	int dfw, N;
	vector<Course> courses;
	double d = 0.0;
	double d2 = 0.0;
	double d3 = 0.0;
	for (const Course& co : dept.Courses)
	{
		d = GetDFWRate(co, dfw, N);
		if (d > hold)
		{
			courses.push_back(co);
			

		}
	}
	if (courses.size() > 1)
	{
		sort(courses.begin(), courses.end(), [&](Course C, Course C2)
		{
			d2 = GetDFWRate(C, dfw, N);
			d3 = GetDFWRate(C2, dfw, N);
			if (d2 == d3)
			{
				if (C.Number == C2.Number)
				{
					return C.Section < C2.Section;
				}
				return C.Number < C2.Number;
			}
			return d2 > d3;
		});
	}
	return courses;

}

/*
	
	Threshold(const College& college, double hold)

	Checks the user threshold in College
	sorts in decending order by dwf rate and ascending order by Dept, course number and section number

	returns the vector



*/

vector<Course> Threshold(const College& college, double hold)
{
	int dfw, N;
	vector<Course> courses;
	double d = 0.0;
	double d2 = 0.0;
	double d3 = 0.0;

	for (const Dept& D : college.Depts)
	{
		for (const Course& C : D.Courses)
		{
			d = GetDFWRate(C, dfw, N);
			if (d > hold)
			{
				courses.push_back(C);
			}
		}
	}
	if (courses.size() > 1)
	{
		sort(courses.begin(), courses.end(), [&](Course C, Course C2)
		{
			d2 = GetDFWRate(C, dfw, N);
			d3 = GetDFWRate(C2, dfw, N);

			if (d2 == d3)
			{
				if (C.Dept == C2.Dept)
				{
					if (C.Number < C2.Number)
					{
						return true;
					}
					else
					{
						if (C.Number == C2.Number)
						{
							return C.Section < C2.Section;
						}
					}
				}
				return C.Dept < C2.Dept;
			}
			return d2 > d3;
		});
	}
	return courses;
}

/*
	LetterA(const Dept& dept, double hold)

	Checks the user threshold for LetterA in Dept
	sorts in decending order by dwf rate and ascending order by course number

	returns the vector



*/

vector<Course> LetterA(const Dept& dept, double hold)
{
	GradeStats m;
	GradeStats n;
	GradeStats o;
	vector<Course> courses;
	for (const Course& co : dept.Courses)
	{
		m = GetGradeDistribution(co);
		if (m.PercentA > hold)
		{
			courses.push_back(co);
		}

	}
	if (courses.size() > 1)
	{
		sort(courses.begin(), courses.end(), [&](Course C, Course C2)
		{
			n = GetGradeDistribution(C);
			o = GetGradeDistribution(C2);
			if (n.PercentA == o.PercentA)
			{
				return C.Number < C2.Number;
			}
			return n.PercentA > o.PercentA;
		});
	}
	return courses;
}
/*
	LetterA(const College& college, double hold)

	Checks the user threshold for LetterA in College
	sorts in decending order by dwf rate and ascending order by Dept, course number and Section

	returns the vector



*/
vector<Course> LetterA(const College& college, double hold)
{
	GradeStats m;
	GradeStats n;
	GradeStats o;
	vector<Course> courses;
	for (const Dept& D : college.Depts)
	{
		for (const Course& C : D.Courses)
		{
			m = GetGradeDistribution(C);
			if (m.PercentA > hold)
			{
				courses.push_back(C);
				
			}
		}
	}
	if (courses.size() > 1)
	{
		sort(courses.begin(), courses.end(), [&](Course C, Course C2)
		{
			n = GetGradeDistribution(C);
			o = GetGradeDistribution(C2);
			if (n.PercentA == o.PercentA)
			{
				if (C.Dept == C2.Dept)
				{
					if (C.Number < C2.Number)
					{
						return true;
					}
					else
					{
						if (C.Number == C2.Number)
						{
							return C.Section < C2.Section;
						}
					}
				}
				return C.Dept < C2.Dept;
			}
			return n.PercentA > o.PercentA;
		});
	}
	return courses;
}




/*
	parseD(string csvline);

	Parse All the departments, checks if there are dublicates
	returns the college object
*/
College parseD(string csvline);
