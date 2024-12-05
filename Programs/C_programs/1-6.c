#include <stdio.h>
#define EOF -1

main() /*Counts blanks, tabs and
        newlines*/
{
    int blnk, tb, nwln, c;
    blnk = tb = nwln = 0;

    while (1) {
        c = getchar();
        if (c == EOF) break;
        if (c == '\t') {
            tb++;
        }
        if (c == ' ') {
            blnk++;
        }
        if (c == '\n') nwln++;
    }

    printf(
        "\nYou typed %d tabs, %d spaces and %d lines.",
        tb,
        blnk,
        nwln + 1
    );
}