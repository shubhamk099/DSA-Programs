
#include<iostream>
using namespace std;

class Node{
    public:
    Node *prev;
    int data;
    Node *next;
    Node(){
        prev = next = NULL;
    }
}*head=NULL;

void CreateNode(int array[],int size){
    if(size<=0)
    return;

    Node *firstnode = new Node;
    firstnode->data = array[0];
    head = firstnode;

    Node *temp = head;
    for(int i=1;i<size;i++){
        Node *newnode = new Node;
        newnode->data = array[i];
        newnode->prev = temp;
        temp->next  = newnode;
        temp = temp->next;
    }

    temp->next = head;
    head->prev = temp;
}

void Display(Node *temp){
    if(temp==NULL)
    return;

    do{
        cout<<(temp->data)<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
}

int Length(Node *temp){
    if(temp==NULL)
    return 0;

    int length=0;
    do{
        length++;
        temp = temp->next;
    }while(temp!=head);
    return length;
}


void Insert(int value,int pos){
    if(pos<0 || pos>Length(head))
    return;

    Node *newnode  = new Node;
    newnode->data = value;
    if(pos==0){
        if(head==NULL){
            head = newnode;
            newnode->next = head;
            newnode->prev = head;
        }
        else{
            Node *temp = head;
            while(temp->next!=head){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
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
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

int Delete(int pos){
    int x = -1;
    if(pos<=0 || pos>Length(head)|| head==NULL)
    return x;

    if(pos==1){
        Node *temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        if(temp==head){
            temp->next = NULL;
            temp->prev = NULL;
            x = temp->data;
            delete temp;
            head = NULL;
        }
        else{
            Node *del = head;
            head = head->next;
            temp->next = head;
            head->prev = temp;
            del->next = NULL;
            del->prev = NULL;
            x = del->data;
            delete del;
        }
    }
    else{
        Node *temp = head;
        for(int i=0;i<pos-2;i++){
            temp = temp->next;
        }
        Node *del = temp->next;
        temp->next = del->next;
        del->next->prev = temp;
        del->next = NULL;
        del->prev = NULL;
        x = del->data;
        delete del;
    }
    return x;
}

int main(){
    int arr[] = {2,3,4,5,6,7,8,9};
    CreateNode(arr,8);
    Display(head);
    Delete(8);
    Display(head);
    return 0;
}