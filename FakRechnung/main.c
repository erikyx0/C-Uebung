#include <stdio.h>

int main(){
    /*
    int x=0, y=0, z=0;
    printf("Faktorielle Berechnungen!\n");
    printf("Zahl: "); scanf("%i", &x);

    while (x > 0){
        y = x * (x-1);
        z = z + y;
        x--;
    }
    printf("X: %i", z);
    */
    int hel[2];
    int c = 0;
    int d = 0;

    for (int i=0; i<=1000; i++ ){
        printf("pos: %i", i);
        if (hel[i] == 0) {
            printf("--> 0");
            c++;
        }
        if (hel[i] == 2) {
            printf("--> 1");
            d++;
        }
        printf("\n");
    }
    printf("%i 0 were found!!\n", c);
    printf("%i 1 were found!!", d);

    //printf("Durchschnitt: %i", sizeof(hel));
    return 0;
}
