#include <stdio.h>
#define EOF -1
#define ESC 27

void reverse(s, size)
char s[]; 
int size; {
    int upper, lower, temp, e, half;
    half = size >> 1;
    upper = size - 1;
    lower = 0;
    temp = s[upper];
    s[upper] = s[lower];
    s[lower] = temp;
}

main() { /*Reverses user input one line at a time*/
    char linebuff[100];
    int e,c;
    int nOfChars;
    for (e = 0; e < 100; e++) linebuff[e] = 0;

    e = 0;
    nOfChars = 0;
    while (e < 100) {
        c = getchar();
        if (c == '\n') break;
        if (c == 8) continue;
        if (c == EOF || c == ESC) exit(0);
        linebuff[e] = c;
        e++;
        nOfChars++;
    }
    printf("%s", "\n");
    reverse(linebuff, nOfChars);

    for (e = 0; linebuff[e] != '\0'; e++) 
        printf("%c", linebuff[e]);
}