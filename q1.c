#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    char name[50];
    int roll;
    float marks[3];
    float percent;
    char grade[3];
};

char* calculateGrade(float p) {
    if (p >= 90) return "A+";
    else if (p >= 80) return "A";
    else if (p >= 70) return "B+";
    else if (p >= 60) return "B";
    else if (p >= 50) return "C";
    else return "F";
}

int main() {
    struct Student s[MAX];
    int n, i, j;
    float sum, avg;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        sum = 0;
        for (j = 0; j < 3; j++) {
            do {
                printf("Marks in subject %d (0-100): ", j + 1);
                scanf("%f", &s[i].marks[j]);
            } while (s[i].marks[j] < 0 || s[i].marks[j] > 100);

            sum += s[i].marks[j];
        }

        s[i].percent = sum / 3;
        strcpy(s[i].grade, calculateGrade(s[i].percent));
    }

   
    float totalPercent = 0;
    for (i = 0; i < n; i++)
        totalPercent += s[i].percent;

    avg = totalPercent / n;

    
    struct Student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].percent < s[j + 1].percent) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\n--- Student Rankings ---\n");
    for (i = 0; i < n; i++)
        printf("%d. %s (%.2f%%)\n", i + 1, s[i].name, s[i].percent);

   
    char g[3];
    printf("\nEnter grade to search: ");
    scanf("%s", g);

    printf("\nStudents with grade %s:\n", g);
    for (i = 0; i < n; i++)
        if (strcmp(s[i].grade, g) == 0)
            printf("%s (Roll %d)\n", s[i].name, s[i].roll);

    
    printf("\nClass Average = %.2f\n", avg);
    printf("Above Average:\n");
    for (i = 0; i < n; i++)
        if (s[i].percent > avg)
            printf("%s (%.2f)\n", s[i].name, s[i].percent);

    printf("\nBelow Average:\n");
    for (i = 0; i < n; i++)
        if (s[i].percent < avg)
            printf("%s (%.2f)\n", s[i].name, s[i].percent);

    return 0;
}
