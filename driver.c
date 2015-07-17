/****************************************************
Homework assignment 5 - Written by Christopher Doege

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
#include <time.h>
#include "passwordgen.h"



int main(int argc, char *argv[])
{
  int i,x;
  clock_t begin, end;
  double time_spent;
  begin = clock();
  //makes a null terminated string from argv and throws it into listMnemeronics
  for(i=1;i<argc;i++)
  {
    x = (int)strlen(argv[i]);
    char temp[x];
    strcpy(temp,argv[i]);
    temp[x] = '\0';
    listPasswords(temp);
  }
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time: %lf \n", time_spent);
  return 0;
}
