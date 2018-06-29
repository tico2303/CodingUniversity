#include "test.c"
#include "test.h"
#include "queue.h"
#include "queue.c"

int main(void){
    test_enqueue();
    test_dequeue();
    test_empty();
    test_full();
    printf("All Tests PASSED!\n");
}
