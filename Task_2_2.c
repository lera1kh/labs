#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int flag_l(char *str) {
    return strlen(str);
}
char *flag_r(char *str) {
    int i, len;
    len = strlen(str);
    for (i = 0; i < len / 2; i++)
    {
        str[i] = str[i] ^ str[len - i - 1];
        str[len - i - 1] = str[i] ^ str[len - i - 1];
        str[i] = str[i] ^ str[len - i - 1];
    }
    return str;
}
char *flag_u(char *str) {
    int i;
    for (i = 0; i < strlen(str); i += 2)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}
char *flag_n(char *str) {
    char s_1[BUFSIZ];
    char s_2[BUFSIZ];
    char s_3[BUFSIZ];
    int count_1 = 0, count_2 = 0,  count_3 = 0, i;
    for(i = 0; i < strlen(str); i++)
    {
       if(isdigit(str[i]))
       {
            s_1[count_1++] = str[i];
       }
       else if(isalpha(str[i]))
       {
            s_2[count_2++] = str[i];
       }
       else
       {
            s_3[count_3++] = str[i];
       }
    }
    str[0] = '\0';
    strcat(str, s_1);
    strcat(str, s_2);
    strcat(str, s_3);
    return str;
}
char *flag_c(char *str, char *str_2) {
    return strcat(str, str_2);
}

int main(int argc, char** argv)
{
    if (argc < 3 || argc > 4) {
        printf("Not correct input\n");
        return -1;
    }

    int counter = strlen(argv[2]);
    if (counter != 2) {
        printf("Not correct input\n");
        return -1;
    }


    if (argv[2][0] == '-' || argv[2][0] == '/') {
        if (argv[2][1] == 'l' && argc == 3) {
            printf("%d\n", flag_l(argv[1]));
            return 0;
        }
        else if (argv[2][1] == 'r' && argc == 3) {
            printf("%s\n", flag_r(argv[1]));
            return 0;
        }
        else if (argv[2][1] == 'u' && argc == 3) {
            printf("%s\n", flag_u(argv[1]));
            return 0;
        }
        else if (argv[2][1] == 'n' && argc == 3) {
            printf("%s\n", flag_n(argv[1]));
            return 0;
        }
        else if (argv[2][1] == 'c' && argc == 4) {
            printf("%s\n", flag_c(argv[1], argv[3]));
            return 0;
        }
        else {
            printf("Not correct input\n");
            return -1;
        }
        printf("%s\n", argv[1]);
    }
    else {
        printf("Not correct input\n");
        return -1;
    }
    return 0;
}
