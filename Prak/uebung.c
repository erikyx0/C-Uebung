#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum button {ON, OFF} Button;
Button press(Button c);
Button power = ON;

int main(int argc, char *argv[]){
    int click = 0;
    char choice;
    
    while (click != 3){
        printf("button (N or F): "); scanf("%s", &choice);
        if ((choice == 'N' && power == ON) || (choice == 'F' && power == OFF)){
            printf("Same, probier nochmal\n");
        }else{
            if (choice == 'N'){
                printf("Buttonstatus: %i\n", press(ON));
            }else if (choice == 'F'){
                printf("Buttonstatus: %i\n", press(OFF));
            }
        }
        click++;
    }

    return 0;
}

Button press(Button c){
    power = c;
    return power;
}