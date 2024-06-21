
// Program to print n numbers using recursion

#include<iostream>
using namespace std;

void printNumbers(int n){
    if(n>0){                                // Base Condition
        cout<<n<<" ";                    // Print numbers on calling time
        printNumbers(n-1);              // Function calling itself                   
    }
}

int main(){
    printNumbers(10);
    return 0;
}