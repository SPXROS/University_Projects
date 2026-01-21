#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float grade;
    char name[200];
} Student;

void findtop(Student *students, int count) {
    float max = -1.0;
    int topIndex = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].grade > max) {
            max = students[i].grade;
            topIndex = i;
        }
    }
    printf("\n--- Top Student ---\n");
    printf("The top student is %s with a grade of %.2f\n", students[topIndex].name, max);
}

int main(void) {
    FILE *fp = fopen("grades.txt", "r");
    if (!fp) {
        perror("Error opening grades.txt");
        return 1;
    }

    Student *students = NULL;
    int count = 0;
    char buffer[400];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        Student *temp = realloc(students, (count + 1) * sizeof(Student));
        if (temp == NULL) {
            free(students);
            fclose(fp);
            return 1;
        }
        students = temp;

        if (sscanf(buffer, "%[^0-9]%f", students[count].name, &students[count].grade) == 2) {
            count++;
        }
    }
    fclose(fp);
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].grade;
    }
    float average = (count > 0) ? (sum / count) : 0;

    if (count > 0) {
        findtop(students, count);
    }

    FILE *fp_avg = fopen("average.txt", "w");
    if (fp_avg) {
        fprintf(fp_avg, "The average grade is %.2f", average);
        fclose(fp_avg);
        printf("\nAverage saved to average.txt\n");
    }

    free(students);
    return 0;
}