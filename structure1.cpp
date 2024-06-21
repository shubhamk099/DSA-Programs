
#include<iostream>
using namespace std;

struct Rectangle{
    private:
    int length;
    int bredth;
    public:
    Rectangle(int l,int b){
        length = l; bredth = b;
    }
    int perimeter();
    int area();
};


int Rectangle::perimeter(){
    return 2*(length+bredth);
}

int Rectangle::area(){
    return length*bredth;
}

int main(){
    Rectangle R1(3,5);
    cout<<R1.area()<<endl;
    cout<<R1.perimeter()<<endl;
    return 0;
}