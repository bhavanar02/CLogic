#include <stdio.h>

int main(void) {
	int c;
	int lines = 1;
	int tabs = 0;
	int spaces = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			lines++;
		}
		if (c == '\t') {
			tabs++;
		} else if (c == ' ') {
			spaces++;
		}
	 
	}
	printf("Lines : %d\n", lines);
	printf("Tabs : %d\n", tabs);
	printf("Spaces : %d\n", spaces);

	return 0;
}