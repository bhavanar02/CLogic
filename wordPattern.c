#include <stdio.h>
#include <string.h>

#define MAX_SIZE 300

int wordPattern(char *pattern, char *s) 
{
    char *words[MAX_SIZE], *mapping[26] = {NULL};
    int count = 0;

    while ((words[count] = strtok((count == 1) ? s : NULL, " ")) != NULL) 
    {
        count++;
    }

    if (strlen(pattern) != count - 1) 
    {
        return 0;
    }

    for (int i = 0; i < count - 1; i++) 
    {
        int index = pattern[i] - 'a';
        if (!mapping[index]) 
        {
            for (int j = 0; j < 26; j++)
                if (mapping[j] && strcmp(words[i], mapping[j]) == 0) 
                {
                    return 0;
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
