
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
    Node *left;
    int data;
    Node *right;
    Node(){
        left = right = nullptr;
        data = 0;
    }
}*root;

class Tree{
    public:
    void createTree();
    void preOrderTraversal(Node*);
    void inorderTraversal(Node*);
    void postOrderTraversal(Node*);
    void iterativePreOrder(Node*);
    void iterativeInOrder(Node*);
    void iterativePostOrder(Node*);
    void levelOrderTraversal(Node*);
};

void Tree::createTree(){
    queue<Node*> Q;
    Node *p;
    root = new Node;
    cout<<"\nEnter the root node : ";
    cin>>(root->data);
    Q.push(root);

    while(!Q.empty()){
        p = Q.front();Q.pop();
        int temp;

        cout<<"\nEnter left child : ";
        cin>>temp;
        if(temp!=-1){
            Node *newnode = new Node;
            newnode->data = temp;
            p->left = newnode;
            Q.push(newnode);
        }
        
        cout<<"\nEnter right child : ";
        cin>>temp;
        if(temp!=-1){
            Node *newnode = new Node;
            newnode->data = temp;
            p->right = newnode;
            Q.push(newnode);
        }
    }
}

void Tree::preOrderTraversal(Node *temp){
    if(temp!=nullptr){
        cout<<(temp->data)<<" ";
        preOrderTraversal(temp->left);
        preOrderTraversal(temp->right);
    }
}

void Tree::inorderTraversal(Node *temp){
    if(temp!=nullptr){
        inorderTraversal(temp->left);
        cout<<(temp->data)<<" ";
        inorderTraversal(temp->right);
    }
}

void Tree::postOrderTraversal(Node *temp){
    if(temp!=nullptr){
        postOrderTraversal(temp->left);
        postOrderTraversal(temp->right);
        cout<<(temp->data)<<" ";
    }
}

void Tree::iterativePreOrder(Node *temp){
    stack<Node*> S;
    while(temp!=nullptr || S.empty()){
        if(temp!=nullptr){
            cout<<(temp->data)<<" ";
            S.push(temp);
            temp = temp->left;
        }
        else{
            temp = S.top();S.pop();
            temp = temp->right;
        }
    }
}

void Tree::levelOrderTraversal(Node *temp){
    queue<Node*> Q;
    Node *p;
    Q.push(temp);
    cout<<(temp->data)<<" ";
    while(!Q.empty()){
        p = Q.front(); Q.pop();
        if(p->left!=nullptr){
            cout<<(p->left->data)<<" ";
            Q.push(p->left);
        }
        if(p->right!=nullptr){
            cout<<(p->right->data)<<" ";
            Q.push(p->right);
        }
    }
}


int main(){
    Tree T1;
    T1.createTree();
    T1.levelOrderTraversal(root); cout<<endl;
    return 0;
}