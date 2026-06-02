#include <stdio.h>
#include <time.h>
double power_iter(int n, int j)
{
    double k = 1;
    for (int i = 1; i <= j; i++) {
        k *= n;
    }
    return k;
}
double power_rec(int n,int j)
{
    double a = 1;
    if (j == 0)
        return 1;
    else
        return n * power_rec(n, j - 1);
    
}

int main(void) {
    clock_t start, stop;
    double cai;
    start = clock();
    double result_iter = power_iter(13, 21);
    printf("반복: %f\n", result_iter);
    stop = clock();
    cai = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("측정시간은 %f초.\n", cai);
    start = clock();
    double result_rec = power_rec(13, 21);
    printf("재귀: %f\n", result_rec);
    stop = clock();
    cai = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("측정시간은 %f초.\n", cai);
    return 0;
}
