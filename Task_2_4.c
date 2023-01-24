#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>



double geom(int count, ...)//переменное число аргументов
{
    double compos = 1.0;//eps
    int i;
    va_list args;
    va_start(args, count);// проверка count 2 и отриц
    for(i = 0; i < count; i++){
        compos *= va_arg(args, double);
        if (i % 2 == 0 && compos < 0){ // i & 1
        return NAN;
    }
    va_end(args);
    }
    return (pow(compos, 1./count));

}
double pwr(double a, int b)// рекурсивная функция сделать!!!
{   
   double res = 1;
   if (b < 0){
    b = -b;
   while(b){
    if(b % 2 == 0){
        b /= 2;
        a *= a;
    }
    else {
        b--;
        res *= a;
    }
   }
   return 1/res;
   }
   else {
    while(b){
    if(b % 2 == 0){
        b /= 2;
        a *= a;
    }
    else {
        b--;
        res *= a;
    }
   }
   return res;
   }
}
/*double rec_power(double num, int power){
     int i;
     if (power == 0) {
        return 1;
    } else if (power > 0) {
        i = power -1;
        return num * pwr(num, i);
    } else if (power < 0) {
        i = power + 1;
        return (1 / num) * pwr(num, i);
    }
}*/

int main () {
    printf("%f\n", pwr(2., -2));
    double res = geom(2, 1., 1.);
    if (isnan(res) != 0){
        printf("Error\n");
        return 1;
    }
    printf("%f\n", geom(2, 1., 1.));
    return 0;
}
