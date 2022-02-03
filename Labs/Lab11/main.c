#include <stdio.h>

typedef struct Employee
{
    char name[100];      // employee's name - last, first
    char title;          // title 'B' or 'M'
    double hoursWorked; // total number of hours worked
    double payrate;      // pay rate per hour
    double payment;      // total payment for the pay period – you will compute!
} Employee;

int main(void)
{
    Employee payroll[200];
    int employeeCount = 0;
    double totalPayroll = 0;
    double averageTotalPayment = 0;
    double maxTotalPayment = -1;
    double minTotalPayment = -1;
    FILE *payrollFile = fopen("payroll.txt", "r");
    for (int i = 0; i < 200; i++)
    {
        if (!feof(payrollFile))
        {
            fgets(payroll[i].name, 100, payrollFile);
            fscanf(payrollFile, "%c\n", &payroll[i].title);
            fscanf(payrollFile, "%lf\n", &payroll[i].hoursWorked);
            fscanf(payrollFile, "%lf\n", &payroll[i].payrate);
            employeeCount++;
            double overtimeHours = payroll[i].hoursWorked - 80;
            if (overtimeHours < 0)
                overtimeHours = 0;
            double overtimeModifier = 1.5;
            if (payroll[i].title == 'M')
                overtimeModifier = 1.8;
            double overtimePayment =  overtimeModifier * payroll[i].payrate * overtimeHours;
            double payment = payroll[i].payrate * (payroll[i].hoursWorked - overtimeHours);
            double totalPayment = payment + overtimePayment;
            payroll[i].payment = totalPayment;
            totalPayroll += totalPayment;
            if (maxTotalPayment == -1 || totalPayment > maxTotalPayment)
            {
                maxTotalPayment = totalPayment;
            }
            if (minTotalPayment == -1 || totalPayment < minTotalPayment)
            {
                minTotalPayment = totalPayment;
            }
        }
    }
    fclose(payrollFile);
    averageTotalPayment = totalPayroll / employeeCount;
    FILE *paidFile = fopen("paid.txt", "w");
    fprintf(paidFile, "Total: $%.2lf\n", totalPayroll);
    fprintf(paidFile, "Average: $%.2lf\n", averageTotalPayment);
    fprintf(paidFile, "Max: $%.2lf\n", maxTotalPayment);
    fprintf(paidFile, "Min: $%.2lf\n", minTotalPayment);
    fclose(paidFile);
    return 0;
}
