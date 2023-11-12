#include <stdio.h>
#include <stdlib.h>

#define sizeofword 16
int main(int argc, char *argv[]){

    //printf("%d\n", argc);
    FILE *file;
    file = fopen("list.txt", "r");
    char word[sizeofword];

    int number = atoi(argv[1]);
    for (int i=0; i<number; i++){
       fgets(word, sizeofword, file);
    }
    printf("word: %s", word);

    for (int i=1; i!=; i++){
        printf("%c\n", word[i-1]);
    }


    fclose(file);
    return 0;
}