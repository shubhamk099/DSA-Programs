
// Program to print n numbers using recursion

#include<iostream>
using namespace std;

void printNumbers(int n){
    if(n>0){                            // Base Condition
        printNumbers(n-1);              // Function calling itself
        cout<<n<<" ";                   // Print numbers on returning time
    }
}

int main(){
    printNumbers(10);
    return 0;
}