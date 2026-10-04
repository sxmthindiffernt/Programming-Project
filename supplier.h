
#ifndef SUPPLIER_H
#define SUPPLIER_H

#define MAX_SUPPLIERS 100

typedef struct
{
    int SupplierID;
    char supplierName[70];
    char Email[70];
    char phone[35];
    char Town[30];
} Supplier;

extern Supplier suppliers[MAX_SUPPLIERS];
extern int supplierCount;

void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(Supplier suppliers[], int count);
void searchSupplier(Supplier suppliers[], int count);
void compareSuppliers(Supplier suppliers[], int count);
void supplierMenu(void);
#endif