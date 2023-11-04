#include <stdio.h>
#include <string.h>

int main(){
    char word[20]; char guess;
    int wordlength = 0;
    int gamecounter = 0;
    int maxFail = 0;
    int correctguess = 0;
    printf("Type the word: "); scanf("%s", word);
    for (int i=0; word[i] != 0; i++){wordlength++;printf("*");} printf("\n");

    while (gamecounter<wordlength && maxFail<3)
    {
        int wordlengthTry=0;
        printf("Guess: "); while(getchar() != '\n'); scanf("%c", &guess);
        printf("Test: %c, %d ", guess, wordlength);

        for (int i=0; i<wordlengthTry; i++){
            if (guess =! word[i]){
                wordlengthTry++;
                printf("%d", wordlengthTry);
            }
        }
        wordlength = wordlengthTry;

        if (wordlengthTry == wordlength-1){
            printf("The char %c is included\n", guess);
            gamecounter++; correctguess++;
        }else {
            printf("The char %c is not included\n", guess);
            maxFail++;
        }
    }
    return 0;
}