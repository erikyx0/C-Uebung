#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    int *position;
    printf("TicTacToe: \n");
    position = malloc(sizeof(int) * 9); // Reihe Eins: 0 1 2 
                                        // Reihe Zwei: 3 4 5
                                        // Reihe Drei: 6 7 8
    
    return 0;
}