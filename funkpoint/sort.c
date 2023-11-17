#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void sorttobiggerorsmaller(int i, int posi, int iplus, int posiplus, int (*smallorbig())(int, int)){
        smallorbig(i, posi, iplus, posiplus);
}

bool NUMcomparison(int a, int b){
    if (a<=b){
            return true;
        }else{
            return false;
        }
}

void sortasbigger(int i, int posi, int iplus, int posiplus){
    switchchar(i, posi, iplus, posiplus, true);
}
void sortasmaller(int i, int posi, int iplus, int posiplus){
    switchchar(iplus, posiplus, i, posi, false);
}
int switchchar(int a, int posA, int b, int posB, bool s){
        

}