#include <math.h>
#include <stdio.h>

double func(double x)
{
    return 1 + pow(x, 2); // формула (можно менять)
}

double trapezoidal(const double eps, const double a, const double b, const int n0)
{
    int n = n0, k;

    double sq[2], delta = 1;
    for (k = 0; delta > eps; n *= 2, k ^= 1)
    {
        double h = (b - a) / n;
        double s = func(a) + func(b);
        for (int i = 1; i < n; i++)
            s += 2 * func(a + h * i);
        sq[k] = s * h / 2;
        if (n > n0)
            delta = fabs(sq[k] - sq[k ^ 1]) / 3.0;
    }
    return sq[k];
}

int main()
{
    FILE* out;
    out = fopen("output.txt", "w");
    const double eps = 1E-5;
    const double a = 0;
    const double b = 4;
    const int n0 = 1000000;
    double res = trapezoidal(eps, a, b, n0);
    fprintf(out, "result = %.6lf", res);
}