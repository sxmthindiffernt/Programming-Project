#ifndef VALIDATION_H
#define VALIDATION_H

void clearInputBuffer(void);
int getValidMenuChoice(int min, int max);
double getValidPositiveNumber(const char prompt[]);
int getValidPositiveInteger(const char prompt[]);

#endif