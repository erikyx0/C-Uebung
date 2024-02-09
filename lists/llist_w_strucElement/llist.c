#include "header.h"
#include <stdlib.h>
#include <stdio.h>

Node *freeNode(list *head){
    if(head == NULL) return NULL;
    else{
        while(head != NULL){
            Node *buffer = head;
            head = buffer->next;
            free(buffer);
        }
    }
    return NULL;
}

void printNode(list *head){
    if(head == NULL) return ;
    Node *nod = head->head;
    
    while(nod->next != NULL){
        printf("%d\n", nod->data);
        nod = nod->next;
    } 
}

Node *insertAtHead(list *head, int value){
    Node *newNode = calloc(1, sizeof(Node));
    newNode->data = value;
    newNode->next = head->head;
    head->lenght++;
    return newNode;
}

Node *insertAtTail(list *head, int value){
    Node *newNode = calloc(1, sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    Node *buffer = head;
    Node *nod = head->head;

    if(head == NULL) return newNode;
    while(nod->next != NULL){
        nod = nod->next;
    }
    nod->next = newNode;
    return buffer;
}