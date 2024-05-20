//implementation of stack data structure using array
/*
push--> inserting an element on top
pop--> deleting the topmost element
peek-->displaying the topmost element
isEmpty-->to check if the stack is empty
isFull-->to check if the stack is full
*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE]; //ek 'stack' naam ka array le liya
int top=-1; //top tells the 'index' of topmost element of stack not position
void push(){ 
// firstly check ki kahi stack full to nahi beacuse we cannot insert an element in a full stack
if(top==SIZE-1){
    printf("Stack Overflow !!!");
}
else{
    top=top+1;
    int val;
    printf("Enter the Element to be Inserted : ");
    scanf("%d",&val);
    stack[top]=val;
    printf("Element added Successfully");
}
}
void pop(){
    //first check ki kahi list empty to nahi because element cannot be removed from empty list
    if(top==-1){
        printf("Stack Underflow !!!");
    }
    else{
        int val;
        val=stack[top];
        top=top-1;
        printf("Element %d Deleted Successfully !!!",val);
    }
}
void peek(){
    //first check ki kahi list empty to nahi because element cannot be displayed from empty list
    if(top==-1){
        printf("Stack Underflow !!!");
    }
    else{
        int val;
        val=stack[top];
        printf("%d",val);
    }
}
void show(){
    if(top==-1){
        printf("Stack is Empty");
    }
            
    else{
        for(int i=top; i>=0; i--){
            printf("%d\n",stack[i]);
        }
    }
}
void isEmpty(){
    if(top==-1){
        printf("The Stack is Empty");
    }
    else{
        printf("The Stack is Not Empty");
    }
}
void isFull(){
    if(top==SIZE){
        printf("The Stack is Full");
    }
    else{
        printf("The Stack is Not Full");
    }
}
int main(){
    
    while(1){
    // now printing the menu
        
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Show\n");
        printf("5.isEmpty\n");
        printf("6.isFull\n");
        printf("7.Exit");
        int choice;
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        
        switch(choice){
            system("cls");
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: peek();
            break;
            case 4: show();
            break;
            case 5: isEmpty();
            break;
            case 6: isFull();
            break;
            case 7: exit(0);
            break;
            default:
            printf("Invalid Choice !!!");
            break;
        }
        printf("\n\n");
        system("pause");
        
    }
    return 0;
}
