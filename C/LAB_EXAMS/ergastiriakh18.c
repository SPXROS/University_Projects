#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    FILE *fp;
    fp = fopen("input.txt", "r");
    if(!fp){
        printf("Error while opening file");
        return 1;
    }

    char buffer[200];
    int arr[10] = {0};
    int max_freq = 0;

    while(fgets(buffer, 200, fp) != NULL){
        for(int i = 0; i < strlen(buffer); i++){
            char ch = buffer[i];
            if(ch >= '0' && ch <= '9'){
                int digit = ch - '0';
                arr[digit] += 1;
                
                if(arr[digit] > max_freq) max_freq = arr[digit];
            }
        }
    }
    fclose(fp);

    char ch1;
    printf("Enter the character you want to use: ");
    scanf(" %c", &ch1);

    for(int i = 0; i < 10; i++){
        int result = 0;
        if(max_freq > 0){
            result = (arr[i] * 40) / max_freq;
        }

        printf("%d : ", i);
        for(int j = 0; j < result; j++){
            printf("%c" , ch1);
        }
        printf("\n");
    }

    return 0;
}