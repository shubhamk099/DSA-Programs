
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1={1,2,3,4,5};
    vector<int> v2={6,7,8};
    vector<int> v3={9,10};

    vector<int> v;
    v = v1;
    v = v2;
    v = v3;

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}