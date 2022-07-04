/***********************************************************************
* Program:
*    Project 13, Sudoku        
*    Brother Ridges, CS124
* Author:
*    Jeremy Johnson
* Summary: 
*    This program will import a pre-made sukoku board from a text
*    file and provide an user interface to interact with the
*    board. This particular iteration of the project will has 
*    a developed function to retrieve the file, write the file
*    to an array, and display the sudoku in classic sudoku 
*    format. 
*
************************************************************************/

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
const int SIZE = 9;

//All Prototypes set below for convenience
bool read(   int board[][SIZE], char *fileName);
void display(int board[][SIZE]);
void interact (int board[][SIZE], char *fileName, int possibleValues[SIZE], 
   int coordinates[2], char chosenSquare[256]);
bool getCoordinates(int board[][SIZE], int coordinates[2], 
   char chosenSquare[256]);
void displayInstructions();
void editSquare(int board[][SIZE], int coordinates[2], char chosenSquare[256]);
void showPossValues(int board[][SIZE], int possibleValues[SIZE], 
   int coordinates[2], char chosenSquare[256]);
void displayOptions();
void saveAndQuit(int board[][SIZE]);



/**********************************************************************
 * The 'main' function sets the board and fileName variables, then 
 * prompts the user for a file. It then calls the 'interact' 
 * function, which is the pivotal function for the program.
 ***********************************************************************/
int main()
{
   int board[SIZE][SIZE];   //The board is 9x9, and stored in this array
   char fileName[256]; //The fileName is stored here.
   int possibleValues[SIZE];
   int coordinates[2];
   char chosenSquare[256];
   cout << "Where is your board located? ";
   cin  >> fileName;
   if (!read(board, fileName))
   {
      cout << "ERROR: Unable to open file \"" << fileName << "\"\n";
      return 1;
   }
   interact(board, fileName, possibleValues, coordinates, 
      chosenSquare); //The 'other main' function.
   saveAndQuit(board);

   return 0;
}

/**********************************************************************
 * This simply displays the instructions for the user.
 ***********************************************************************/
void displayInstructions()
{
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit";
   cout << "\n";

   return;
}

/**********************************************************************
 * The 'interact' function calls the other functions for the
 * user to interact with the program. It needs several parameters
 * that are arrays for each of the functions to function. See what
 * I did there? :)
 ***********************************************************************/
void interact(int board[][SIZE], char *fileName, int possibleValues[SIZE], 
   int coordinates[2], char chosenSquare[256])
{
   char selection;
   //This 'do while' loop serves has embedded 'if' 
   //statements to run the program through the 
   //users selections.
   displayInstructions();
   display(board);
   cout << "\n> ";
   cin >> selection;
   //'Do While' loop allows the user to instantly be able to cycle through the
   // options.
   do
   {
      // If d, call the display function.
      if ((selection == 'd') || (selection == 'D'))
      {
         display(board);
         cout << "\n> ";
         cin >> selection;
      }
      // If e, call the editSquare function.
      else if ((selection == 'e') || (selection == 'E'))
      {
         editSquare(board, coordinates, chosenSquare);
         cout << "\n> ";
         cin >> selection;
      }
      // If 's', call the showPossValues function.
      else if ((selection == 's') || (selection == 'S'))
      {
         showPossValues(board, possibleValues, coordinates, chosenSquare);
         cout << "\n> ";
         cin >> selection;
      }

      else if (selection == '?')
      {
         displayInstructions();
         cout << "\n\n> ";
         cin >> selection;
      }
      else
      {
         cout << "ERROR: Invalid command\n";
         cout << "\n> ";
         cin >> selection;
      }
   } 
   // If the user selects 'Q', then we exit, and the 
   // save and quit function is at the end of the 'main'.
   while ((selection != 'Q') && (selection != 'q'));

   return;
}


/**************************************************************
 * READ
 * Read the board from the specified filename, and place it
 * into the 'board' array.
 *************************************************************/
