#include "queue.h"
#include <assert.h>

void test_enqueue(){
    printf("Testing Enqueue..\n");
    queue *q = create_queue();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    print_q(q);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);
    print_q(q);
    free(q);
    printf("\n\n\n");
}

void test_dequeue(){
    printf("Testing Dequeue..\n");
    queue *q = create_queue();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    print_q(q);
    enqueue(q,40);
    /* print_q(q); */
    printf("removed:%d\n ", dequeue(q));
    printf("removed:%d\n ", dequeue(q));
    printf("removed:%d\n ", dequeue(q));
    free(q);
}

void test_empty(){
    queue *q = create_queue();
    enqueue(q,10);
    assert(empty(q) == false);
    dequeue(q);
    assert(empty(q) == true);
}

void test_full(){
    queue *q = create_queue();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    /* enqueue(q,40); */
    assert(full(q) == true);
}
