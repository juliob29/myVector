#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <set>
#include "vec.h"
using namespace std;

int main(int argc, char** argv) {

    Vector<int> x; 
    
    for (int i = 0; i < 10; i++) { x.push (i); }
    
    vector<char> normal;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        normal.push_back(ch);
    }

    /* Implementing begin and end members, so range based for loop also works. */
    for (int elem : x) {
        cout << elem << endl;
    }

    /* Operator Overload works here */ 
    cout << x[0] << endl;

    /* Seems like you can access the normal and end iterators with std::begin() or just
       calling the .begin() and .end() functions from the collections. (std::begin() wraps that)
     */ 

    // for (auto i = normal.begin(); i < normal.end(); i++) {
    //     cout << *i << endl;
    // }

    // for (auto i = begin(normal); i < end(normal); i++) {
    //     cout << *i << endl;
    // }

    
    

    return 0;
} 