#include "linkedlist.h"
#include <assert.h>

Node* init_node(int item){
       Node *node = (Node *) malloc(sizeof(Node));
       node->data = item;
       node->next = NULL;
       return node;
}
void free_list(Node *head){
    Node *prev;
    while(head->next){
       prev = head;
       head = head->next;
       free(prev);
    }
}
void print_list(Node *head){
    if(head == NULL){printf("Head is NULL\n");}
    else{
        Node* nptr = head;
        while(nptr->next){
            printf("%d->", nptr->data);
            nptr = nptr->next;
        }
        printf("%d\n",nptr->data);
    }
    printf("\n");
}

int size(Node *head){
    if(head == NULL){
       return 0;
    }
    else{
        int size=0;
        Node *nptr = head;
        while(nptr){
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

bool empty(Node *head){
    return head == NULL;
}

int value_at(Node *head, int index){
    assert(size(head)>=index);
    Node *current = head;
    int i=0;
    while(i<index){
        current = current->next;
        i++; 
    }
    return current->data;
}

int pop_front(Node **head){
    Node *front = *head;
    int data = front->data;
    *head = front->next;
    free(front);
    return data;
}

int pop_back(Node **head){
    assert(*head != NULL);
    Node *back = *head;
    Node *prev = NULL;
    while(back->next){
        prev = back;
        back = back->next;
    }
    
    int data = back->data;
    free(back);
    if(prev){
        prev->next = NULL;
    }
    else{
        *head = NULL;
    }
    return data;
}

int front(Node *head){
    assert(head != NULL);
    return head->data; 
}
int back(Node *head){
    assert(head != NULL); 
    Node *back = head;
    while(back->next){back=back->next;}
    return back->data;
}

void insert(Node **head, int index, int value){
    if(index == 0){push_front(head, value);return; }
    if(index == (size(*head))){push_back(head, value);return;}
    Node *node = init_node(value);
    Node *current = *head;
    Node *prev = NULL;
    int i=0;
    while(i<index){
        prev = current;
        current = current->next;
        i++;
    }
    node->next = current;
    if(prev){prev->next = node;}
}
void erase(Node **head,int index){
    assert(*head != NULL);
    assert(index <size(*head));
    Node *current = *head;
    if(index == 0){
       *head = current->next;
        free(current);
        return;
    }
    Node *prev = NULL;
    int i=0;
    while(i<index){
        prev = current;
        current = current->next;
        i++;
    }
    prev->next = current->next;
    free(current);
}

int value_n_from_end(Node *head,int n){
    int index = size(head)-1 - n;
    int i=0;
    Node *current = head;
    while(i<index){
        current = current->next;
        i++;
    }
    return current->data;
}

void reverse(Node **head){
    assert(*head != NULL);
    Node *current = *head;
    Node *next = *head;
    Node *prev = NULL;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void remove_value(Node **head,int value){
    assert(*head != NULL);
    Node *current = *head;
    Node *prev = NULL;
    while(current){
        if(current->data == value){
            if(prev){prev->next = current->next;}
            else{*head = current->next;}
            free(current);
        }
        prev = current;
        current = current->next;
    }
}


