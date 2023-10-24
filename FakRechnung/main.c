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
    int a[] = {1,2,3,4,5};
    int b = 3;
    int *p;
    p = &b;

    for (int i=0; i<5; i++){
        printf("%p\n",a[i] );
    }

    
    printf("%p\n", p);
    printf("%p\n", &b);
    printf("%d", p);
    //pint_funk(a);
    return 0;

}

void pint_funk(int *array){
    printf("%p", array);
}
