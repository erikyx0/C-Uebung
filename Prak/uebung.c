#include <stdio.h>

int funk(int a, int b){
    return a+b;
}
int main(void){
    int a=0, b=0;
    printf("Zahl1: "); scanf("%i", &a);
    printf("Zahl2: "); scanf("%i", &b);

    printf("%i + %i = %i", a, b, funk(a,b));
    return 0;
}