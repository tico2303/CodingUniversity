#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct NodeStruct{
    int data;
    struct NodeStruct *next;
}Node;

// creates a pointer to node stuct with item
Node* init_node(int item);

// free's memory of list
void free_list(Node *head);

// prints list values
void print_list(Node *head);

// returns number of items in list
int size(Node *head);

// returns false if empty otherwise true
bool empty(Node *head);

// returns value at specifed index
int value_at(Node *head, int index);

// adds value to front of list
void push_front(Node **head, int item);

// returns element at front of list and removes it
int pop_front(Node **head);

// adds value to back of list
void push_back(Node **head,int value);

// returns element at back of list and removes it
int pop_back(Node **head);

// returns element at front of list
int front(Node *head);

// returns element at end of list
int back(Node *head);

// inserts value into specified index
void insert(Node **head,int index, int value);

// removes element by index
void erase(Node **head,int index);

// return the value that is index from the end
int value_n_from_end(Node *head,int n);

//reverses List
void reverse(Node **head);

// removes first item in list with value
void remove_value(Node **head,int value);

#endif
