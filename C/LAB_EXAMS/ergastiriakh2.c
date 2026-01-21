#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int delCharacter(char *line, char ch);
char* changeFileName(char *originalName, char ch);

int main(void) {
    FILE *fp, *fpOut;
    char ch;
    char *line;
    char *newName;
    int sum = 0;

    fp = fopen("plato-parmenides.txt", "r");
    if (!fp) {
        printf("Error opening input file\n");
        return 1;
    }

    printf("Please enter a character to remove: ");
    scanf(" %c", &ch);

    newName = changeFileName("plato-parmenides.txt", ch);

    fpOut = fopen(newName, "w");
    if (!fpOut) {
        printf("Error opening output file\n");
        fclose(fp);
        free(newName);
        return 1;
    }

    line = malloc(200 * sizeof(char));
    if (line == NULL) {
        printf("Memory allocation failed\n");
        fclose(fp);
        fclose(fpOut);
        return 1;
    }

    while (fgets(line, 200, fp) != NULL) {
        sum += delCharacter(line, ch);      
        fputs(line, fpOut);       
    }



    printf("File processed and saved to %s\n", newName);
    printf("File processed and deleted %d\n", sum);

    free(line);
    free(newName);
    fclose(fp);
    fclose(fpOut);
    
    return 0;
}

int delCharacter(char *line, char ch) {
    int i, newlen = 0;
    int count = 0;
    int len = strlen(line);

    for (i = 0; i < len; i++) {
        if (line[i] != ch) {
            line[newlen] = line[i]; 
            newlen++;
        } else {
            count++;
        }
    }
    line[newlen] = '\0';

    return count;
}

char* changeFileName(char *originalName, char ch) {

    int len = 0;
    while (originalName[len] != '\0') {
        len++;
    }

    char *newName = malloc((len + 15) * sizeof(char));
    
    int i = 0;
    while (originalName[i] != '.' && originalName[i] != '\0') {
        newName[i] = originalName[i];
        i++;
    }

    newName[i++] = '-';
    newName[i++] = 'w';
    newName[i++] = 'i';
    newName[i++] = 't';
    newName[i++] = 'h';
    newName[i++] = 'o';
    newName[i++] = 'u';
    newName[i++] = 't';
    newName[i++] = '-';
    
    newName[i++] = ch;

    newName[i++] = '.';
    newName[i++] = 't';
    newName[i++] = 'x';
    newName[i++] = 't';
    newName[i++] = '\0';

    return newName;
}