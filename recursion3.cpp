

// Program to print sum of first n natural numbers using recursion

#include<iostream>
using namespace std;

int sumNumbers(int n){
    if(n==0)
    return 0;
    return n + sumNumbers(n-1);
}

int factNumber(int n){
    if(n==1)
    return 1;
    return n*factNumber(n-1);
}

int powerNumber(int m,int n){
    if(n==0)
    return 1;
    return m*powerNumber(m,n-1);
}

int main(){
    cout<<sumNumbers(10)<<endl;
    cout<<factNumber(5)<<endl;
    cout<<powerNumber(2,5)<<endl;
    return 0;
}