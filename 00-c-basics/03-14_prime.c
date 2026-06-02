#include <stdio.h>

int main(void) {
    int i = 0;
    int j = 0;
    int sum = 0;

    for (i = 2; i < 100; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
        }


        if (i == j)
            sum = +i;
        printf("%d ", i);
    }


    return 0;
}