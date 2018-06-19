#ifndef ARRAY_H
#define ARRAY_H

#define DEFAULT_CAPACITY 16
#define GROWTH_FACTOR 2

#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

template <class T>
class Array{

    private:
    int size;
    int capacity;
    T *data;
    void resize();

    public:
    Array();
    Array(int cap);
    ~Array();
    
    T at(int index);
    void push(T item);
    bool is_empty(){return this->size == 0;}
    void print_array();
    void insert(int index, T item);
    void prepend(T item);
    T pop();
    T &operator[](int i);

    //Accessor
    int get_size(){return this->size;}
    int get_capacity(){return this->capacity;}

};
//Tests
void test_Array();
bool test_push();
Array<int>* setup();
bool test_insert();
bool test_pop();



#endif//ARRAY_H

