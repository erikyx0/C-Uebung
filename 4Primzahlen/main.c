#include <stdio.h>

//void calculate(int max2);

int main (){
    int max;
    printf("Primzahlen bis zu welche Zahl berechen: ");
    scanf("%i", &max);
    calculate(max);
    return 0;
}

void calculate(int max2){
    int count;
    int x=1;
    for (int i=1; i<max2; i++){
        while (x<i){
            if (x%i==0){

                count++;
                printf("%d", count);
            }
            x++;
        }
    }
    

}

