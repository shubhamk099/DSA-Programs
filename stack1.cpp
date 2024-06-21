
// Stack Implementation using Arrays

#include<iostream>
using namespace std;

class Stack{
    private:
    int size;
    int *array;
    int top;
    public:
    Stack(int);
    void Push(int);
    int Pop();
    int Peek(int);
    int StackTop();
    bool IsEmpty();
    bool IsFull();
    void Display();
};


Stack::Stack(int n){
    size = n;
    array = new int[size];
    top = -1;
}

bool Stack::IsFull(){
    if(size-1==top)
    return true;

    return false;
}

bool Stack::IsEmpty(){
    if(top==-1)
    return true;

    return false;
}

void Stack::Push(int value){
    if(IsFull())
    return;

    top++;
    array[top] = value;
}

int Stack::Pop(){
    int x = -1;
    if(IsEmpty())
    return -1;
    else{
    x = array[top];
    top--;
    }
    return x;
}

int Stack::StackTop(){
    if(IsEmpty())
    return -1;

    return array[top];
}

int Stack::Peek(int pos){
    int x = -1;
    if(IsEmpty() || pos<=0)
    return x;

    if(top-pos+1>=0)
    return array[top-pos+1];

    return -1;
}

void Stack::Display(){
    if(IsEmpty())
    return;

    for(int i=0;i<=top;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Stack S1(5);
    while(1){
        int choice;
        cout<<"\n1. Push";
        cout<<"\n2. Pop";
        cout<<"\n3. Peek";
        cout<<"\n4. StackTop";
        cout<<"\n5. IsEmpty";
        cout<<"\n6. IsFull";
        cout<<"\n7. Display";
        cout<<"\n8. Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
            int temp1;
            if(S1.IsFull())
            cout<<"\nCan't push more elements, stack is Full !\n";
            else{
            cout<<"\nEnter the element you want to push : ";
            cin>>temp1;
            S1.Push(temp1);
            }
            break;

            case 2:
            int popedValue;
            popedValue = S1.Pop();
            if(popedValue!=-1)
            cout<<"\nPoped element : "<<popedValue;
            else
            cout<<"\nStack is Empty !";
            break;

            case 3:
            if(S1.IsEmpty())
            cout<<"\nStack is Empty !";
            else{
            int temp2;
            cout<<"\nEnter the position of element you want : ";
            cin>>temp2;
            if(S1.Peek(temp2)!=-1)
            cout<<"\nElement at position "<<temp2<<" is : "<<S1.Peek(temp2);
            else
            cout<<"\nInvalid Index";
            }
            break;
            
            case 4:
            if(S1.StackTop()!=-1)
            cout<<"\nElement at stack top : "<<S1.StackTop();
            else
            cout<<"\nStack is Empty !";
            break;

            case 5:
            if(S1.IsEmpty())
            cout<<"\nStack is Empty !";
            else
            cout<<"\nStack is not Empty";
            break;

            case 6:
            if(S1.IsFull())
            cout<<"\nStack is Full !";
            else
            cout<<"\nStack is not Full";
            break;

            case 7:
            if(S1.IsEmpty())
            cout<<"\nStack is Empty !";
            else{
            cout<<"\nElements in stack are : ";
            S1.Display();
            }
            break;

            case 8:
            exit(1);

            default:
            cout<<"\nInvalid Choice !";
            break;

        }

    }
}

