#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef struct node
{
    int value;
    struct node *next;
}Node;
Node *insert_at_head(Node *head, int new_value);
Node *insert_at_tail(Node *head, int new_value);
Node *delete_at_head(Node *head);
Node *delete_at_tail(Node *head);
int count(Node *head, int value);
int searchlist(Node *head, int value);
int lenght(Node *head);
void print_list(Node *head);
void replace(Node *head, int value, int replace_value);
void sort(Node *head);
void remove_double(Node *head);
void insert_after_value(Node *head, int search_value, int value);
void add_values_recursivly(Node *list1, Node *list2);
Node *copy_list_recursivly(Node *head);
Node *free_list(Node *head);
Node *reversing_list(Node *head);
Node *delete_first_match(Node *head, int value_search, bool *was_deletet);
Node *delete_all_matches(Node *head, int delete_value, bool *was_deleted);
Node *append_lists(Node *head1, Node *head2);
Node *insert_once_after_value(Node *head, int search_value, int value);
Node *add_list_values(Node *list1, Node *list2);
Node *copy_list(Node *head);
Node *merge_sordet_lists_new(Node *list1, Node *list2);

int main(){
    Node *list1_head = NULL, *list2_head = NULL;

    //list1_head = insert_at_head(list1_head, 2);
    //list1_head = insert_at_head(list1_head, 5);
    //list1_head = insert_at_head(list1_head, 1);
    //list1_head = insert_at_head(list1_head, -2);
    //list1_head = insert_at_head(list1_head, 9);


    //list2_head = insert_at_head(list2_head, 67);
    //list2_head = insert_at_head(list2_head, 7);
    //list2_head = insert_at_head(list2_head, 1);
    //list2_head = insert_at_head(list2_head, -1);
    //list2_head = insert_at_head(list2_head, 7);
    //list2_head = insert_at_head(list2_head, 0);
    //list2_head = insert_at_head(list2_head, 1);


    //sort(list1_head); sort(list2_head);

    printf("%d", 1000/CLOCKS_PER_SEC);
    list1_head = free_list(list1_head);
    list2_head = free_list(list2_head);


    return 0;
}



