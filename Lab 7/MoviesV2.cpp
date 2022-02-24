// Identification comments code block
// Wills Stern
// Lab 7, Queue
// Editor(s) used: VS Code
// Compiler(s) used: g++


#include <iostream>
using std::cout;
using std::cin;
using std::ios;

#include <fstream>
using std::ifstream;
using std::ofstream;

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
void showMenu(Movie *, Movie *&, Movie *&, int&);
void addMovie(Movie *&, Movie *&, Movie *&, int&);
void updateMovie(Movie *, int);
void removeMovie(Movie *&, Movie *&, int&);
void listMovies(Movie *);
void arrangeTitle(Movie *);
void arrangeViewed(Movie *);
void arrangeRating(Movie *);
void serializeUp(Movie *&, Movie*&, int&);
void serializeDown(Movie *);






int main()
{

  // identification output code block
  cout << "Wills Stern\n\n";
  cout << "Lab 7, Queue\n";
  cout << "Editor(s) used: VSCode\n";
  cout << "Compiler(s) used: g++\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n\n\n";

  
  

  int nodeCount = 0; // keeps track of number of nodes
  Movie *firstMovie = 0, *lastMovie = 0, *temp = 0;

  
  serializeUp(firstMovie, lastMovie, nodeCount);


  showMenu(firstMovie, lastMovie, temp, nodeCount);


  // Removes all nodes when program ends
  while (firstMovie)
  {
    Movie* temp = firstMovie;
    firstMovie = firstMovie->next;
    delete temp;
  }

  lastMovie = 0; // Can't forget to set lastMovie pointer to 0/null

}




/*************************************************************
* Purpose: shows option menu and leads to the other functions
*          to manipulate the movies queue
* Parameters:
*    Movie * - to pass, edit, and view queue
*    Movie *& - to keep track of end node of queue
*    Movie *& - pass by reference, to help traverse queue
*    int & - pass by reference, to help traverse queue
*
* Return:    (Nothing)
**************************************************************/
void showMenu(Movie *firstMovie, Movie *&lastMovie, Movie *&temp, int& count)
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

      addMovie(firstMovie, lastMovie, temp, count);

    }
    else if (option == 'U')
    {

      updateMovie(firstMovie, count);

    }
    else if (option == 'E')
    {

      removeMovie(firstMovie, lastMovie, count);

    }
    else if (option == 'L')
    {

      listMovies(firstMovie);

    }
    else if (option == 'T')
    {

      arrangeTitle(firstMovie);

    }
    else if (option == 'V')
    {

      arrangeViewed(firstMovie);

    }
    else if (option == 'R')
    {

      arrangeRating(firstMovie);

    }
    else
    {
      cout << "Invalid input, try again.\n\n" << endl;
      // doesn't break on purpose to continue loop until valid input
    }
    

  }


  serializeDown(firstMovie);

}




/*************************************************************
* Purpose: adds a movie to the movies queue
* Parameters:
*    Movie *& - pass by reference, to add to queue
*    Movie *& - pass by reference, to keep track of end node of queue
*    Movie *& - pass by reference, to help traverse queue
*    int & - pass by reference, also to help traverse queue
*
* Return:    Modified movies queue
**************************************************************/
void addMovie(Movie *&firstMovie, Movie *&lastMovie, Movie *&temp, int& count)
{

  string buf, movieName;
  int year, rating;

  cout << "Name of Movie: ";
  getline(cin, movieName);

  cout << "Year Viewed: ";
  cin >> buf; year = atoi(buf.c_str());

  cout << "Your Rating (1-5): ";
  cin >> buf; rating = atoi(buf.c_str());

  // following block adds the new movie to the queue
  temp = new Movie {movieName, year, rating};
  temp->next = 0;
  if (lastMovie) lastMovie->next = temp;
  else firstMovie = temp;
  lastMovie = temp;

  cout << "\n" << endl;

  count++;

}




/*************************************************************
* Purpose: updates a movie in the movies queue
* Parameters:
*    Movie * - so the function can modify the queue
*    int - to help user locate the movie node to update
*
* Return:    Modified movies queue
**************************************************************/
void updateMovie(Movie *firstMovie, int count)
{

  string buf;
  Movie *nodePtr; // Movie pointers to track node location
  int indexMovie, i = 0;

  listMovies(firstMovie);

  cout << "Select a movie to update (1-" << count << "): ";
  cin >> buf; indexMovie = atoi(buf.c_str()) - 1; // subtracts 1 for the loop
  cin.ignore(200, '\n');

  // finds node to update
  for (nodePtr = firstMovie; i < indexMovie; nodePtr = nodePtr->next, i++);
    

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
        cin.ignore(200, '\n');
        getline(cin, nodePtr->title);
        break;
      }
      // case-independently checks if user wants to update the year viewed
      else if (toupper(option) == 'Y')
      {
        cout << "\nEnter a new year viewed for " << nodePtr->title << ": ";
        cin.ignore(200, '\n');
        cin >> buf; nodePtr->yearViewed = atoi(buf.c_str());
        break;
      }
      // case-independently checks if user wants to update the rating
      else if (toupper(option) == 'R')
      {
        cout << "\nEnter a new rating for " << nodePtr->title << ": ";
        cin.ignore(200, '\n');
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



  cout << "\n" << endl;

}




