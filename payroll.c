#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float basic, allowance, deduction, netSalary;
};

void calculateSalary(struct Employee *e) {
    e->allowance = e->basic * 0.20; // 20% allowance
    e->deduction = e->basic * 0.10; // 10% deduction
    e->netSalary = e->basic + e->allowance - e->deduction;
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d ID: ", i + 1);
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic);

        calculateSalary(&emp[i]);
    }

    printf("\n--- Payroll Summary ---\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Name: %s | Net Salary: %.2f\n",
               emp[i].id, emp[i].name, emp[i].netSalary);
    }
    return 0;
}
