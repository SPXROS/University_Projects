#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "codes.c"

#define TARGET_SIZE 1048576

typedef struct Morse codes;

int main(void) {
    FILE *fp, *fp1;
    fp = fopen("message.txt", "r");
    fp1 = fopen("output.txt", "w");

    if (!fp || !fp1) {
        perror("Error opening files");
        return 1;
    }

    char buffer[200];

    while (fgets(buffer, 200, fp) != NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            char ch = buffer[i];

            for (int j = 0; j < 26; j++) {
                if (toupper(ch) == morse_table[j].letter) {
                    fprintf(fp1, "%s ", morse_table[j].code);
                    break;
                }
            }
            
            if (ch == ' ') {
                fprintf(fp1, "   ");
            }
        }
        fprintf(fp1, "\n");
    }

    long current_pos = ftell(fp1);
    
    if (current_pos < TARGET_SIZE) {
        long padding_needed = TARGET_SIZE - current_pos;
        for (long i = 0; i < padding_needed; i++) {
            fputc('#', fp1);
        }
    }

    fseek(fp1, 0, SEEK_END);
    long final_size = ftell(fp1);

    printf("Translation complete.\n");
    printf("Final File Size: %ld bytes\n", final_size);

    if (final_size == TARGET_SIZE) {
        printf("Validation Successful: File is exactly 1MB.\n");
    } else {
        printf("Validation Failed: File size is %ld.\n", final_size);
    }

    fclose(fp);
    fclose(fp1);
    return 0;
}