
/*gradeutil.cpp*/

//
// <<Hamza Amjad>>

// 



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "gradeutil.h"

using namespace std;

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
//   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,instructor
//
// Example:
//   BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington
//
// Note the lack of spaces, except perhaps in the title.
// If the given line does not have this format, the behavior 
// of the function is undefined (it may crash, it may throw
// an exception, it may return).
//
Course ParseCourse(string csvline)
{	
	Course  course;
	string  value;

		stringstream  ss(csvline);

		// format: Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,instructor

		getline(ss, course.Dept, ',');

		getline(ss, value, ',');
		course.Number = stoi(value);
		getline(ss, value, ',');
		course.Section = stoi(value);

		getline(ss, course.Title, ',');

		getline(ss, value, ',');
		course.NumA = stoi(value);
		getline(ss, value, ',');
		course.NumB = stoi(value);
		getline(ss, value, ',');
		course.NumC = stoi(value);
		getline(ss, value, ',');
		course.NumD = stoi(value);
		getline(ss, value, ',');
		course.NumF = stoi(value);

		getline(ss, value, ',');
		course.NumI = stoi(value);
		getline(ss, value, ',');
		course.NumNR = stoi(value);
		getline(ss, value, ',');
		course.NumS = stoi(value);
		getline(ss, value, ',');
		course.NumU = stoi(value);
		getline(ss, value, ',');
		course.NumW = stoi(value);

		getline(ss, course.Instructor, ',');
		
	
	return course;
	

	//returnCourse(csvline);
	
}


College ParseCollege(string csvline)
{
	string value, name1, sem1;
	int ye1;
	string line;
	ifstream file(csvline);
	getline(file, line);
	stringstream ss(line);

	getline(ss, name1, ',');
	getline(ss, sem1, ',');
	getline(ss, value, ',');
	ye1 = stoi(value);

	return College(name1, sem1, ye1);
}



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
double GetDFWRate(const Course& c, int& DFW, int& N)
{

	DFW = 0;
	N = 0;
	double rate = 0.0;

	if (c.getGradingType() != Course::Letter)
	{
		//do nothing
	}
	else
	{
		DFW = c.NumD + c.NumF + c.NumW;
		N = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW;
		rate = double(DFW) / double(N) * 100;
	}

	return rate;


	return N;
	return DFW;


}

double GetDFWRate(const Dept& dept, int& DFW, int& N)
{
	DFW = 0;
	N = 0;


	double rate = 0.0;
	int totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalF = 0, totalW = 0;

	if (dept.Courses.empty())
	{
		return 0.0;
	}

	for (const Course& C : dept.Courses)
	{
		if (C.getGradingType() != Course::Letter)
		{
			// do nothing

		}
		else
		{
			totalA = totalA + C.NumA;
			totalB = totalB + C.NumB;
			totalC = totalC + C.NumC;
			totalD = totalD + C.NumD;
			totalF = totalF + C.NumF;
			totalW = totalW + C.NumW;
			DFW = totalD + totalF + totalW;
			N = totalA + totalB + totalC + totalD + totalF + totalW;

			rate = double(DFW) / double(N) * 100;

		}
	}


	return rate;
	return DFW;
	return N;

}

double GetDFWRate(const College& college, int& DFW, int& N)
{
	DFW = 0;
	N = 0;
	int totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalF = 0, totalW = 0;
	double rate = 0.0;

	if (college.Depts.empty())
	{
		return 0.0;
	}


	for (const Dept& D : college.Depts)
	{
		for (const Course& C : D.Courses)
		{
			if (C.getGradingType() != Course::Letter)
			{

				//do nothing
			}
			else
			{
				totalA = totalA + C.NumA;
				totalB = totalB + C.NumB;
				totalC = totalC + C.NumC;
				totalD = totalD + C.NumD;
				totalF = totalF + C.NumF;
				totalW = totalW + C.NumW;
				DFW = totalD + totalF + totalW;
				N = totalA + totalB + totalC + totalD + totalF + totalW;
				rate = double(DFW) / double(N) * 100;

			}
		}
	}


	return rate;


	return DFW;
	return N;

}


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
GradeStats GetGradeDistribution(const Course& c)
{

	int N = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
	double perA, perB, perC, perD, perF;
	perA = perB = perC = perD = perF = 0.0;

	if (c.getGradingType() != Course::Letter)
	{
		// do nothing
	}
	else
	{
		perA = double(c.NumA) / double(N) * 100;
		perB = double(c.NumB) / double(N) * 100;
		perC = double(c.NumC) / double(N) * 100;
		perD = double(c.NumD) / double(N) * 100;
		perF = double(c.NumF) / double(N) * 100;
	}


	return GradeStats(N, c.NumA, c.NumB, c.NumC, c.NumD, c.NumF, perA, perB, perC, perD, perF);
}

