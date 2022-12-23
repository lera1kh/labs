#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double atof_implementation(char *num)
{
  double res = 0;
  int after_dot=0;
  double scale=1;
  int neg = 0;
  if (*num == '-') {
    num++;
    neg = 1;
  }
  while (*num) {
    if (after_dot) {
      scale = scale/10;
      res = res + (*num-'0')*scale;
    } else {
      if (*num == '.')
    after_dot++;
      else
    res = res * 10.0 + (*num - '0');
    }
    num++;
  }
  if(neg) return -res;
  else    return  res;
}
void flag_q(double a, double b, double c) {

    if (!a) {
        printf("This is not a square equation");
        return;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a),
               x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two solution: %f %f\n", x1, x2);
    }
    else if (discriminant == 0) {
        double x1 = -b / (2 * a);
        printf("One solution: %f\n", x1);
    }
    else {
        printf("No solution\n");
    }
}
void flag_m(double a, double b) {
    int x = (int) a;
    int y = (int) b;
    if (x != a || y != b) {
        printf("Not correct input\n");
        return;
    }
    if (!a || !b) {
        printf("Error\n");
        return;
    }
    if (x % y == 0) {
        printf("%d is a multiple of %d\n", x, y);
    }
    else {
        printf("%d is not a multiple of %d\n", x, y);
    }
}
void flag_t(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Not correct input\n");
        return;
    }
    if ((a * a  == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b)) {
        printf("Can be sides of triangle\n");
    }
    else {
        printf("Can't be sides of triangle\n");
    }
}
int main(int argc, char** argv)
{
    if (argc < 4 || argc > 5) {
        printf("Not correct input\n");
        return 0;
    }
    int counter = strlen(argv[1]);
    if (counter != 2) {
        printf("Not correct input\n");
        return 0;
    }
    double a, b, c;
    if (argv[1][0] == '-' || argv[1][0] == '/') {
        if (argc == 4) {
            a = atof_implementation(argv[2]);
            b = atof_implementation(argv[3]);
        }
        else if (argc == 5) {
            a = atof_implementation(argv[2]);
            b = atof_implementation(argv[3]);
            c = atof_implementation(argv[4]);
        }
        else {
            printf("Not correct input\n");
            return 0;
        }
        if (argv[1][1] == 'q' && argc == 5) {
            flag_q(a, b, c);
        }
        else if (argv[1][1] == 'm' && argc == 4) {
            flag_m((int)a, (int)b);
        }
        else if (argv[1][1] == 't' && argc == 5) {
            flag_t(a, b, c);
        }
        else {
            printf("Not correct input\n");
            return 0;
        }
    }
    else {
        printf("Not correct input\n");
        return 0;
    }
    return 0;
}
