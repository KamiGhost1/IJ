#include "head.h"

void workspace(){
    _Bool found;
    int i,j=0;
    FILE *in;
    Route routeTable[] ={
        {"help",helpMenu},
        {"show",PrintTable},
        {"Jeany",jeany},
        {"decil",decil}
    };
    char *name, cmd[10],ch;
    name = (char*)malloc(sizeof(char)*SIZE_NAME);
    printf("enter name of File: ");
    scanf("%s",name);
    in = fopen(name, "r");
    if(!in){
        printf("file not found!\n");
        exit(2);
    }
    printf("loading...\n");
    while((ch =fgetc(in)) !=EOF){
        if(ch=='\n')
            j++;
    }
    printf("size of table = %d\n",j);
    fseek(in, 0,SEEK_SET);
    Human *Humans;
    Humans = createTable(j,in);
    free(name);
    printf("Start of work! good luck!\n");
    while(1){
        found = 0;
        printf(">");
        scanf("%s",cmd);
        for(i=0;i<sizeof(routeTable)/sizeof(Route);i++){
            if(!strcmp(cmd, routeTable[i].cmd)){
                routeTable[i].func(Humans,j);
                found = 1;
            }
        }
        if(!strcmp(cmd,"exit")){
            break;
        }
        if(!found){
            printf("command not found!\nuse help!\n");
        }
    }
    printf("End of work!\n");
    free(Humans);
}