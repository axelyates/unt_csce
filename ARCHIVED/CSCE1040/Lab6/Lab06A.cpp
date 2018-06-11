#include <iostream>     // cin, cout
#include <cstring>      // strlen
#include <stdlib.h>     // atoi
#include <cmath>	// pow
#include <stdio.h>      // printf

using namespace std;

int getUserInput(int& inNum);



/*********************************************************************
				//save_file << 
 ** PROGRAM:  Process Repeated User-input Integers                  **
 **  AUTHOR:  Patick Burke                                          **
 **   CLASS:  CSCE-1040                                             **
 ** DESCRIPTION:  This program inputs, validates, and displays a    **
 **    sequence of POSITIVE numbers from a user (input via the      **
 **    keyboard).  The user simply types a number and presses return**
 **    before typing another number.  The user signifies that the   **
 **    sequence is complete by pressing the RETURN key without      **
 **    entering any data on the line first.  The sequence of        **
 **    validated numbers is printed as it is input.                 **
 ** ERROR CONDITIONS:                                               **
 **    Any non-numeric character input (except the empty string)    **
 **    results in an error.                                         **
 *********************************************************************/

int inputNum = 0;     // user number returned from getUserInput
int status = 0;       // status returned from function call

int main()
{ //**MAIN**
 do
 {
    status = getUserInput(inputNum);
    if (status == 0)
    {  //**status**
       printf("\nSorry ... INVALID USER INPUT\n");
       return(0);
    }  //**status**

    if (inputNum < 0)
    {    //** inputNum less than zero **
       printf("\n***Processing Complete***\n\n");
       return(1);
    }    //** inputNum less than zero **

    else

    {    //** inputNum greater than or equal to than zero **
       printf("\n%6d",inputNum);
    }    //** inputNum greater than or equal to than zero **

 } while (inputNum >= 0);

	return 0;
} //**MAIN**

/***********************************************************************
 **  Function getUserInput (inNum)                                    **
 **  Author:  Patrick Burke                                           **
 **   Class:  CSCE-1040                                               **
 **  DESCRIPTION:  This function prompts for and processes repeated   **
 **     POSITIVE INTEGER numerical input from the until the user has  **
 **     a blank submission (just the "end of string" character        **
 **     ("\0"). User input is initially captured in CHARACTER format  **
 **     in order to recognize and report ERRONEOUS non-numerical      **
 **     data.  Each input character is validated as a digit, the      **
 **     numerical value of the number is calculated, and the          **
 **     calculated value is returned as the parameter "inNum".        **
 **       If a non-numeric character is encountered during processing,**
 **     the function is returned with a funtion value of 0 (failure). **
 **       The user just presses "ENTER" with no data, a blank string  **
 **     is generated (position 0 has the value "\0".  This signifies  **
 **     that the user is done submitting the sequence of numbers, and **
 **     inNum is set to a negative number (-1).                       **
 **                                                                   **
 **  NOTE: The use of "atoi" to accomplish the conversion from        **
 **     characters to integers presents one problem. The return status**
 **     from "atoi" is set to zero if a non-numeric character is      **
 **     found, which is good.  Unfortunately, the status is ALSO set  **
 **     to zero if the character "0" (zero) is being processed.  As   **
 **     such, special processing must be handled for zero characters. **
 ***********************************************************************/
int getUserInput (int &inNum)
{ //*********getUserInput*********

  int str_length = 0; // used to calculate the length of the input string
  int value = 0;      // calculated numeric value of input char string
  char s[10]={0};     // string as read from user input
  int i;              // iterator
  char c[10]={0};     // holds a single character from s[] for processing
   
  printf("\nEnter a string: ");
  cin.getline(s, 10);
  str_length = (unsigned) strlen(s);  // deterine actual length of string

  if (str_length == 0)
  {     //** string length zero ... end of input**
     inNum = -1;
     return(1);
  }     //** string length zero ... end of input**

       //************************************************************
       //** String greater than 0 characters to process. Character **
       //** in s[] is moved to c[] (one at a time) for verification**
       //** and conversion the equivalent integer.                 **
       //************************************************************
  c[0] = s[0];

  for(i=0; (s[i]!='\0'); ++i)
  {     //** FOR **
     c[0] = s[i];
     if (c[0] != '0')   //*******************************************
                        //** Special case for "0" input.  If it is **
                        //** "0" it is just skipped, since it adds **
                        //no value to the input integer.           **
                        //*******************************************
     {      //** if **
        if (atoi(c))
        {      //** s[i] is a valid numeric character **
 
                       //******************************************** 
                       //** Build the integer value based on the   **
                       //** charater's placement in the int string.**
                       //********************************************    
            value = value + atoi(c) * pow(10,(str_length-i-1));
        }      //** s[i] is a valid numeric character **
        else
        {      //** INVALID INPUT ... not an integer character **
           printf("***ERROR***: INVALID INPUT: ,%s\n\n",c);
           inNum = 0;
           return (1);
        }      //** INVALID INPUT **
     }       //** IF **

  }     //** FOR **
  
  inNum = value;
  return 1;
}  //*********getUserInput*********
