// Identification comments code block
// Wills Stern
// Lab 2, Making Exact Change
// Editor(s) used: VS Code
// Compiler(s) used: g++



#include <iostream>

using std::cout;
using std::cin;
using std::endl;


#include <string>

using std::string;


#include <cstdlib>



int main()
{

  // identification output code block
  cout << "Wills Stern\n\n";
  cout << "Lab 2, Making Exact Change\n";
  cout << "Editor(s) used: VS Code\n";
  cout << "Compiler(s) used: g++\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n\n";


  // variables
  string buf;
  double cost = 0.0;
  double totalPayed = 0.0;
  double change = 0.0;
  int hundreds = 0;
  int fifties = 0;
  int twenties = 0;
  int tens = 0;
  int fives = 0;
  int ones = 0;
  int cent50 = 0;
  int cent25 = 0;
  int cent10 = 0;
  int cent5 = 0;
  int cent1 = 0;


  // Getting the cost of the item(s)
  cout << "Enter the cost of the item(s): ";
  cin >> buf; cost = atof(buf.c_str());

  // Getting the amount payed with
  cout << "Enter the bill/amount of money you're paying with: ";
  cin >> buf; totalPayed = atof(buf.c_str());


  // calculating total change
  change = totalPayed - cost;

  cout << "\n\nChange: $" << change << "\n\n";

  // Checking, calculating, and printing for 100 dollar bills
  while ( (change - 100) >= 0 ) {

    hundreds++;

    change -= 100;

  }

  if (hundreds == 1) {

    cout << hundreds << " $100 bill" << endl;

  } else if (hundreds > 1) {

    cout << hundreds << " $100 bills" << endl;

  }
  

  // Checking, calculating, and printing for 50 dollar bills  
  while ( (change - 50) >= 0 ) {

    fifties++;

    change -= 50;

  }

  if (fifties == 1) {

    cout << fifties << " $50 bill" << endl;

  } else if (fifties > 1) {

    cout << fifties << " $50 bills" << endl;

  }
  
  
  // Checking, calculating, and printing for 20 dollar bills
  while ( (change - 20) >= 0 ) {

    twenties++;

    change -= 20;

  }

  if (twenties == 1) {

    cout << twenties << " $20 bill" << endl;

  } else if (twenties > 1) {

    cout << twenties << " $20 bills" << endl;

  }
  
  
  // Checking, calculating, and printing for 10 dollar bills
  while ( (change - 10) >= 0 ) {

    tens++;

    change -= 10;

  }

  if (tens == 1) {

    cout << tens << " $10 bill" << endl;

  } else if (tens > 1) {

    cout << tens << " $10 bills" << endl;

  }
  
  
  // Checking, calculating, and printing for 5 dollar bills
  while ( (change - 5) >= 0 ) {

    fives++;

    change -= 5;

  }

  if (fives == 1) {

    cout << fives << " $5 bill" << endl;

  } else if (fives > 1) {

    cout << fives << " $5 bills" << endl;

  }
  
  
  // Checking, calculating, and printing for 1 dollar bills
  while ( (change - 1) >= 0 ) {

    ones++;

    change -= 1;

  }

  if (ones == 1) {

    cout << ones << " $1 bill" << endl;

  } else if (ones > 1) {

    cout << ones << " $1 bills" << endl;

  }
  
  
  // Checking, calculating, and printing for 50 cent coins
  while ( change > 0.499999 ) {

    cent50++;

    change -= 0.5;

  }

  if (cent50 == 1) {

    cout << cent50 << " 50-cent coin" << endl;

  } else if (cent50 > 1) {

    cout << cent50 << " 50-cent coins" << endl;

  }
  
  
  // Checking, calculating, and printing for 25 cent coins
  while ( change > 0.2499999 ) {

    cent25++;

    change -= 0.25;

  }

  if (cent25 == 1) {

    cout << cent25 << " 25-cent coin" << endl;

  } else if (cent25 > 1) {

    cout << cent25 << " 25-cent coins" << endl;

  }
  
  
  // Checking, calculating, and printing for 10 cent coins
  while ( change > 0.099999 ) {

    cent10++;

    change -= 0.1;

  }

  if (cent10 == 1) {

    cout << cent10 << " 10-cent coin" << endl;

  } else if (cent10 > 1) {

    cout << cent10 << " 10-cent coins" << endl;

  }
  
  
  // Checking, calculating, and printing for 5 cent coins
  while ( change > 0.0499999 ) {

    cent5++;

    change -= 0.05;

  }

  if (cent5 == 1) {

    cout << cent5 << " 5-cent coin" << endl;

  } else if (cent5 > 1) {

    cout << cent5 << " 5-cent coins" << endl;

  }
  
  
  // Checking, calculating, and printing for 1 cent coins
  while ( change > 0.0099999 ) {

    cent1++;

    change -= 0.01;

  }

  if (cent1 == 1) {

    cout << cent1 << " 1-cent coin" << endl;

  } else if (cent1 > 1) {

    cout << cent1 << " 1-cent coins" << endl;

  }


}
