
// Implementation of Queue using arrays

#include<iostream>
using namespace std;

class queue{
    public:
    int size;
    int front;
    int rear;
    int *Q;
    queue(int);
    void InQueue(int);
    int DeQueue();
    void Display();
    bool IsEmpty();
    bool IsFull();
    ~queue();
};

queue::queue(int n){
    size = n;
    front = rear = -1;
    Q = new int[size];
}

bool queue::IsFull(){
    if(rear == size-1)
    return true;
    return false;
}

bool queue::IsEmpty(){
    if(rear == front)
    return true;
    return false;
}

void queue::InQueue(int value){
    if(IsFull()){
    cout<<"\nQueue is full !";
    return;
    }

    rear++;
    Q[rear] = value;
}

int queue::DeQueue(){
    if(IsEmpty()){
    cout<<"\nQueue is empty !";
    return -1;
    }

    front++;
    return Q[front];
}

void queue::Display(){
    if(IsEmpty())
    cout<<"\nQueue is empty !";

    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

queue::~queue(){
    front = rear = -1;
    delete []Q;
}

int main(){
    queue q1(5);
    q1.InQueue(10);
    q1.InQueue(20);
    q1.InQueue(30);

    q1.Display();

    q1.DeQueue();
    q1.DeQueue();
    q1.DeQueue();
    
    q1.InQueue(10);
    q1.InQueue(20);
    q1.InQueue(30);
    q1.InQueue(40);
    q1.InQueue(50);

    q1.Display();
    return 0;
}


