#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

int main(){
    vector<int> vec;
    auto x='A';

    int size=10;
    for(int i=0; i<size; i++){
        vec.push_back(i);
    }
    for(auto v: vec)
        cout << v << endl;
    return 0;
}
