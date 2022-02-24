// Identification comments code block
// Wills Stern
// Lab 8, Artificial Intelligence With Innate Knowledge
// Editor(s) used: VS Code
// Compiler(s) used: g++


#include <iostream>
using std::cout;
using std::cin;
using std::ios;
using std::endl;

#include <fstream>
using std::ofstream;

#include <string>
using std::string;
using std::getline;

#include <cctype> // for tolower


struct PC_Part
{
  string choice;
  PC_Part* yes;
  PC_Part* no;
};

// function prototypes
void deallocate(PC_Part*);
void serializeDown(ofstream&, PC_Part*);


/* BINARY TREE DESIGN
                        Is it a CPU (AKA a processor)?
        yes/                                                           \no
          /                                                             \
            Is it from Intel?                                           Does it process computer graphics?
        yes/                  \no                                 yes/                                     \no
        	/                    \                                    /                                       \
    Is it new?            Does it have 7 nm transistors?         Is it a new NVIDIA GPU?                Does it concern power consumption?
  yes/        \no           yes/              \no                    yes/             \no                        yes/                \no
    /          \              /                \                       /               \                           /                  \ 
i9-10900K     i5-9400F     Ryzen 9 5900X    Ryzen 5 2600X      It's an RTX 3090      It's a GTX 1660 Ti       It's a PSU          It's a storage unit
*/

int main()
{

  // identification output code block
  cout << "Wills Stern\n\n";
  cout << "Lab 8, Artificial Intelligence With Innate Knowledge\n";
  cout << "Editor(s) used: VSCode\n";
  cout << "Compiler(s) used: g++\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n\n\n";

  


  ofstream fout; // to serialize down to a TXT file

  // results
  PC_Part* answer1 = new PC_Part {"It's an i9-10900K"};
  PC_Part* answer2 = new PC_Part {"It's an i5-9400F"};
  PC_Part* answer3 = new PC_Part {"It's a Ryzen 9 5900X"};
  PC_Part* answer4 = new PC_Part {"It's a Ryzen 5 2600X"};
  PC_Part* answer5 = new PC_Part {"It's an RTX 3090"};
  PC_Part* answer6 = new PC_Part {"It's a GTX 1660 Ti"};
  PC_Part* answer7 = new PC_Part {"It's a PSU (Power Supply Unit"};
  PC_Part* answer8 = new PC_Part {"It's a storage unit"};
  

  // 2nd level questions
  PC_Part* lv2_Q1 = new PC_Part {
    "Is it new?",
    answer1,
    answer2
  };

  PC_Part* lv2_Q2 = new PC_Part {
    "Does it have 7 nm transistors?",
    answer3,
    answer4
  };

  PC_Part* lv2_Q3 = new PC_Part {
    "Is it a new NVIDIA GPU?",
    answer5,
    answer6
  };

  PC_Part* lv2_Q4 = new PC_Part {
    "Does it concern power consumption?",
    answer7,
    answer8
  };


  // 1st level questions
  PC_Part* lv1_Q1 = new PC_Part {
    "Is it from Intel?",
    lv2_Q1,
    lv2_Q2
  };

  PC_Part* lv1_Q2 = new PC_Part {
    "Does it process computer graphics?",
    lv2_Q3,
    lv2_Q4
  };


  // top question
  PC_Part* topQ = new PC_Part {
    "Is it a CPU (AKA a processor)?",
    lv1_Q1,
    lv1_Q2
  };

 
  char opt; // allows the user to enter Y/y or N/n for each option
 
  // the "challenge" to the user
  cout << "\nTell me about a PC component and I'll identify it.\n";
 
  PC_Part* p = topQ; // move p through the tree

  // the p-loop
  while (true)
  {
    cout << p->choice; // outputs question/answer
    if (p->yes == 0 && p->no == 0) break; // it was the answer
    cout << " [Y/y or N/n]: ";

    cin >> opt;
    if (tolower(opt) == 'y') p = p->yes;
    else if (tolower(opt) == 'n') p = p->no;
  }

  cout << endl; // extra spacing


  fout.open("ai.txt");

  serializeDown(fout, topQ);

  fout.close();


  deallocate(topQ); // deallocates all nodes in binary tree


}




/*************************************************************
* Purpose: recursively serializes down all the nodes in the binary tree
* Parameters:
*    ofstream& - pass by reference, so the function can write to the TXT file
*    PC_Part* - so the function can traverse the binary tree
*
* Return:    (Nothing)
**************************************************************/
void serializeDown(ofstream& fout, PC_Part* p)
{
  // make sure there's something to serialize
  if (p == nullptr)
    fout << "EOF\n";
  else
  {
    // serialize the p node itself
    fout << p->choice << "\n";
	serializeDown(fout, p->yes);  // serialize p->yes and all nodes below it
    serializeDown(fout, p->no);  // serialize p->no and all nodes below it
  }
}




/*************************************************************
* Purpose: recursively deallocates all the nodes in the binary tree
* Parameters:
*    PC_Part* - so the function can traverse the binary tree
*
* Return:    (Nothing)
**************************************************************/
void deallocate(PC_Part* p)
{

  if (p == 0) return;

  // this block recursively travels through and deallocates entire tree
  deallocate(p->yes);
  deallocate(p->no);

  delete p;

}
