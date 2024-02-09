#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void){
    list *list1;
    list1->head = NULL;
    list1->lenght = 0;

    for(int i=0; i<9; i++){
        list1 = insertAtTail(list1, i);
    }
    printNode(list1->head);
    list1 = freeNode(list1->head);
    return 0;
}