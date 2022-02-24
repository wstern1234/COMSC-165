// Identification comments code block
// Wills Stern
// Lab 6, Linked Lists
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

#include <algorithm>
using std::swap;

#include <cstdlib> // for atoi/atof
#include <cctype> // for toupper and tolower




struct Movie {

  string title;
  int yearViewed;
  int rating;
  Movie *next;

};







// function prototypes
void showMenu(Movie *, Movie *&, int&);
void addMovie(Movie *&, Movie *&, int&);
void updateMovie(Movie *, int);
void removeMovie(Movie *&, int&);
void listMovies(Movie *);
void arrangeTitle(Movie *);
void arrangeViewed(Movie *);
void arrangeRating(Movie *);
string toLowerCase(string);






int main()
{

  // identification output code block
  cout << "Wills Stern\n\n";
  cout << "Lab 6, Linked Lists\n";
  cout << "Editor(s) used: VSCode\n";
  cout << "Compiler(s) used: g++\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n\n\n";

  
  

  int nodeCount = 0; // keeps track of number of nodes
  Movie *movies = 0, *temp = 0; // The head of the linked list and a temporary
                                // Movie pointer


  showMenu(movies, temp, nodeCount);



  // Removes all nodes when program ends
  while (movies) 
  {
      Movie* p = movies; // head node

      movies = movies->next;
      delete p;  // now deallocate the old head
  }

}




/*************************************************************
* Purpose: shows option menu and leads to the other functions
*          to manipulate the movies linked list
* Parameters:
*    Movie * - to pass, edit, and view linked list
*    Movie *& - pass by reference, to help traverse linked list
*    int & - pass by reference, to help traverse linked list
*
* Return:    (Nothing)
**************************************************************/
void showMenu(Movie *movies, Movie *&temp, int& count)
{

  char buf, option;

  // directs the entire program
  while (true)
  {

    cout << "Expense Tracking Menu:\n";
    cout << " A: Add a movie\n";
    cout << " U: Update a movie\n";
    cout << " E: rEmove a movie\n";
    cout << " L: List all movies\n";
    cout << " T: arrange by Title\n";
    cout << " V: arrange by year Viewed\n";
    cout << " R: arrange by Rating\n";
    cout << " Q: Quit" << endl;
    cout << "Option: ";
    

    cin >> buf;
    if (toupper(buf) == 'Q') break; // the infinite loop will break with Q
    option = toupper(buf); // helps make the program case-independent
    cin.ignore(200, '\n'); // making sure the next input doesn't get skipped

    cout << "\n\n\n" << endl; // just to space up console output

    if (option == 'A')
    {

      addMovie(movies, temp, count);

    }
    else if (option == 'U')
    {

      updateMovie(movies, count);

    }
    else if (option == 'E')
    {

      removeMovie(movies, count);

    }
    else if (option == 'L')
    {

      listMovies(movies);

    }
    else if (option == 'T')
    {

      arrangeTitle(movies);

    }
    else if (option == 'V')
    {

      arrangeViewed(movies);

    }
    else if (option == 'R')
    {

      arrangeRating(movies);

    }
    else
    {
      cout << "Invalid input, try again." << endl << endl << endl;
      // doesn't break on purpose to continue loop until valid input
    }
    

  }

}




/*************************************************************
* Purpose: adds a movie to the movies linked list
* Parameters:
*    Movie *& - pass by reference, to add to linked list
*    Movie *& - pass by reference, to help traverse linked list
*    int & - pass by reference, to help traverse linked list
*
* Return:    Modified movies linked list
**************************************************************/
void addMovie(Movie *&movies, Movie *&temp, int& count)
{

  string buf, movieName;
  int year, rating;

  cout << "Name of Movie: ";
  getline(cin, movieName);

  cout << "Year Viewed: ";
  cin >> buf; year = atoi(buf.c_str());

  cout << "Your Rating (1-5): ";
  cin >> buf; rating = atoi(buf.c_str());

  // following block adds the new movie to the linked list
  temp = new Movie {movieName, year, rating};
  temp->next = movies;
  movies = temp;

  cout << endl << endl;

  count++;

}




