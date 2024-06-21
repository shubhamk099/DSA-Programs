#include<stdio.h>
#include<stdlib.h>

#define size 4
void push();
void pop();
void display();
int arr[size],top=-1;
int main()
{
    while(1){     // While loop was missing
    int choice;
    printf("\noperation perform on stack\n");
    printf("\n1.push the element \n2.pop the element\n3.display the element\n4.exit");
    printf("\nenter your choice\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break; 
    case 3:
        display();
        break;  
    case 4:
        exit(0);
        break;     
    
    default:
        printf("invalid choice");
       break;
    }
    }
}

void push()
{  
    int x;
    if(top == size-1)
    {
        printf("overflow!");
    }
    else{
        printf("enter the element you want to push");
        scanf("%d",&x);
        top=top+1;   
        arr[top]=x;      
       
    }
}
void pop()
{   
    int x;
    if(top==-1)
    {
        printf("underflow\n");
    }
    else{
        // printf("enter the element you want to pop");  ( we can only remove elements from top only, so no need to ask)
        // scanf("%d",&x);
        top=top-1;
    }
}
void display()
{   
    if(top==-1)
    {
        printf("underflow!");
    }
    else{
    printf("elements in the stack\n");
    for(int i=top;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
    }
}