#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "supplier.h"
#include "validation.h"

void employeeReport(void)
{
if (employeeCount == 0)
{
printf("\n========================================\n");
printf(" EMPLOYEE REPORT\n");
printf("========================================\n");
printf("No employees registered.\n");
printf("========================================\n");
return;
}

double totalSalary = 0.0;
double highestSalary = 0.0;
double lowestSalary = 0.0;

for (int i = 0; i < employeeCount; i++)
{
    double salary = calculateSalary(
        employees[i].basicSalary,
        employees[i].housingAllowance,
        employees[i].transportAllowance
    );

    totalSalary += salary;

    if (i == 0)
    {
        highestSalary = salary;
        lowestSalary = salary;
    }
    else
    {
        if (salary > highestSalary)
        {
            highestSalary = salary;
        }

        if (salary < lowestSalary)
        {
            lowestSalary = salary;
        }
    }
}

double averageSalary = totalSalary / employeeCount;

printf("\n========================================\n");
printf("           EMPLOYEE REPORT\n");
printf("========================================\n");
printf("Total Employees      : %d\n", employeeCount);
printf("Average Gross Salary : N$%.2f\n", averageSalary);
printf("Highest Gross Salary : N$%.2f\n", highestSalary);
printf("Lowest Gross Salary  : N$%.2f\n", lowestSalary);
printf("========================================\n");

}

void budgetReport(void)
{
if (budgetCount == 0)
{
printf("\n========================================\n");
printf(" BUDGET REPORT\n");
printf("========================================\n");
printf("No budget data available.\n");
printf("========================================\n");
return;
}

double totalAllocated = 0.0;
double totalExpenditure = 0.0;
double totalRemaining = 0.0;

int exceededCount = 0;

for (int i = 0; i < budgetCount; i++)
{
    totalAllocated += budgets[i].allocatedBudget;
    totalExpenditure += budgets[i].expenditure;
    totalRemaining += budgets[i].remainingBudget;

    if (budgets[i].isExceeded)
    {
        exceededCount++;
    }
}

printf("\n========================================\n");
printf("             BUDGET REPORT\n");
printf("========================================\n");
printf("Total Allocated Budget : N$%.2f\n", totalAllocated);
printf("Total Expenditure      : N$%.2f\n", totalExpenditure);
printf("Total Remaining Budget : N$%.2f\n", totalRemaining);

printf("\nDepartments Exceeding Budget:\n");

if (exceededCount == 0)
{
    printf("None\n");
}
else
{
    for (int i = 0; i < budgetCount; i++)
    {
        if (budgets[i].isExceeded)
        {
            printf("- %s\n", budgets[i].department);
        }
    }
}

printf("========================================\n");

}

void supplierReport(void)
{
if (supplierCount == 0)
{
printf("\n========================================\n");
printf(" SUPPLIER REPORT\n");
printf("========================================\n");
printf("No suppliers registered.\n");
printf("========================================\n");
return;
}

printf("\n========================================\n");
printf("            SUPPLIER REPORT\n");
printf("========================================\n");

for (int i = 0; i < supplierCount; i++)
{
    printf("\nSupplier %d\n", i + 1);
    printf("Supplier ID : %d\n", suppliers[i].SupplierID);
    printf("Name        : %s\n", suppliers[i].supplierName);
    printf("Email       : %s\n", suppliers[i].Email);
    printf("Phone       : %s\n", suppliers[i].phone);
    printf("Town        : %s\n", suppliers[i].Town);
}

printf("\n========================================\n");

}

void assetReport(void)
{
printf("\n========================================\n");
printf(" ASSET REPORT\n");
printf("========================================\n");
printf("Asset Management module is still being integrated.\n");
printf("========================================\n");
}

void reportsMenu(void)
{
int choice;

do
{
    printf("\n========================================\n");
    printf("              REPORTS MENU\n");
    printf("========================================\n");
    printf("1. Employee Report\n");
    printf("2. Budget Report\n");
    printf("3. Supplier Report\n");
    printf("4. Asset Report\n");
    printf("5. Return to Main Menu\n");
    printf("========================================\n");

    choice = getValidMenuChoice(1, 5);

    switch (choice)
    {
        case 1:
            employeeReport();
            break;

        case 2:
            budgetReport();
            break;

        case 3:
            supplierReport();
            break;

        case 4:
            assetReport();
            break;

        case 5:
            printf("\nReturning to Main Menu...\n");
            break;
    }

} while (choice != 5);

}
