#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE *f_in, *f_out;
    char str1[100], str2[100], str3[100];
    if (argc != 2) {
        printf("Enter filename\n");
        return 0;
    }

    f_in = fopen(argv[1], "r");
    if (!f_in) {
        printf("Problems with files\n");
        return 0;
    }
    f_out = fopen("newtxt.txt", "w");

    while (fscanf(f_in, "%s%s%s", str1, str2, str3) != EOF) {
        fprintf(f_out, "%s %s %s\n", str3, str1, str2);
    }

    fclose(f_in);
    fclose(f_out);
    remove(argv[1]);
    rename("newtxt.txt", argv[1]);
    return 0;
}