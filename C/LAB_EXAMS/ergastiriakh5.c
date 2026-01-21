#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp, *fout;
    fp = fopen("text.txt", "r");
    if (!fp) {
        printf("Error trying to open file\n");
        return 1;
    }

    fout = fopen("filtered.txt", "w");

    char line[200], forbidden[200];
    int word_count = 0;

    printf("Enter a forbidden word: ");
    fgets(forbidden, sizeof(forbidden), stdin);
    forbidden[strcspn(forbidden, "\n")] = 0;

    int len = strlen(forbidden);
    char stars[len + 1];
    for (int i = 0; i < len; i++) stars[i] = '*';
    stars[len] = '\0'; 

    while (fgets(line, sizeof(line), fp) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == ' ' || line[i] == '\n') word_count++;
        }

        char *pos = strstr(line, forbidden);
        while (pos != NULL) {
            memcpy(pos, stars, len);
            pos = strstr(pos + len, forbidden);
        }
        
        fprintf(fout, "%s", line);
    }

    printf("Total words (approx): %d\n", word_count);
    printf("Censored file saved as filtered.txt\n");

    fclose(fp);
    fclose(fout);
    return 0;
}