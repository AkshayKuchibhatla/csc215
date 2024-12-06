#include <stdio.h>
#define EOF -1

int main(argc, argv)
int argc;
char *argv[]; {
    FILE *fptr, *fopen();
    
    if (argc == 1) {/*no args, copy std in*/
        filecopy(stdin);
    } else {
        while (--argc > 0) {
            if ((fptr = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
                break;
            } else {
                filecopy(fptr);
                fclose(fptr);
            }
        }
    }

    return 0;
}

filecopy(fp) /*Copy file fp to standard output*/
FILE *fp; { /*Pass in the file pointer*/
    int c;

    while ((c = getc(fp)) != EOF)
        putc(c, stdout);
}