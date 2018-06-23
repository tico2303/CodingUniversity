
void test_push_back(){
    ForwardList *list = init_List();    
    push_back(&list,10);
    print_list(list);
}

void test_print_list(){
    ForwardList *list = init_List();    
    Node *node1 = init_node(10);
    Node *node2 = init_node(20);
    list->head = node1;
    list->tail = node2;
    list->head->next = list->tail;
    print_list(list);
}


