#include <stdio.h>
#include <stdlib.h>

typedef struct blatt{
    int data;
    struct blatt *left, *right;
}Blatt;

Blatt *add_leaf(Blatt *head, int data);
Blatt *free_tree(Blatt *head);
void print_tree(Blatt *head);
void print_layer(Blatt *head, int layer);

int main(void){
    Blatt *tree;
    for(int i=0; i<8; i++){
        tree = add_leaf(tree, i);
    }
    tree = add_leaf(tree, -1);
    tree = add_leaf(tree, 4);
    tree = add_leaf(tree, 89);
    print_tree(tree);
    printf("\n");
    print_layer(tree, 0);
    return 0;
}

Blatt *add_leaf(Blatt *head, int data){
    Blatt *newBlatt = calloc(1, sizeof(Blatt)), *Buffer, *trueHead;
    newBlatt->data = data;
    if(head == NULL){return newBlatt;}
    else{
        trueHead = head;
        while(head != NULL){
            Buffer = head;
            if(data <= head->data) head = head->left;
            else if(data > head->data) head = head->right;
        }
        if(data <= Buffer->data) Buffer->left = newBlatt;
        else if(data > Buffer->data) Buffer->right = newBlatt;
    }
    return trueHead;
}

void print_tree(Blatt *head){
/*
    Blatt *left_max = head, *right_max = head;
    int lmax=0, rmax=0, true_max;
    while(left_max != NULL){
        left_max = left_max->left;
        lmax++;
    }
    while(right_max != NULL){
        right_max = right_max->right;
        rmax++;
    }
    if(lmax <= rmax) true_max = lmax;
    else true_max = rmax;
*/
    if(head != NULL){
        print_tree(head->left);
        printf("%d ", head->data);
        print_tree(head->right);
    }
}

Blatt *free_tree(Blatt *head){
    if(head != NULL){
        free_tree(head->left);
        free_tree(head->right);
        free(head);
    }
    return NULL;
}

void print_layer(Blatt *head, int layer){
    if (head == NULL) {
        return; 
    if (layer == 0){
        printf("%d ", head->data);
    } else {
        // Ansonsten rekursiv die linke und rechte Seite durchlaufen und die Layerzahl um eins verringern
        print_layer(head->left, layer - 1);
        print_layer(head->right, layer - 1);
    }
    }
}