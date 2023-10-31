#include <stdio.h>
#include <stdbool.h>

int calculate(int max2);

int main (){
    int max;
    printf("Primzahlen bis zu welche Zahl berechen: ");
    scanf("%i", &max);

    printf("Es gibt bis %d insgesamt %d Primzahlen.",max, calculate(max));
    return 0;
}

int calculate(int max2){
    int total = 0;
    
    for (int a=0; a<=max2; a++){
        bool prim = false;
        int count=0;

        for (int b=1; b<=a; b++){
            int c = a%b;
            if (c==0) count++;
        }

        if (count==2){
            total++; 
            prim = true;
        }else{
            prim = false;
        }

        printf("%d: %d\n", a, prim);
    }
    
    return total;
}

