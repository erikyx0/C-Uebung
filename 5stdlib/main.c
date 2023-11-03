#include <stdio.h>
#include <stdlib.h>
int save(int *Snumbers, int *size, int count);
void view(int *Vnumbers, int *size);
void order(int *Onumbers, int *Osize);
int main(){
    char choice;
    int *numbers; 
    int count=0;
    int size = 2; int *psize; psize = &size;
    numbers = malloc(sizeof(int) * size);

    do {
    printf("Please make a choice:\n - save data (type s)\n - view data (type v)\n - sort data (type o)\n - exit      (type e)\nType here:  ");
    scanf("%c", &choice); printf("\n");
    switch (choice)
    {
    case 'v':
        view(numbers, psize); break;
    case 's':
        count = save(numbers, psize, count);break;
    case 'o':
        order(numbers, psize);break;
    case 'e': 
        break;
    default: 
        printf("\nInvalid Syntax!\n\n"); break;
    }

    }while(choice != 'e');

    free(numbers); printf("logging out!....\n");
    return 0;
    
}
int save(int *Snumbers, int *Ssize, int count){
    int num=0;
    do{
        
        if (count == *Ssize){
            *Ssize +=2;
            printf("--Reservating bigger space to %d--\n", *Ssize);
            Snumbers = realloc(Snumbers, sizeof(int) * *Ssize);
        }
        printf("Save number (-1 to cancel): ");
        scanf("%d", &num);

        if (num != -1) {Snumbers[count] = num; count++;}
        
    }while(num != -1);

    printf("count:%d and Ssize:%d\n", count, *Ssize);
    while (count<*Ssize){
        (*Ssize)--;
    }
    printf("NEW: count:%d and Ssize:%d\n", count, *Ssize);
    while(getchar() != '\n');

    return (count);
}

void view(int *Vnumbers, int *Vsize){
    printf("size: %d\n", *Vsize);
    for (int i=0; i<*Vsize; i++){
        if (i<*Vsize) printf("numbers[%d] = %d\n", i, Vnumbers[i]);
    }
    while(getchar() != '\n');
}

void order(int *Onumbers, int *Osize){
    int orderCount = 0;
    printf("Osize: %d, Onumbers[i]: %d\n", *Osize, Onumbers[1]);
    while(orderCount < *Osize){
        orderCount = 0;
        printf("----------------\n");
        for (int i = 0; i<*Osize; i++){
            if (Onumbers[i]<Onumbers[i+1]){
                printf("Bigger\n");
                orderCount++;
            }else if (Onumbers[i]==Onumbers[i+1]){
                printf("Same\n");
                orderCount++;
            }else{
                printf("Smaller\n");
                int shipping=0;
                shipping = Onumbers[i];
                Onumbers[i] = Onumbers[i+1];
                Onumbers[i+1] = shipping;
            }
        }
        
    }
    for(int i=0; i<*Osize; i++){
        printf("Number[%d] = %d\n",i, Onumbers[i]);
    }
    while(getchar() != '\n');
}
