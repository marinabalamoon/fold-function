//
//  main.cpp
//  fold function
//
//  Created by Marina Balamoon on 3/6/26.
//

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int fold(vector<int>& v, int (*f)(int, int), int index = 0){
    if(index == v.size() - 1){
        return v[index];
    }
    else{
        return f(v[index], fold(v, f, index + 1));
    }
}
int add(int a, int b){
    return a + b;
}
int multiply(int a, int b){
    return a * b;
}
int maxValue(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}
int minValue(int a, int b){
    if (a < b){
        return a;
    }
    return b;
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    assert(fold(v, add) == 10);
    assert(fold(v, multiply) == 24);
    assert(fold(v, maxValue) == 4);
    assert(fold(v, minValue) == 1);
    
    cout << "Asserts Passed!" << endl;
}
