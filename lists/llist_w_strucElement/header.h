#pragma once

typedef struct node{
    struct node *next;
    int data; 
}Node;

typedef struct
{
    Node *head;
    int lenght;
}list;

Node *freeNode(list *head);
Node *insertAtHead(list *head, int value);
Node *insertAtTail(list *head, int value);
void printNode(list *head);
