#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *free_list(Node*);
Node *insert_at_head(Node*, int);
Node *insert_at_tail(Node*, int);
Node *delete_at_head(Node*);
Node *delete_at_tail(Node*);
void print_list(Node*);

int main(int argv, char *argc){
    Node *list1=NULL;
    for(int i=0; i<10; i++){
        list1 = insert_at_tail(list1, i);
    }
    print_list(list1);
    printf("\n");
    list1 = delete_at_head(list1);
    list1 = delete_at_tail(list1);

    print_list(list1);
    list1 = free_list(list1);
    return 0;
}


Node *free_list(Node *head){
    while(head != NULL){
        Node *buffer = head;
        head = head->next;
        free(buffer);
    }
    return NULL;
}

Node *insert_at_head(Node *head, int value){
    Node *new_Node = calloc(1, sizeof(Node));
    new_Node->data = value;
    if(head == NULL) return new_Node;
    new_Node->next = head;
    return new_Node;
}

Node *delete_at_head(Node *head){
    if(head == NULL){
        fprintf(stderr, "Error: can not delete empty list element!\n");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }

    Node *buffer = head->next;
    free(head);
    return buffer;
}

Node *insert_at_tail(Node *head, int value){
    Node *new_Node = calloc(1, sizeof(Node));
    new_Node->data = value;
    if(head == NULL) return new_Node;

    Node *head_elemet = head;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = new_Node;

    return head_elemet;
}

Node *delete_at_tail(Node *head){
    if(head == NULL){
        fprintf(stderr, "Error: can not delete empty list element!\n");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }

    Node *current = head;
    while(current->next->next != NULL) current = current->next;
    Node *buffer = current->next;
    current->next = NULL;
    free(buffer);
    return head;
}

void print_list(Node *head){
    if(head == NULL){
        fprintf(stderr, "Error: empty list!");
        return ;
    }
    while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }
}