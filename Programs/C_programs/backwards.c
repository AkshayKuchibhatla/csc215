#include <stdio.h>
#define EOF -1
#define ESC 27

void reverseLine(s, size)
char s[]; 
int size; {
    int upper, lower, temp, e, half;
    half = size >> 1;
    upper = size - 1;
    lower = 0;
    for (lower = 0; lower < half; lower++) {
        upper = size - (lower + 1);
        temp = s[upper];
        s[upper] = s[lower];
        s[lower] = temp;
    }
}

/*Program that prints each line of a file backwards*/
main(argc, argv)
int argc;
int *argv[];{
    FILE *fptr, *fopen();

    printf("%s", "\n");

    if (argc == 1){ /*No file given, copy std out*/
        printf("No file given\n");
        exit(0);
    } else {
        while (--argc > 0) {
            if ((fptr = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "charnums: can't open %s\n", *argv);
                exit(1);
            } else {
                printLinesBackwards(fptr);
                fclose(fptr);
            }
        }
    }
    exit(0);
}

printLinesBackwards(file)
FILE *file; {
    int c,j,charCount;
    char lineBuff[100]; /*Buffer to store line*/

    while (1) {
        for (j = 0; j < 100; j++) lineBuff[j] = 0; /*Make all zeros*/

        j = 0;
        charCount = 0;
        while (j < 100) {
            c = getc(file);
            if (c == EOF) exit(0);
            if (c == '\n') break;
            lineBuff[j] = c;
            j++;
            charCount++;
        }
        /*Reverse the line*/
        reverseLine(lineBuff, charCount);

        /*Print reversed line*/
        for (j = 0; lineBuff[j] != '\0' && j < 100; j++) 
            printf("%c", lineBuff[j]);
        
        printf("%s", "\n");
        if (c == EOF) break;
    }
}
