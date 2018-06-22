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
    if(size(head) != 3){return false;}
    /* if(value_at(head, 0) != 2){return false;} */
    /* if(value_at(head, 1) != 4){return false;} */
    /* if(value_at(head, 2) != 6){return false;} */
    /* print_list(head); */
    return true;
}

bool test_push_back(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
    if(size(head) != 4){return false;}
    if(value_at(head, 0) != 2){return false;}
    if(value_at(head, 1) != 3){return false;}
    if(value_at(head, 2) != 4){return false;}
    if(value_at(head, 3) != 5){return false;}
    /* print_list(head); */
    return true;
}

bool test_empty(){
    Node *head = NULL;
    if(empty(head) == false){return false;}
    return true;
}
bool test_value_at(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
    if(size(head) != 4){return false;}
    if(value_at(head, 0) != 2){return false;}
    if(value_at(head, 1) != 3){return false;}
    if(value_at(head, 2) != 4){return false;}
    if(value_at(head, 3) != 5){return false;}
    return true;
}
bool test_pop_front(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
    if(size(head) != 4){return false;}
    if(pop_front(&head) != 2){return false;}
    if(pop_front(&head) != 3){return false;}
    return true;
}

bool test_pop_back(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
    
    if(size(head) != 4){return false;}
    if(pop_back(&head) != 5){return false;}
    if(pop_back(&head) != 4){return false;}
    if(pop_back(&head) != 3){return false;}
    if(pop_back(&head) != 2){return false;}
    /* pop_back(&head); */

    return true;
}


bool test_front(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
    
    if(size(head) != 4){return false;}
    if(front(head)!=2){return false;} 
    pop_front(&head);
    if(front(head)!=3){return false;} 
    pop_front(&head);
    pop_front(&head);
    if(front(head)!=5){return false;} 
    return true;
}
bool test_back(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
    
    if(back(head) != 5){return false;}
    if(size(head) != 4){return false;}
    return true;
}


bool test_insert(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);

   
    insert(&head, 2,10);
    if(value_at(head,2) != 10){return false;}

    insert(&head, 4,20);
    if(value_at(head,4) != 20){return false;}

    insert(&head, 0,100);
    if(value_at(head,0) != 100){return false;}

    insert(&head, 7,200);
    if(value_at(head,7) != 200){return false;}

    return true;
}

bool test_erase(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);

    erase(&head, 0);
    erase(&head, 2);
    erase(&head, 0);
    erase(&head, 0);
    return true;
}

bool test_value_n_from_end(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);
    if(value_n_from_end(head, 1) != 4){return false;} 
    if(value_n_from_end(head, 0) != 5){return false;} 
    if(value_n_from_end(head, 2) != 3){return false;} 

    return true;
}
bool test_reverse(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);

    /* print_list(head); */
    /* printf("Reversing Linked List...\n"); */
    reverse(&head);
    return true;
}

bool test_remove_value(){
    Node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);

    remove_value(&head,4);
    if(value_at(head,2) != 5){return false;}

    remove_value(&head,2);
    if(value_at(head,0) != 3){return false;}

    remove_value(&head,5);
    if(size(head) != 1){return false;}

    return true;
}


