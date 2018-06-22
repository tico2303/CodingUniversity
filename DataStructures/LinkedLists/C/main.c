#include "test.h"
#include "test.c"

int main(void){
    
    assert(test_value_at());
    assert(test_push_front());
    assert(test_push_back());
    assert(test_empty());
    assert(test_pop_front());
    assert(test_pop_back());
    assert(test_front());
    assert(test_back());
    assert(test_insert());
    assert(test_erase());
    assert(test_value_n_from_end());
    assert(test_reverse());
    assert(test_remove_value());
    
    printf("PASSED ALL TESTS\n");
    return 0;
}
