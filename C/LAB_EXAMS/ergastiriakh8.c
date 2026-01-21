/*Dynamic Line Buffer: Write a program that reads a file with very long lines. 
Use malloc and realloc to dynamically 
expand your buffer as you read each character until you hit a newline \n.*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("text.txt", "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    size_t capacity = 10;
    size_t length = 0;
    char *line = malloc(capacity * sizeof(char));
    
    if (!line) { 
        fclose(fp);
        return 1; 
    }

    int ch;

    while ((ch = fgetc(fp)) != EOF && ch != '\n') {

        if (length + 1 >= capacity) {
            capacity *= 2;
            char *temp = realloc(line, capacity * sizeof(char));
            if (!temp) {
                free(line);
                fclose(fp);
                return 1;
            }
            line = temp;
        }
        
        line[length] = (char)ch;
        length++;
    }

    line[length] = '\0';

    printf("Line read: %s\n", line);

    free(line);
    fclose(fp);

    return 0;
}