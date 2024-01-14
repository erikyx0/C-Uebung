#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Node;

typedef struct doublyList
{
    int size;
    Node *head;
    Node *tail;
}DoublyList;

void insert_at_head(DoublyList *structureElement, int value);

int main(int argv, char *argc){

    return 0;
}

void insert_at_head(DoublyList *structureElement, int value){
    Node *newNode = calloc(1, sizeof(Node));
    if(structureElement->head == NULL) return
}
