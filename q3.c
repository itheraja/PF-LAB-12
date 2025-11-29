#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    char department[20];
    char designation[20];
    float salary;
    char joinDate[12];
    int years;
};

int main() {
    struct Employee e[MAX];
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &e[i].id);

        printf("Name: ");
        scanf("%s", e[i].name);

        printf("Department (IT/HR/Finance/Marketing/Operations): ");
        scanf("%s", e[i].department);

        printf("Designation (Intern/Junior/Senior/Manager/Director): ");
        scanf("%s", e[i].designation);

        printf("Salary: ");
        scanf("%f", &e[i].salary);

        printf("Year of Joining: ");
        scanf("%d", &e[i].years);
    }

   
    for (i = 0; i < n; i++)
        e[i].years = 2025 - e[i].years;

    printf("\n--- Employee Summary ---\n");
    for (i = 0; i < n; i++) {
        printf("%d | %s | %s | %s | %.2f | Exp: %d yrs\n",
            e[i].id, e[i].name, e[i].department, e[i].designation,
            e[i].salary, e[i].years);

        if (e[i].years > 3)
            printf("Eligible for Promotion!\n");
    }

    return 0;
}
