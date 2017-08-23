/****************************************************
Written by Christopher Doege

Prupose:
  A program which prints all possible permutations of letters
  within a phone digit.
Input:
  a series of digits excluding 0,1 or any non-digit
Output:
  Prints each permutation or prints an error.

****************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> //Used to track generation time
#include "passwordgen.h"



int main(int argc, char *argv[]) //Taking user input through *argv[]
{
  int i;
  int strlenArgv; // Used to create a new string that is null terminated.
  clock_t begin, end;
  double time_spent;
  begin = clock(); // Sets the start time
  //makes a null terminated string from argv and throws it into listPasswords
  for(i=1;i<argc;i++) // Loop through all elemens in argv
  {
    strlenArgv = (int)strlen(argv[i])+1; // Take the size of the current argv and add 1
    char nullTerminatedArgv[strlenArgv];
    strncpy(nullTerminatedArgv, argv[i], strlenArgv);
    nullTerminatedArgv[strlenArgv-1] = '\0';
    printf("String : %s %d\n", nullTerminatedArgv, strlenArgv);
    listPasswords(nullTerminatedArgv);
  }
  end = clock(); //Sets the end time
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC; //Calculates the total time spent
  printf("Time: %lf \n", time_spent);
  return 0;
}
