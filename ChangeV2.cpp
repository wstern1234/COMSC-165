// Identification comments code block
// Wills Stern
// Lab 2A, Making Exact Change Using Functions
// Editor(s) used: VS Code
// Compiler(s) used: g++



#include <iostream>

using std::cout;
using std::cin;
using std::endl;


#include <string>

using std::string;


#include <cstdlib>


void calcDollars(double&, int);
void calcCents(double&, int);



int main()
{

  // identification output code block
  cout << "Wills Stern\n\n";
  cout << "Lab 2A, Making Exact Change Using Functions\n";
  cout << "Editor(s) used: VS Code\n";
  cout << "Compiler(s) used: g++\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n\n";


  // variables
  string buf;
  double cost = 0.0;
  double totalPayed = 0.0;
  double change = 0.0;


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
  calcDollars(change, 100);
  

  // Checking, calculating, and printing for 50 dollar bills  
  calcDollars(change, 50);
  
  
  // Checking, calculating, and printing for 20 dollar bills
  calcDollars(change, 20);
  
  
  // Checking, calculating, and printing for 10 dollar bills
  calcDollars(change, 10);
  
  
  // Checking, calculating, and printing for 5 dollar bills
  calcDollars(change, 5);
  
  
  // Checking, calculating, and printing for 1 dollar bills
  calcDollars(change, 1);
  
  
  // Checking, calculating, and printing for 50 cent coins
  calcCents(change, 50);
  
  
  // Checking, calculating, and printing for 25 cent coins
  calcCents(change, 25);
  
  
  // Checking, calculating, and printing for 10 cent coins
  calcCents(change, 10);
  
  
  // Checking, calculating, and printing for 5 cent coins
  calcCents(change, 5);
  
  
  // Checking, calculating, and printing for 1 cent coins
  calcCents(change, 1);


  // Clears the buffer so that it doesn't automatically execute the following line
  cin.ignore(200, '\n');

  
  // Makes the program pause, which allows the user to see the output without the console window closing automatically
  cout << "\n\n\nPress ENTER or RETURN to continue..." << endl;
  cin.get();



}


// void function that calculates the amount of dollars needed to be returned to the buyer, change here is pass-by-reference
void calcDollars(double& change, int dollarVal)
{

  int counter = 0;

  // loops until the type of dollar can no longer be subtracted from the change without it going negative
  while ( (change - dollarVal) >= 0 )
  {

    counter++;

    change -= dollarVal;

  }

  // determines if the output is plural or not, then outputs how many of that dollar to return to the buyer
  if (counter == 1)
  {

    cout << counter << " $" << dollarVal << " bill" << endl;

  }
  else if (counter > 1)
  {

    cout << counter << " $" << dollarVal << " bills" << endl;

  }

}


// void function that calculates the amount of cents needed to be returned to the buyer, change here is pass-by-reference
void calcCents(double& change, int centVal)
{

  int counter = 0;

  /* loops until the type of cent can no longer be subtracted from the change without it going negative
      also casts the cent's value to a double to be compatible with the change variable */
  while ( change > (static_cast<double>(centVal) / 100.0 - 0.00001) )
  {

    counter++;

    change -= (static_cast<double>(centVal) / 100.0);

  }

  // determines if the output is plural or not, then outputs how many coins of that cent to return to the buyer
  if (counter == 1)
  {

    cout << counter << " " << centVal << "-cent coin" << endl;

  }
  else if (counter > 1)
  {

    cout << counter << " " << centVal << "-cent coins" << endl;

  }

}