#include <stdio.h>
#include <string.h> // Include string.h for strlen function

int main(){
    int age=0;
    float gpa=0.0F;
    char grade = '\n';
    char name[50] = "";

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your GPA: ");
    scanf("%f", &gpa);

    printf("Enter your grade: ");
    scanf(" %c", &grade); // Note the space before %c to consume any leftover newline character

    getchar(); // Clear the newline character from the input buffer
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin); // Using fgets to read string input // using sizeof so when a change is made on the index of name it is made on the fgets without needing to change the number
    name[strlen(name)-1] = '\0'; // Remove the newline character

    printf("Age: %d\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Grade: %c\n", grade);
    printf("Name: %s\n", name);

    return 0;
}
