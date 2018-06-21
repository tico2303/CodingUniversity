#include "linkedlist.h"

Node* init_node(int item){
       Node *node = (Node *) malloc(sizeof(Node));
       node->data = item;
       node->next = NULL;
       return node;
}
void print_list(Node *head){
    if(head == NULL){printf("Head is NULL\n");}
    else{
        Node* nptr = head;
        while(nptr){
            printf("%d ->", nptr->data);
            nptr = nptr->next;
        }
        printf("\n");
    }
    printf("Done printing\n");
}
void print_list_2star(Node **head){
    if(*head == NULL){printf("Head is NULL\n");}
    else{
        Node* nptr = *head;
        while(nptr){
            printf("%d ->", nptr->data);
            nptr = nptr->next;
        }
        printf("\n");
    }
    printf("Done printing\n");
}

int size(Node *head){
    if(head == NULL){
       return 0;
    }
    else{
        int size=0;
        Node *nptr = head;
        while(nptr->next != NULL){
            size++; 
            nptr = nptr->next;
        }
        return size;
    }
}

void push_front(Node **head, int item){
    Node *node = init_node(item);
    node->next = *head;
    *head = node;
    print_list(*head);
}
void push_back(Node **head, int item){
    if(!*head){
        *head = init_node(item);
    }
    else
    {
        Node *current = *head;
        while(current->next){
            current = current->next;
        }
        current->next = init_node(item);
    }
}




