#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle) 
{

    for (int i = 0; haystack[i] != '\0'; ++i) 
    {
        int j;
        for (j = 0; needle[j] != '\0'; ++j) 
        {
            if (haystack[i + j] != needle[j]) 
            {
                break;
            }
        }
        if (needle[j] == '\0')
        {
            return i;
        }
    }

    return -1;
}

int main() {
    char haystack1[] = "sadbutsad";
    char needle1[] = "sad";
    char haystack2[] = "leetcode";
    char needle2[] = "leeto";
    printf("%d\n", strStr(haystack1, needle1));  // Output: 0
    printf("%d\n", strStr(haystack2, needle2));  // Output: -1

    return 0;
}
