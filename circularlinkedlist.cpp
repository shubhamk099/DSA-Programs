
#include<iostream>
using namespace std;

// class for Node
class Node{
    public:
    int data;
    Node *next;
    Node(){
        data = 0;
        next = NULL;
    }
}*head;

// function to create a  circular linked list to work on
void CreateLinkedList(int array[], int n){
    Node *newnode,*last;
    head = new Node;
    head->data = array[0];
    head->next = head;
    last = head;

    for(int i=1;i<n;i++){
        newnode = new Node;
        newnode->data = array[i];
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }
}

// function to display circular linked list
void Display(){
    if(head==NULL)
    return;

    Node *temp = head;
    do{
        cout<<(temp->data)<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
}

// function to display circular linked list using recursion
void Rdisplay(Node *h){
    if(head==NULL)
    return;

    static int flag = 0;
    if(h!=head || !flag){
        flag = 1;
        cout<<(h->data)<<" ";
        Rdisplay(h->next);
    }
    flag = 0;
}

// function to count no of nodes in circular linkedlist
int CountNodes(){
    if(head==NULL)
    return 0;

    if(head->next==head)
    return 1;

    Node *temp = head;
    int count = 0;
    do{
        count++;
        temp = temp->next;
    }while(temp!=head);
    return count;
}

// function to insert a new node in circular linkedlist
void Insert(int value,int pos){
    if(pos<0 || pos>=CountNodes()+1)
    return;
    Node *newnode = new Node;
    newnode->data = value;
    if(pos==0){
        if(head==NULL){
            head = newnode;
            newnode->next = head;
        }
        else{
            Node *temp = head;
            while(temp->next!=head)
                temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
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

// function to delete a node in circular linked list
int Delete(int pos){
    int data;
    if(head==NULL || pos<0 || pos>CountNodes())
    return -1;

    if(pos==1){
        Node *temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        data = head->data;
        if(temp==head){
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
        Node *del  = temp->next;
        temp->next = del->next;
        data = del->data;
        del->next = NULL;
        delete del;
    }
    return data;
}

// main function
int main(){
    int a[]={7,3,5,9,1,2,7};
    CreateLinkedList(a,7);
    Display();
    cout<<endl;
    cout<<Delete(7)<<endl;
    Display();
    return 0;
}

