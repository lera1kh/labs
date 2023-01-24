#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int strLength(const char *string) {
    int count = 0;
    while (string[count] != '\0') {
        count++;
    }
    return count;
}

void strReverse(char *string) {
    int len = strLength(string); 
    char tmp;
    for (int x = 0; x < len / 2; x++) {
        tmp = string[x];
        string[x] = string[len - x - 1];
        string[len - x - 1] = tmp;
    }
}

short isLetter(char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        return 1;
    }
    return 0;
}

short isDigit(char c) {
    if ('0' <= c && c <= '9') {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char *cmd = argv[2];
    char *string = argv[1];
    if (
            (argc != 3 && strcmp(cmd, "-c") != 0) ||
            (argc != 4 && strcmp(cmd, "-c") == 0)
            ) {
        printf("Incorrect arguments\n");
        return 1;
    }


    if (strcmp(cmd, "-l") == 0) {
        printf("%d\n", strLength(string));
    } else if (strcmp(cmd, "-r") == 0) {
        strReverse(string);
        printf("%s\n", string);
    } else if (strcmp(cmd, "-u") == 0) {
        for (int x = 0; x < strLength(string); x++) {
            if (x % 2 != 0 &&'a' <= string[x] && string[x] <= 'z') {
                string[x] = (char) (string[x] - 'a' + 'A');
            }
        }
        printf("%s\n", string);
    } else if (strcmp(cmd, "-n") == 0) {
        int strLen = strLength(string);
        char newString[strLen + 1];
        int newStringIndex = 0;
        for (int x = 0; x < strLen; x++) {
            if (isDigit(string[x])) {
                newString[newStringIndex] = string[x];
                newStringIndex++;
            }
        }
        for (int x = 0; x < strLen; x++) {
            if (isLetter(string[x])) {
                newString[newStringIndex] = string[x];
                newStringIndex++;
            }
        }
        for (int x = 0; x < strLen; x++) {
            if (!isDigit(string[x]) && !isLetter(string[x])) {
                newString[newStringIndex] = string[x];
                newStringIndex++;
            }
        }
        newString[newStringIndex] = '\0';
        printf("%s\n", newString);
    } else if (strcmp(cmd, "-c") == 0) {
        int firstStrLen = strLength(string);
        int secondStrLen = strLength(argv[3]);
        char newString[firstStrLen + secondStrLen + 1];
        
        for (int x = 0; x < firstStrLen; x++) {
            newString[x] = string[x];
        }
        for (int x = 0; x < secondStrLen + 1; x++) {
            newString[firstStrLen + x] = argv[3][x];
        }
        printf("%s\n", newString);
    } else {
        printf("Incorrect command\n");
        return 1;
    }
    return 0;
}