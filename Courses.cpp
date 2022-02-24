// Identification comments code block
// Wills Stern
// Lab 4, Course Objects With Serializations
// Editor(s) used: VS Code
// Compiler(s) used: g++


#include <iostream>
using std::cout;
using std::cin;
using std::ios;


#include <string>
using std::string;
using std::getline;
using std::endl;


#include <fstream>
using std::ofstream;
using std::ifstream;


#include <cstdlib> // for atoi



struct Course {

  string name;
  int year;
  int units;
  char grade;

};

// function prototypes
void tableHeader();
Course cinOneCourse();
void coutAllCourses(Course[ ], int);
void serializeDown(Course[ ], int);


int main()
{

  // identification output code block
  cout << "Wills Stern\n\n";
  cout << "Lab 4, Course Objects With Serializations\n";
  cout << "Editor(s) used: VSCode\n";
  cout << "Compiler(s) used: g++\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n\n\n";

  

  const int CAPACITY = 100;
  int size = 0; // records the size, not capacity, of Courses array

  Course myCourses[CAPACITY] = { }; // initializes everything to blank/zero

  ifstream fin; // creating object fin of "ifstream"


  fin.open("courses.txt");


  // Checks to see if the file is good, then loop begins
  while (fin.good())
  {

    string buf;

    getline(fin, buf); // will be either first attribute or EOF

    /*
     * when buf isn't "EOF", then the name attribute of courses gets buf value
     * and then the rest of the attributes gets their values regularly. Also
     * without buf.length() == 0, one of the blank array elements will output
     */
    if (buf == "EOF" || buf.length() == 0) break;
    
    myCourses[size].name = buf;
    fin >> myCourses[size].year;
    fin >> myCourses[size].units;
    fin >> myCourses[size].grade;

    size++; // count the number of objects loaded from file

    fin.ignore(200, '\n'); // else serializing up will produce weird results

  }

  fin.close(); // ALWAYS close the file


  tableHeader();
  coutAllCourses(myCourses, size); // size b/c we only output courses

  // Loop that breaks if "Q"/"q" is inputted by user to quit the program
  while (true)
  {

    myCourses[size] = cinOneCourse();

    /* 
     * Checks for "Q" or "q" from user to quit program and will blank/zero out
     * the course year, units, and grade that has the name of "Q" or "q"
     */
    if ( myCourses[size].name == "Q" || myCourses[size].name == "q" )
    {
      myCourses[size].name = " ";
      myCourses[size].year = 0;
      myCourses[size].units = 0;
      myCourses[size].grade = ' ';
      break;
    }
    else
    {
      size++;
    }

  }



  serializeDown(myCourses, size);

}




/*************************************************************
* Purpose: Output the table header
* Parameters:
*    (None)
*
* Return:    (Nothing, void function)
**************************************************************/
void tableHeader()
{
  cout << "Course Name      Year Units Grade\n";
  cout << "---------------- ---- ----- -----\n";
}




/*************************************************************
* Purpose: Add one course to the list of courses
* Parameters:
*    (None)
*
* Return:    the new Course object
**************************************************************/
Course cinOneCourse()
{

  string buf;
  Course course;
  
  
  // receiving the name of the course
  cout << "Course Name (Q or q to quit): ";
  getline(cin, course.name);

  // if the name of the course is "Q" or "q", it won't ask for any other data
  if (course.name != "Q" && course.name != "q")
  {
    cout << "Course Year: ";
    cin >> buf; course.year = atoi(buf.c_str());

    cout << "Course Units: ";
    cin >> buf; course.units = atoi(buf.c_str());

    cout << "Course Grade (X for incomplete course): ";
    cin >> course.grade; // since it is a character, only have to use cin >>


    cin.ignore(200, '\n');
  }


  return course;

}




/*************************************************************
* Purpose: Output all courses neatly along with the table header
* Parameters:
*    courses[] (IN) - the array of courses taken/taking/going to take
*    size (IN) - the number of courses in the array
*
* Return:    (Nothing, void function)
**************************************************************/
void coutAllCourses(Course courses[], int size)
{

  // neatly outputs all courses in order with the tableHeader()
  for (int i = 0; i < size; i++)
  {

    cout.setf(ios::left); cout.width(10); cout << courses[i].name;
    cout.unsetf(ios::left); cout.width(11); cout << courses[i].year;
    cout.width(4); cout << courses[i].units;
    cout.width(6); cout << courses[i].grade << endl;

  }

  cout << "\n\n";

}




/*************************************************************
* Purpose: Serialize down the courses into a TXT file
* Parameters:
*    courses[] (IN) - the array of courses taken/taking/going to take
*    size (IN) - the number of courses in the array
*
* Return:    (Nothing, void function)
**************************************************************/
void serializeDown(Course courses[], int size)
{

  ofstream fout; // creating object fout of "ofstream"

  fout.open("courses.txt"); // opening (or creating) courses.txt

  //sends all attributes of each course to courses.txt
  for (int i = 0; i < size; i++)
  {
    fout << courses[i].name << "\n" << courses[i].year << "\n";
    fout << courses[i].units << "\n" << courses[i].grade << "\n";
  }

  fout << "EOF" << endl;

  fout.close(); // ALWAYS close the file

}