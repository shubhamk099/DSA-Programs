
// Parenthesis Matching using linked list


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
    void Display();
    bool IsEmpty();
    bool IsFull();
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

bool Stack::ParanthesisMatching(string exp){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        Push(exp[i]);

        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            char temp = Pop();
            if(temp=='(' && exp[i]==')')
            continue;

            else if(temp=='{' && exp[i]=='}')
            continue;

            else if(temp=='[' && exp[i]==']')
            continue;

            else
            return false;
        }
    }
    return IsEmpty();
}


int main(){
    Stack S1;
    string expression = "{([a+b]*[c-d])/e}";
    cout<<S1.ParanthesisMatching(expression);
    return 0;
}
