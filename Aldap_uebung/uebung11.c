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
    int lenght; //first position starts at 1
}List;

Node *freeList(List *);
Node *first(List *);
Node *last(List *);
Node *removeLast(List *);
void insert(List *, int, int);
int lookup(List *, int);
bool isEmpty(List *); // 0 list is empty & 1 is not empty
Node *addFirst(List *, int );
void print_list(List *);

int main(void){
    List *l1 = calloc(1, sizeof(List));
    l1->lenght = 0; l1->head = NULL;
    
    for(int i=0; i<10; i++){
        l1->head = addFirst(l1, i);
    }

    insert(l1, 44, 4);

    print_list(l1);
    printf("IsEmpty: %d\n", isEmpty(l1));
    printf("Lookup: %d\n", lookup(l1, 1));

    return 0;
}
Node *addFirst(List *list, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = list->head;
    list->head = newNode;
    list->lenght++;
    return newNode;
}

void print_list(List *List){
    Node *head = List->head;
    if(List->lenght == 0) {printf("Empty List\n"); return ;}
    while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }
}

bool isEmpty(List *list){
    if(list->head == NULL) return 0;
    else return 1;
}

int lookup(List *list, int position){
    Node *head = list->head;
    for(int i=1; i<position; i++){
        head = head->next;
    }
    return head->data;
}

void insert(List *list, int data, int position){
    Node *newNode = calloc(1, sizeof(Node));
    newNode->data = data;
    if(position == 1){
        newNode->next = list->head;
        list->head = newNode;
    }else{
        Node *head = list->head, *Buffer;
        for(int i=1; i<(position-1); i++){
            head = head->next;
        }
        Buffer = head->next;
        head->next = newNode;
        newNode->next = Buffer;
        free(Buffer);
    }
}

Node *freeList(List *list){
    if(list->lenght = 1) free(list->head);
    Node *head = list->head, *Buffer;
    while(head != NULL){
        Buffer = head->next;
        free(head);
        head = Buffer;
    }
    free(Buffer);
    return NULL;
}

Node *last(List *list){
    Node *head = list->head;
    while(head->next != NULL) head = head->next;
    return head;
}

Node *first(List *list){
    return list->head;
}

Node *removeLast(List *list){
    Node *head = list->head, *Buffer;
    while(head->next->next != NULL) head = head->next;
    Buffer = head->next;
    head->next = NULL;
    free(Buffer);
}