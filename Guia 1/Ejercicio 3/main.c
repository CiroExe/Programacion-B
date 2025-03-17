#include <stdio.h>
#include <stdlib.h>
#define NUM 15
int main()
{
    char A;
    A='a';
    printf("%c\n", A);
    printf("%d\n", A);
    A='a' + 10;
    printf("%c\n", A);
    printf("%d\n", A);

    int B=5;
    printf("%d\n", B);
    printf("%c\n", B);
    B=5+'A';
    printf("%d\n", B);
    printf("%c\n", B);

    printf("%d\n", NUM);
    printf("%c\n", NUM);



    return 0;
}
