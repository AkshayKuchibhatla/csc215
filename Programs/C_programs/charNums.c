#include <stdio.h>
#define EOF -1

/*Program that places line numbers at the beginning */
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
                numChars(fptr);
                fclose(fptr);
            }
        }
    }
    exit(0);
}

numchars(file)
FILE *file; {
    int c,j,charCount;
    char* lineBuff[100]; /*Buffer to store line*/

    while (1) {
        for (j = 0; j < 100; j++) lineBuff[j] = 0; /*Make all zeros*/

        j = 0;
        charCount = 0;
        while ((c = getc(file)) != '\n' && c != EOF) {
            lineBuff[j] = c;
            j++;
            charCount++;
        }
        /*Print number of chars with space formatting*/
        if (charCount < 10) {
            printf("%d:  ", charCount);
        } else {
            printf("%d: ", charCount);
        }

        /*Print line ahead of number*/
        for (j = 0; lineBuff[j] != '\0'; j++) 
            printf("%c", lineBuff[j]);
        
        printf("%s", "\n");
        if (c == EOF) break;
    }
}
