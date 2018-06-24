#include "linkedlist.h"
#include <assert.h>

void test_size(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    assert(size(list) == 1);
    push_back(&list,20);
    assert(size(list) == 2);
    push_back(&list,30);
    push_back(&list,40);
    assert(size(list) == 4);
}

void test_push_back(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    push_back(&list,40);
    /* print_list(list); */
}

void test_print_list(){
    ForwardList *list = init_List();    
    Node *node1 = init_node(1);
    Node *node2 = init_node(2);
    list->head = node1;
    list->tail = node2;
    list->head->next = list->tail;
}

void test_empty(){
    ForwardList *list = init_List();    
    assert(empty(list) == true);
    push_back(&list,10);
    assert(empty(list) == false);
}

void test_value_at(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    push_back(&list,40);
    assert(value_at(list, 0) == 10);
    assert(value_at(list, 2) == 30);
    assert(value_at(list, 1) == 20);
    assert(value_at(list, 3) == 40);
}

void test_push_front(){
    ForwardList *list = init_List();    
    push_front(&list, 11);
    push_front(&list, 12);
    push_front(&list, 13);
    push_front(&list, 14);
    /* print_list(list); */
}
void test_pop_front(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    /* print_list(list); */
    assert(pop_front(&list) == 10);
    /* print_list(list); */
    assert(pop_front(&list) == 20);
    /* print_list(list); */
    assert(pop_front(&list) == 30);
    /* print_list(list); */
}

void test_pop_back(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    /* print_list(list); */
    assert(pop_back(&list) == 30);
    /* print_list(list); */
    assert(pop_back(&list) == 20);
    /* print_list(list); */
    assert(pop_back(&list) == 10);
}

void test_front(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    /* print_list(list); */
    assert(front(list) == 10);
    pop_front(&list);
    assert(front(list) == 20);
    pop_front(&list);
    assert(front(list) == 30);
}

void test_back(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    /* print_list(list); */
    assert(back(list) == 30);
    pop_back(&list);
    assert(back(list) == 20);
    pop_back(&list);
    assert(back(list) == 10);
}

void test_insert(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    push_back(&list,40);

    /* print_list(list); */
    insert(&list,1,11);
    /* print_list(list); */
    insert(&list,0,100);
    insert(&list,5,55);
    /* print_list(list); */
    insert(&list,7,77);
    /* print_list(list); */
}
void test_erase(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    push_back(&list,40);
    /* print_list(list); */
    erase(&list, 0);
    assert(size(list) == 3);
    /* print_list(list); */
    erase(&list, 2);
    assert(size(list) == 2);
    /* print_list(list); */
}
void test_value_n_from_end(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    push_back(&list,40);
    /* print_list(list); */
    assert(value_n_from_end(list, 0) == 40);
    assert(value_n_from_end(list, 1) == 30);
    assert(value_n_from_end(list, 2) == 20);
    assert(value_n_from_end(list, 3) == 10);

}
void test_reverse(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    push_back(&list,40);

    /* print_list(list); */
    reverse(&list);
    assert(value_at(list, 0) == 40);
    assert(value_at(list, 3) == 10);
    /* print_list(list); */
}
void test_remove_value(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    push_back(&list,20);
    push_back(&list,30);
    push_back(&list,30);
    push_back(&list,40);

    /* print_list(list); */
    remove_value(&list, 10);
    assert(value_at(list, 0) == 20);
    remove_value(&list, 30);
    assert(value_at(list, 1) == 30);
    assert(value_at(list, 2) == 40);
    /* print_list(list); */
}
