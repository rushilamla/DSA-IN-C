#include<stdio.h>
#include<stdlib.h>
//declare node for a doubly linked list
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node* create_node(){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    printf("enter data: ");
    scanf("%d",&node->data);
    node->prev=NULL;
    node->next=NULL;
    return node;
}
void create_list(){
    int n;
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    struct Node *temp=NULL;//to keep track of previous node in order to do lining
    for(int i=0; i<n; i++){
        struct Node *newNode=create_node();

        if(head==NULL){
            head=newNode;
        }
        else{
            temp->next=newNode;
            newNode->prev=temp;
        }
        temp=newNode;
    }
}
void display(){
    struct Node *traversal=head;
    
    if(head==NULL){
        printf("List is empty!!!");
    }
    else{
        while(traversal!=NULL){
            printf("%d ",traversal->data);
            traversal=traversal->next;
        }
    }
}
void reverse_display(){
    struct Node *traversal=head;

   while(traversal->next!=NULL){
    traversal=traversal->next;
   }
   while(traversal!=NULL){
    printf("%d ",traversal->data);
    traversal=traversal->prev;
   }
   
}
void insert_in_beginning(){
    struct Node *newNode=create_node();
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}
void insert_in_end(){
    struct Node *traversal=head;
    struct Node *newNode=create_node();
    while(traversal->next!=NULL){
        traversal=traversal->next;
    }
    traversal->next=newNode;
    newNode->prev=traversal;
    newNode->next=NULL;

}
void insert_at_any_position(){
    int n;
    printf("Enter the Position: ");
    scanf("%d",&n);
    
    if(n<=0){
        printf("Invalid Position!!!");
    }
    else if(n==1){
        struct Node *newNode=create_node();
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    else{
        struct Node *newNode=create_node();
        struct Node *traversal=head;

        for(int i=1; i<n-1; i++){
            traversal=traversal->next;
        }
        if(traversal->next==NULL){
            traversal->next=newNode;
            newNode->prev=traversal;
            newNode->next=NULL;
        }
        else{
            newNode->next=traversal->next;
            traversal->next->prev=newNode;
            traversal->next=newNode;
            newNode->prev=traversal;
        }

    }
    
}
void delete_node(){

    if(head==NULL){
        printf("List is Empty");
    }
    else{
            int n;
            printf("Enter the position from which you want to delete: ");
            scanf("%d",&n);
            struct Node *traversal=head;

            if(n==1){
                traversal->next->prev=NULL;
                head=traversal->next;
            }
            else if(n<=0){
                printf("invalid input!!!!\n");
            }
            else{
                for(int i=1; i<n-1; i++){
                    traversal=traversal->next;
                }
                if(traversal->next->next==NULL){  // last node delete karne ki condition
                    traversal->next->prev=NULL;
                    traversal->next=NULL;
                }   
                else{
                    traversal->next->prev=NULL;
                    traversal->next=traversal->next->next;
                    traversal->next->prev=traversal;
                }
            }
        }
}
void search(){
    int n;
    printf("Enter the Element to be searched: ");
    scanf("%d",&n);

    struct Node *traversal=head;
    while(traversal!=NULL){
        if(traversal->data==n){
            printf("Element Found!!!\n");
            break;
        }
        else{
            traversal=traversal->next;
        }
    }
    if(traversal==NULL){
        printf("Element NOT Found!!!\n");
    }

}
int main(){
    create_list();
    while(1){
        system("cls");
        printf("1.Insert Node in beginning\n");
        printf("2.Insert node in end\n");
        printf("3.Insert node at any position\n");
        printf("4.Delete node from given position\n");
        printf("5.Search node in the list\n");
        printf("6.Display list\n");
        printf("7.Display List in Reverse Order\n");
        printf("8.Exit\n");

        int choice;
        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            insert_in_beginning();

            break;

            case 2:
            insert_in_end();
            
            break;

            case 3:
            insert_at_any_position();
            
            break;

            case 4:
            delete_node();
            break;

            case 5:
            search();
            break;

            case 6:
            display();
            
            break;

            case 7:
            reverse_display();
            break;

            case 8:
            exit(0);

            default :
            printf("invalid choice!!!");
            break;
        }
        system("pause");
    }
}
