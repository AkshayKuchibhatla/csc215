#include <stdio.h>

int checkNumber(param) 
char* param;
{
    int i;
    i = 0;

    while(param[i] != '\0') {
        if (param[i] < 48 || param[i] > 57) {
            return 0;
        }
        i++;
    }
    return 1;
}

int convertToInt(intStr) 
char* intStr;
{
    int x;
    x = 0;
    while (*intStr != '\0') {
        x = x * 10 + (*intStr - '0');
        intStr++;
    }
    return x;
}

main(argc,argv)
int argc;
char **argv;
{
    int a;
    a = 0;
    int i;
    for (i = 1; i < argc; i++) {
        if (!checkNumber(argv[i])) {
            printf("\n\"%s\" is not a number. Please enter only numbers.", argv[i]);
            break;
        } else {
            a += convertToInt(argv[i]);
        }
    }

    printf("%d", a);
}