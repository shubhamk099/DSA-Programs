
// Implementing Circular Linked List using class and object

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

class CircularLinkedList{
    public:
    Node *head = NULL;
    void Append(int);
    void Insert(int,int);
    void Display();
    int Count();
    int Delete(int);
};

void CircularLinkedList::Display(){
    if(head==NULL)
    return;

    Node *temp = head;
    do{
        cout<<(temp->data)<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
}

void CircularLinkedList::Append(int value){
    Node *newnode = new Node;
    newnode->data = value;

    if(head==NULL){
        head = newnode;
        head->next = head;
    }
    else{
        Node *temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

int CircularLinkedList::Count(){
    if(head==NULL)
    return 0;

    Node *temp = head;
    int count  = 0;
    do{
        count++;
        temp = temp->next;
    }while(temp!=head);
    return count;
}


void CircularLinkedList::Insert(int value,int pos){
    if(pos<0 || pos>Count()){
        return;
    }

    Node *newnode = new Node;
    newnode->data = value;
    if(pos==0){
        if(head==NULL){
            head = newnode;
            head->next = head;
        }
        else{
            Node *temp = head;
            while(temp->next!=head){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
        }
    }
    else{
        Node *temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int CircularLinkedList::Delete(int pos){
    if(pos<0 || pos>Count() || head==NULL)
    return -1;

    int x = 0;
    if(pos==0){
        Node *temp = head;
        x = head->data;
        while(temp->next!=head){
            temp = temp->next;
        }
        if(temp == head){
            head->next = NULL;
            delete head;
            head = NULL;
        }
        else{
        temp->next = head->next;
        head->next = NULL;
        delete head;
        head = temp->next;
        }
    }
    else{
        Node *temp = head;
        for(int i=0;i<pos-2;i++){
            temp = temp->next;
        }
        Node *del = temp->next;
        x = del->data;
        temp->next = del->next;
        del->next = NULL;
        delete del;
    }
    return x;
}

int main(){
    CircularLinkedList C1;

    C1.Display();

    cout<<C1.Delete(0);

    C1.Display();
    return 0;
}