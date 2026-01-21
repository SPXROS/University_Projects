/*File Mirroring: Read a file name from the command line (argv).

Read the file line-by-line,

reverse each line using a pointer-based function,

and save it to a new file named reversed_original.txt.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reversefile(const char *filename); 

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Error: Provide the file name. Usage: %s <file name>\n", argv[0]);
        return 1;
    }

    reversefile(argv[1]);

    return 0;
}

void reversefile(const char *filename) {

    FILE *fp, *fp1;
    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error while trying to open input file\n");
        return;
    }

    fp1 = fopen("reversed_original.txt", "w");
    if (!fp1) {
        printf("Error while trying to open output file\n");
        fclose(fp);
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), fp) != NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        if (len > 0 && line[len - 1] == '\n') { 
            line[len - 1] = '\0'; 
            len--; 
        }

        char *start, *end, temp;
        for (start = line, end = line + len - 1; start < end; start++, end--) {
            temp = *start;
            *start = *end;
            *end = temp;
        }
        fprintf(fp1, "%s\n", line);
    }

    fclose(fp);
    fclose(fp1);
    printf("Mirroring complete. Check reversed_original.txt\n");
}