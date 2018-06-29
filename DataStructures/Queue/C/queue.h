#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


const int QueueSize = 4;

typedef struct QueueArray{
    int data[QueueSize]; 
    int front;
    int back;

}queue;

void print_q(queue *q);

queue* create_queue();

// adds item at end of available storage
void enqueue(queue *q, int value);

// returns value and removes least recently added element
int dequeue(queue *q);

// true if queue is empy
bool empty(queue *q);

// true if queue is full
bool full(queue *q);

#endif


