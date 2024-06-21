
// Pairs in C++ STL

#include<iostream>
using namespace std;

int main(){
    pair<int,string> p;             // To declare a pair
    p = make_pair(2,"Hello");       // To assign value to a pair
    p = {123,"Hello Again"};        // Can also assign values like this
    cout<<p.first;                  // Access pair values
    cout<<p.second;   
    pair<int,string> &q = p;        // Can copy one pair to another ( here using reference)
    return 0;
}

 