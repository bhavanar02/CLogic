#include <stdio.h>

int romanToInt(char *s) {
    int result = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'I') {
            if (s[i + 1] == 'V' || s[i + 1] == 'X') {
                result -= 1;
            } else {
                result += 1;
            }
        } else if (s[i] == 'X') {
            if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                result -= 10;
            } else {
                result += 10;
            }
        } else if (s[i] == 'C') {
            if (s[i + 1] == 'D' || s[i + 1] == 'M') {
                result -= 100;
            } else {
                result += 100;
            }
        } else if (s[i] == 'V') {
            result += 5;
        } else if (s[i] == 'L') {
            result += 50;
        } else if (s[i] == 'D') {
            result += 500;
        } else if (s[i] == 'M') {
            result += 1000;
        }
    }
    
    return result;
}

int main() {
    char s1[] = "III";
    char s2[] = "LVIII";
    char s3[] = "MCMXCIV";

    printf("%s -> %d\n", s1, romanToInt(s1));
    printf("%s -> %d\n", s2, romanToInt(s2));
    printf("%s -> %d\n", s3, romanToInt(s3));

    return 0;
}
