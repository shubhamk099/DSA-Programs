
// Sparse Matrix Implementation using LinkedList

#include<iostream>
using namespace std;

class Node{
    public:
    int col;
    int data;
    Node *next;
    Node(){
        next = NULL;
    }
};

class SparseMatrix{
    private:
    Node **head;
    int noofcols;
    int noofrows;
    int nonzeros;
    public:
    SparseMatrix(){
        head = NULL;
    }
    void TakeInput();
    void Display();
};

void SparseMatrix::TakeInput(){
    cout<<"\nEnter no of columns : ";
    cin>>noofcols;
    cout<<"\nEnter no of rows : ";
    cin>>noofrows;
    cout<<"\nEnter no of non-zero elements : ";
    cin>>nonzeros;

    head = new Node*[noofrows];

    int rowValue,colValue,value;
    for(int i=0;i<nonzeros;i++){

        cout<<"\nEnter row, col, value : ";
        cin>>rowValue>>colValue>>value;

        if(head[rowValue]==NULL){
        head[rowValue] = new Node;
        Node *temp = head[rowValue];
        temp->col = colValue;
        temp->data = value;
        }
        else{
            Node *temp = head[rowValue];
            while(temp->next!=NULL)
            temp = temp->next;
            
            Node *newnode = new Node;
            newnode->col = colValue;
            newnode->data = value;
            temp->next = newnode;
        }
    }
}


void SparseMatrix::Display(){
    for(int i=0;i<noofrows;i++){
        Node *temp = head[i];
        for(int j=0;j<noofcols;j++){
            if(j==temp->col){
                cout<<(temp->data)<<" ";
                temp = temp->next;
            }
            else{
                cout<<"0"<<" ";
            }
        }
    }
}



int main(){
    SparseMatrix S1;
    S1.TakeInput();
    S1.Display();
    return 0;
}

