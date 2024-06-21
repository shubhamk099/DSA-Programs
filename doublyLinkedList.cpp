
// Doubly Linked List Implementation
#include<iostream>
using namespace std;

class Node{
    public:
    Node *prev;
    int data;
    Node *next;
    Node(){
        prev = next = nullptr;
    }
}*head,*last;

// function to create a doubly linkedlist from an array
void CreateLinkedList(int array[],int size){
    if(size<=0)
    return;

    Node *firstnode = new Node;
    firstnode->data = array[0];
    head = firstnode;

    last = head;
    for(int i=1;i<size;i++){
        Node *newnode = new Node;
        newnode->prev = last;
        last->next = newnode;
        newnode->data = array[i];
        last = newnode;
    }
}

// function to display doubly linked list
void Display(Node *temp){
    if(head==nullptr)
    return;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// function to count no of nodes in linked list
int Length(Node *temp){
    if(head==nullptr)
    return 0;

    int length = 0;
    while(temp){
        length++;
        temp = temp->next;
    }
    return length;
}

// function to insert a new node in doubly linkedlist at given position
void Insert(int value, int pos){
    if(pos<0 || pos>Length(head))
    return;

    if(pos==0){
        Node *newnode = new Node;
        newnode->data = value;
        if(head==nullptr){
            head  = last = newnode;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }        
    }
    else{
        Node *temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        Node *newnode = new Node;
        newnode->data = value;
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        if(temp->next!=nullptr) 
        temp->next->prev = newnode;
    }
}

// function to delete a node in doubly linked list

int Delete(int pos){
    if(pos<=0 || pos>Length(head) ||head==nullptr){
        return -1;
    }

    int x;
    if(pos==1){
       Node *temp = head;
       head = head->next;
       temp->next = nullptr;
       if(head) head->prev = nullptr;
       x = temp->data;
       delete temp;
    }
    else{
        Node *temp = head;
        for(int i=0;i<pos-2;i++){
            temp = temp->next;
        }
        Node *del = temp->next;
        temp->next = del->next;
        if(del->next) del->next->prev = temp;
        del->next = nullptr;
        del->prev = nullptr;
        x = del->data;
        delete del;
    }
    return x;
}

// function to reverse a doubly linked list
void ReverseX(Node *p){
    if(p==nullptr)
    return;

    last = p;
    Node *temp;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=nullptr && p->next==nullptr)
        head = p;
    }
}

// main function
int main(){
    int arr[] = {2,3,4,5,6,7,8,9};
    CreateLinkedList(arr,8);
    Display(head);
    ReverseX(head);
    Display(head);
    return 0;
}
