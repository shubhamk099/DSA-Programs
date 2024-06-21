
// Implementation of circular Queue using arrays

#include<iostream>
using namespace std;

class queue{
    public:
    int size;
    int front;
    int rear;
    int *Q;
    queue(int);
    queue();
    void InQueue(int);
    int DeQueue();
    void Display();
    bool IsEmpty();
    bool IsFull();
    ~queue();
};

queue::queue(int n){
    size = n;
    front = rear = 0;
    Q = new int[size];
}

queue::queue(){
    size = 10;
    front = rear = 0;
    Q = new int[size];
}

bool queue::IsFull(){
    if((rear+1)%size==front)
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
    cout<<"\nQueue is full !\n";
    return;
    }

    rear = (rear+1)%size;
    Q[rear] = value;
}

int queue::DeQueue(){
    if(IsEmpty()){
    cout<<"\nQueue is empty !\n";
    return -1;
    }

    front = (front+1)%size;
    return Q[front];
}

void queue::Display(){
    if(IsEmpty()){
    cout<<"\nQueue is empty, nothing to display !\n";
    return;
    }
    int i = front+1;
    do{
        cout<<Q[i]<<" ";
        i = (i+1)%size;
    }while(i!=(rear+1)%size);
    cout<<endl;
}

queue::~queue(){
    front = rear = 0;
    delete []Q;
    Q = NULL;
}

int main(){
    queue q1(6);
    q1.InQueue(10);
    q1.InQueue(20);
    q1.InQueue(30);

    q1.Display();

    q1.DeQueue();
    q1.DeQueue();
    q1.DeQueue();
    
    q1.Display();

    q1.InQueue(10);
    q1.InQueue(20);
    q1.InQueue(30);
    q1.InQueue(40);
    q1.InQueue(50);

    q1.Display();
    return 0;
}


