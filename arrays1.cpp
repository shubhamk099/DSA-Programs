

// Program to take input in array and print it

#include<iostream>
using namespace std;

int main(){
    int array[10];
    cout<<"\nEnter 10 numbers : ";
    for(int i=0;i<10;i++){
        cin>>array[i];
    }
    cout<<"\nEntered numbers are : ";
    for(int i=0;i<10;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}