// Identification comments code block
// Wills Stern
// Lab 5, Tracking Expenses with Arrays
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

#include <cstdlib> // for atoi and atof


// function prototypes
void showMenu(struct Expense[ ], int);
void showExpenses(struct Expense[ ], int);
void addExpense(struct Expense[ ], int&);
void wordSearchExpenses(struct Expense[ ], int);
void costSearchExpenses_ge(struct Expense[ ], int);
string toLowerCase(string);




struct Expense
{

  string description;
  double cost;

};



int main()
{

  // identification output code block
  cout << "Wills Stern\n\n";
  cout << "Lab 5, Tracking Expenses with Arrays\n";
  cout << "Editor(s) used: VSCode\n";
  cout << "Compiler(s) used: g++\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n\n\n";

  
  
  const int CAPACITY = 100;
  int size = 0;

  Expense expenses[CAPACITY] = {};

  
  cout << "Welcome to the expense handling system!" << endl;
  cout << "This program can hold up to 100 expenses.\n" << endl;

  showMenu(expenses, size);

}




/*************************************************************
* Purpose: shows option menu and leads to the other functions
* Parameters:
*    Expense (IN) - to pass as function parameters
*    int (IN) - to pass as function parameters
*
* Return:    Either only outputs or adds an Expense element to expenses array
**************************************************************/
void showMenu(Expense expenses[], int size)
{

  char buf[2];
  int option;

  while (true)
  {

    cout << "Expense Tracking Menu:\n";
    cout << " 1. Show all\n";
    cout << " 2. Spend\n";
    cout << " 3. Search expenses containing this string\n";
    cout << " 4. Search expenses with greater than or equal to this amount\n";
    cout << " 5. Exit" << endl;
    cout << "Option: ";
    

    buf[0] = '\0'; // reset buf from prior looping
    cin >> buf;
    if (strcmp(buf, "5") == 0) break; // the infinite loop will break with 5
    option = atoi(buf); // C-string, so .c_str() is unnecessary
    cin.ignore(200, '\n'); // making sure the next input doesn't get skipped

    cout << "\n\n\n" << endl;

    switch (option)
    {

      case 1:
        showExpenses(expenses, size);
        cout << endl << endl;
        break;
      case 2:
        addExpense(expenses, size);
        cout << endl << endl;
        break;
      case 3:
        wordSearchExpenses(expenses, size);
        cout << endl << endl;
        break;
      case 4:
        costSearchExpenses_ge(expenses, size);
        cout << endl << endl;
        break;
      default:
        cout << "Invalid input, try again." << endl;
        cout << endl << endl;
        // doesn't break on purpose to continue loop until valid input

    }

  }

}




/*************************************************************
* Purpose: neatly outputs expenses array
* Parameters:
*    Expense (IN) - the Expense array to be searched through
*    int (IN) - for the condition to loop through the array
*
* Return:    (nothing, just for output)
**************************************************************/
void showExpenses(Expense expenses[], int size)
{

  
  

    if (size <= 0)
    {

      cout << "There is no expense entry available." << endl;

    }
    else
    {

      for (int i = 0; i < size; i++)
      {
      
        cout.setf(ios::fixed); // to focus on decimal
        cout.precision(2); // 2 numbers after decimal since it's US dollars
        cout << expenses[i].description << ": $" << expenses[i].cost << endl;

      }

    }

  

}




/*************************************************************
* Purpose: adds an Expense to the expenses array
* Parameters:
*    Expense (OUT) - the Expense array to be searched through
*    int& (IN) - for the condition to loop through the array, also increments
*
* Return:    Expense array with new Expense element
**************************************************************/
void addExpense(Expense expenses[], int& size)
{

  string buf;
  double doubleBuf;


  while (true)
  {

    int counter = 0;

    cout << "Name/Describe the expense: ";
    getline(cin, buf);

    // Check to see if entire input is only spaces
    for (int i = 0; i < buf.length(); i++)
      if (buf[i] != ' ')
        counter++;

    if (counter > 0)
    {

      expenses[size].description = buf;
      break;

    }

    // will loop if input is invalid
    cout << "Name/Description shouldn't be empty, try again." << endl;

  }


  while (true)
  {

    cout << "Cost of the expense: ";
    cin >> buf;
    doubleBuf = atof(buf.c_str());
    cin.ignore(200, '\n'); // making sure the next input doesn't get skipped


    // checks to see if input is invalid
    if (doubleBuf > 0)
    {

      expenses[size].cost = doubleBuf;
      break;

    }

    cout << "Cost shouldn't be less than or equal to 0, try again." << endl;

  }

  size++;

}




/*************************************************************
* Purpose: searches expenses array by a keyword
* Parameters:
*    Expense (IN) - the Expense array to be searched through
*    int (IN) - for the condition to loop through the array
*
* Return:    (nothing, just for output)
**************************************************************/
void wordSearchExpenses(Expense expenses[], int size)
{

  string buf;
  string keyWord;


  cout << "Enter a keyword/keyphrase to search your expenses by: ";
  getline(cin, keyWord);


  for (int i = 0; i < size; i++)
  {

    keyWord = toLowerCase(keyWord);

    // checks if the keyword is in the expenses array
    if (toLowerCase(expenses[i].description).find(keyWord) != string::npos)
      cout << expenses[i].description << ": $" << expenses[i].cost << endl;

  }

}




/*************************************************************
* Purpose: searches expenses by a cost >= the specified cost
* Parameters:
*    Expense (IN) - the Expense array to be searched through
*    int (IN) - for the condition to loop through the array
*
* Return:    (nothing, just for output)
**************************************************************/
void costSearchExpenses_ge(Expense expenses[], int size)
{

  string buf;
  double cost;


  cout << "Enter a cost to search your expenses by: ";
  cin >> buf; cost = atof(buf.c_str()); // inputting buf into cost
  cin.ignore(200, '\n'); // making sure the next input doesn't get skipped


  for (int i = 0; i < size; i++)
    if (expenses[i].cost >= cost)
      cout << expenses[i].description << ": $" << expenses[i].cost << endl;

}




/*************************************************************
* Purpose: Converts a string to lowercase (function written by Professor Lam)
* Parameters:
*    string (OUT) - the string to be converted to lowercase
*
* Return:    the lowercase version of aCppString
**************************************************************/
string toLowerCase(string aCppString)
{
  int n = aCppString.length( );
  for (int i = 0; i < n; i++)
    aCppString[i] = tolower(aCppString[i]);
  return aCppString;
}