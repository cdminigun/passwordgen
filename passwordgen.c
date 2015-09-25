#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "passwordgen.h"

char *determineLetters(char num);
void printPasswords(char numbers[], int x);
int checkIllegalChars(char numbers[], int x);

//determines the letters for the phone based on num
char *determineLetters(char num) { //Uses the user's input to decide upon the available ranges
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
          return "abcdefghiklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZ0123456789!@#$^&*()"; //The number of the beast
        default:
            return NULL;
    }
}
//recurisve function that assigns values based on the number and position
//was challenging to think of how I'd recurse this
void printPasswords(char numbers[], int position) { //Prints the total range of passwords from user's given range
    char newnum = numbers[position];
    if (newnum == 0) {
        printf("\t%s\n", numbers);
    } else {
        char *letters = determineLetters(newnum);
        if (letters==NULL) {
            numbers[position] = '*';
            printPasswords(numbers, position + 1);
        } else {
            for(;*letters!=0; letters++) {
                numbers[position] = *letters;
                printPasswords(numbers, position + 1);
            }
        }
        numbers[position] = newnum;
    }
}
//wrapper function to both hide how things work and allow for the driver to call
void listPasswords(char *numbers) { //Wrapper and error checking for the control 
  int bFlag;
  printf("Passwords for %s are: \n", numbers);
  bFlag = checkIllegalChars(numbers, strlen(numbers)); //Checks user input to make sure it isn't ouside of bounds
  if(bFlag==0)
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
      printf("\tNone, %s contains a digit 1 || 0.\n", numbers); // Exit characters
      return 1;
    }
    if(!isdigit(numbers[i]) || (int)numbers[i]>6 || (int)numbers[i]<0) //Outside of datset and boundry cases
    {
      printf("\tNone, %s contains at least one alphabetic character.\n", numbers);
      return 1;
    }
  }
  return 0;
}
