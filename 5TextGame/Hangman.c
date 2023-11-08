#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    char word[20]; char guess;
    int wordlength = 0, maxFail = 0, correctguess = 0;
    bool included = false, schongeraten = false;

    int *geratendeBS = calloc(1 ,sizeof(char));

    printf("Welches Wort: "); scanf("%s", word);
    for (int i=0; word[i] != 0; i++){wordlength++;printf("*");} printf("\n");

    while (correctguess<wordlength && maxFail<3)
    {
        schongeraten = false;
        printf("Char: "); while(getchar() != '\n'); scanf("%c", &guess);

        for(int a=0; a < 10; a++){
            if (guess == geratendeBS[a]){
                printf("Schon geraten! raten etwas Anders!\n");
                schongeraten = true;
            }
        }

        if (schongeraten == false){
            for (int i=0; i<wordlength; i++){ 
                if (guess == word[i]){
                    included = true;
                    break;
                }else included = false;
            }

            if (included == true){
                if (correctguess>1){
                    geratendeBS = realloc(geratendeBS, sizeof(char)*(maxFail+1));
                }
                geratendeBS[correctguess] = guess;
                
                for (int i=0; i <wordlength; i++){
                    if (guess == word[i]){
                        correctguess++;
                    }
                }
                printf("Richtig! Anzahl der korrekt geratende BS: %d\n", correctguess);
            }else {
                maxFail++;
                printf("Falsch\n");
            }
        }

        
    }

    if (correctguess == wordlength) printf("Gewonnen :)\n");
    else printf("\nFail :(\n");

    free(geratendeBS); 
    return 0;
}