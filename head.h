#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE_NAME 32
#define STR_SIZE 80

#pragma pack (push,1)
typedef struct _HUMAN{
    char f_Name[20];
    char s_Name[20];
    char Gender[8];
    char Occupation[30];
    unsigned int Salary;
}Human;
#pragma pack(pop)

typedef struct _Route{
    char cmd[10];
    void (*func)();
}Route;


void Checkparam();
void workspace();
Human *createTable();
void helpMenu();
void PrintTable(Human *h, int i);
int jeany(Human *h, int i);
int comp(const int *, const int *);