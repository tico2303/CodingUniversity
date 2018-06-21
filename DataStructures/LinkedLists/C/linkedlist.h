#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct NodeStruct{
    int data;
    struct NodeStruct *next;
}Node;

Node* init_node(int item);

void print_list(Node *head);

int size(Node *head);

bool empty(Node *head);

int value_at(Node *head, int index);

void push_front(Node **head, int item);

int pop_front(Node **head);

void push_back(Node **head,int value);

int pop_back(Node **head);

int front(Node *head);

int back(Node *head);

void insert(Node **head,int index, int value);

void erase(Node **head,int index);

void value_n_from_end(Node *head,int n);

void reverse(Node *head);

void remove_value(Node *head,int value);

#endif
