#include <stdio.h>
#include <stdlib.h>
int save(); 
int view(int *Vnumbers, int size);

int main(){
    char choice;
    int *numbers; int num=0; int count=0;
    int size = 2;
    numbers = malloc(sizeof(int) * size);

    do{
        if (count==size){
            size +=2;
            printf("Reservating bigger space to %d\n", size);
            numbers = realloc(numbers, sizeof(int) *size);
        }
        printf("Save number (-1 to cancel): ");
        scanf("%d", &num);

        if (num != -1) numbers[count] = num; count++;

    }while(num != -1);
    
    printf("View data? (j/n): "); while(getchar() != '\n');
    scanf("%c", &choice);
    if (choice == 'j'){
        view(numbers, size);
    }
    free(numbers);
    return 0;
}
int save(){

}

int view(int *Vnumbers, int size){
    for (int i=0; i<size; i++){
        printf("numbers[%d] = %d\n", size, Vnumbers[i]);
    }
}