Node *free_list(Node *head){
    while (head != NULL){
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

Node *merge_sordet_lists_new(Node *list1, Node *list2){
    if(list1 == NULL && list2 == NULL) return NULL;
    if(list1 == NULL && list2 != NULL) return list2;
    else if(list1 != NULL && list2 == NULL) return list1;
    
    Node *curr1, *curr2, *new_sordet, *new_sordet_head = calloc(1, sizeof(Node));
    if (list1->value < list2->value){
        curr1 = list1->next;
        curr2 = list2;
        new_sordet = calloc(1, sizeof(Node));
        new_sordet->value = list1->value;
    }else{
        curr1 = list1;
        curr2 = list2->next;
        new_sordet = calloc(1, sizeof(Node));
        new_sordet->value = list2->value;
    }
    new_sordet_head = new_sordet;

    while(curr1 != NULL || curr2 != NULL){
        Node *new = calloc(1, sizeof(Node));
        if(curr1 != NULL && curr2 != NULL){
            if(curr1->value < curr2->value){
                new->value = curr1->value;
                curr1 = curr1->next;
            }else{
                new->value = curr2->value;
                curr2 = curr2->next;
            }
        }
        else if(curr1 == NULL && curr2 != NULL){
            new->value = curr2->value;
            curr2 = curr2->next;
        }
        else if(curr1 != NULL && curr2 == NULL){
            new->value = curr1->value;
            curr1 = curr1->next;
        }
        
        new_sordet->next = new;
        new_sordet = new_sordet->next;
    }

    return new_sordet_head;

}
//same as copy_list
Node *copy_list_recursivly(Node *head){
    if (head == NULL) return NULL;

    Node *new_Node = calloc(1, sizeof(Node));
    new_Node->value = head->value;
    new_Node->next = copy_list_recursivly(head->next);
    return new_Node;
}

Node *copy_list(Node *head){
    if (head == NULL) return NULL;
    else if (head->next == NULL){
        Node *new_list = calloc(1,sizeof(Node));
        new_list->next = NULL;
        new_list->value = head->value;
        return new_list;
    }
    
    Node *new_list = NULL;
    Node *new_list2;
    
    while(head != NULL){
        Node *new_Node = calloc(1,sizeof(Node));
        new_Node->value = head->value;

        if (new_list == NULL) {
            new_list = new_Node;
            new_list2 = new_list;
        }
        else{
            new_list->next = new_Node;
            new_list = new_list->next;
        }
        head = head->next;
    }

    return new_list2;
}
// add_values_recursivly ist ähnlich, doch add_values_recursivly ist "besser", weil kürzer;
void add_values_recursivly(Node *list1, Node *list2){
    if(list1 == NULL || list2 == NULL) return ;
    list1->value = list1->value + list2->value;
    add_values_recursivly(list1->next, list2->next);
}

Node *add_list_values(Node *list1, Node *list2){
    if(list1 == NULL && list2 == NULL) return NULL;

    Node *current1 = list1;
    Node *current2 = list2;
    Node *prev = list1;

    while(current1 != NULL && current2 != NULL){
        current1->value = current2->value + current1->value;

        prev = current1;
        current1 = current1->next;
        current2 = current2->next;
    }

    if (current1 == NULL && current2 != NULL){
        while (current2 != NULL){
            Node *new_node = calloc(1, sizeof(Node));
            new_node->value = current2->value;
            prev->next = new_node;
            
            current2 = current2->next;
            prev = prev->next;
        }
    }
    return list1;

}

Node *insert_once_after_value(Node *head, int search_value, int value){
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = value;
    if (head == NULL) return new_node;
    else{
        Node *current = head;
        while(current != NULL){
            if (current->value == search_value){
                Node *buffer = current->next;
                current->next = new_node;
                new_node->next = buffer;
                return head;
            }
            else current = current->next;
        }
        return head;
    }
}

void insert_after_value(Node *head, int search_value, int value){
    Node *current = head, *buffer;
    while(current != NULL){
        if (current->value == search_value){
            Node *new_node = calloc(1, sizeof(Node));
            buffer = current->next;

            new_node->value = value;
            current->next = new_node;
            new_node->next = buffer;
        }
        current = current->next;
    }
}

void remove_double(Node *head){
    if (head == NULL || head->next == NULL) return ;

    Node *current1, *current2, *duplicate;
    current1 = head;

    while(current1 != NULL && current1->next != NULL){
        current2 = current1;
        while(current2->next != NULL){
            if (current1->value == current2->next->value){
                duplicate = current2->next;
                current2->next = current2->next->next;
                free(duplicate);
            }else current2 = current2->next;
        }
        current1 = current1->next;
    }
    
}


void sort(Node *head){
    int i;
    if (head != NULL){
        do{
            i=0;
            Node *buf = head;
            while(buf->next != NULL){

                if (buf->value > buf->next->value){
                    int valbuff = buf->value;
                    buf->value = buf->next->value;
                    buf->next->value = valbuff;
                    i++;
                }
                buf = buf->next;
            }
        }while (i != 0);
    }
}

int searchlist(Node *head, int value_search){
    int i=1;
    while(head->value != value_search && head->next != NULL){
        head = head->next;
        i++; 
    }
    if(head->next != NULL){
        return i;
    }else{
        return 0;
    }
}

Node *reversing_list(Node *head){
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    Node *current = head;
    Node *next_node = head->next;

    current->next = NULL;
    while(next_node != NULL){
        Node *tmp = next_node->next;
        next_node->next = current;
        current = next_node;
        next_node = tmp;
    }
    return current;
}

Node *append_lists(Node *head1, Node *head2){
    if (head1 == NULL) return head2;
    Node *current = head1;
    while (current->next != NULL) current = current->next;
    current->next = head2;
    return head1;
}

Node *delete_all_matches(Node *head, int delete_value, bool *was_deleted){
     if (head == NULL){
        *was_deleted = false;
        return NULL;
     }
     
     
     Node *current = head;
     Node *prev = NULL;
     *was_deleted = false;
     while(head->value == delete_value){
        head = delete_at_head(head);
        prev = current;
        current = current->next;
        if (current == NULL) return NULL;
     }
     while (current != NULL){
        if (current->value == delete_value){
            if (current->next == NULL){
                prev->next = NULL;
                free(current);
                *was_deleted = true;
                return head;
            }else{
                prev->next = current->next;
                free(current);
                current = prev->next;
                *was_deleted = true;
            }
        }

        prev = current;
        current = current->next;
     }
     return head;

}

Node *delete_first_match(Node *head, int delete_value, bool *was_deleted){
    if (head == NULL){
        *was_deleted = false;
        return NULL;
    }

    if (head->value == delete_value){
        Node *temp = head->next;
        free(head);
        *was_deleted = true;
        return temp;
        
       //return delete_at_head(head);
    }
    Node *current = head->next;
    Node *prev = head;
    while (current != NULL){
        if (current->value == delete_value){
            prev->next = current->next;
            free(current);
            *was_deleted = true;
            //current = prev->next;
            return head;
        }
        prev = current;
        current = current->next;
    }
    *was_deleted = false;
    return head;
}

int count(Node *head, int value_search){
    if (head == NULL) return 0;
    else if (head->value == value_search) return 1 + count(head->next, value_search);
    else return count(head->next, value_search);
}

void replace(Node *head, int value, int replace_value){
    if (head != NULL){ 
        if (head->value == value) {
            head->value = replace_value;
        }
        replace(head->next, value, replace_value);
    }
}


int lenght(Node *head){
    return (head == NULL) ? 0 : 1 + lenght(head->next);
} 

Node *delete_at_head(Node *head){
    if (head == NULL){
        return NULL;
    }else{
        Node *buffer = head->next;
        free(head);
        return buffer;   
    }
}

Node *delete_at_tail(Node *head){
    if(head == NULL){
        return NULL;
    }else if (head->next == NULL){
        free(head);
        return NULL;
    }else{
        Node *buffer = NULL;
        Node *current = head;
        while (current->next != NULL){
            buffer = current;
            current = current->next;
        }
        buffer->next = NULL;
        free(current);
        return head;
    }
}

Node *insert_at_head(Node *head, int new_value){

    Node *new_node = calloc(1,sizeof(Node));
    new_node->value = new_value;
    if (head == NULL){
        return new_node;
    }else{
        new_node->next = head;
        return new_node;
    }

}

Node *insert_at_tail(Node *head, int new_value){
    Node *new_tail = calloc(1,sizeof(Node));
    new_tail->value = new_value;
    if(head == NULL){
        return new_tail;
    }else{
        Node *current = head;
        while(current->next != NULL){
            current = current->next; 
        }
        current->next = new_tail;
        return head;
    }

    //new_tail = NULL;
    //head->next = new_tail;
    //return new_tail;

}



void print_list(Node *head){
    Node *current;
    current = head;
    while(current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }
}
