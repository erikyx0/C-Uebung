#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
int Arraysize(int NUmarr[]);

int apos; int *Papos = &apos;
int bpos; int *Pbpos = &bpos;


int main(int argc , char **argv){
    int sizecheck = 1, sizeofcall = 0, checkvar = 0;;
    int *inputnumbers; inputnumbers = calloc(sizecheck, sizeof(int));

    do{
        inputnumbers[sizeofcall] = atoi(argv[sizecheck]);
        sizecheck++; sizeofcall++;
    }while  (atoi(argv[sizecheck]) != 0);

    do{
        for (int i=0; i<sizeofcall; i++){
            for (int c=0; c<sizeofcall; i++){
                if (inputnumbers[c]<inputnumbers[c+1]){
                    checkvar++;
                }
            }
            bool choice = NUMcomparison(inputnumbers[i], inputnumbers[i+1]);
            if (choice){
                sorttobiggerorsmaller(inputnumbers[i], i, inputnumbers[i+1], i+1, sortasmaller);
                inputnumbers[*Papos] = 
                }
            else {
                sorttobiggerorsmaller(inputnumbers[i], i, inputnumbers[i+1], i+1, sortasbigger);
                }

            //sorttobiggerorsmaller(inputnumbers, sizeofcall);
        }
    }while(checkvar != sizeofcall);

    return 0;
}



