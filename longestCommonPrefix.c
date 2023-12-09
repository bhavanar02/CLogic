#include <stdio.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
	for(int i=0;; ++i)
	{
		if(strs[0][i] == '\0') 
			return strs[0];
		for(int s=1; s<strsSize; ++s)
		{
			if(strs[s][i] != strs[0][i]) 
			{
				strs[0][i] = '\0';
				return strs[0];
			}
		}
	}
}

int main() {
    char *strs1[] = {"flower", "flow", "flight"};
    printf("%s\n", longestCommonPrefix(strs1, 3));
    char *strs2[] = {"dog", "racecar", "car"};
    printf("%s\n", longestCommonPrefix(strs2, 3));

    return 0;
}