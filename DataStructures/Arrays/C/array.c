#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

void print_array(struct MyArray *arr){
    printf("printing array:\n");
    for(int i=0; i < arr->capacity;i++){
        printf("%d:%d\n",i,arr->data[i]);
    }
}

struct MyArray* init_array(int cap){
    struct MyArray *arr;
    arr =  (struct MyArray *) malloc(sizeof(struct MyArray)); 
    arr->size = 0;
    arr->capacity = cap;
    arr->data = (int *) malloc(sizeof(int) * arr->capacity);
    memset(arr->data,0, sizeof(int) * arr->capacity);
    return arr;
}

int size(struct MyArray *arr){
    return arr->size;    
}

int capacity(struct MyArray *arr){
    return arr->capacity;
}

int is_empty(struct MyArray *arr){
    return 1;
}

int at(struct MyArray *arr, int index){
    if((arr->size -1) >= index){
        return  *(arr->data+index);
    }
    return -1;
}

void copy_array(struct MyArray *old, int *narr){
        for(int i=0; i<=old->size-1; i++){
            *(narr+i) = *(old->data+i);
        }
}

void resize(struct MyArray *arr){
       int *temp = (int *) malloc(sizeof(int)*(GrowthFactor * arr->capacity));
       memset(temp,0,GrowthFactor* sizeof(int)*arr->capacity);
       arr->capacity = GrowthFactor * arr->capacity;
       copy_array(arr, temp);
       free(arr->data);
       arr->data = temp;
}

void push(struct MyArray *arr, int item){
    if(arr->size == arr->capacity){resize(arr);}
    *(arr->data+arr->size) = item;
    arr->size +=1;

}

void insert(struct MyArray *arr, int index, int item){
    if(arr->size == arr->capacity){resize(arr);}
    if(index < arr->capacity ){
        for(int i = arr->size-1; i > index-1; i--){
            *(arr->data+i+1) = *(arr->data+i);   
        }
        *(arr->data+index) = item;
        arr->size +=1;
    }
}

void prepend(struct MyArray *arr,int item){
    insert(arr,0,item);
}

int pop(struct MyArray *arr){
    int r;
    r = *(arr->data+arr->size-1);
    *(arr->data +arr->size-1) = 0;
    arr->size --;
    return r;
}

void delete(struct MyArray *arr,int index){
    *(arr->data+index) = 0;
    for(int i=index; i <arr->size-1;i++){
        *(arr->data +i) = *(arr->data +i+1);
    }
    *(arr->data +arr->size-1) = 0;
    arr->size--;
}

void rremove(struct MyArray *arr,int item){
    int size = arr->size;
    for(int i=0; i < size; i++){
        if(*(arr->data+i) == item){
            delete(arr, i);
            i--;
        }
    }
}

int find(struct MyArray *arr,int item){
    for(int i=0; i<arr->size; i++){
        if(*(arr->data + i) == item){
            return i;
        }
    }
    return -1;
}

void test_struct(){
    struct MyArray *arr;
    arr->size = 2;
    arr->capacity = 40;
    printf("size is %d\n",size(arr)); 
    printf("capacity is %d\n",capacity(arr)); 
}
void* setup_test(){
    struct MyArray *arr;
    arr = init_array(5);
    push(arr,4);
    push(arr,5);
    push(arr,5);
    push(arr,6);
    push(arr,5);
    push(arr,7);
    push(arr,5);
    return arr;
}

void test_init(){
    struct MyArray *arr2;
    arr2 = init_array(16);
    print_array(arr2);
    printf("capacity is %d\n",capacity(arr2)); 
    printf("size is %d\n",size(arr2)); 
}
void test_at(){
    struct MyArray *arr;
    arr = init_array(2);
    push(arr,4);
    push(arr,5);
    print_array(arr);
    printf("element at index 0 is %d\n",at(arr,0)); 
    printf("element at index 1 is %d\n",at(arr,1)); 
    printf("extending array now...\n");
    push(arr,6);
    push(arr,7);
    printf("element at index 0 is %d\n",at(arr,0)); 
    printf("element at index 1 is %d\n",at(arr,1)); 
    printf("element at index 2 is %d\n",at(arr,2)); 
    printf("element at index 3 is %d\n",at(arr,3)); 
    print_array(arr);
}
void test_insert(){
    struct MyArray *arr;
    arr = init_array(2);
    printf("Testing insert\n");
    push(arr,4);
    push(arr,5);
    push(arr,6);
    print_array(arr);
    push(arr,7);
    print_array(arr);
    insert(arr,2,20);
    print_array(arr);
    printf("done calling insert\n");
}
void test_prepend(){
    struct MyArray *arr;
    arr = init_array(2);
    printf("Testing prepend\n");
    push(arr,4);
    push(arr,5);
    push(arr,6);
    prepend(arr,10);
    print_array(arr);
}
void test_pop(){
    struct MyArray *arr;
    arr = setup_test();
    printf("Testing pop\n");
    print_array(arr);
    printf("poped el: %d",pop(arr));
    print_array(arr);
}

void test_delete(){
    struct MyArray *arr;
    arr = setup_test();
    printf("Testing delete\n");
    print_array(arr);
    delete(arr,2);
    print_array(arr);
    
}

void test_remove(){
    struct MyArray *arr;
    arr = setup_test();
    printf("Testing remove\n");
    print_array(arr);
    rremove(arr,5);
    print_array(arr);
}
void test_find(){
    struct MyArray *arr;
    arr = setup_test();
    printf("Testing Find\n");
    print_array(arr);
    printf("found 5 at: %d\n",find(arr,5));
    printf("found 4 at: %d\n",find(arr,4));
    printf("found 7 at: %d\n",find(arr,7));
    printf("found 10 at: %d\n",find(arr,10));

}
