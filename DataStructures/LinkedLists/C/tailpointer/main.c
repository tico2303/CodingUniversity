#include "test.h"
#include "test.c"
#include "linkedlist.h"
#include "linkedlist.c"
#include <stdio.h>

int main(void){
    test_print_list();
    test_push_back();
    
    printf("PASSED ALL TESTS!");
    return 0;
}

