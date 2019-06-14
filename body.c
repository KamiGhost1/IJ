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
    printf("\t HELP MENU:\n-start - start program\n exit - exit from program\n");
    printf(" show - show list\n Jeany - GINI Index\n decil - calculate decil\n");
    printf(" quartel - quartel koef\n");
}

void PrintTable(Human *h, int j){
    int i;
    for(i=0;i<j;i++){
        printf("%d. %s ; %s ; %s ; %s ; %d\n",i+1, h[i].f_Name, h[i].s_Name,h[i].Gender, h[i].Occupation, h[i].Salary);
    }
}

int comp(const int * i, const int * j){
    return *i-*j;
}

int jeany(Human *h, int i){
    int *array,j,k;
    unsigned long int sum = 0;
    double Rev=0, Jeany=0;
    array= (int*)malloc(sizeof(int)*i);
    for(j=0;j<i;j++){
        array[j]=h[j].Salary;
        sum +=array[j];
    }
    qsort(array,i,sizeof(int),comp);
    for(j=0;j<i;j++)
        for(k=0;k<i;k++)
            Rev += fabsf((array[j])-(array[k]));
    Jeany = Rev/(sum*(i)*2);
    printf("GINI = %lf\n",Jeany);
    free(array);
    return 0;
}

int decil(Human *h, int i){
    int *array,j,dec=0,seg;
    double decil=0,sum1=0,sum2=0;
    array = (int*)malloc(sizeof(int)*i);
    for(j=0;j<i;j++){
        array[j]=h[j].Salary;
    }
    qsort(array,i,sizeof(int),comp);
    dec = i/10;
    printf("choose decil 0-9: ");
    scanf("%d",&seg);
    for(j=dec*seg;j<dec*(seg+1);j++)
        sum1+=array[j];
    for(j=i;j>i-dec;j--)
        sum2+=array[j];
    decil = (sum2/sum1);
    printf("decil N %d = %lf\n",seg,decil);
    free(array);
    return 0;
}

int quartel(Human *h, int i){
    int *array,j,dec=0,seg;
    double quartel=0,sum1=0,sum2=0;
    array = (int*)malloc(sizeof(int)*i);
    for(j=0;j<i;j++){
        array[j]=h[j].Salary;
    }
    qsort(array,i,sizeof(int),comp);
    dec = i/4;
    printf("choose quartel 0-3: ");
    scanf("%d",&seg);
    for(j=dec*seg;j<dec*(seg+1);j++)
        sum1+=array[j];
    for(j=i;j>i-dec;j--)
        sum2+=array[j];
    quartel = (sum2/sum1);
    printf("QK N %d = %lf\n",seg,quartel);
    free(array);
    return 0;
}

