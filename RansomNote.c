#include <stdio.h>

int canConstruct(char *ransomNote, char *magazine) 
{
    int magazineCount[26] = {0};
    for (int i = 0; magazine[i] != '\0'; i++) 
    {
        magazineCount[magazine[i] - 'a']++;
    }

    for (int i = 0; ransomNote[i] != '\0'; i++) 
    {
        int index = ransomNote[i] - 'a';
        if (magazineCount[index] > 0) 
        {
            magazineCount[index]--;
        } 
        else 
        { 
            return 0;   //FALSEEE
        }
    }

    return 1; //TRUEEEE
}

int main() {
    // Test cases
    printf("%d\n", canConstruct("a", "b"));      // Output: 0 (false)
    printf("%d\n", canConstruct("aa", "ab"));    // Output: 0 (false)
    printf("%d\n", canConstruct("aa", "aab"));   // Output: 1 (true)

    return 0;
}
