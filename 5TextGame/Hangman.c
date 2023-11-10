#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    char word[20]; char guess; 
    int wordlength = 0, maxFail = 0, correctguess = 0;
    bool included = false, schongeraten = false;
    char *geratendeBS = calloc(1 ,sizeof(char));

    printf("Welches Wort: "); scanf("%s", word);
    for (int i=0; word[i] != 0; i++){wordlength++;printf("*");} printf("\n");

    char *posWord = calloc(wordlength, sizeof(char));


    while (correctguess<wordlength && maxFail<3)
    {
        schongeraten = false;
        printf("\nChar: "); while(getchar() != '\n'); scanf("%c", &guess);

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
                    geratendeBS = realloc(geratendeBS, sizeof(char)*(correctguess+1));
                }

                geratendeBS[correctguess] = guess;

                for (int i=0; i <wordlength; i++){
                    if (guess == word[i]){
                        correctguess++;
                    }
                }

                printf("Richtig!: ", correctguess);

            }else {
                maxFail++;
                printf("Falsch!: ");
            }

            for(int i=0; i<wordlength; i++){
                for(int j=0; j<wordlength; j++){
                    if (geratendeBS[i]==word[j]){
                       posWord[j] = geratendeBS[i];
                    }
                }
            }

            for (int i=0; i<wordlength; i++){
                if (posWord[i] != 0){
                    printf("%c", posWord[i]);
                }else{
                    printf("*");
                }
            }
        }  
    }

    if (correctguess == wordlength) printf("\nGewonnen :)\n");
    else printf("\nFail :(\n");

    free(geratendeBS); free(posWord);
    return 0;
}