#include "array.h"
#include "array.cc"

int main(){
    
    assert(test_resize());
    cout << "Test Resize Passed" << endl;
    
    assert(test_insert());
    cout << "Test Insert Passed" << endl;

    assert(test_push());
    cout << "Test Push Passed" << endl;
   
    assert(test_pop());
    cout << "Test Pop Passed" << endl;
    
    assert(test_subscript_op());
    cout << "Test Subscript Operator Passed" << endl;
    cout << "[+] PASSED ALL TESTS [+]" << endl;
    return 0;
}
