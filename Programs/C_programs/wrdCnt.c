#include <stdio.h>
#define EOF -1
#define ESC 27
#define YES 1
#define NO  0

main() { /*Count lines, words, chars in input*/
    int c, nOfLines, nOfWrds, nOfChars, inword;

    inword = NO;
    nOfLines = nOfWrds = nOfChars = 0;
    while ((c = getchar()) != EOF && c != ESC) {
        nOfChars++;
        if (c == '\n') nOfLines++;
        if (c == ' ' || c == '\n' || c == '\t') {
            inword = NO;
        } else if (inword == NO) {
            inword = YES;
            nOfWrds++;
        }
    }
    printf("\n\n%d lines,\n%d words,\n%d characters.", 
            nOfLines, nOfWrds,nOfChars);
}