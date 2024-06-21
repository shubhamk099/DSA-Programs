

// Program to access matrix from bottom to top

#include<iostream>
using namespace std;

int main(){
    int array[4][4];

    cout<<"Enter array elements : ";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>array[i][j];
        }
    }

    for(int i=4-1;i>=0;i--){
        for(int j=4-1;j>=0;j--){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}