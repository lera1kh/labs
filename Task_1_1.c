#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

long long int factorial(long long int number) {
    long long int result = 1;
    if (number == 0 || number == 1) {
        return 1;
    } else {
        for (int i = 1; i <= number; i++) {
            if (LLONG_MAX / result > i) {
                result *= i;
            } else {
                return -1;
            }
        }
        return result;
    }
}
double strToInt(char *number){
    int res = 0;
    for(int i = 0; number[i] != '\0'; i++){
        res += number[i]-'0';
        res *= 10;
    }
    res /= 10;
    return res;
}
int symbolInInt(char *number){
    for(int i = 0; number[i] != '\0'; i++){
        if (number[i] == '-' && i == 0){
            return 1;
        }
        if (number[i] < '0' || number[i] > '9'){
            return 1;
        }
    }
    return 0;
}
int main(int argc, char *argv[]){
    if (argc == 1){
        printf("No arguments\n");
        return 1;
    }
    else {
        for (int i = 0; argv[2][i] != '\0'; i++) {
            if (
                    (argv[2][i] >= '0' && argv[2][i] <= '9') &&
                    ((argv[1][0] == '-' || argv[1][0] == '/') &&
                     (argv[1][1] == 'a' || argv[1][1] == 'e' ||
                      argv[1][1] == 'f' || argv[1][1] == 'h' ||
                      argv[1][1] == 'p' || argv[1][1] == 's'))
                ) {
                printf("Enter number the first, than the flag\n");
                return 1;
            }
        }
    }
    if (argc != 3) {
        printf("Enter two arguments\n");
        return 1;
    }
    else {if (symbolInInt(argv[1]) ) {
        printf("Please,enter only positive numbers without symbols\n");
         return 1;
         }
    }
    if (argv[2][0] != '-' && argv[2][0] != '/') {
            printf("There must be symbol '-' or '/' before the flag\n");
            return 1;
        }
        int num = 0;
        num = strToInt(argv[1]);
    if (strcmp(argv[2], "-h") == 0 || strcmp(argv[2], "/h") == 0) {
            if (num > 100) {
                printf("No multiples\n");
            } else if (num == 0) {
                printf("Divide by zero\n");
            } else {
                int i = 1;
                int num_1 = 0;
                while(num * i <= 100){
                    num_1 = num * i;
                    i++; 
                    printf("%d ", num_1);
                    }
                }
            return 0;
        } 
        else if (strcmp(argv[2], "-p") == 0 || strcmp(argv[2], "/p") == 0) {
            if (num == 1 || num == 0) {
                printf("Enter the number other than one or zero\n");
                return 0;
            } else {
                for (int i = 2; i < floor(sqrt(num)); i++) {
                    if (num % i == 0) {
                        printf("Your number is composite\n");
                        return 0;
                    }
                }
                printf("Your number is prime\n");
                return 0;
            }
        } else if (strcmp(argv[2], "-s") == 0 || strcmp(argv[2], "/s") == 0) {
            for (int i = 0; argv[1][i] != '\0'; i++) {
                printf("%c ", argv[1][i]);
            }
        } else if (strcmp(argv[2], "-e") == 0 || strcmp(argv[2], "/e") == 0) {
            if (num == 0||num > 10) {
                printf("Enter number more than 0 and less than 11\n");
                return 1;
            }  else {
            long long int res = 1;
            for (int i = 1; i <= 10; i++) {
            printf("%d: ", i);
                for (int j = 1; j <= num; j++) {
                res = res * i;
                printf("%lld ", res);
                }
            res = 1;
            printf("\n");
            }
        }
        } else if (strcmp(argv[2], "-a") == 0 || strcmp(argv[2], "/a") == 0) {
            if (num == 0) {
                printf("Enter number more than 0\n");
                return 0;
            } else {
                int res = 0;
                res = (num * (num + 1)) / 2;
                printf("%d\n", res);
                return 0;
            }
        } else if (strcmp(argv[2], "-f") == 0 || strcmp(argv[2], "/f") == 0) {
            long long int fac = num;
            fac = factorial(fac);
            if (fac == -1) {
                printf("Overflow\n");
                return 0;
            }
            printf("%lld\n", fac);
            return 0;
        } else {
            printf("Wrong argument\n");
            return 0;
        }
    }