bool read(int board[][SIZE], char *fileName)
{
   assert(*fileName);

   // open the file
   ifstream fin(fileName);
   if (fin.fail())
      return false;

   // read through the array.
   // read the row
   for (int r = 0; r < SIZE; r++) 
   // read the column
      for (int c = 0; c < SIZE; c++)
      {
         fin >> board[r][c];
      }

   // close the file
   fin.close();
   return true;
}


/*******************************************************
 * Display the contents the the screen. This was accomplished
 * with a series of 'if' statements.
 *****************************************************/
void display(int board[][SIZE])
{
   cout << "\n   A B C D E F G H I\n";
   // Loop through the row
   for (int r = 0; r < SIZE; r++)
   {
      cout << r + 1 << "  ";
      // Loop through the column
      for (int c = 0; c < SIZE; c++)
      {
         if ((c == 8) && (r != 2) && (r != 5))
         {
            if (board[r][c] == 0)
            {
               cout << " "; 
               cout << "\n";
            }
            else
            {
               cout << board[r][c];
               cout << "\n";
            }
         }
         else if ((c == 8) && ((r == 2) || (r == 5)))
         {
            if (board[r][c] == 0)
            {
               cout << " "; 
               cout << "\n" << "   -----+-----+-----\n";
            }
            else
            {
               cout << board[r][c];               
               cout << "\n" << "   -----+-----+-----\n";
            }
         }
         else
         {
            if (board[r][c] == 0)
            {
               if ((c == 2) || (c == 5))
                  cout << " |";
               else 
                  cout << "  ";
            }
            else
            {
               if ((c == 2) || (c == 5))
                  cout << board[r][c] << "|";
               else
                  cout << board[r][c] << " ";
            }
         }
      }
   }
   
   return;

}

/**********************************************************************
 * This editSquare allows the user to choose and edit a square from the
 * board.
 ***********************************************************************/
void editSquare(int board[][SIZE], int coordinates[2], char chosenSquare[256])
{
   int insertedValue;
   bool validCoordinates;
   int rowStart;
   int colStart;
   bool checkNumRow = true;
   bool checkNumCol = true;
   bool checkNumBox = true;
   int row = 0;
   int col = 0;

   // We need to get coordinates, by calling that function.
   validCoordinates = getCoordinates(board, coordinates, chosenSquare);
   if (validCoordinates == false)
      return;
   else
   {
      row = coordinates[0];
      col = coordinates[1];
   }

   // We now get the value for the chosen square and put it in 'insertedValue';
   cout << "What is the value at '" << chosenSquare << "': ";
   cin >> insertedValue; 

   // This is to get a starting place to loop through
   // the square, depending on the row/column numbers.
   if (row <= 2)
      rowStart = 0;
   else if (row <= 5)
      rowStart = 3;
   else if (row <= 9)
      rowStart = 6;

   if (col <= 2)
      colStart = 0;
   else if (col <= 5)
      colStart = 3;
   else if (col <= 8)
      colStart = 6;


   // Here, we loop through the board, and check the chosen
   // number against the possible values.
   for (int m = 0; m < SIZE; m++)
   {
      for (int c = 0; c < SIZE; c++)
      {
         if (board[row][c] == insertedValue)
            checkNumCol = false;         
      }

      for (int r = 0; r < SIZE; r++)
      {
         if (board[r][col] == insertedValue)
            checkNumRow = false;
      }

      for (int j = rowStart; j < rowStart + 3; j++)
      {
         for (int k = colStart; k < colStart + 3; k++)
         {
            if (board[j][k] == insertedValue)
               checkNumBox = false;
         }
      }

      if ((checkNumBox == true) && (checkNumCol == true) 
         && (checkNumRow == true))
      {
         board[row][col] = insertedValue;
         return;
      }
      else
      {
         cout << "ERROR: Value '" << insertedValue << "' in square '" << 
            chosenSquare << "' is invalid\n";
         break;
      }
   }



   return;
}

