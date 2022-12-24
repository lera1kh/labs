#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>



double geom(int count, ...)
{
    double compos = 1;
    int i;
    va_list l;
    va_start(l, count);
    for(i = 0; i < count; i++){
        compos *= va_arg(l, double);
    }
    va_end(l);
    return (pow(compos, 1.0/count));
}

double power(double a, int b)
{
    if (b == 0) return 1;
    if (b < 0){
        b *= -1;
        return 1 / (a * power(a, b - 1));
    }
    if (b == 1) return a;
    else return a * power(a, b - 1);
}

int main () {
    printf("%f\n", geom(3, 2., 4., 8.));
    printf("%f\n", power(5., -2));
    return 0;
}
