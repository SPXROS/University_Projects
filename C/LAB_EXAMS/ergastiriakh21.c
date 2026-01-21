#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replaceChar(char *buffer, char old, char new);

int main(void) {
    FILE *fp = fopen("source.txt", "r");
    if (!fp) {
        printf("Could not open file.\n");
        return 1;
    }

    char buffer[200];
    char old, new;
    int total_replacements = 0;

    printf("Enter character to find and character to replace with: ");
    if (scanf(" %c %c", &old, &new) != 2) return 1;

    while (fgets(buffer, 200, fp) != NULL) {
        total_replacements += replaceChar(buffer, old, new);
    }

    printf("\nTotal replacements made: %d\n", total_replacements);

    fclose(fp);
    return 0;
}

int replaceChar(char *buffer, char old, char new) {
    int count = 0;
    int len = strlen(buffer);

    for (int i = 0; i < len; i++) {
        if (buffer[i] == old) {
            buffer[i] = new;
            count++;
        }
    }
    
    printf("%s", buffer);
    return count;
}