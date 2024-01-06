#include <stdio.h>
#include <string.h>

#define MAX_SIZE 300

int isIsomorphic(char *pattern, char *s) 
{
    char* words[MAX_SIZE];
    char* mapping[26] = {NULL};

    int count = 0;
    char *token = strtok(s, " ");
    while (token != NULL) 
    {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    if (strlen(pattern) != count) 
    {
        return 0;
    }

    for (int i = 0; i < count; i++) 
    {
        int index = pattern[i] - 'a';

        if (mapping[index] == NULL) 
        {
            for (int j = 0; j < 26; j++) 
            {
                if (mapping[j] != NULL && strcmp(words[i], mapping[j]) == 0) 
                {
                    return 0;
                }
            }
            mapping[index] = words[i];
        } 
        else 
        {
            if (strcmp(words[i], mapping[index]) != 0) 
            {
                return 0;
            }
        }
    }

    return 1;
}

int main() 
{
    char pattern[MAX_SIZE];
    char s[MAX_SIZE];

    printf("Enter the pattern: ");
    scanf("%s", pattern);
    printf("Enter the string s: ");
    getchar();
    fgets(s, MAX_SIZE, stdin);
    s[strcspn(s, "\n")] = '\0';

    if (isIsomorphic(pattern, s)) 
    {
        printf("Output: true\n");
    } 
    else 
    {
        printf("Output: false\n");
    }

    return 0;
}
