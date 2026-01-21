#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Useful for tolower()

char* filterVowels(char *str);

int main(void) {
    char *str = malloc(200 * sizeof(char));
    printf("Please enter a phrase: ");
    fgets(str, 200, stdin);

    str[strcspn(str, "\n")] = 0;

    char *str1 = filterVowels(str);

    printf("Original: %s\n", str);
    printf("Consonants: %s\n", str1);

    free(str);
    free(str1);
    return 0;
}

char* filterVowels(char *str) {
    char *result = NULL;
    int len = 0;

    for (int i = 0; i < strlen(str); i++) {
        char ch = tolower(str[i]);
        
        if (isalpha(ch) && 
            ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            char *tmp = realloc(result, len + 2); 
            if (tmp == NULL) return NULL;
            
            result = tmp;
            result[len++] = str[i];
        }
    }

    if (result != NULL) {
        result[len] = '\0';
        
        result = realloc(result, len + 1);
    } else {
        result = malloc(1);
        result[0] = '\0';
    }

    return result;
}