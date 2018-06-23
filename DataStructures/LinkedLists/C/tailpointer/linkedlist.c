
ForwardList* init_List(){
    ForwardList *Flist = (ForwardList *) malloc(sizeof(ForwardList));
    Flist->head = NULL;
    Flist->tail = NULL;
    return Flist;
}

Node* init_node(int item){
    Node *node = ( Node *) malloc(sizeof(Node));    
    node->data = item;
    node->next = NULL;
    return node;
}
void print_list(ForwardList *Flist){
    Node *current = Flist->head;
    while(current->next){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("%d\n",current->data);
}

void push_back(ForwardList **Flist,int value){
    Node *node = init_node(value); 
    Node *current = (*Flist)->head;
    while(current){
        current = current->next;
    }
    current->next = node;
    (*Flist)->tail = node;