/*************************************************************
* Purpose: removes a movie in the movies queue
* Parameters:
*    Movie *& - pass by reference, so the function can modify the queue
*    Movie *& - pass by reference, to keep track of end node of queue
*    int& - pass by reference, to locate the node and to update node count
*
* Return:    Modified movies queue
**************************************************************/
void removeMovie(Movie *&firstMovie, Movie *&lastMovie, int& count)
{

  string buf;
  Movie *nodePtr, *prev; // Movie pointers to track node location
  int indexMovie, i = 0;

  listMovies(firstMovie);

  cout << "Select a movie to remove (1-" << count << "): ";
  cin >> buf; indexMovie = atoi(buf.c_str()) - 1; // subtracts 1 for the loop

  // finds node to delete
  for (nodePtr = firstMovie, prev = 0; i < indexMovie;
      prev = nodePtr, nodePtr = nodePtr->next, i++);
    

  // removes node and links the two nodes around the removed node
  if (nodePtr)
  {
    if (prev)
      prev->next = nodePtr->next;
    else
      firstMovie = nodePtr->next; // new head 
    
    delete nodePtr; // no longer needed, so delete
    if (nodePtr == lastMovie) lastMovie = prev;
  }
  else
    cout << "Movie wasn't found";


  cout << "\n\n" << endl;

  count--;

}




/*************************************************************
* Purpose: neatly outputs the movies queue
* Parameters:
*    Movie * - so the function can output the queue
*
* Return:    (Nothing)
**************************************************************/
void listMovies(Movie *firstMovie)
{

  // header
  cout << "#  Title                                              Viewed    Rating\n";
  cout << "-  -------------                                      ------    ------\n";

  int index = 1;

  // loops through and outputs the queue
  for (Movie *nodePtr = firstMovie; nodePtr; nodePtr = nodePtr->next, index++)
  {
    cout << index << "  ";
    cout.width(1); cout << nodePtr->title;

    // neatly distances the sequence num and title from year viewed and rating
    for (int i = 0; i < 52 - nodePtr->title.length(); i++)
      cout << " ";

    cout.setf(ios::right);
    cout << nodePtr->yearViewed;
    cout.width(8); cout << nodePtr->rating << endl;
    cout.unsetf(ios::right);
  }

  cout << "\n" << endl;

}




/*************************************************************
* Purpose: arranges the movies queue by title
* Parameters:
*    Movie * - so the function can rearranged the queue
*
* Return:    rearranged queue
**************************************************************/
void arrangeTitle(Movie *firstMovie)
{

  // main loop and inner loop to perfectly rearrange queue
  for (Movie *p = firstMovie; p; p = p->next)
    for (Movie *q = p->next; q; q = q->next)
      if (q->title < p->title)  {
        swap(*p, *q);
        swap(p->next, q->next);
        
      }

}




/*************************************************************
* Purpose: arranges the movies queue by viewing year
* Parameters:
*    Movie * - so the function can rearranged the queue
*
* Return:    rearranged queue
**************************************************************/
void arrangeViewed(Movie *firstMovie)
{

  // main loop and inner loop to perfectly rearrange queue
  for (Movie *p = firstMovie; p; p = p->next)
    for (Movie *q = p->next; q; q = q->next)
      if (q->yearViewed < p->yearViewed)  {
        swap(*p, *q);
        swap(p->next, q->next);
        
      }

}




/*************************************************************
* Purpose: arranges the movies queue by rating
* Parameters:
*    Movie * - so the function can rearranged the queue
*
* Return:    rearranged queue
**************************************************************/
void arrangeRating(Movie *firstMovie)
{

  // main loop and inner loop to perfectly rearrange queue
  for (Movie *p = firstMovie; p; p = p->next)
    for (Movie *q = p->next; q; q = q->next)
      if (q->rating < p->rating)  {
        swap(*p, *q);
        swap(p->next, q->next);
        
      }

}




/*************************************************************
* Purpose: Serialize up the queue from a TXT file
* Parameters:
*    Movie*& - pass by reference, starting point to begin serializing up
*    Movie*& - pass by reference, to keep track of end node of queue
*    int& - pass by reference, to keep track of node count
*
* Return:    (Nothing)
**************************************************************/
void serializeUp(Movie*& firstMovie, Movie*& lastMovie, int& nodeCount)
{

  ifstream fin;
  fin.open("movies.txt");

  // serializes up data from movies.txt into queue
  while (fin.good())
  {
    string buf;
    getline(fin, buf);
    if (fin.eof() || buf == "EOF") break; // if end of file reached, it breaks

    // use buf as the first attribute
    Movie* temp = new Movie;
    temp->title = buf;

    // read the remaining attributes
    fin >> temp->yearViewed; fin.ignore(1000, 10);
    fin >> temp->rating; fin.ignore(1000, 10);

    // link to the end of the queue
    temp->next = 0;
    if (lastMovie) lastMovie->next = temp;
    else firstMovie = temp;
    lastMovie = temp;

    nodeCount++;
  }
  fin.close( );

}




/*************************************************************
* Purpose: Serialize down the queue into a TXT file
* Parameters:
*    Movie* - starting point to begin serializing down
*
* Return:    (Nothing)
**************************************************************/
void serializeDown(Movie* firstMovie)
{

  ofstream fout; // creating object fout of "ofstream"

  fout.open("movies.txt"); // opening (or creating) movies.txt

  //sends all attributes of each course to movies.txt
  for (Movie* p = firstMovie; p; p = p->next)
  {
    fout << p->title << "\n";
    fout << p->yearViewed << "\n";
    fout << p->rating << "\n";
  }

  fout << "EOF" << endl;

  fout.close(); // ALWAYS close the file

}
