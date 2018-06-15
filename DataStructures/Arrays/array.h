#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int GrowthFactor = 2;

struct MyArray{
  int size;
   int capacity;
   int *data;

};

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




