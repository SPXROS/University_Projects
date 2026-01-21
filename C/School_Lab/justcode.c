//ARRAYS & LOOPS


void FindMaxMin(int *arr, int num, int *max, int *min) {
    *max = *arr; 
    *min = *arr;
    
    for(int i = 1; i < num; i++) { 
        if(*max < *(arr + i)) {
            *max = *(arr + i);
        }
        if(*min > *(arr + i)) {
            *min = *(arr + i);
        }
    }
}

/*Reverse Array In-Place: Reverse an integer array without using extra space.*/

void ReverseArr(int *arr, int num){


    for(int i = 0; i < num/2; i++){
        int temp = *(arr + i);
        *(arr + i) = *(arr + num - 1 - i);
        *(arr + num - 1 - i) = temp;   
    }
}

/*Remove Duplicates: Remove duplicate elements from an array and return the new size.*/

int RemoveDuplicates(int *arr, int num, int *result){
    int newSize = 0; 
    
    for(int i = 0; i < num; i++){
        int isDuplicate = 0;
        
        for(int j = 0; j < newSize; j++){
            if(*(arr + i) == *(result + j)){
                isDuplicate = 1;
                break;
            }
        }
        
        if(!isDuplicate){
            *(result + newSize) = *(arr + i);
            newSize++;
        }
    }
    
    return newSize;
}


/*Student Structure: Create Student struct (name, id, marks), write functions to input, display, find highest scorer.*/

#include <stdio.h>

struct Student {
    char name[40];
    int id;
    int marks[5];
};

int main()
{
    struct Student STUD;

    printf("Enter your name:\n");
    fgets(STUD.name, sizeof(STUD.name), stdin);

    printf("Enter your id: ");
    scanf("%d", &STUD.id);

    printf("Enter your marks:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &STUD.marks[i]);
    }

    return 0;
}



//STRINGS


void strreverse(char *arr, char *arr1){

    int len = strlen(arr);

    for(int i = 0; i<len; i++){
        *(arr1 + i) = *(arr + len - 1 - i);
    }

    arr1[len] = '\0';
}


void CountString(char *arr,
                 int *let, int *num, int *space,
                 int *vowels, int *consonants)
{
    int i = 0;

    while (arr[i] != '\0' && arr[i] != '\n') {

        arr[i] = toupper((unsigned char)arr[i]);

        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            (*let)++;

            if (arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' ||
                arr[i] == 'O' || arr[i] == 'U') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
        else if (arr[i] >= '0' && arr[i] <= '9') {
            (*num)++;
        }
        else if (arr[i] == ' ') {
            (*space)++;
        }

        i++;
    }
}

void RemoveSpaces(const char *arr, char *arr1)
{
    int newSize = 0;

    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] != ' ') {
            arr1[newSize++] = arr[i];
        }
    }

    arr1[newSize] = '\0';
}

//Word Counter: Count number of words in a string.
void WordCounter(const char *arr, int *word)
{
    int i = 0;
    int inWord = 0;

    while (arr[i] != '\0') {

        if (arr[i] != ' ' && arr[i] != '\n' && !inWord) {
            (*word)++;
            inWord = 1;
        }
        else if (arr[i] == ' ' || arr[i] == '\n') {
            inWord = 0;
        }

        i++;
    }
}



//First Non-Repeating Character: Find first character that doesn't repeat.

void FindNonRepeat(const char *arr, char *let)
{
    int len = strlen(arr);

    for (int i = 0; i < len; i++) {
        int isDup = 0;

        for (int j = 0; j < len; j++) {
            if (i != j && arr[i] == arr[j]) {
                isDup = 1;
                break;
            }
        }

        if (!isDup) {
            *let = arr[i];
            return;
        }
    }

    *let = '\0';  // no non-repeating character found
}


#include <stdio.h>
#include <ctype.h>

void ToggleCase(char *arr)
{
    for (int i = 0; arr[i] != '\0'; i++) {
        if (isupper((unsigned char)arr[i])) {
            arr[i] = tolower((unsigned char)arr[i]);
        } else if (islower((unsigned char)arr[i])) {
            arr[i] = toupper((unsigned char)arr[i]);
        }
    }
}

//Remove Character: Remove all occurrences of a specific character from string.

void RemoveChar(char *arr, char remove,char *arr1){

    int newSize = 0;

    for(int i = 0; arr[i] != '\0'; i++){
        if (arr[i] != remove) {
            arr1[newSize++] = arr[i];
        }
    }

    arr1[newSize] = '\0';
}

