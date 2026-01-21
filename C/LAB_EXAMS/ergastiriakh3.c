#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countFrequencies(const char *filename, int *counts, int *totalLetters);
void drawGraph(int *counts, int totalLetters, char symbol);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int counts[26] = {0};
    int totalLetters = 0;

    countFrequencies(argv[1], counts, &totalLetters);

    if (totalLetters == 0) {
        printf("No Latin letters found in the file.\n");
        return 0;
    }

    drawGraph(counts, totalLetters, '*');

    return 0;
}

void countFrequencies(const char *filename, int *counts, int *totalLetters) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            int index = toupper(c) - 'A';
            counts[index]++;
            (*totalLetters)++;
        }
    }
    fclose(fp);
}

void drawGraph(int *counts, int totalLetters, char symbol) {
    int maxCount = 0;
    

    for (int i = 0; i < 26; i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
        }
    }

    float maxPercent = ((float)maxCount / totalLetters) * 100.0;

    for (int i = 0; i < 26; i++) {
        printf("%c|", 'A' + i);
        
        int barLength = 0;
        if (maxCount > 0) {
            barLength = (counts[i] * 50) / maxCount;
        }

        for (int j = 0; j < barLength; j++) {
            putchar(symbol);
        }
        printf("\n");
    }

    printf(" +");
    for (int i = 0; i < 50; i++) printf("-");
    printf("\n");

    printf("0%% %47.2f%%\n", maxPercent);
}