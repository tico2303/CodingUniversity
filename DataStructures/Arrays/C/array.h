#ifndef ARRAY_H
#define ARRAY_H

const int GrowthFactor = 2;

struct MyArray{
  int size;
   int capacity;
   int *data;

};


void print_array(struct MyArray *arr);

struct MyArray* init_array(int cap);

int size(struct MyArray *arr);

int capacity(struct MyArray *arr);

int is_empty(struct MyArray *arr);

int at(struct MyArray *arr, int index);

void copy_array(struct MyArray *old, int *narr);

void push(struct MyArray *arr, int item);

void insert(struct MyArray *arr, int index, int item);

void prepend(struct MyArray *arr,int item);

int pop(struct MyArray *arr);

void delete(struct MyArray *arr,int index);

void rremove(struct MyArray *arr,int item);

int find(struct MyArray *arr,int item);

void test_find();

void test_remove();

void test_delete();

void test_pop();

void test_prepend();

void test_insert();

void test_at();

void test_init();

void* setup_test();

void test_struct();

#endif//ARRAY_H
