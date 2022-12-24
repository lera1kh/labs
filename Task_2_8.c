#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double foo(double a, double b, double eps){
    double c;
    if (pow(a,2) - 3*a + 1 == 0) 
    return a;
    if (pow(b,2) - 3*b + 1 == 0) 
    return b;
    while ((b - a) > eps){
        c = (b + a) / 2.;
        if (pow(c,2) - 3.*c + 1. < 0.){
            a = c;
        }else {
            b = c;
        }
    }
    return (b + a) / 2.;
}

void main(){
    double a = 0.;
    double b = 2.;
    double eps = 0.01;
    printf("%lf", foo(a, b, eps));
}