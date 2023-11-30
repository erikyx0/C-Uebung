#include <stdio.h>

#define cm int
int main(){
    cm a = 10;
    char string[100];
    sprintf(string, "hello %d\n", a);
    printf("string: %s\n", string);

    return 0;
} 