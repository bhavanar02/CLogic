#include <stdio.h>

int lengthOfLastWord(char* s)
{
    int len = 0;  // length of curr word 
    int currWrdStrt = -1;  // in case last word is the first word of the string

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            // Check if the current character is not a space
            // and the previous character was a space.

            if (i > 0 && s[i - 1] == ' ')
            {
                // If true, it means a new word is starting.
                // Set currWrdStrt to the current index.
                currWrdStrt = i;
            }

            // Calculate the length of the current word.
            // i - currWrdStrt + 1 represents the length of the word
            // including the current character.
            len = i - currWrdStrt + 1;
        }
    }

    return len;
}

int main(void)
{
    char s[] = "Seven   coom bois   on  a  big   old   boat   ";
    int result = lengthOfLastWord(s);
    printf("%d\n", result);

    return 0;
}

// IT WORKSSSSSSSSSSSSSSSSSS