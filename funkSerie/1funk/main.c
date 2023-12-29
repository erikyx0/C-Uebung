#include <stdlib.h>
#include <stdio.h>
#include "funk.h"

int main(int argv, char *argc[]){

    int a = atoi(argc[1]);
    int b = atoi(argc[2]);
    draw_rec(a, b);
    return 0;
}