#include <stdio.h>

int main(int argv, char **argc){
    int a[] = {1, 2, 3, 4};
    
    printf("%zu\n", a);
    printf("%zu\n", a+1);
    printf("%zu\n", &a);
    printf("%zu\n", &a+1);
    
    return 0;
}