#include "test.h"
#include "test.c"
#include "linkedlist.h"
#include "linkedlist.c"
#include <stdio.h>

int main(void){
    test_print_list();
    test_push_back();
    test_size();
    test_empty();
    test_value_at();
    test_push_front();
    test_pop_front();
    test_pop_back();
    test_front();
    test_back();
    test_insert();
    test_erase();
    test_value_n_from_end();
    test_reverse();
    test_remove_value();
    
    printf("PASSED ALL TESTS!\n");
    return 0;
}

