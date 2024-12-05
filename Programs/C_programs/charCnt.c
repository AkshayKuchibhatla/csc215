#include <stdio.h>
#define EOF -1

main() {    /*Counts the number of chars inputted.
            accounts for backspaces.*/
    int nOfChars,c          ;
    nOfChars = 0;

    while (1) {
        c = getchar();
        if (c == EOF) break;
        if (c == 8) {
            nOfChars = nOfChars - 1;
        } else {
            nOfChars++;
        }
    }
    printf("%c", "\n");
    printf("\n\nYou wrote %d characters.\n", nOfChars);
}