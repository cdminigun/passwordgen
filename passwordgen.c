#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "passwordgen.h"

char *determineLetters(char num);
void printPasswords(char numbers[], int x);
int checkIllegalChars(char numbers[], int x);

//determines the letters for the phone based on num
char *determineLetters(char num) {
    switch (num) {
        case '2':
          return "abcdefghiklmnopqrstuvwxyz";
        case '3':
          return "ABCDEFGHIKLMNOPQRSTUVWXYZ";
        case '4':
          return "0123456789";
        case '5':
          return "!@#$^&*()";
        case '6':
          return "abcdefghiklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZ0123456789!@#$^&*()";
        case '7':
          return "";
        case '8':
          return "";
        case '9':
          return "";
        default:
            return NULL;
    }
}
//recurisve function that assigns values based on the number and position
//was challenging to think of how I'd recurse this
void printPasswords(char numbers[], int x) {
    char newnum = numbers[x];
    if (newnum == 0) {
        printf("\t%s\n", numbers);
    } else {
        char *letters = determineLetters(newnum);
        if (letters==NULL) {
            numbers[x] = '*';
            printPasswords(numbers, x + 1);
        } else {
            for(;*letters!=0; letters++) {
                numbers[x] = *letters;
                printPasswords(numbers, x + 1);
            }
        }
        numbers[x] = newnum;
    }
}
//wrapper function to both hide how things work and allow for the driver to call
void listPasswords(char *numbers) {
  int i;
  int x = strlen(numbers);
  printf("Passwords for %s are: \n", numbers);
  i = checkIllegalChars(numbers, strlen(numbers));
  if(i==0)
    printPasswords(numbers, 0);
}

//checks for 1,0, or if any index is not a digit. Handles special chracters
int checkIllegalChars(char numbers[], int x)
{
  int i;
  for(i=0;i<x;i++)
  {
    if(numbers[i] == '0' || numbers[i]== '1')
    {
      printf("\tNone, %s contains a digit 1 || 0.\n", numbers);
      return 1;
    }
    if(!isdigit(numbers[i]))
    {
      printf("\tNone, %s contains at least one alphabetic character.\n", numbers);
      return 1;
    }
  }
  return 0;
}
