#include <stdio.h>
#include <math.h>

double exp_taylor(double x, int n) 
{
    double sum = 1.0;
    double term = 1.0;

    for (int i = 1; i <= n; i++) {
        term *= x / i;
        sum += term;
    }

    return sum;
}

int main() 
{
    double x = 2.0;
    int n = 10;

    printf("exp(%lf) = %lf\n", x, exp(x));
    printf("exp_taylor(%lf, %d) = %lf\n", x, n, exp_taylor(x, n));

    return 0;
}