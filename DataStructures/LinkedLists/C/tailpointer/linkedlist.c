
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
    if(Flist->head == NULL){printf("Head is NULL\n");}
    else{
        Node *current = Flist->head;
        while(current->next){
            printf("%d->",current->data);
            current = current->next;
        }
        printf("%d\n",current->data);
    }
}
void print_nodes(Node *head){
    Node *current = head;
    while(current->next){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("%d\n",current->data);

}
void push_back(ForwardList **Flist,int value){
    Node *node = init_node(value); 
    if((*Flist)->head == NULL){
        (*Flist)->head = node;
        (*Flist)->tail = node;
    }
    else{
        Node *current = (*Flist)->tail;
        current->next = node;
        (*Flist)->tail = node;
    }
}
int size(ForwardList *Flist){
    Node *current = Flist->head;
    int sz = 0;
    while(current){
        sz++; 
        current = current->next;
    }
    return sz;
}
bool empty(ForwardList *Flist){
    return Flist->head == NULL;
}

int value_at(ForwardList *Flist, int index){
    assert(index <= size(Flist)-1);
    Node *current = Flist->head;
    int i=0;
    int data = 0;
    while(current){
        if(i == index){
            data = current->data;
            break;
        }
        current = current->next;
        i++;
    }
    return data;
}

void push_front(ForwardList **Flist, int item){
    Node *node = init_node(item); 
    node->next = (*Flist)->head;
    (*Flist)->head = node;
}

int pop_front(ForwardList **Flist){
    assert((*Flist)->head != NULL);
    Node *front = (*Flist)->head;
    int data = front->data;
    if( (*Flist)->head->next){
        (*Flist)->head = (*Flist)->head->next;
    }
    else{
        (*Flist)->head = NULL;
    }
    free(front);
    return data;
}

int pop_back(ForwardList **Flist){
    assert( (*Flist)->head != NULL);
    Node *back = (*Flist)->tail;
    Node *current = (*Flist)->head;
    Node *prev = NULL;
    while(current->next)
    {
        prev = current;
        current = current->next;
    }
    int data = back->data; 
    (*Flist)->tail = prev;
    if(prev){prev->next = NULL;}
    free(back);
    return data;
}

int front(ForwardList *Flist){
    return Flist->head->data;
}

int back(ForwardList *Flist){
    return Flist->tail->data;
}

void insert(ForwardList **Flist,int index, int value){
    if(index == size(*Flist)){ push_back(Flist,value); }
    else{
        Node *node = init_node(value); 
        Node *current = (*Flist)->head;
        Node *prev = NULL;
        int i = 0;
        while(i < index){
            if(i == index){ break; }
            prev = current;
            current = current->next;
            i++;
        }
        if(current == (*Flist)->head){ (*Flist)->head = node; }
        node->next = current;
        if(prev){ prev->next = node; }
    } 
}
void erase(ForwardList **Flist,int index){
    assert( (*Flist)->head != NULL );
    assert( index <= size(*Flist) );
    Node *current = (*Flist)->head;
    Node *prev = NULL;
    int i=0;
    while(i < index){
        if(i == index){ break; }
        prev = current;
        current = current->next;
        i++;
    }
    if(prev){prev->next = current->next;}
    else{
        (*Flist)->head = current->next;
    }
    if( (*Flist)->tail == current){ (*Flist)->tail = prev;}
    free(current);

}
int value_n_from_end(ForwardList *Flist,int n){
    assert( Flist->head != NULL );
    int index = size(Flist)-1 -n; 
    int i = 0;
    int data = -1;
    Node *current = Flist->head;
    while(i < index){
        if(i == index){ break; }
        current = current->next;
        i++;
    } 
    data = current->data;
    return data;
    
}
void reverse(ForwardList **Flist){
    assert((*Flist)->head != NULL);
    Node *current = (*Flist)->head;
    Node *next = (*Flist)->head;
    Node *prev = NULL;
    while(current->next){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current->next = prev;
    (*Flist)->tail = (*Flist)->head;
    (*Flist)->head = current;
}
void remove_value(ForwardList **Flist,int value){
    Node *current = (*Flist)->head;
    Node *prev = NULL;
    while(current){
        if(current->data == value){
           break;
        }
        prev = current;
        current = current->next;
    }
    if(current == (*Flist)->head){ (*Flist)->head = current->next; }
    if(prev){prev->next = current->next;} 
    free(current);
}
