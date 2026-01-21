#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.c"

#define MAX_SIZE 524288 

int main(void) {
    char line[200];

    printf("Enter a sentence: ");
    if (fgets(line, sizeof(line), stdin) == NULL) return 1;
    line[strcspn(line, "\n")] = 0;

    FILE *fp = fopen("trans.dat", "wb");
    if (!fp) {
        perror("ERROR");
        return 1;
    }

    char *word = strtok(line, " ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < DICT_SIZE; i++) {
            if (strcmp(word, dictionary[i].greek) == 0) {
                int len = (int)strlen(dictionary[i].english);

                fwrite(&len, sizeof(int), 1, fp);

                fwrite(dictionary[i].english, 1, len, fp);
                
                found = 1;
                break; 
            }
        }
        word = strtok(NULL, " ");
    }

    long curr_pos = ftell(fp);
    if (curr_pos < MAX_SIZE) {
        long bytes_to_add = MAX_SIZE - curr_pos;
        fseek(fp, MAX_SIZE - 1, SEEK_SET);
        char null_byte = '\0';
        fwrite(&null_byte, 1, 1, fp);
    }

    fclose(fp);
    printf("Done. File size is exactly 512 KB.\n");
    return 0;
}