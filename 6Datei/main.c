#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "funk.h"

int (*choice())(int, int){
    int op;
    printf("Options:\n- mul(1)\n- add(2)\n- sub(3)\n- divi(4)\nChoice: ");
    scanf("%d", &op);

    //printf("Choice Pointer: %p\n", choice());
    //printf("mul Pointer: %p\n", mul);

    switch (op)
    {
    case 1: return mul; break;
    case 2: return add; break;
    case 3: return sub; break;
    case 4: return divi; break;
    default: return NULL;
        break;
    }
    
}

int main(int argc, char *argv[]){
    
    int (*choiceTO) (int, int) = choice(); // mul(8,9) oder 72
    int produkt = choiceTO(8,9);
    
    printf("%d\n", produkt);
    return 0;
}