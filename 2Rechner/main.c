#include <stdio.h>

int main (){
    double x, y, z;
    char op;
    printf("Taschenrechner: \n");

    printf("Zahl Eins: ");
    scanf("%lf", &x);
    printf("Operator: ");
    scanf("%c", &op);
    // printf("Zahl Zwei: ");
    // scanf("%lf", &y);

    switch (op)
    {
    case '/': z=x/y; break;
    case '*': z=x*y; break;
    case '-': z=x-y; break;
    case '+': z=x+y; break;
    
    default: break;
    }
    printf("Ergebnis: %lf", z);
}