
// Implementation of stack using LinkedList


#include<iostream>
using namespace std;

class Node{
    public:
    char data;
    Node *next;
    Node(){
        data = 0;
        next = NULL;
    }
};

class Stack{
    private:
    Node *top;
    public:
    Stack();
    void Push(char);
    char Pop();
    int Peek(int);
    void Display();
    bool IsEmpty();
    bool IsFull();
    int StackTop();
    bool ParanthesisMatching(string);
};


Stack::Stack(){
    top = NULL;
}

void Stack::Push(char value){
    Node *newnode = new Node;
    if(newnode==NULL)
    return;

    newnode->data = value;
    if(top==NULL){
        top = newnode;
    }
    else{
        newnode->next = top;
        top = newnode;
    }
}

char Stack::Pop(){
    char x = '\0';
    if(top==NULL)
    return x;

    Node *del = top;
    x = del->data;
    top = top->next;
    del->next = NULL;
    delete del;
    return x;
}

void Stack::Display(){
    if(top==NULL)
    return;

    Node *temp = top;
    while(temp){
        cout<<(temp->data)<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool Stack::IsFull(){
    Node *testNode = new Node;
    if(testNode==NULL)
    return true;
    return false;
}

bool Stack::IsEmpty(){
    if(top==NULL)
    return true;
    return false;
}

int Stack::StackTop(){
    if(top==NULL)
    return -1;
    return (top->data);
}

int Stack::Peek(int pos){
    if(pos<=0)
    return -1;

    int count = 0;
    Node *temp = top;
    while(temp){
        count++;
        if(count == pos)
        break;
        temp=temp->next;
    }

    if(temp==NULL)
    return -1;
    else
    return (temp->data);
}

bool Stack::ParanthesisMatching(string exp){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(')
        Push('(');
        else if(exp[i]==')'){
            if(IsEmpty())
            return false;
            Pop();
        }
    }
    return IsEmpty();
}

int main(){
    Stack S1;
    // while(1){
    //     int choice;
    //     cout<<"\n1. Push";
    //     cout<<"\n2. Pop";
    //     cout<<"\n3. Peek";
    //     cout<<"\n4. StackTop";
    //     cout<<"\n5. IsEmpty";
    //     cout<<"\n6. IsFull";
    //     cout<<"\n7. Display";
    //     cout<<"\n8. Exit\n";
    //     cout<<"\nEnter your choice : ";
    //     cin>>choice;
    //     switch(choice){
    //         case 1:
    //         if(S1.IsFull())
    //         cout<<"\nStack Overflow !";
    //         else{
    //             int num1;
    //             cout<<"\nEnter the element you want to push : ";
    //             cin>>num1;
    //             S1.Push(num1);
    //         }
    //         break;

    //         case 2:
    //         if(S1.IsEmpty())
    //         cout<<"\nStack Underflow !";
    //         else{
    //             int popedvalue;
    //             popedvalue = S1.Pop();
    //             cout<<"\nPoped Element : "<<popedvalue;
    //         }
    //         break;

    //         case 3:
    //         if(S1.IsEmpty())
    //         cout<<"\nStack is Empty !";
    //         else{
    //             int num2;
    //             cout<<"\nEnter the position of element : ";
    //             cin>>num2;
    //             if(S1.Peek(num2)==-1)
    //             cout<<"\nInvalid Position";
    //             else{
    //                 cout<<"\nElement is : "<<S1.Peek(num2);
    //             }
    //         }
    //         break;

    //         case 4:
    //         if(S1.IsEmpty())
    //         cout<<"\nStack is Empty !";
    //         else{
    //             cout<<"\nStack top element is : "<<S1.StackTop();
    //         }
    //         break;

    //         case 5:
    //         if(S1.IsEmpty())
    //         cout<<"\nStack is Empty !";
    //         else
    //         cout<<"\nStack is not Empty";
    //         break;

    //         case 6:
    //         if(S1.IsFull())
    //         cout<<"\nStack is Full !";
    //         else
    //         cout<<"\nStack is not Full";
    //         break;

    //         case 7:
    //         if(S1.IsEmpty())
    //         cout<<"\nStack is Empty !";
    //         else{
    //             cout<<"\nElements in stack are :";
    //             S1.Display();
    //         }
    //         break;

    //         case 8:
    //         exit(1);

    //         default:
    //         cout<<"\nInvalid Choice !";
    //     }
    // }
    cout<<S1.ParanthesisMatching("((a+b)*(c-d))");
    return 0;
}