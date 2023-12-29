#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next_node;
}Node;

Node *add_to_head(Node *head, int value);
Node *add_to_tail(Node *head, int value);
Node *delete_from_tail2(Node *head);
Node *delete_from_tail(Node *head);
Node *delete_from_head(Node *head);
Node *print_node(Node *head);

int main(int argv, char *argc){
    Node *head_node = NULL;
    for (int i=0; i<1; i++){
        head_node = add_to_tail(head_node, i);
        //list1_head = insert_at_head(list1_head, i);
    }


    head_node = delete_from_tail2(head_node);
    head_node = delete_from_tail2(head_node);

    //head_node = delete_from_tail(head_node);
    print_node(head_node);
    return 0;
}

Node *add_to_head(Node *head, int value){
    Node *new_node = calloc(1,sizeof(Node));
    new_node->value = value;
    if (head == NULL){
        new_node->next_node = NULL;
        return new_node;
    }else{
        new_node->next_node = head;
        return new_node;
    }
}

Node *add_to_tail(Node *head, int value){
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = value;
    if (head == NULL){
        return new_node;
    }else{
        Node *current = head;
        while (current->next_node != NULL){
            current = current->next_node;
        }
        current->next_node = new_node;
        return head;
    }
}

Node *delete_from_tail(Node *head){
    if (head != NULL){
        if (head->next_node == NULL){
            free(head);
            return NULL;
        }else{
            Node *current = head->next_node;
            Node *new_end = head;
            while (current->next_node != NULL){
                new_end = new_end->next_node;
                current = current->next_node;
            }
            new_end->next_node = NULL;
            free(current);
            return head;
        }
    }else{
        printf("Empty list!\n");
    }
}


//oder:
Node *delete_from_tail2(Node *head){
    if (head != NULL){
        if (head->next_node == NULL){
            free(head);
            return NULL;
        }else{
            Node *current = head;
            Node *new_end = NULL;
            while (current->next_node != NULL){
                new_end = current;
                current = current->next_node;
            }
            new_end->next_node = NULL;
            free(current);
            return head;
        }
    }else{
        printf("Empty list!\n");
    }
}


Node *delete_from_head(Node *head){
    if (head == NULL){
        return NULL;
    }else{
        Node *current = head->next_node;
        free(head);
        return current;
    }
}

Node *print_node(Node *head){
    Node *current = head;
    if (current == NULL){
        printf("Empty list!\n");
    }else{
        while (current != NULL){
            printf("%d\n", current->value);
            current = current->next_node;
        }
    }
}