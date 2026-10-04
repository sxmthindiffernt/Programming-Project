#include <stdio.h>
#include <string.h>
#include "supplier.h"
#include "validation.h"

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;  

void addSupplier(Supplier suppliers[], int *count)
{
    if (*count >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    printf("\n--- Add Supplier ---\n");

    printf("Enter Supplier ID: ");
    scanf("%d", &suppliers[*count].SupplierID);
    getchar();

    printf("Enter Supplier name: ");
    fgets(suppliers[*count].supplierName,
          sizeof(suppliers[*count].supplierName), stdin);
    suppliers[*count].supplierName[
        strcspn(suppliers[*count].supplierName, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(suppliers[*count].Email,
          sizeof(suppliers[*count].Email), stdin);
    suppliers[*count].Email[
        strcspn(suppliers[*count].Email, "\n")] = '\0';

    printf("Enter Phone: ");
    fgets(suppliers[*count].phone,
          sizeof(suppliers[*count].phone), stdin);
    suppliers[*count].phone[
        strcspn(suppliers[*count].phone, "\n")] = '\0';

    printf("Enter Town: ");
    fgets(suppliers[*count].Town,
          sizeof(suppliers[*count].Town), stdin);
    suppliers[*count].Town[
        strcspn(suppliers[*count].Town, "\n")] = '\0';

    (*count)++;

    printf("\nSupplier added successfully.\n");
}

void displaySuppliers(Supplier suppliers[], int count)
{
    if (count == 0)
    {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printf("\n--- Supplier List ---\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID: %d\n", suppliers[i].SupplierID);
        printf("Name: %s\n", suppliers[i].supplierName);
        printf("Email: %s\n", suppliers[i].Email);
        printf("Phone: %s\n", suppliers[i].phone);
        printf("Town: %s\n", suppliers[i].Town);
    }
}

void searchSupplier(Supplier suppliers[], int count)
{
    int searchID;
    int found = 0;

    printf("Enter Supplier ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; i++)
    {
        if (suppliers[i].SupplierID == searchID)
        {
            printf("\n--- Supplier Found ---\n");
            printf("Supplier ID: %d\n", suppliers[i].SupplierID);
            printf("Name: %s\n", suppliers[i].supplierName);
            printf("Email: %s\n", suppliers[i].Email);
            printf("Phone: %s\n", suppliers[i].phone);
            printf("Town: %s\n", suppliers[i].Town);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nSupplier not found.\n");
    }
}

void compareSuppliers(Supplier suppliers[], int count)
{
    int ID1;
    int ID2;
    int found = 0;

    printf("Enter First Supplier ID: ");
    scanf("%d", &ID1);

    printf("Enter Second Supplier ID: ");
    scanf("%d", &ID2);

    printf("\n--- Supplier Comparison ---\n");

    for (int i = 0; i < count; i++)
    {
        if (suppliers[i].SupplierID == ID1 ||
            suppliers[i].SupplierID == ID2)
        {
            printf("\nSupplier ID: %d\n", suppliers[i].SupplierID);
            printf("Name: %s\n", suppliers[i].supplierName);
            printf("Email: %s\n", suppliers[i].Email);
            printf("Phone: %s\n", suppliers[i].phone);
            printf("Town: %s\n", suppliers[i].Town);

            found = 1;
        }
    }

    if (!found)
    {
        printf("\nNo matching suppliers found.\n");
    }
}
void supplierMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("        SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Return to Main Menu\n");
        printf("========================================\n");

        choice = getValidMenuChoice(1, 5);

        switch (choice)
        {
            case 1:
                addSupplier(suppliers, &supplierCount);
                break;

            case 2:
                displaySuppliers(suppliers, supplierCount);
                break;

            case 3:
                searchSupplier(suppliers, supplierCount);
                break;

            case 4:
                compareSuppliers(suppliers, supplierCount);
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;
        }

    } while (choice != 5);
}