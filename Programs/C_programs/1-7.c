#include <stdio.h>
#define EOF -1
/*Exercise 1-7 in the book: page 18*/
/*Function to delete an element at index
from an array.*/
delElement(arr, index, size) 
int** arr;
int index;
{
    int len,j;
    j = 0;
    /*First, let's get the length of the 
    inputted array:*/
    for (len = 0; arr[len] != '\0'; len++);
    printf("\n%d\n", len);
}

main() {    /*Outputs the user's input back
            at them without consecutive blanks.*/
    int c,j,e;
    int usrIn[100]; /*Limit of 100 char input!*/

    for (j = 0; j < 100; j++) usrIn[j] = 0;
    j = 0;

    /*First, get something from the
    user:*/
    while (1) {
        c = getchar();
        if (c == EOF) break;
        if (c != 8 && j < 100) {
            usrIn[j] = c;
            j++;
        }
    }

    printf("%s", "\n\n");
    delElement(usrIn, 0);
    int** newArr;
    
    for (j = 0; j < 100; j++) printf("%c", usrIn[j]);
}