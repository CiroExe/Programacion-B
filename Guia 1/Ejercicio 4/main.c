#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c=3,d=2;
    a=8 - 5 * 3 + 2;
    b=7 % 3 + 4 *2;
    printf("valor de a %d\tvalor de b %d\n",a, b);
    b%=a;
    printf("valor de b %d\t\n", b);
    return 0;
}
