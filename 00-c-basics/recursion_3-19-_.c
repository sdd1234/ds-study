#include <stdio.h>
#include <time.h>
int long long factorial_iter(long m)
{
    long i; 
    long long result = 1;
    for (i = 1; i <= m; i++)
    {
        result *= i;
        }
    return result;
    }
int  long long factorial_rec(long n)
{
   if (n <= 1) 
        return 1;
     else{ 
        
       
          return n * factorial_rec(n - 1);
       
    }
 }
int main(void) {
    long long u = factorial_iter(20);
    long long s = factorial_rec(20);
    printf("1식 %lld 2식 %lld", u, s);
        


   
       return 0;
}