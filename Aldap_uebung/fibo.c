#include <stdio.h>

void fibo(size_t, size_t, size_t);
void fibo_normal(int);

int main(void){
    fibo_normal(100);
    return 0;
}

void fibo_normal(int max){
    int a = 0, b = 1, buffer;
    while(max>a){
        printf("%d\n", a);
        buffer = a;
        a = b;
        b = buffer+b;
    }
}

void fibo(size_t max, size_t a, size_t b){
    if(max>a){
        printf("%d\n", a);
        fibo(max, b, a+b);
    }
}