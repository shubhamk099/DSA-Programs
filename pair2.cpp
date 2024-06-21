
#include<iostream>
using namespace std;

int main(){
    int a[] = {1,2,3,4,5};               // Normal two arrays
    char b[] = {'a','b','c','d','e'};

    pair<int,char> parray[5];              // Array of pairs
    parray[0] = {1,'a'};
    parray[1] = {2,'b'};
    parray[2] = {3,'c'};
    parray[3] = {4,'d'};
    parray[4] = {5,'e'};

    swap(parray[0],parray[4]);

    for(int i=0;i<5;i++){
        cout<<parray[i].first<<" "<<parray[i].second<<endl;
    }
    return 0;
}