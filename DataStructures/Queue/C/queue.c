
void print_q(queue *q){
    /* printf("q->back:%d\n",q->back); */
    /* printf("q->front:%d\n",q->front); */
    for(int i=q->front; i != q->back; i=(i+1)%QueueSize){
        printf("%d:%d,",i,*(q->data + i) );
    }
    printf("\n");
}
queue* create_queue(){
    queue *q = malloc(sizeof(queue));
    for(int i =0; i< QueueSize; i++){
        q->data[i] = 0;
    }
    q->front = 0;
    q->back = 0;
    return q;
}

void enqueue(queue *q, int value){
    q->data[q->back] = value;
    q->back = (q->back +1) %QueueSize;
}

int dequeue(queue *q){
    int data = q->data[q->front];
    q->front = (q->front +1) %QueueSize; 
    q->data[q->front] = 0;
    return data;
}

bool empty(queue *q){
    return (bool)q->front == q->back;
}

bool full(queue *q){
    return q->front == (q->back+1)%QueueSize;
}