/*************************************************************
* Purpose: updates a movie in the movies linked list
* Parameters:
*    Movie * - so the function can modify the linked list
*
* Return:    Modified movies linked list
**************************************************************/
void updateMovie(Movie *movies, int count)
{

  string buf;
  Movie *nodePtr; // Movie pointers to track node location
  int indexMovie, i = 0;

  listMovies(movies);

  cout << "Select a movie to update (1-" << count << "): ";
  cin >> buf; indexMovie = atoi(buf.c_str()) - 1; // subtracts 1 for the loop

  // finds node to update
  for (nodePtr = movies; i < indexMovie; nodePtr = nodePtr->next, i++);
    

  // directs user to update an attribute, else not found
  if (nodePtr)
  {
    string buf;
    char option;

    // infinite loop to catch for user error
    while (true)
    {

      cout << "Choose which to update ((T)itle, (Y)ear Viewed, (R)ating)): ";
      cin >> option;


      // case-independently checks if user wants to update the title
      if (toupper(option) == 'T')
      {
        cout << "\nEnter a new title for " << nodePtr->title << ": ";
        getline(cin, nodePtr->title);
        break;
      }
      // case-independently checks if user wants to update the year viewed
      else if (toupper(option) == 'Y')
      {
        cout << "\nEnter a new year viewed for " << nodePtr->title << ": ";
        cin >> buf; nodePtr->yearViewed = atoi(buf.c_str());
        break;
      }
      // case-independently checks if user wants to update the rating
      else if (toupper(option) == 'R')
      {
        cout << "\nEnter a new rating for " << nodePtr->title << ": ";
        cin >> buf; nodePtr->rating = atoi(buf.c_str());
        break;
      }
      else
      {
        cout << "Not valid, try again" << endl;
      }
    }
    

    cout << endl;
  }
  else
  cout << "Movie wasn't found" << endl;



  cout << endl << endl;

}




/*************************************************************
* Purpose: removes a movie in the movies linked list
* Parameters:
*    Movie *& - pass by reference, so the function can modify the linked list
*    int & - pass by reference, helps define the size of the linked list
*
* Return:    Modified movies linked list
**************************************************************/
void removeMovie(Movie *&movies, int& count)
{

  string buf;
  Movie *nodePtr, *prev; // Movie pointers to track node location
  int indexMovie, i = 0;

  listMovies(movies);

  cout << "Select a movie to remove (1-" << count << "): ";
  cin >> buf; indexMovie = atoi(buf.c_str()) - 1; // subtracts 1 for the loop

  // finds node to delete
  for (nodePtr = movies, prev = 0; i < indexMovie;
      prev = nodePtr, nodePtr = nodePtr->next, i++);
    

  // removes node and links the two nodes around the removed node
  if (nodePtr)
  {
    if (prev)
      prev->next = nodePtr->next;
    else
      movies = nodePtr->next; // new head 
    delete nodePtr; // no longer needed, so delete
  }
  else
    cout << "Movie wasn't found";


  cout << endl << endl << endl;

  count--;

}




/*************************************************************
* Purpose: neatly outputs the movies linked list
* Parameters:
*    Movie * - so the function can output the linked list
*
* Return:    (Nothing)
**************************************************************/
void listMovies(Movie *movies)
{

  // header
  cout << "#  Title                                    Viewed    Rating\n";
  cout << "-  -------------                            ------    ------\n";

  int index = 1;

  // loops through and outputs the linked list
  for (Movie *nodePtr = movies; nodePtr; nodePtr = nodePtr->next, index++)
  {
    cout << index << "  ";
    cout.width(1); cout << nodePtr->title;

    // neatly distances the sequence num and title from year viewed and rating
    for (int i = 0; i < 42 - nodePtr->title.length(); i++)
      cout << " ";

    cout.setf(ios::right);
    cout << nodePtr->yearViewed;
    cout.width(8); cout << nodePtr->rating << endl;
    cout.unsetf(ios::right);
  }

  cout << endl << endl;

}




/*************************************************************
* Purpose: arranges the movies linked list by title
* Parameters:
*    Movie * - so the function can rearranged the linked list
*
* Return:    rearranged linked list
**************************************************************/
void arrangeTitle(Movie *movies)
{

  // main loop and inner loop to perfectly rearrange linked list
  for (Movie *p = movies; p; p = p->next)
    for (Movie *q = p->next; q; q = q->next)
      if (q->title < p->title)  {
        swap(*p, *q);
        swap(p->next, q->next);
        
      }

}




/*************************************************************
* Purpose: arranges the movies linked list by viewing year
* Parameters:
*    Movie * - so the function can rearranged the linked list
*
* Return:    rearranged linked list
**************************************************************/
void arrangeViewed(Movie *movies)
{

  // main loop and inner loop to perfectly rearrange linked list
  for (Movie *p = movies; p; p = p->next)
    for (Movie *q = p->next; q; q = q->next)
      if (q->yearViewed < p->yearViewed)  {
        swap(*p, *q);
        swap(p->next, q->next);
        
      }

}




/*************************************************************
* Purpose: arranges the movies linked list by rating
* Parameters:
*    Movie * - so the function can rearranged the linked list
*
* Return:    rearranged linked list
**************************************************************/
void arrangeRating(Movie *movies)
{

  // main loop and inner loop to perfectly rearrange linked list
  for (Movie *p = movies; p; p = p->next)
    for (Movie *q = p->next; q; q = q->next)
      if (q->yearViewed < p->yearViewed)  {
        swap(*p, *q);
        swap(p->next, q->next);
        
      }

}




/*************************************************************
* Purpose: Converts a string to lowercase
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