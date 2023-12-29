#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *file;
    file = fopen("file.csv", "w");

    if (file == NULL){
        printf("Feher!\n");
    }else{
        for (int random=0; random<30; random++){

            fprintf(file, "%d, %d, %d, %d, %d, %d, %d, %d\n", random, random, random, random, random, random, random, random);

        }
    }
    fclose(file);

    return 0;
}