/**********************************************************************
 * The 'showPossValues' function will allow the user to select a
 * square, and then get the possible values for that square based
 * on the rules of sudoku. This is similar to the editSquare 
 * function, except it loops through 1-9 instead of checking one
 * single number.
 ***********************************************************************/
void showPossValues(int board[][SIZE], int possibleValues[SIZE], 
   int coordinates[2], char chosenSquare[256])
{
   int rowStart1;
   int colStart1;
   bool checkNumRow1 = true;
   bool checkNumCol1 = true;
   bool checkNumBox1 = true;
   int checkNum1 = 1;
   int count1 = 1;
   int row1 = 0;
   int col1 = 0;


   bool validCoordinates1;
   validCoordinates1 = getCoordinates(board, coordinates, chosenSquare);
   if (validCoordinates1 == false)
      return;
   else
   {
      row1 = coordinates[0];
      col1 = coordinates[1];
   }

   if (row1 <= 2)
      rowStart1 = 0;
   else if (row1 <= 5)
      rowStart1 = 3;
   else if (row1 <= 9)
      rowStart1 = 6;

   if (col1 <= 2)
      colStart1 = 0;
   else if (col1 <= 5)
      colStart1 = 3;
   else if (col1 <= 8)
      colStart1 = 6;




   cout << "The possible values for '" << chosenSquare << "' are: ";

// Attempt at possible values
   for (int m1 = 0; m1 < SIZE; m1++)
   {
      for (int c1 = 0; c1 < SIZE; c1++)
      {
         if (board[row1][c1] == checkNum1)
            checkNumCol1 = false;         
      }

      for (int r1 = 0; r1 < SIZE; r1++)
      {
         if (board[r1][col1] == checkNum1)
            checkNumRow1 = false;
      }

      for (int j1 = rowStart1; j1 < rowStart1 + 3; j1++)
      {
         for (int k1 = colStart1; k1 < colStart1 + 3; k1++)
         {
            if (board[j1][k1] == checkNum1)
               checkNumBox1 = false;
         }
      }

      if ((checkNumBox1 == true) && (checkNumCol1 == true) 
         && (checkNumRow1 == true))
      {
         possibleValues[count1] = checkNum1;
         checkNum1++;
         count1++;
      }
      else
      {
         checkNum1++;
         checkNumRow1 = true;
         checkNumCol1 = true;
         checkNumBox1 = true;  
      } 
   }
   int poss1 = possibleValues[0];
   int poss2 = possibleValues[1];
   int poss3 = possibleValues[2];
   int poss4 = possibleValues[3];
   int poss5 = possibleValues[4];
   int poss6 = possibleValues[5];
   int poss7 = possibleValues[6];
   int poss8 = possibleValues[7];
   int poss9 = possibleValues[8];

   // This is how we are outputting the possible numbers.
   cout << poss1;

   if (count1 == 1)
   {
      "\n";
   }
   else if (count1 == 2)
   {
      cout << ", " << poss2 << "\n";
   }
   else if (count1 == 3)
   {
      cout << ", " << poss2 << ", " << poss3 << "\n";
   }
   else if (count1 == 4)
   {
      cout << ", " << poss2 << ", " << poss3 << 
         ", " << poss4 << "\n";
   }
   else
   {
      "\n";
   }   

   return;
}

/**********************************************************************
 * The getCoordinates function will is called in two places, and it 
 * intended to alert the user if the square is full, and also to 
 * output an error if the user types something in incorrectly.
 ***********************************************************************/
