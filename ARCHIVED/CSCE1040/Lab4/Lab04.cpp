#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/********************************************************************
 **        NAME:  Patrick Burke         USERID:pwb0013             **
 **  ASSIGNMENT:  CSCE1040 Lab04                                   **
 ** DESCRIPTION:  This program reads "word data" from a file       **
 **      specified as a "Command Line Input".  The user provided   **
 **      the filename on the same line that runs the executable    **
 **      code (along with a count of parameters.  For example,     **
 **              ./a.out 3 twentywords.txt                         **
 **                                                                **
 **      The data in that file consists of exactly 20 lines, each  **
 **      comprised of the integer length of the word followed by   **
 **      the word itself ... with no spaces in between.  Each word **
 **      is read into the program, the number of "t" characters is **
 **      calculated, and the sum of the ascii values of the        **
 **      constituent characters is them computed.  These values    **
 **      are then reported to the screen.                          **
 **                                                                **
 ********************************************************************/

using namespace std;

int main ( int argc, char *argv[] )
{ //***MAIN***

  const int MAX_WORDS = 20;  // max number of words in input file
  const int MAX_S_LEN = 20;  // max length of the words in input file

  ifstream in_stream;        // identify the input file
  char word[MAX_WORDS];      // temp holds words as read char-by-char

  int i,                     // general purpose iterator
      str_len,               // actual string length of input words
      wordNum,               // word number being actively worked
      asciiVal,              // ascii value of input characters
      asciiTot,              // total ascii val of all letter in word
      t_count;               // count of "t" characters in a word
  
  /***************************************************************
   *  Print an output Header to identify the user for grading    *
   ***************************************************************/
  cout << "+----------------------------------------------------+\n";
  cout << "|  CSCE1040 -- Computer Science II                   |\n";
  cout << "|  NAME:  Pat Burke               EUID:pwb0013       |\n";
  cout << "|  EMAIL: Patrick.Burke@unt.edu                      |\n";
  cout << "|  Lab Assignment 4               Spring 2016        |\n";
  cout << "+----------------------------------------------------+\n\n";
  cout << "12345678901234567890123\n";

  /***************************************************************
   *  This program uses "command line input" to utilize a user-  *
   *  specified text file with input data.  The "meaning" of the *
   *  input parameters is as follows:                            * 
   *       argv[0] is the executable file for this program       *
   *       argv[1] is the first parameter (argc)                 *
   *       argv[2] is the user-supplied input file               *
   ***************************************************************/
  
      /************************************************
       * Open the input file (argv[2]).  If unable to *
       * open the file, report an error and exit the  *
       * program.                                     *
       ************************************************/
  in_stream.open(argv[2]);
  if (in_stream.fail())
  {          //***IF in_stream.fail***
     cout << "Unable to open input file: " << argv[2] <<" \n\n";
     return 1;
  }          //***IF in_stream.fail***

      /*******************************************************
       * The input file was successfully opened.             *
       *                                                     *
       * Now begin a loop of                                 *
       *     - clearing leading blanks                       *
       *     - reading the length of the next word           *
       *     - retrieving the word                           *  
       *     - count "t" characters and compute ascii values *
       *     - clearing to the next line                     *
       * for each of the MAX_WORDS (or until the end         *
       * of the input file is reached)                       *
       *******************************************************/
  
  wordNum = 0;
  
  while (!in_stream.eof() && wordNum < MAX_WORDS)
    {     //***WHILE not eof***
 
    in_stream >> str_len;  //retrieve the string length of the next word
    asciiTot = 0;  // reset the ascii-value total for the next word
    t_count = 0;   // reset the "count of t characters" for the next word

    for (i=0; i<=str_len-1 ;++i)
      {     // FOR i to str_len-1
      word[i] = in_stream.get();      //get the next character
      asciiVal = (int) word[i];       //convert to equivalent ascii value
      asciiTot = asciiTot + asciiVal; //add to total ascii value for word
      if (word[i] == 't')             //increment "t counter" if "t"
         t_count = t_count + 1;
      }     // FOR i to str_len-1

    cout << word << "  "  << t_count << "  " << asciiTot << "\n";
    wordNum = wordNum + 1;

    for (i=0; i<=MAX_S_LEN; i++)
      {     // FOR i to MAX_S_LEN
       word[i] = '\0';     //clear contents of word
      }     // FOR i to MAX_S_LEN

 
      /********************************************************
       * Move to the next line for processing the next word.  *
       * This one-line "while loop" skips over any blanks     *
       * until the carriage return character is read, sending *
       * the file pointer to the next line.                   *
       ********************************************************/
    while ((!in_stream.eof()) && (int(in_stream.get())!= 13));

    }     //***WHILE not eof***

  //close the input file
  in_stream.close();
  
} //***MAIN***