// POINTERS

#include <stdio.h>

void SwapNumbers(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x = 5;
    int y = 10;

    SwapNumbers(&x, &y);

    printf("After swap, x = %d and y = %d\n", x, y);
}

int* arraysize(int *outSize) {

    int numItems = 15;
    int *myArray = malloc(numItems * sizeof(int));
    if (!myArray) return NULL;

    for (int i = 0; i < numItems; i++) {
        myArray[i] = i + 1;
        printf("%d ", myArray[i]);
    }
    printf("\n");

    int newSize = 6;

    int *tmp = realloc(myArray, newSize * sizeof(int));
    if (!tmp) {
        free(myArray);
        return NULL;
    }

    myArray = tmp;
    *outSize = newSize;

    return myArray;
}

//Pointer Array Sort: Sort array of integers using pointer arithmetic.

void SortArray(int *arr, int num){

    for(int i = 0; i<num - 1; i++){
        for(int j = i + 1; j<num; j++)
            if(*(arr+i) > *(arr+j)){
                int temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;           
            }
    }
}

//or more advanced:
void SortArray(int *arr, int num)
{
    for (int *i = arr; i < arr + num - 1; i++) {
        for (int *j = i + 1; j < arr + num; j++) {
            if (*i > *j) {
                int temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

//Copy String (strcpy): Implement your own strcpy() using pointers.
char *CopyString(const char *arr)
{
    int len = strlen(arr);
    char *arr1 = malloc(len + 1);

    if (!arr1) return NULL;

    for (int i = 0; i <= len; i++) {
        arr1[i] = arr[i];
    }

    return arr1;
}

//String Concatenation: Implement strcat() using pointers.

char *STRINGCAT(char *arr, const char *arr1) {
    int len  = strlen(arr);
    int len1 = strlen(arr1);

    char *tmp = realloc(arr, (len + len1 + 1) * sizeof(char));
    if (tmp == NULL) {
        return NULL;
    }

    arr = tmp;

    for (int i = 0; i < len1; i++) {
        arr[len + i] = arr1[i];
    }

    arr[len + len1] = '\0';

    return arr;
}

//Reverse Array Using Pointers: Reverse array using only pointer arithmetic.

void ReverseArray(int *arr, int num) {
    int *left  = arr;
    int *right = arr + num - 1;

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

//STRUCT

//Book Structure: Create Book struct, write function to search by title, sort by price.

#include <stdio.h>
#define MAXLEN 256
#include <stdlib.h>
#include <string.h>

typedef struct books{
    char title[256];
    int price;
}BOOK;

void addbook(BOOK **books, int *BookCount);
void sort(BOOK *books, int *BookCount);

int main(){

    BOOK *books = NULL;
    int BookCount = 0;



    return 0;
}

void addbook(BOOK **books, int *BookCount) {
    BOOK *tmp = realloc(*books, (*BookCount + 1) * sizeof(BOOK));
    if (tmp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    *books = tmp;

    BOOK *newbook = &(*books)[*BookCount];

    printf("Enter book title: ");
    fgets(newbook->title, MAXLEN, stdin);
    newbook->title[strcspn(newbook->title, "\n")] = '\0';

    printf("Enter book price: ");
    scanf("%d", &newbook->price);
    getchar();

    (*BookCount)++;
}

void sort(BOOK *books, int *BookCount){

    BOOK temp;
    
    for(int i = 0; i <BookCount - 1; i++){
        for(int j = 0 ; j<BookCount - i - 1; j++){ 
            if(books[j].price > books[j + 1].price){
                    temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;

            }
        }
    }
}

void sort(BOOK *books, int BookCount) {
    BOOK temp;

    for (int i = 0; i < BookCount - 1; i++) {
        for (int j = 0; j < BookCount - i - 1; j++) {
            if (books[j].price > books[j + 1].price) {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

BOOK *searchByTitle(BOOK *books, int BookCount, const char *title) {
    for (int i = 0; i < BookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return &books[i];
        }
    }
    return NULL;
}

//Point Distance: Create Point struct (x, y), calculate distance between two points.

#include <stdio.h>
#include <math.h>

struct point {
    float x;
    float y;
};

float Distance(struct point a, struct point b);

int main() {
    struct point p1, p2;

    printf("Enter x and y of first point: ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter x and y of second point: ");
    scanf("%f %f", &p2.x, &p2.y);

    printf("Distance: %.2f\n", Distance(p1, p2));

    return 0;
}

float Distance(struct point a, struct point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}


int primenumber(int x) {
    if (x <= 1) return 0;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }

    return 1;
}

int factorial(int x) {
    if (x < 0) return -1;

    int result = 1;
    for (int i = 2; i <= x; i++) {
        result *= i;
    }

    return result;
}

//FILES

int main(void) {
    int arr[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
    return 0;
}

//Read from File: Read numbers from file into array.

#include <stdio.h>

int main(void) {
    int arr[10];
    FILE *fp = fopen("num.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            printf("Error reading number %d\n", i);
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}


int main(void) {
    FILE *fp = fopen("message.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int ch;
    int lines = 0, words = 0, chars = 0;
    int inWord = 0;

    while ((ch = fgetc(fp)) != EOF) {
        chars++;

        if (ch == '\n')
            lines++;

        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }
    }

    fclose(fp);

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);

    return 0;
}

//Copy File: Copy contents of one file to another.
#include <stdio.h>

int main(void){
    
    FILE *fp, *fp1;
    
    fp = fopen("message.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fp1 = fopen("newmessage.txt", "w");
    if (fp1 == NULL) {
        printf("Error opening file\n");
        fclose(fp);
        return 1;
    }

    int ch;

    while((ch = fgetc(fp)) != EOF) {
        fputc(ch, fp1);
    }

    fclose(fp);
    fclose(fp1);

    return 0;
}


#include <stdio.h>

int main(void) {
    FILE *fp = fopen("message.txt", "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(fp, "This line was appended.\n");

    fclose(fp);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("message.txt", "r");
    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }

    char input[100];
    char line[100];
    int linenum = 0;
    int found = 0;

    printf("Enter a word: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    while (fgets(line, sizeof(line), fp)) {
        linenum++;

        if (strstr(line, input)) {
            printf("Found at line %d\n", linenum);
            found = 1;
        }
    }

    if (!found) {
        printf("No match found.\n");
    }

    fclose(fp);
    return 0;
}


//Find Missing Number: Array has 1 to N with one missing, find it

#include <stdio.h>

#define N 5

int main(void) {
    int arr[N] = {1, 2, 3, 5}; // missing 4
    int sum = 0;

    for (int i = 0; i < N - 1; i++) {
        sum += arr[i];
    }

    int expected = N * (N + 1) / 2;
    int missing = expected - sum;

    printf("Missing number: %d\n", missing);
    return 0;
}

// FILE OPERATIONS

#include <stdio.h>

int main(void) {

    FILE *fp, *fp1;

    fp = fopen("original.txt", "r");
    if (!fp) {
        printf("Error opening source file\n");
        return 1;
    }

    fp1 = fopen("backup.txt", "w");
    if (!fp1) {
        printf("Error opening destination file\n");
        fclose(fp);
        return 1;
    }

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, fp1);
    }

    fclose(fp);
    fclose(fp1);

    return 0;
}

//File Merger: Merge contents of two text files into a third file, alternating lines from each file.

#include <stdio.h>

#define MAXLINE 256

int main(void) {

    FILE *fp, *fp1, *fp2;

    fp = fopen("messages.txt", "r");
    if (!fp) {
        printf("Error opening messages.txt\n");
        return 1;
    }

    fp1 = fopen("messages1.txt", "r");
    if (!fp1) {
        printf("Error opening messages1.txt\n");
        fclose(fp);
        return 1;
    }

    fp2 = fopen("New_messages.txt", "w");
    if (!fp2) {
        printf("Error opening New_messages.txt\n");
        fclose(fp);
        fclose(fp1);
        return 1;
    }

    char line1[MAXLINE];
    char line2[MAXLINE];

    while (fgets(line1, MAXLINE, fp) || fgets(line2, MAXLINE, fp1)) {

        if (!feof(fp))
            fputs(line1, fp2);

        if (!feof(fp1))
            fputs(line2, fp2);
    }

    fclose(fp);
    fclose(fp1);
    fclose(fp2);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("message.c", "r");
    FILE *fp_out = fopen("message_no_comments.c", "w");
    if (!fp || !fp_out) {
        printf("Error opening file\n");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        char *comment_pos = strstr(line, "//");
        if (comment_pos != NULL) {
            *comment_pos = '\0';
        }

        if (line[0] != '\0' && line[0] != '\n')
            fputs(line, fp_out);
    }

    fclose(fp);
    fclose(fp_out);

    return 0;
}