#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "validation.h"

Budget budgets[MAX_DEPARTMENTS];
int budgetCount = 0;

void calculateBudget(Budget * budget){
    budget->remainingBudget = budget->allocatedBudget - budget->expenditure;
    budget->isExceeded = (budget->expenditure > budget->allocatedBudget) ? 1 : 0;

}
void addBudget(Budget budgets[], int *count){
    if (*count >= MAX_DEPARTMENTS){
        printf("\n[ERROR] Maximum department limit reached!\n");
        return;
    }
    Budget budget;
    printf("\n-- Add / Update Department budget --\n");
    printf("Enter department name: ");
    fgets(budget.department, DEPARTMENT_NAME_LENGTH, stdin);
    budget.department[strcspn(budget.department, "\n")] = '\0';
    
    budget.allocatedBudget =
        getValidPositiveNumber("Enter allocated budget (N$): ");
    budget.expenditure =
        getValidPositiveNumber("Enter expenditure (N$): ");

    calculateBudget(&budget);
    budgets[*count] = budget;
    (*count)++;

    printf("\n[SUCCESS] Budget for department '%s' added successfully!\n", budget.department);

}

void displayBudgets(const Budget budgets[], int count){
    if (count == 0){
        printf("\n[ERROR] No budget data available.\n");
        return;
    }
    printf("\n========== BUDGET MANAGEMENT REPORT ==========\n");
    printf("%-20s %-15s %-15s %-15s %-10s\n", "Department", "Allocated Budget", "Expenditure", "Remaining Budget", "Exceeded");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++){
        printf("%-20s N$%-14.2f N$%-14.2f N$%-14.2f %-10s\n",
               budgets[i].department,
               budgets[i].allocatedBudget,
               budgets[i].expenditure,
               budgets[i].remainingBudget,
               budgets[i].isExceeded ? "Yes" : "No");
    }
    
}
void budgetMenu(void){
   
    int choice;

    do{
        printf("\n========================================\n");
        printf("          BUDGET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add / Update Department Budget\n");
        printf("2. Display Budget Report\n");
        printf("3. Return to Main Menu\n");

        choice = getValidMenuChoice(1, 3);

        switch (choice){
            case 1:
                addBudget(budgets, &budgetCount);
                break;
            case 2:
                displayBudgets(budgets, budgetCount);
                break;
            case 3:
                printf("\nReturning to Main Menu...\n");
                break;
        }
    } while (choice != 3);
}
