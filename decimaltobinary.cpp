

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> Conversion(int n){
    vector<int> v;
    int r;
    for(int i = n;i!=0;i=i/2){
        r = i%2;
        v.push_back(r);
    }
    reverse(v.begin(),v.end());
    return v;
}


int main(){
    int num = 9;
    cout<<"Binary of "<<num<<" is : ";
    vector<int> binary = Conversion(num);
    for(int i=0;i<binary.size();i++){
        cout<<binary[i];
    }
    cout<<endl;
    return 0;
}