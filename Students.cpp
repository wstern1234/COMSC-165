// Identification comments code block
// Wills Stern
// Lab 3, Student Objects With Serializing Down
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


#include <cstdlib> // for atoi and atof



struct Student {

  string name;
  int age;
  int grade;
  double gpa;
  string idCode;

};

// function prototypes
void tableHeader();
void outputStudent(int, Student);
Student setupStudent(int);
void serializeUp(Student, Student, Student);


int main()
{

  // identification output code block
  cout << "Wills Stern\n\n";
  cout << "Lab 3, Student Objects With Serializing Down\n";
  cout << "Editor(s) used: VSCode\n";
  cout << "Compiler(s) used: g++\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  

  // Creating 3 student objects
  Student student1 = setupStudent(1);
  Student student2 = setupStudent(2);
  Student student3 = setupStudent(3);


  //outputting data of student objects
  tableHeader();
  outputStudent(1, student1);
  outputStudent(2, student2);
  outputStudent(3, student3);

  // serializing up student objects
  serializeUp(student1, student2, student3);

}


void tableHeader()
{
  cout << "#     Name                Age Grade GPA   id  \n";
  cout << "---- -------------------- --- ----- --- ------\n";
}


void outputStudent(int order, Student student)
{
  // outputs the sequence number
  cout.width(2); cout << order << "   ";

  // outputs info about student
  cout.setf(ios::left); cout.width(12); cout << student.name;
  cout.unsetf(ios::left); cout.width(12); cout << student.age;
  cout.width(5); cout << student.grade;
  cout.width(5); cout << student.gpa;
  cout.width(7); cout << student.idCode << endl;
}


Student setupStudent(int order)
{

  // variables
  string buf;
  Student student;

  // Receiving key info from student
  cout << "Student " << order << " Name: ";
  getline(cin, student.name);

  cout << "Student " << order << " Age: ";
  cin >> buf; student.age = atoi(buf.c_str());

  cout << "Student " << order << " Grade: ";
  cin >> buf; student.grade = atoi(buf.c_str());

  cout << "Student " << order << " GPA: ";
  cin >> buf; student.gpa = atof(buf.c_str());

  // cin.ignore because of getline below
  cin.ignore(200, '\n');

  cout << "Student " << order << " ID: ";
  getline(cin, student.idCode);

  return student;

}


void serializeUp(Student student1, Student student2, Student student3)
{

  ofstream fout; // Creating object fout of "ofstream"

  fout.open("studentObjects.txt"); // opening/creating studentObjects.txt

  fout << student1.name << "\n" << student1.age << "\n" << student1.grade << "\n";
  fout << student1.gpa << "\n" << student1.idCode << "\n";

  fout << student2.name << "\n" << student2.age << "\n" << student2.grade << "\n";
  fout << student2.gpa << "\n" << student2.idCode << "\n";

  fout << student3.name << "\n" << student3.age << "\n" << student3.grade << "\n";
  fout << student3.gpa << "\n" << student3.idCode << "\n";

  fout.close(); // done with the file

}