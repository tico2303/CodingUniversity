#include "array.h"

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
    push(arr,5);
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
int main(void){
    /* test_struct(); */
    /* test_init(); */
    /* test_at(); */
    /* test_insert(); */
    /* test_prepend(); */
    /* test_pop(); */
    /* test_delete(); */
    test_remove();
    

    return 0;
}
