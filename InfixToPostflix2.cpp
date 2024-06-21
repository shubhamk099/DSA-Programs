

// Parenthesis Matching using linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
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
    int Pop();
    void Display();
    bool IsEmpty();
    bool IsFull();
    int StackTop();
    string InfixToPostFix(string);
    int EvaluatePostfix(string);
    int OutPrecedence(int);
    int InPrecedence(int);
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

int Stack::Pop(){
    char x = -1;
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
    if(IsEmpty())
    return '\0';

    return top->data;
}

int Stack::OutPrecedence(int x){
    if(x=='+'||x=='-')
    return 1;
    if(x=='*'||x=='/')
    return 3;
    if(x=='^')
    return 6;
    if(x=='(')
    return 7;
    if(x==')')
    return 0;

    return -1;
}

int Stack::InPrecedence(int x){
    if(x=='+'||x=='-')
    return 2;
    if(x=='*'||x=='/')
    return 4;
    if(x=='^')
    return 5;
    if(x=='C')
    return 0;
    if(x==')')
    return -1;

    return -1;
}

int Stack::EvaluatePostfix(string exp){
    int i = 0;
    while(exp[i]!='\0'){
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            int first = Pop();
            int second = Pop();
            if(exp[i]='+') Push(second+first);
            if(exp[i]='-') Push(second-first);
            if(exp[i]='*') Push(second*first);
            if(exp[i]='/') Push(second/first);
            i++;
        }
        else if(exp[i]>='0' && exp[i]<='9'){
            Push(exp[i]-48);
        }
    }
    return StackTop();
}


string Stack::InfixToPostFix(string exp){
    char *result = new char[exp.length()+1];
    int j = 0;
    int i = 0;
    while(exp[i]!='\0'){
        if(exp[i]>=97 && exp[i]<=122)
        result[j++] = exp[i++];
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^'||exp[i]=='('||exp[i]==')'){
            if(StackTop()=='('&& exp[i]==')'){
            Pop();
            i++;
            }

            if(InPrecedence(StackTop())<OutPrecedence(exp[i]) || IsEmpty())
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
    string expression = "35*62/+4-";
    cout<<"\nResult is : "<<S1.EvaluatePostfix(expression)<<endl;
    return 0;
}
