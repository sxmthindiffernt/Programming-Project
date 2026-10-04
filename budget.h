#ifndef budget_h
#define budget_h
#define MAX_DEPARTMENTS 55
#define DEPARTMENT_NAME_LENGTH 50

typedef struct{
    char department[DEPARTMENT_NAME_LENGTH];
    double allocatedBudget;
    double expenditure;
    double remainingBudget;
    int isExceeded;
}Budget;
extern Budget budgets[MAX_DEPARTMENTS];
extern int budgetCount;

void addBudget(Budget budgets[], int *count);
void displayBudgets(const Budget budgets[], int count);
void calculateBudget(Budget * budget);
void budgetMenu(void);

#endif