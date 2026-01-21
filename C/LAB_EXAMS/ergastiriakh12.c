#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Error: Missing arguments. Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    FILE *fin, *fout;
    fin = fopen(argv[1], "r"); 
    if (!fin) {
        printf("Error while opening source file\n");
        return 1;
    }

    fout = fopen(argv[2], "a"); 
    if (!fout) {
        printf("Error while opening destination file\n");
        fclose(fin);
        return 1;
    }
    
    char *line = malloc(200 * sizeof(char));
    if (!line) {
        printf("Memory allocation failed\n");
        fclose(fin);
        fclose(fout);
        return 1;
    }

    while (fgets(line, 200, fin) != NULL) {
        fprintf(fout, "%s", line);
    }

    free(line); 
    
    fclose(fin);
    fclose(fout);
    
    printf("Content appended successfully!\n");
    return 0;
}