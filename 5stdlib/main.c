#include <stdio.h>
#include <stdlib.h>
int save(int *Snumbers, int *size);
int view(int *Vnumbers, int *size);
int main(){
    char choice;
    int *numbers; 
    int size = 2;
    numbers = malloc(sizeof(int) * size);

    do {
    printf("Please make a choice:\n - save data (type s)\n - view data (type v)\n - exit      (type e)\nType here:  ");
    scanf("%c", &choice);
    switch (choice)
    {
    case 'v':
        view(numbers, &size); break;
    case 's':
        save(numbers, &size);break;
    case 'e':
        printf("logging out!....\n"); break;
    default: printf("\nInvalid Syyntax!\n\n");
        break;
    }

    
    }while(choice != 'e');
    /*printf("View data? (j/n): "); while(getchar() != '\n');
    scanf("%c", &choice);
    if (choice == 'j'){
        view(numbers, size);
    }
    */
    free(numbers);
    return 0;
    
}
int save(int *Snumbers, int *Ssize){
    int num=0; int count=0; int *pSsize; pSsize = Ssize;
    do{
        if (count == *Ssize){
            Ssize +=2;
            printf("Reservating bigger space to %d\n", *Ssize);
            Snumbers = realloc(Snumbers, sizeof(int) * *Ssize);
        }
        printf("Save number (-1 to cancel): ");
        scanf("%d", &num);

        if (num != -1) Snumbers[count] = num; count++;

    }while(num != -1);
}

int view(int *Vnumbers, int *Vsize){
    for (int i=0; i<*Vsize; i++){
        printf("numbers[%d] = %d\n", *Vsize, Vnumbers[i]);
    }
}
