// Identification comments code block
// Wills Stern
// Lab 1, Console Programming Basics
// Editor(s) used: VS Code
// Compiler(s) used: g++




#include <iostream>

using std::cout;
using std::cin;
using std::ios;


#include <string>

using std::string;
using std::getline;


#include <cstdlib>



int main()
{


  // identification output code block
  cout << "Wills Stern\n\n";
  cout << "Lab 1, Console Programming Basics\n";
  cout << "Editor(s) used: VSCode\n";
  cout << "Compiler(s) used: g++\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n\n\n\n";

  
  // variables
  string buf;
  int age;
  string name;
  double currTemp;
  string currCity;


  // asking for and retrieving age
  cout << "Enter your age: ";
  cin >> buf; age = atoi(buf.c_str());

  // skips rest of input line
  cin.ignore(200, '\n');

  
  // asking for and retrieving name
  cout << "Enter your name: ";
  getline(cin, name);


  // asking for and retrieving current, glocal temperature
  cout << "Enter the temperature outside right now (degrees F): ";
  cin >> buf; currTemp = atof(buf.c_str());

  // skips rest of input line
  cin.ignore(200, '\n');


  // asking for and retrieving current city of location
  cout << "What city are you in right now? ";
  getline(cin, currCity);



  // first half of output block
  cout << "\n\n" << name << " is " << age << " years old now, and will be " << (age + 2) << " two years from now.\n";
  cout << "It's " << currTemp << " degrees F in " << currCity << " -- that's ";
  
  // formatting (focusing on the numbers after the decimal point and restricting it to 1 number)
  cout.setf(ios::fixed);
  cout.precision(1);

  // second half of the output block
  cout << ( (currTemp - 32) * (5.0/9) ) << " degrees C.\n";

  //flushing the buffer
  cout.flush();


}