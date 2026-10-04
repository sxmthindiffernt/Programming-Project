#include <stdio.h>
#include <string.h>
#include "assets.h"

void addAsset(Asset assets[], int *count)
{
printf("Enter Asset ID: ");
scanf("%d", &assets[*count].assetID);
getchar();

while (assets[*count].assetID <= 0)
{
    printf("Asset ID must be greater than 0. Enter again: ");
    scanf("%d", &assets[*count].assetID);
}

printf("Enter Asset Name: ");
fgets(assets[*count].assetName, sizeof(assets[*count].assetName), stdin);
assets[*count].assetName[strcspn(assets[*count].assetName, "\n")] = '\0';

while (strlen(assets[*count].assetName) == 0)
{
    printf("Asset name cannot be empty. Enter again: ");
    fgets(assets[*count].assetName, sizeof(assets[*count].assetName), stdin);
    assets[*count].assetName[strcspn(assets[*count].assetName, "\n")] = '\0';
}

printf("Enter Asset Type: ");
scanf(" %[^\n]", assets[*count].assetType);

printf("Enter Purchase Value: ");
scanf("%f", &assets[*count].purchaseValue);

while (assets[*count].purchaseValue < 0)
{
    printf("Purchase value cannot be negative. Enter again: ");
    scanf("%f", &assets[*count].purchaseValue);
}

printf("Enter Department: ");
scanf(" %[^\n]", assets[*count].department);

printf("Enter Condition: ");
scanf(" %[^\n]", assets[*count].condition);

    (*count)++;

    printf("Asset added successfully!\n");
}
void displayAssets(Asset assets[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No assets registered.\n");
        return;
    }

    printf("\n===== ASSET REGISTER =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("ID: %d\n", assets[i].assetID);
        printf("Name: %s\n", assets[i].assetName);
        printf("Type: %s\n", assets[i].assetType);
        printf("Purchase Value: N$%.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}
    void searchAsset(Asset assets[], int count)
{
    int searchID;
    char searchName[50];
    int choice;
    int i;
    int found = 0;

printf("\nSearch by:\n");
printf("1. Asset ID\n");
printf("2. Asset Name\n");
printf("Enter choice: ");
scanf("%d", &choice);
if (choice == 1)
{
    printf("Enter Asset ID to search: ");
    scanf("%d", &searchID);
}
else if (choice == 2)
{
    printf("Enter Asset Name to search: ");
    scanf(" %[^\n]", searchName);
}
else
{
    printf("Invalid choice.\n");
    return;
}

    for (i = 0; i < count; i++)
    {
       if ((choice == 1 && assets[i].assetID == searchID) ||
    (choice == 2 && strcmp(assets[i].assetName, searchName) == 0))
        {
            printf("\n===== ASSET FOUND =====\n");
            printf("ID: %d\n", assets[i].assetID);
            printf("Name: %s\n", assets[i].assetName);
            printf("Type: %s\n", assets[i].assetType);
            printf("Purchase Value: N$%.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nAsset not found.\n");
    }
}
