#include <stdio.h>
#include <string.h>


int degree(int x, int n) {
    int y = x;
    for (int i = 1; i < n; i++) {
        y *= x;
    }
    return y;
}
int atoi_implementation(char *m) {
    int n = 0;
    while (*m) {
        n = (n << 3) + (n << 1) + (*m) - '0';
        m++;
    }
    return n;
}
int strlen_implementation(char *c_str) {
    int count = 0;
    while (*c_str++) {
        count++;
    }
    return count;
}
void flag_h(int var) {
    if (var <= 100) {
        int i = 1;
        while (var * i <= 100) {
                printf("%d ", i * var);
                i++;
        }
    }
    else {
        printf("The number is more than 100");
    }
    printf("\n");
}
void flag_p(int var) {
    int i;
    if (var == 1) {
        printf("Nomber is not prime\n");
        return;
    }
    else if(var == 2) {
        printf("Prime number\n");
        return;
    }
    else {
        for (i = 2; i <= (var / 2 + 1); i++) {
            if (var % i == 0) {
                printf("Composite number\n");
                return;
            }
        }
    }
    printf("Prime number\n");
}
void flag_s(int var, int length) {
    int counter = degree(10, length);
    while (counter > 0) {
        var = var % counter;
        counter /= 10;
        printf("%d ", var / counter);
    }
    printf("\n");
}
void flag_e(int var) {
    if (var > 10) {
        printf("The number is incorrect. Please, enter number <= 10\n");
        return;
    }
    long long counter = 1;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= var; j++) {
            counter = counter * i;
            printf("%lld ", counter);
        }
        counter = 1;
        printf("\n");
    }
}
void flag_a(int var) {
    int i = 1;
    int sum = 0;
    while (var > 0){
        sum += i;
        i++;
        var--;
    }
    printf("%d\n", sum);
}
void flag_f(int var) {
    long long factorial = 1;
    while (var != 0) {
        factorial *= var--;
    }
    printf("%lld \n", factorial);
}
int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("Wrong value,try again\n");
        return 0;
    }
    int quantity_of_symbols = strlen_implementation(argv[2]);
    if (quantity_of_symbols != 2) {
        printf("Wrong value,try again\n");
        return 0;
    }
    int var = 0, length = strlen_implementation(argv[1]);
    var = atoi_implementation(argv[1]);
    if ((argv[2][0] == '-' || argv[2][0] == '/') && var > 0) {
        if (argv[2][1] == 'h') {
            flag_h(var);
        }
        else if (argv[2][1] == 'p') {
            flag_p(var);
        }
        else if (argv[2][1] == 's') {
            flag_s(var, length);
        }
        else if (argv[2][1] == 'e') {
            flag_e(var);
        }
        else if (argv[2][1] == 'a') {
            flag_a(var);
        }
        else if (argv[2][1] == 'f') {
            flag_f(var);
        }
        else {
            printf("Wrong value,try again\n");
            return 0;
        }
    }
    else {
        printf("Wrong value,try again\n");
        return 0;
    }

    return 0;
}
