#include <stdio.h>

void draw_rec(int x, int y){
    char xA[100];
    char yA[100];
    for (int i=0; i<x; i++){
        xA[i]='+';
        yA[i]=' ';
        
    }
    yA[0]='+';
    yA[x-1]='+';
    for (int i=0; i<y; i++){
        if(i==0 || i==y-1){
            for (int j=0; j<x; j++){
                printf("%c ", xA[j]);
            }printf("\n");
        }
        else{
            for (int j=0; j<x; j++){
                printf("%c ", yA[j]);
            }printf("\n");
        }
    }

}