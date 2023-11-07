#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    char word[20]; char guess;
    int wordlength = 0;
    int maxFail = 0;
    int correctguess = 0;
    bool included = false, schongeraten = false;

    int *geratendeBS = malloc(sizeof(char) * 1);

    printf("Welches Wort: "); scanf("%s", word);
    for (int i=0; word[i] != 0; i++){wordlength++;printf("*");} printf("\n");

    while (correctguess<wordlength && maxFail<3)
    {

        int wordlengthTry=0;
        printf("Char: "); while(getchar() != '\n'); scanf("%c", &guess);

        for(int a=0; a < 10; a++){
            if (guess == geratendeBS[a]){
                printf("Schon geraten! raten etwas Anders!\n");
                schongeraten = true;
            }else {schongeraten = false;}
        }

        if (schongeraten == false){
            for (int i=0; i<wordlength; i++){ 
                if (guess == word[i]){
                    included = true;
                    break;
                }else included = false;
            }

            if (included == true){
                correctguess++;
                printf("Richtig!\n");
            }else {
                if (maxFail>1){
                    geratendeBS = realloc(geratendeBS, sizeof(char)*(maxFail+1));
                }
                geratendeBS[maxFail] = guess;
                maxFail++;
                printf("Falsch\n");
            }
        }

        
    }
    if (correctguess == wordlength) printf("Gewonnen :)\n");
    else printf("Fail :(\n");

    return 0;
}