#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));

    FILE *fp = fopen(argv[1], "w");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }


    int *counts = calloc(26, sizeof(int));
    if (!counts) {
        printf("Memory allocation failed\n");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        int random_val = rand() % 26;
        char ch = 'a' + random_val;
        
        fputc(ch, fp);
        counts[random_val]++;
    }

    fclose(fp);

    printf("Letter frequencies:\n");
    for (int i = 0; i < 26; i++) {
        char current_char = 'a' + i;
        float percentage = ((float)counts[i] / N) * 100.0;
        printf("%c\t%.1f%%\n", current_char, percentage);
    }

    free(counts);
    return 0;
}