
// Implementation of queue using linkedlist

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    public:
    Node(){
        data = 0; next = NULL;
    }
};

class Queue{
    private:
    Node *front;
    Node *rear;
    public:
    Queue();
    void InQueue(int);
    int DeQueue();
    bool IsEmpty();
    bool IsFull();
    void Display();
    ~Queue();
};

Queue::Queue(){
    front = rear = NULL;
}

bool Queue::IsEmpty(){
    if(front==NULL)
    return true;

    return false;
}

bool Queue::IsFull(){
    Node *testNode = new  Node;
    if(testNode==NULL)
    return true;

    return false;
}

void Queue::InQueue(int value){
    if(IsFull()){
    cout<<"\nQueue is full !";
    return;
    }

    Node *newnode = new Node;
    newnode->data = value;
    if(front==NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

int Queue::DeQueue(){
    int x = -1;
    if(IsEmpty()){
        cout<<"\nQueue is empty !";
    }
    
    Node *temp = front;
    front = front->next;
    temp->next = NULL;
    x = temp->data;
    delete temp;
    return x;
}

void Queue::Display(){
    if(IsEmpty()){
        cout<<"\nQueue is empty, nothing to display !";
        return;
    }

    Node *temp = front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Queue::~Queue(){
    front = rear = NULL;
}

int main(){
    Queue Q1;
    Q1.InQueue(10);
    Q1.InQueue(20);
    Q1.InQueue(30);
    Q1.InQueue(40);
    Q1.InQueue(50);
    Q1.InQueue(60);

    Q1.Display();

    Q1.DeQueue();
    Q1.DeQueue();
    Q1.DeQueue();

    Q1.Display();
    return 0;
}