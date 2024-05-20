#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
//take head node to store the address of first node
struct Node *head=NULL;
//now create a function to create node, to be called when we have to create nodes
// it returns address of created node so it's return type is pointer to node

struct Node* create_node(){

    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    printf("enter data: ");
    scanf("%d",&node->data);
    node->next=NULL;
    return node;


}
void create_list(){
    int n;
    printf("enter the no. of nodes: ");
    scanf("%d",&n);
    struct Node *temp=NULL; // to point to last node

    for(int i=0; i<n; i++){
        struct Node *newNode=create_node();
        
        
        if(head==NULL){
            head=newNode;
        }
        else{
            temp->next=newNode;

        }
        temp=newNode;
    }
}
void display_list(){
    struct Node *traversal=head;//to travel in list
    if(head==NULL){
            printf("list is empty\n");
        }
    while(traversal!=NULL){
        
        
            printf("%d ",traversal->data);
        
        traversal=traversal->next;
    }

}
void insert_node_in_begin(){
    struct Node *newNode=create_node();
    newNode->next=head;
    head=newNode;
}
void insert_node_in_end(){
    struct Node *newNode=create_node();
    struct Node *traversal=head; //traversal pointer to traverse in whole list
    while(traversal->next!=NULL){
        traversal=traversal->next;
    }
    traversal->next=newNode;
    newNode->next=NULL;
}
void insert_node_at_any_position(){
    int n;
    printf("enter position: ");
    scanf("%d",&n);

    
    if(n<=0){
        printf("invalid position");
    }
    else if(n==1){
        insert_node_in_begin();
    }
    else{
        struct Node *newNode=create_node();
        struct Node *traversal=head;
        for(int i=1; i<n-1; i++){
            traversal=traversal->next;
        }
        newNode->next=traversal->next;
        traversal->next=newNode;
    }
}
void delete_node(){
    if(head==NULL){
        printf("list is empty");
    }
    else{
        struct Node *traversal=head;
        int n;
        printf("enter the position you want to delete: ");
        scanf("%d",&n);

        if(n==1){
            head=traversal->next;
        }
        else{
            for(int i=1; i<n-1; i++){
                traversal=traversal->next;
            }
            if(traversal->next->next==NULL){
                traversal->next=NULL;
            }
            else{
                traversal->next=traversal->next->next;
            }
        }
    }
}
void search(){
    int n;
    printf("Enter data to search: ");
    scanf("%d",&n);

    if(head==NULL){
        printf("List is empty");
    }
    else{
        struct Node *traversal=head;
        while(traversal!=NULL){
            if(traversal->data==n){
                printf("Element Found!!!");
                break;
            }
            else{
                traversal=traversal->next;
            }
        }
        if(traversal==NULL){
            printf("Element NOT found!!!");
        }
    }
}
void reverse(){
    struct Node *traversal=head;
    struct Node *temp1=head;
    struct Node *temp2=head->next;

    while(temp2!=NULL){
        traversal=temp2;
        temp2=temp2->next;
        traversal->next=temp1;
        temp1=traversal;
    }
    head->next=NULL;
    head=traversal;
}
int main(){
    create_list();
    while(1){
        system("cls");
        printf("1.Insert Node in Beginning\n");
        printf("2.Insert Node in End\n");
        printf("3.Insert Node at any position\n");
        printf("4.Delete Node from given Position\n");
        printf("5.Search Node in the list\n");
        printf("6.Display list\n");
        printf("7.Reverse the linked list\n");
        printf("8.Exit\n");

        int n;
        printf("Enter Choice: ");
        scanf("%d",&n);

        switch(n){

            case 1:
            insert_node_in_begin();
            break;
            case 2:
            insert_node_in_end();
            break;
            case 3:
            insert_node_at_any_position();
            break;
            case 4:
            delete_node();
            break;
            case 5:
            search();
            break;
            case 6:
            display_list();
            break;
            case 7:
            reverse();
            break;
            case 8:
            exit(0);
            break;          
            default:
            printf("invalid choice");
        }
        printf("\n");
        system("pause");
    }
}
