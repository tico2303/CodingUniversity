#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct NodeStruct{
    int data;
    struct NodeStruct *next;
}Node;

typedef struct SinglyLinkedList{
    Node *head;
    Node *tail;
}ForwardList;

// creates a pointer to node stuct with item
ForwardList* init_List();

Node* init_node(int item);

// free's memory of list
void free_list(ForwardList *Flist);

// prints list values
void print_list(ForwardList *Flist);

// returns number of items in list
int size(ForwardList *Flist);

// returns false if empty otherwise true
bool empty(ForwardList *Flist);

// returns value at specifed index
int value_at(ForwardList *Flist, int index);

// adds value to front of list
void push_front(ForwardList **Flist, int item);

// returns element at front of list and removes it
int pop_front(ForwardList **Flist);

// adds value to back of list
void push_back(ForwardList **Flist,int value);

// returns element at back of list and removes it
int pop_back(ForwardList **Flist);

// returns element at front of list
int front(ForwardList *Flist);

// returns element at end of list
int back(ForwardList *Flist);

// inserts value into specified index
void insert(ForwardList **Flist,int index, int value);

// removes element by index
void erase(ForwardList **Flist,int index);

// return the value that is index from the end
int value_n_from_end(ForwardList *Flist,int n);

//reverses List
void reverse(ForwardList **Flist);

// removes first item in list with value
void remove_value(ForwardList **Flist,int value);


#endif
