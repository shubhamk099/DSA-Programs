

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
    char StackTop();
    string InfixToPostFix(string);
    int Precedence(char);
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

char Stack::StackTop(){
    if(IsEmpty())
    return '\0';

    return top->data;
}

int Stack::Precedence(char x){
    if(x=='+'||x=='-')
    return 1;
    if(x=='*'||x=='/')
    return 2;

    return 0;
}

string Stack::InfixToPostFix(string exp){
    char *result = new char[exp.length()+1];
    int j = 0;
    int i = 0;
    while(exp[i]!='\0'){
        if(exp[i]>=97 && exp[i]<=122)
        result[j++] = exp[i++];
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            if(Precedence(StackTop())<Precedence(exp[i]) || IsEmpty())
                Push(exp[i++]);
            else
                result[j++] = Pop();
        }
    }
    while(!IsEmpty()){
        result[j++] = Pop();
    }
    result[j] = '\0';
    return result;
}

int main(){
    Stack S1;
    string expression = "a+b*c-d/e";
    cout<<"\nPostfix is : "<<S1.InfixToPostFix(expression)<<endl;
    return 0;
}
