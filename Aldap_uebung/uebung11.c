#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    struct node *next;
    int data;
}Node;

typedef struct{
    Node *head;
    int lenght;
}list;

Node *freeList();
bool isEmpty();
Node *first();
Node *last();
Node *addFirst();
Node *removeLast();
Node *insert();
int lookup();

int main(void){
    
    return 0;
}
Node *addFirst(){

}