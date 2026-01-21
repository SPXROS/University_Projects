#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_file> <option: -e|-d> <output_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[2], "-e") != 0 && strcmp(argv[2], "-d") != 0) {
        printf("Error: Selection must be -e (encrypt) or -d (decrypt)\n");
        return 1;
    }

    FILE *fp, *fp1;
    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error while reading input file\n");
        return 1;
    }

    fp1 = fopen(argv[3], "w");
    if (!fp1) {
        printf("Error while opening output file\n");
        fclose(fp);
        return 1;
    }

    char *line = malloc(200 * sizeof(char));
    if (!line) {
        printf("Memory allocation failed\n");
        fclose(fp);
        fclose(fp1);
        return 1;
    }

    if (strcmp(argv[2], "-e") == 0) {
        while (fgets(line, 200, fp) != NULL) {
            int len = strlen(line);
            for (int i = 0; i < len; i++) {
                char ch = line[i];
                fputc(ch, fp1);
            }
        }
    }

    if (strcmp(argv[2], "-d") == 0) {
        while (fgets(line, 200, fp) != NULL) {
            int len = strlen(line);
            for (int i = 0; i < len; i++) {
                char ch = line[i];
                ch--;
                fputc(ch, fp1);
            }
        }
    }

    free(line);
    fclose(fp);
    fclose(fp1);
    return 0;
}