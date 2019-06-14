#include "head.h"





Human *createTable(int i,FILE *in){
    Human *h;
    int j;
    char str[STR_SIZE],sep[]={',','"'};
    fgets(str,STR_SIZE,in);
    h = (Human*)malloc(sizeof(Human)*i);
    if(!h){
        printf("need more RAM!\n");
        exit(5);
    }
    for (j=0;j<i;j++){
        fgets(str,STR_SIZE,in);
        strcpy(h[j].s_Name,strtok(str,sep));
        strcpy(h[j].f_Name,strtok(NULL,sep));
        strcpy(h[j].Gender,strtok(NULL,sep));
        strcpy(h[j].Occupation,strtok(NULL,sep));
        h[j].Salary=atoi(strtok(NULL,sep));
    }
    printf("table is loaded!\n");
    return h;
}







void Checkparam(int C, char **V){}


void helpMenu(){
    printf("");
}

void PrintTable(Human *h, int j){
    int i;
    for(i=0;i<j;i++){
        printf("%d. %s ; %s ; %s ; %s ; %d\n",i+1, h[i].f_Name, h[i].s_Name,h[i].Gender, h[i].Occupation, h[i].Salary);
    }
}