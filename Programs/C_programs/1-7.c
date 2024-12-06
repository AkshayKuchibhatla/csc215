#include <stdio.h>
#define EOF -1
/*Exercise 1-7, page 18 in the book*/

main()
{ /*Outputs the user's input back
  at them without consecutive blanks.*/
    int c, j, e;
    char usrIn[100]; /*Limit of 100 char input!*/

    for (j = 0; j < 100; j++)
        usrIn[j] = 0;

    /*First, get something from the
    user:*/
    j = 0;
    while (1)
    {
        c = getchar();
        if (c == EOF)
            break;
        if (c != 8 && j < 100)
        {
            usrIn[j] = c;
            j++;
        }
    }

    printf("%s", "\n\n");

    /*Then, copy over the input without extra
    spaces:*/
    char newUsrIn[100]; /*New array*/
    for (j = 0; j < 100; j++)
        newUsrIn[j] = 0; /*Fill with zeros*/
    e = 0; /*Index counter for new array*/
    /*j is the index counter for old array*/
    for (j = 0; usrIn[j] != 0; j++)
    {
        newUsrIn[e] = usrIn[j];
        e++;
        if (usrIn[j] == ' ')
        {
            /*When you find a space, move forward
            past all consecutive spaces*/
            while (usrIn[j] == ' ')
            {
                j++;
            }
            /*Keep placing chars in the new
            array*/
            newUsrIn[e] = usrIn[j];
            e++;
        }
    }

    printf("%s", "\n");
    for (j = 0; j < 100; j++)
        printf("%c", newUsrIn[j]);
}
/*word word  word   word*/