GradeStats GetGradeDistribution(const Dept& dept)
{
	int N = 0;
	int numA, numB, numC, numD, numF;
	numA = numB = numC = numD = numF = 0;
	double perA, perB, perC, perD, perF;
	perA = perB = perC = perD = perF = 0.0;

	for (const Course& C : dept.Courses)
	{
		if (C.getGradingType() != Course::Letter)
		{

			//do nothing
		}
		else
		{
			numA = numA + C.NumA;
			numB = numB + C.NumB;
			numC = numC + C.NumC;
			numD = numD + C.NumD;
			numF = numF + C.NumF;

			N = numA + numB + numC + numD + numF;
			perA = double(numA) / double(N) * 100;
			perB = double(numB) / double(N) * 100;
			perC = double(numC) / double(N) * 100;
			perD = double(numD) / double(N) * 100;
			perF = double(numF) / double(N) * 100;
		}

	}


	return GradeStats(N, numA, numB, numC, numD, numF, perA, perB, perC, perD, perF);
}

GradeStats GetGradeDistribution(const College& college)
{

	int N = 0;
	int numA, numB, numC, numD, numF;
	numA = numB = numC = numD = numF = 0;

	double perA, perB, perC, perD, perF;
	perA = perB = perC = perD = perF = 0;

	for (const Dept& D : college.Depts)
	{
		for (const Course& C : D.Courses)
		{
			if (C.getGradingType() != Course::Letter)
			{
				//do nothing

			}
			else
			{
				numA = numA + C.NumA;
				numB = numB + C.NumB;
				numC = numC + C.NumC;
				numD = numD + C.NumD;
				numF = numF + C.NumF;

				N = numA + numB + numC + numD + numF;
				perA = double(numA) / double(N) * 100;
				perB = double(numB) / double(N) * 100;
				perC = double(numC) / double(N) * 100;
				perD = double(numD) / double(N) * 100;
				perF = double(numF) / double(N) * 100;
			}
		}
	}

	return GradeStats(N, numA, numB, numC, numD, numF, perA, perB, perC, perD, perF);
}


//
// FindCourses(dept, courseNumber)
//
// Searches the courses in the department for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, and returned in
// ascending order by section number.
//
vector<Course> FindCourses(const Dept& dept, int courseNumber)
{
	vector<Course>  courses;

	for (const Course& co : dept.Courses)
	{
		if (co.Number == courseNumber)
		{

			courses.push_back(co);
			sort(courses.begin(), courses.end(), [](Course C, Course C2)
			{
				if (C.Section == C2.Section)
					return C.Section < C2.Section;
				return C.Section < C2.Section;


			}
			);
		}
		else
		{
			courses.empty();
		}
	}
	return courses;
}


College parseD(string csvline)
{	
	Course co;
	College U;

	string line;
	ifstream file(csvline);
	if (!file.good())
	{
		cout << "Cannot open" << endl;
		exit(0);
	}
	getline(file, line);
	getline(file, line);

	while (getline(file,line))
	{
		co = ParseCourse(line);

		auto iter = find_if(U.Depts.begin(), U.Depts.end(), [=](const Dept& dep)
		{
			if (dep.Name == co.Dept)
			{
				return true;
			}
			else
			{
				return false;
			}
		});
		if (iter == U.Depts.end())
		{
			Dept dept(co.Dept);
			dept.Courses.push_back(co);
			U.Depts.push_back(dept);
		}
		else
		{
			iter->Courses.push_back(co);
		}
	}

	
	return U;
}


//-----------------------------------------------------------------------------------------------------

