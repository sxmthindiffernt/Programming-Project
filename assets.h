#ifndef ASSETS_H
#define assets_H

#define MAX_ASSETS 100

typedef struct {
       int assetID;
       char assetName[50];
       char assetType[30];
       float purchaseValue;
       char department[50];
       char condition[30];

} Asset;

extern Asset assets[MAX_ASSETS];
extern int assetCount;

void addAsset(Asset assets[], int *count);
void displayAssets(Asset assets[], int count);
void searchAsset(Asset assets[], int count);
void assetMenu(void);

#endif
