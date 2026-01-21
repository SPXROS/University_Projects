/*Caesar Cipher Tool: Read a file and a shift integer $N$ from argv. 
Create an encrypted version of the file where each letter is shifted by $N$.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void shiftletter(char *filename, int N);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <shift integer>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[2]);

    if (N < 1 || N > 25) {
        printf("Error: Shift integer must be between 1 and 25.\n");
        return 1;
    }

    shiftletter(argv[1], N);

    return 0;
}

void shiftletter(char *filename, int N) {
    FILE *fp, *fp1;
    
    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open source file.\n");
        return;
    }

    fp1 = fopen("shifted_copy.txt", "w");
    if (!fp1) {
        printf("Error: Could not create output file.\n");
        fclose(fp);
        return;
    }

    char line[200];
    N = (N % 26 + 26) % 26;

    while (fgets(line, sizeof(line), fp) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            char c = line[i];

            if (isupper(c)) {
                line[i] = ((c - 'A' + N) % 26) + 'A';
            } 
            else if (islower(c)) {
                line[i] = ((c - 'a' + N) % 26) + 'a';
            }
        }
        fprintf(fp1, "%s", line);
    }

    fclose(fp);
    fclose(fp1);
    printf("Success! Created 'shifted_copy.txt'\n");
}