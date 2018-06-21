#include "test.h"
#include "linkedlist.h"
#include "linkedlist.c"

bool test_size(){
    return true;
}

bool test_push_front(){
    Node *head = NULL;
    push_front(&head, 2);
    push_front(&head, 4);
    push_front(&head, 6);
    print_list(head);
    return true;
}

bool test_push_back(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
    print_list(head);
    return true;
}

