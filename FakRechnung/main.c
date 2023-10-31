#include <stdio.h>
#include <stdlib.h>
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

    int *a;
    a = malloc(sizeof(int)*100);
    for (int i=0; i<100; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    free(a); 
   return 0;
}
