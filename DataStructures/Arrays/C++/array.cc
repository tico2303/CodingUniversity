#include "array.h"

template<class T>
Array<T>::Array(){
    this->size = 0;
    this->capacity = DEFAULT_CAPACITY;
    this->data = new T[DEFAULT_CAPACITY];
}
/*
template<class T>
Array<T>::Array(int cap){
    this->size = 0;
    this->capacity = cap;
    this->data = new T[capacity];
}
*/
template<class T>
Array<T>::~Array(){
    delete []this->data;    
}

template<class T>
T Array<T>::at(int index){
    assert(index < this->size);
    return *(this->data + index);
}
template<class T>
void Array<T>::push(T item){
    if(this->size == this->capacity){
        this->resize();
    }
    *(this->data + this->size) = item;
    this->size++;
}
template<class T>
void Array<T>::resize(){
    T *temp = new T[GROWTH_FACTOR * this->capacity]; 
    for(int i=0; i< this->size; i++){
        *(temp + i) = *(this->data +i);
    }
    delete []this->data;
    this->data = temp;
    this->capacity = GROWTH_FACTOR * this->capacity;

}
template<class T>
void Array<T>::print_array(){
    cout << "Printing Array:" << endl;
    for(int i=0; i< this->size; i++){
        cout << i << ":"<< *(this->data +i) << endl;
    }
    cout << endl;
}
template<class T>
void Array<T>::insert(int index, T item){
    assert((index <= this->size) and (index > -1));
    if(this->size == this->capacity){this->resize();} 
    for(int i=this->size; i> index;i--){
        *(this->data + i) = *(this->data + i-1 );
    }
    *(this->data +index) = item;
    this->size++;
}
template<class T>
void Array<T>::prepend( T item){
    this->insert(0,item);
}

template<class T>
T Array<T>::pop(){
    assert(this->size >0);
    T item = *(this->data);
    for(int i=0; i<this->size; i++){
        *(this->data +i) = *(this->data +i +1);
    }
    this->size--;
    return item;
}
template<class T>
T &Array<T>::operator[](int i){
    return *(this->data +i);
}



//////////// Tests ////////////
Array<int>* setup(){
    Array<int> *arr = new Array<int>();
    return arr;
}
void test_Array(){
    Array<int> *arr = setup(); 
    cout << arr->get_size() << endl;
}
bool test_push(){
    Array<int> *arr = setup();
    arr->push(2);
    arr->push(3);
    arr->push(4);
    arr->print_array();
    if(arr->get_size() !=3){return false;}
    if(arr->at(0) != 2){return false;}
    if(arr->at(1) != 3){return false;}
    if(arr->at(2) != 4){return false;}
    return true;

}
bool test_insert(){
    Array<int> *arr = setup();
    arr->insert(0,10);
    arr->insert(1,20);
    arr->insert(2,30);
    arr->insert(3,40);
    arr->insert(0,1);
    arr->print_array();
    if(arr->get_size() != 5){return false;}
    if(arr->at(0) != 1) {return false;}
    if(arr->at(2) != 20){return false;}
    if(arr->at(3) != 30){return false;}
    if(arr->at(4) != 40){return false;}
    return true;
}
bool test_resize(){
    Array<int> *arr = setup();
    int test_max = 20;
    for(int i=0; i< test_max; i++){
        arr->push(i);
    }
    /* arr->print_array(); */
    cout << "Capacity: "<< arr->get_capacity() << endl;
    /* cout << "size is : " << arr->get_size() << endl; */
    if(arr->get_capacity() != 32){return false;}
    if(arr->get_size() != test_max){return false;}
    return true;
}
bool test_pop(){
    Array<int> *arr = setup();
    int test_max = 3;
    for(int i=0; i< test_max; i++){
        arr->push(i);
    }
    if(arr->get_size() != test_max){return false;}
    if(arr->pop() != 0){return false;}
    if(arr->get_size() != test_max-1){return false;}
    if(arr->pop() != 1){return false;}
    if(arr->get_size() != test_max-2){return false;}
    if(arr->pop() != 2){return false;}
    return true;
}
bool test_subscript_op(){
    int test_max = 3;
    Array<int> arr = Array<int>();
    for(int i=0; i< test_max; i++){
        arr.push(i);
    }
    
    if(arr[0] != 0){return false;}
    if(arr[1] != 1){return false;}
    if(arr[2] != 2){return false;}

    return true;


}

