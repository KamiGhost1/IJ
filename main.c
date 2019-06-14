#include "head.h"

int main(int C, char **V){
    if (C==1){
        printf("lab  4 by Ghost\nEnjoy!\n");
        return 0;
    }
    if(C==2){
        if (!strcmp(V[1],"-h")){
            helpMenu();
            return 0;
        }
        if (!strcmp(V[1],"-start")){
            workspace();
            return 0;
        }
    if (C>2){
        Checkparam();
        return 0;
    }
    }
    printf("unknown params!\nuse -h for more info!\n");
    return 1;
}