bool getCoordinates(int board[][SIZE], int coordinates[2], 
   char chosenSquare[256])
{
   cout << "What are the coordinates of the square: "; // User chooses square
   cin >> chosenSquare; // Input that value into the array.

   // Below is how we chose to convert the user input into and int coordinate.
   char cColumn = chosenSquare[0]; 
   char cRow = chosenSquare[1];
   
   int iRow = 0;
   int iColumn = 0;

   if (cRow == '1')
      iRow = 0;
   else if (cRow == '2')
      iRow = 1;
   else if (cRow == '3')
      iRow = 2;
   else if (cRow == '4')
      iRow = 3;
   else if (cRow == '5')
      iRow = 4;
   else if (cRow == '6')
      iRow = 5;
   else if (cRow == '7')
      iRow = 6;
   else if (cRow == '8')
      iRow = 7;
   else if (cRow == '9')
      iRow = 8;
   else
      iRow = 99;

   if ((cColumn == 'a') || (cColumn == 'A'))
      iColumn = 0;
   else if ((cColumn == 'b') || (cColumn == 'B'))
      iColumn = 1;
   else if ((cColumn == 'c') || (cColumn == 'C'))
      iColumn = 2;
   else if ((cColumn == 'd') || (cColumn == 'D'))
      iColumn = 3;
   else if ((cColumn == 'e') || (cColumn == 'E'))
      iColumn = 4;
   else if ((cColumn == 'f') || (cColumn == 'F'))
      iColumn = 5;
   else if ((cColumn == 'g') || (cColumn == 'G'))
      iColumn = 6;
   else if ((cColumn == 'h') || (cColumn == 'H'))
      iColumn = 7;
   else if ((cColumn == 'i') || (cColumn == 'I'))
      iColumn = 8;
   else
      iColumn = 99;

   // Verify the selection is within the parameters of the board
   while ((iColumn == 99) || (iRow == 99))
   {
      char chosenSquare[256];
      cout << "ERROR: Square '" << chosenSquare << "' is invalid.\n";
      cout << "What are the coordinates of the square: ";
      cin >> chosenSquare;

      cColumn = chosenSquare[0];
      cRow = chosenSquare[1];
   
      if (cRow == '1')
         iRow = 0;
      else if (cRow == '2')
         iRow = 1;
      else if (cRow == '3')
         iRow = 2;
      else if (cRow == '4')
         iRow = 3;
      else if (cRow == '5')
         iRow = 4;
      else if (cRow == '6')
         iRow = 5;
      else if (cRow == '7')
         iRow = 6;
      else if (cRow == '8')
         iRow = 7;
      else if (cRow == '9')
         iRow = 8;
      else
         iRow == 99;

      if ((cColumn == 'a') || (cColumn == 'A'))
         iColumn = 0;
      else if ((cColumn == 'b') || (cColumn == 'B'))
         iColumn = 1;
      else if ((cColumn == 'c') || (cColumn == 'C'))
         iColumn = 2;
      else if ((cColumn == 'd') || (cColumn == 'D'))
         iColumn = 3;
      else if ((cColumn == 'e') || (cColumn == 'E'))
         iColumn = 4;
      else if ((cColumn == 'f') || (cColumn == 'F'))
         iColumn = 5;
      else if ((cColumn == 'g') || (cColumn == 'G'))
         iColumn = 6;
      else if ((cColumn == 'h') || (cColumn == 'H'))
         iColumn = 7;
      else if ((cColumn == 'i') || (cColumn == 'I'))
         iColumn = 8;
      else
         iColumn = 99;
   }

   while (board[iRow][iColumn] != 0)
   {
      cout << "ERROR: Square '" << chosenSquare << "' is filled\n";
      return false;
   }  

   coordinates[0] = iRow;
   coordinates[1] = iColumn;
   
   return true; 

}

/**********************************************************************
 * The 'saveAndQuit' function will write the user's changes to 
 * a file they create.
 ***********************************************************************/
void saveAndQuit(int board[][SIZE])
{
   char board1[256];
   cout << "What file would you like to write your board to: ";
   cin >> board1;
   ofstream fout(board1);

   if (fout.fail())
   {
      cout << "Unable to open file " << board1
         << "." << "\n";
      return;
   }
   for (int r = 0; r < SIZE; r++)
   {
      for (int c = 0; c < SIZE; c++)
      {
         if (c != (SIZE - 1))
            fout << board[r][c] << " ";
         else
            fout << board[r][c] << "\n";
      }
   }
   cout << "Board written successfully\n";
   fout.close();
   return;
}