int main()
{
	cout << std::fixed;
	cout << std::setprecision(2);

	string user;
	int dfw, N;

	string filename;
	std::cin >> filename;
	int total = 0;
	Dept D;

    College U = ParseCollege(filename);		// Get College information
	College colg = parseD(filename);		// Get Courses, Depts, and College
	
	
	int totalC = 0;
	// count total students and courses for college
	for (const Dept& DDD : colg.Depts)
	{
		for (const Course& CCC : DDD.Courses)
		{
			total = total + CCC.getNumStudents();
		}
		totalC = totalC + DDD.Courses.size();
	}
	// Get the Data from Colg 
	for (const Dept& dept : colg.Depts)
	{
		for (const Course& C : dept.Courses)
		{

			auto iter = find_if(colg.Depts.begin(), colg.Depts.end(), [=](const Dept& d)
			{
				if (d.Name == C.Dept)
				{

					return true;
				}
				else
				{

					return false;
				}

			});

			if (iter == colg.Depts.end())
			{
				cout << "Dept not found << endl" << endl;
			}
			else
			{
				iter->numOfCourses++;
				iter->A += C.NumA;
				iter->B += C.NumB;
				iter->C += C.NumC;
				iter->D += C.NumD;
				iter->F += C.NumF;
				iter->S += C.NumS;
				iter->I += C.NumI;
				iter->NR += C.NumNR;
				iter->W += C.NumW;
				iter->U += C.NumU;

			}

		}
	}
	GradeStats G = GetGradeDistribution(colg);
	double dfwRate = GetDFWRate(colg, dfw, N);

	cout << "** College of " << U.Name << ", " << U.Semester << " " << U.Year << " **" << endl;
	cout << "# of courses taught: " << totalC << endl;
	cout << "# of students taught: " << total << endl;
	cout << "grade distribution (A-F): " << G.PercentA << "%, " << G.PercentB << "%, " << G.PercentC << "%, " << G.PercentD << "%, " << G.PercentF << "%" << endl;
	cout << "DFW rate: " << dfwRate << "%" << endl;
	cout << endl;


	
	
	double r = 0.0;
	int i = 0;
	cout << "Enter a command> ";

	cin >> user;


	//-------------------------- Starting While Loop ----------------------------------------
	while (user != "#")
	{

		// ----------------------- Summary --------------------------------
		if (user == "summary")
		{
			
			cout << "dept name, or all? ";
			cin >> user;
			auto iter = find_if(colg.Depts.begin(), colg.Depts.end(), [=](Dept DD)
			{
				if (user == DD.Name)
				{
					return true;
				}
				else
				{
					return false;
				}
			});
			
			if (iter != colg.Depts.end())
			{
				int countCourse = 0;
				int y = 0;
				Dept D2;
				GradeStats gr;
					

				for (const Dept& R : colg.Depts)
				{
					if (user == R.Name)
					{
						for (const Course& C : R.Courses)
						{
							y = y + C.getNumStudents();
							countCourse++;
						}
						r = GetDFWRate(R, dfw, N);
						gr = GetGradeDistribution(R);
						
						cout << R.Name << ":" << endl;
					
					}
					
				}

				cout << " # courses taught: " << countCourse << endl;
				cout << " # students taught: " << y << endl;
				cout << " grade distribution (A-F): " << gr.PercentA << "%, " << gr.PercentB << "%, " << gr.PercentC << "%, " << gr.PercentD << "%, " << gr.PercentF << "%" << endl;
				cout << " DFW rate: " << r << "%" <<endl;
				
			}
			else if (user == "all")
			{
				double r = 0.0;
				GradeStats d;
				int y = 0;
				int countCourse = 0;
				sort(colg.Depts.begin(), colg.Depts.end(), [](Dept D, Dept D2)
				{
					if (D.Name == D2.Name)
						return D.Name < D2.Name;
					return D.Name < D2.Name;
				}
				);
				for ( Dept& dept : colg.Depts)
				{
					r = GetDFWRate(dept, dfw, N);
					d = GetGradeDistribution(dept);
				
					
					cout << dept.Name << ":" << endl;
					cout << " # courses taught: " << dept.getNumCourses() << endl;
					cout << " # students taught: " << dept.getnumstudents() << endl;
					cout << " grade distribution (A-F): " << d.PercentA << "%, " << d.PercentB << "%, " << d.PercentC << "%, " << d.PercentD << "%, " << d.PercentF << "%" << endl;
					cout << " DFW rate: " << r << "%"<< endl;
				}
				
			}
			else
			{
				cout << "**dept not found" << endl;
			}// end Summary
		}
		// ---------------------------- Search -----------------------------------------
		else if (user == "search")
		{
		
			cout << "dept name, or all? ";
			cin >> user;
			
			auto iter = find_if(colg.Depts.begin(), colg.Depts.end(), [=](Dept DD)
			{
				if (user == DD.Name)
				{
					return true;
				}
				else
				{
					return false;
				}
			});
			if (iter != colg.Depts.end())
			{
				Dept D4;
				vector<Course> findCo;
				GradeStats Fc;
				double F = 0.0;
				for (const Dept& R : colg.Depts)
				{
					if (user == R.Name)
					{
						for (auto& C : R.Courses)
						{
							D4.Name = R.Name;
							D4.Courses.push_back(C);
						}
					}

				}
			
				cout << "course # or instructor prefix? ";
				string prefix;
				int courseNum;
				cin >> prefix;
				//----------------------------
				stringstream ss(prefix);
				ss >> courseNum;
				//----------------------------
				if (ss.fail())
				{
					findCo = FindCourses(D4, prefix);
				}
				else
				{
					findCo = FindCourses(D4, courseNum);
				}
				if (findCo.empty())
				{
					cout << "**none found" << endl;
				}
				else
				{
					for (Course& C : findCo)
					{
						Fc = GetGradeDistribution(C);
						F = GetDFWRate(C, dfw, N);
						cout << C.Dept << " " << C.Number << " (section " << C.Section << "): " << C.Instructor << endl;
						cout << " # students: " << C.getNumStudents() << endl;
						if (C.getGradingType() == Course::Satisfactory)
						{
							cout << " course type: " << "satisfactory" << endl;
						}
						else if (C.getGradingType() == Course::Unknown)
						{
							cout << " course type: " << "unknown" << endl;
						}
						else if (C.getGradingType() == Course::Letter)
						{
							cout << " course type: " << "letter" << endl;
						}
						cout << " grade distribution (A-F): " << Fc.PercentA << "%, " << Fc.PercentB << "%, " << Fc.PercentC << "%, " << Fc.PercentD << "%, " << Fc.PercentF << "%" << endl;
						cout << " DFW rate: " << F << "%" << endl;
					}
				}
			}
			else if(user == "all")
			{
				vector<Course> findCo;
				GradeStats Fc;
				double F = 0.0;
				cout << "course # or instructor prefix? ";
				string prefix;
				int courseNum;
				cin >> prefix;
				stringstream ss(prefix);
				ss >> courseNum;
				if (ss.fail())
				{
					findCo = FindCourses(colg, prefix);
				}
				else
				{
					findCo = FindCourses(colg, courseNum);
				}
				
				if (findCo.empty())
				{
					cout << "**none found" << endl;
				}
				else
				{
					for (auto& C : findCo)
					{
						Fc = GetGradeDistribution(C);
						F = GetDFWRate(C, dfw, N);
						cout << C.Dept << " " << C.Number << " (section " << C.Section << "): " << C.Instructor << endl;
						cout << " # students: " << C.getNumStudents() << endl;
						if (C.getGradingType() == Course::Satisfactory)
						{
							cout << " course type: " << "satisfactory" << endl;
						}
						else if (C.getGradingType() == Course::Unknown)
						{
							cout << " course type: " << "unknown" << endl;
						}
						else if (C.getGradingType() == Course::Letter)
						{
							cout << " course type: " << "letter" << endl;
						}
						cout << " grade distribution (A-F): " << Fc.PercentA << "%, " << Fc.PercentB << "%, " << Fc.PercentC << "%, " << Fc.PercentD << "%, " << Fc.PercentF << "%" << endl;
						cout << " DFW rate: " << F << "%" <<endl;
					}
				}
				
			}
			else if(iter == colg.Depts.end())
			{
				string prefix;;
				cout << "course # or instructor prefix? ";
				cin >> prefix;
				cout << "**dept not found" << endl;
			}//end Search
		}
		// -------------------------------- Unknown -----------------------------------
		else if (user == "unknown")
		{
			cout << "dept name, or all? ";
			cin >> user;

			auto iter = find_if(colg.Depts.begin(), colg.Depts.end(), [=](Dept DD)
			{
				if (user == DD.Name)
				{
					return true;
				}
				else
				{
					return false;
				}
			});
			if (iter != colg.Depts.end())
			{
				Dept D5;
				vector<Course> findU;
				double z = 0.0;
				GradeStats fu;
				for (const Dept& R : colg.Depts)
				{
					if (user == R.Name)
					{
						for (const Course& C : R.Courses)
						{
							
							D5.Name = C.Dept;
							D5.Courses.push_back(C);

							
						}
					}
				}
				
				findU = FindUnknown(D5);
				if (findU.empty())
				{
					cout << "**none found" << endl;
				}
				else
				{
					for (Course& C : findU)
					{
						fu = GetGradeDistribution(C);
						z = GetDFWRate(C, dfw, N);
						cout << C.Dept << " " << C.Number << " (section " << C.Section << "): " << C.Instructor << endl;
						cout << " # students: " << C.getNumStudents() << endl;
						if (C.getGradingType() == Course::Unknown)
						{
							cout << " course type: " << "unknown" << endl;
						}
						cout << " grade distribution (A-F): " << fu.PercentA << "%, " << fu.PercentB << "%, " << fu.PercentC << "%, " << fu.PercentD << "%, " << fu.PercentF << "%" << endl;
						cout << " DFW rate: " << z << "%" <<endl;
					}
				}
			}
			else if (user == "all")
			{
				vector<Course> findU;
				double z = 0.0;
				GradeStats fu;
				findU = FindUnknown(colg);
				if (findU.empty())
				{
					cout << "**none found" << endl;
				}
				else
				{
					for (Course& C : findU)
					{
						fu = GetGradeDistribution(C);
						z = GetDFWRate(C, dfw, N);
						cout << C.Dept << " " << C.Number << " (section " << C.Section << "): " << C.Instructor << endl;
						cout << " # students: " << C.getNumStudents() << endl;
						if (C.getGradingType() == Course::Unknown)
						{
							cout << " course type: " << "unknown" << endl;
						}
						cout << " grade distribution (A-F): " << fu.PercentA << "%, " << fu.PercentB << "%, " << fu.PercentC << "%, " << fu.PercentD << "%, " << fu.PercentF << "%" << endl;
						cout << " DFW rate: " << z  << "%" << endl;
					}
				}

			}
			else
			{
				cout << "**dept not found" << endl;
			}// End Unknown
			
			
		}
		// -------------------------------- DFW -------------------------------------
		else if (user == "dfw")
		{
			
			cout << "dept name, or all? ";
			cin >> user;
			auto iter = find_if(colg.Depts.begin(), colg.Depts.end(), [=](Dept DD)
			{
				if (user == DD.Name)
				{
					return true;
				}
				else
				{
					return false;
				}
			});
			if (iter != colg.Depts.end())
			{
				Dept dept;
				vector<Course> courses;
				double threshold;
				double g = 0.0;
				GradeStats k;
				for (const Dept& R : colg.Depts)
				{
					for (const Course& C : R.Courses)
					{
						if (user == C.Dept)
						{
							dept.Name = C.Dept;
							dept.Courses.push_back(C);

						}
					}

				}
				cout << "dfw threshold? ";
				cin >> threshold;
				courses = Threshold(dept, threshold);
				if (courses.empty())
				{
					cout << "**none found" << endl;
				}
				else
				{
					for (Course& C : courses)
					{
						g = GetDFWRate(C, dfw, N);
						k = GetGradeDistribution(C);
						cout << C.Dept << " " << C.Number << " (section " << C.Section << "): " << C.Instructor << endl;
						cout << " # students: " << C.getNumStudents() << endl;
						if (C.getGradingType() == Course::Letter)
						{
							cout << " course type: " << "letter" << endl;
						}
						cout << " grade distribution (A-F): " << k.PercentA << "%, " << k.PercentB << "%, " << k.PercentC << "%, " << k.PercentD << "%, " << k.PercentF << "%" << endl;
						cout << " DFW rate: " << g << "%" << endl;

					}
				}
			}
			else if(user == "all")
			{
				vector<Course> courses;
				double z = 0.0;
				GradeStats fu;
				double threshold;
				cout << "dfw threshold? ";
				cin >> threshold;
				courses = Threshold(colg, threshold);
				if (courses.empty())
				{
					cout << "**none found" << endl;
				}
				else
				{
					for (const Course& C : courses)
					{
						fu = GetGradeDistribution(C);
						z = GetDFWRate(C, dfw, N);
						cout << C.Dept << " " << C.Number << " (section " << C.Section << "): " << C.Instructor << endl;
						cout << " # students: " << C.getNumStudents() << endl;
						if (C.getGradingType() == Course::Letter)
						{
							cout << " course type: " << "letter" << endl;
						}
						cout << " grade distribution (A-F): " << fu.PercentA << "%, " << fu.PercentB << "%, " << fu.PercentC << "%, " << fu.PercentD << "%, " << fu.PercentF << "%" << endl;
						cout << " DFW rate: " << z << "%" << endl;
					}
				}

			}
			else if(iter == colg.Depts.end())
			{
				double t;
				cout << "dfw threshold? ";
				cin >> t;
				cout << "**dept not found" << endl;
			}// End DFW

		}
		// ----------------------------- Letter A --------------------------------------------
		else if (user == "letterA")
		{
			Dept dept;
			cout << "dept name, or all? ";
			cin >> user;
			auto iter = find_if(colg.Depts.begin(), colg.Depts.end(), [=](Dept DD)
			{
				if (user == DD.Name)
				{
					return true;
				}
				else
				{
					return false;
				}
			});
			if (iter != colg.Depts.end())
			{
				for (const Dept& R : colg.Depts)
				{
					for (const Course& C : R.Courses)
					{
						if (user == C.Dept)
						{
							dept.Name = C.Dept;
							dept.Courses.push_back(C);
						}
					}
				}
				vector<Course> courses;
				double threshold;
				double j;
				GradeStats m;
				cout << "letter A threshold? ";
				cin >> threshold;
				courses = LetterA(dept, threshold);
				if (courses.empty())
				{
					cout << "**none found" << endl;
				}
				else
				{
					for (Course& C : courses)
					{
						j = GetDFWRate(C, dfw, N);
						m = GetGradeDistribution(C);
						cout << C.Dept << " " << C.Number << " (section " << C.Section << "): " << C.Instructor << endl;
						cout << " # students: " << C.getNumStudents() << endl;
						if (C.getGradingType() == Course::Letter)
						{
							cout << " course type: " << "letter" << endl;
						}
						cout << " grade distribution (A-F): " << m.PercentA << "%, " << m.PercentB << "%, " << m.PercentC << "%, " << m.PercentD << "%, " << m.PercentF << "%" << endl;
						cout << " DFW rate: " << j <<"%" <<endl;

					}
				}
			}
			else if (user == "all")
			{
				vector<Course> courses;
				double threshold;
				double j;
				GradeStats m;
				cout << "letter A threshold? ";
				cin >> threshold;
				courses = LetterA(colg, threshold);
				if (courses.empty())
				{
					cout << "**none found" << endl;
				}
				else
				{
					for (const Course& C : courses)
					{
						j = GetDFWRate(C, dfw, N);
						m = GetGradeDistribution(C);
						cout << C.Dept << " " << C.Number << " (section " << C.Section << "): " << C.Instructor << endl;
						cout << " # students: " << C.getNumStudents() << endl;
						if (C.getGradingType() == Course::Letter)
						{
							cout << " course type: " << "letter" << endl;
						}
						cout << " grade distribution (A-F): " << m.PercentA << "%, " << m.PercentB << "%, " << m.PercentC << "%, " << m.PercentD << "%, " << m.PercentF << "%" << endl;
						cout << " DFW rate: " << j <<"%" << endl;
					}
				}
			}
			else if(iter == colg.Depts.end())
			{
				double lA;
				cout << "letter A threshold? ";
				cin >> lA;
				cout << "**dept not found" << endl;
			}//End LetterA

		}
		// Checks if the command is valid
		else
		{
			cout << "**unknown command" << endl;
		}
		cout << "Enter a command> ";
		cin >> user;						// prompt againt
		
	}
	
	cout << endl;
	
	return 0;

} //Done, end main()
	

