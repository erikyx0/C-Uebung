#include <stdio.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

void print_list(Node *head);

int main(){
    Node a, b, c;
    a.value = 5;
    b.value = 6;
    c.value = 7;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    print_list(&a);
    //printf("value: %d\n", a.value);
    return 0;
}

void print_list(Node *head){
    Node *current;
    current = head;
    while(current != NULL){
        printf("%d", current->value);
        current = current->next;
    }

}
