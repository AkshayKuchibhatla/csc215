#include <stdio.h>

/*Program that multiplies two numbers using 
the Russian Peasant algorithm.*/

multiply(a,b)
int a,b; {
    printf("\nA: %d    B: %d\n");
    int product;
    while (b != 1) {
        /*printf("\nA: %d    B: %d    Product: %d\n");*/
        if (b % 2 == 0) {
            a = a << 1;
            b = b >> 1;
        } else {
            product += a;
            a = a << 1;
            b = b >> 1;
        }
    }
    product += a;
    return product;
}

int main(argc, argv) 
int argc;
char** argv; {
    printf("\n%d * %d = %d\n", argv[1], argv[2], multiply(argv[1],argv[2]));

    return 0;
}
