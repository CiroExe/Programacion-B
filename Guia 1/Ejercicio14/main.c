#include <stdio.h>
#include <stdlib.h>
#define N 9

int main()
{
    int i,j;

    for (i=0;i<N;i++) {
        for (j=0;j<N;j++){
            if (i==0 || j==0 || i==N-1 || j==N-1)
                printf("#");
            else
              printf(" ");
        }

        printf("\n");
    }


    return 0;
}
