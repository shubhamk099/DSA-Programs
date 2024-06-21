
#include<iostream>
#include <climits>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(){
        data=0;
        next=NULL;
    }
};

class LinkedList{
    public:
    Node *head;
    int size;
    LinkedList();
    void InsertBeginning(int);
    void InsertAfter(int,int);
    void InsertEnd(int);
    void Insert(int,int);
    void InsertSorted(int);
    void Display();
    int DeleteFirst();
    int DeletePOS(int);
    int CountNodes();
    int SumOfAll();
    int MaxElement();
    int MinElement();
    Node* LinearSearch(int);
    Node* ImprovedLinearSearch(int);
};

// Constructor for linked list

LinkedList::LinkedList(){
    head = NULL;
    size = 0;
}

// Function to insert a new node at beginning of a linked list

void LinkedList::InsertBeginning(int value){
    Node *newnode = new Node;
    newnode->data = value;
    if(head==NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

// Function to insert a new node after a given position

void LinkedList::InsertAfter(int value,int pos){
    if(head==NULL)
        return;
    else{
        Node *newnode = new Node;
        newnode->data = value;
        Node *temp = head;
        for(int i=0;i<pos-1 && temp;i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// Function to insert a new node at end of Linked List

void LinkedList::InsertEnd(int value){
    Node *newnode = new Node;
    newnode->data = value;
    
    if(head==NULL){
        head = newnode;
    }
    else{
        Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to insert a new node at any position in linked list

void LinkedList::Insert(int value,int pos){
    Node *temp = head;
    if(pos==0){
        Node *newnode = new Node;
        newnode->data = value;
        newnode->next = head;
        head = newnode;
    }
    else if(pos>0){
        Node *temp = head;
        for(int i=0;i<pos-1 && temp;i++){
            temp = temp->next;
        }
        if(temp){
            Node *newnode = new Node;
            newnode->data = value;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void LinkedList::InsertSorted(int value){
    Node *temp = head;
    if(value<temp->data){
        InsertBeginning(value);
    }
    else{
        Node *q = NULL;
        while(temp && temp->data<value){
            q = temp;
            temp = temp->next;
        }
        Node *newnode = new Node;
        newnode->data = value;
        newnode->next = q->next;
        q->next = newnode;
    }
}

// Function to display Linked List

void LinkedList::Display(){
    Node *temp = head;
    while(temp){
        cout<<(temp->data)<<" ";
        temp = temp->next;
    }
}

// Function to delete first node in linked list

int LinkedList::DeleteFirst(){
    if(head!=NULL){
        Node *temp = head;
        head = head->next;
        return (temp->data);
        delete temp;
    }
    return -1;
}

// Function to delete a node from given position

int LinkedList::DeletePOS(int pos){
    if(head!=NULL){
        Node *temp = head;
        Node *q = NULL;
        for(int i=0;i<pos-1;i++){
            q = temp;
            temp = temp->next;
        }
        q->next = temp->next;
        return (temp->data);
        delete temp;
    }
    return -1;
}

// Function to count no of nodes in a linked list

int LinkedList::CountNodes(){
    Node *temp = head;
    int count = 0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

// Function to find sum of all elements in linkedlist

int LinkedList::SumOfAll(){
    Node *temp = head;
    int sum =0;
    while(temp){
        sum += (temp->data);
        temp = temp->next;
    }
    return sum;
}

// Function to find largest element in linkedlist

int LinkedList::MaxElement(){
    Node *temp = head;
    int max = INT_MIN;
    while(temp){
        if(temp->data>max)
        max = temp->data;
        temp = temp->next;
    }
    return max;
}

// Function to find minimum element in linkedlist

int LinkedList::MinElement(){
    Node *temp = head;
    int min = INT_MAX;
    while(temp){
        if(temp->data<min)
        min = temp->data;
        temp = temp->next;
    }
    return min;
}

// Linear search function for linkedlist

Node* LinkedList::LinearSearch(int key){
    Node *temp = head;
    while(temp){
        if(temp->data==key)
        return temp;
        temp=temp->next;
    }
    return NULL;
}

// Impreoved Linear search - Move to head

Node* LinkedList::ImprovedLinearSearch(int key){
    Node *temp = head;
    Node *previous = NULL;
    while(temp){
        if(temp->data==key){
            previous->next = temp->next;
            temp->next = head;
            head = temp;
            return head;
        }
        previous = temp;
        temp = temp->next;
    }
    return NULL;
}

int main(){
    LinkedList L1;
    L1.InsertEnd(10);
    L1.InsertEnd(30);
    L1.InsertEnd(50);
    L1.InsertEnd(60);
    L1.InsertEnd(90);
    L1.Display();
    L1.DeletePOS(1);
    cout<<endl;
    L1.Display();
    return 0;
}





