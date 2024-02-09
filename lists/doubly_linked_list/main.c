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

Node *insert_at_head(DoublyList *structureElement, int value);

int main(int argv, char *argc){
    DoublyList list1;
    list1.size = 0;
    list1.head = NULL;
    list1.tail = NULL;

    return 0;
}

Node *insert_at_head(DoublyList *structureElement, int value){
    Node *newNode = calloc(1, sizeof(Node));
    newNode->data = value;
    if(structureElement->head == NULL){
        structureElement->head = newNode;
        structureElement->tail = newNode;
        return newNode;
    }
    
}
