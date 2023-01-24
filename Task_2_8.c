#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double f(double x) {
    return pow(x,2) - 3*x + 1 ;
}

double dihot(double a, double b, double eps, double (*func)(double)) {
    double c;
    if(a < b||eps < 0){
    return NAN;
    }
    while (fabs(b) - fabs(a) > eps) {//a < b && eps>0
        c = (a + b) / 2.0;
        if (func(b) * func(c) < eps)
            a = c;
        else
            b = c;
    }
    return (a + b) / 2.0;
}

int main(int argc, char *argv[]) {
    double res = dihot(0, 2, -0.01, f);
    if (isnan(res) != 0){
        printf("Error\n");
        return 1;
    }
    printf("%f", dihot(4, 2, 0.01, f));
    return 0;
}