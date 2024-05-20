#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL; //head node
//now creating createNode function

struct Node* createNode(){
    struct  Node *node=(struct Node*)malloc(sizeof(struct Node));
    printf("enter data: ");
    scanf("%d",&node->data);
    node->next=NULL;
    return node;

    
}
void createcircularList(){
    int n;
    printf("enter total number of nodes: ");
    scanf("%d",&n);

    struct  Node *temp=NULL; // stores the address of last element of the list
    for(int i=0; i<n; i++){
        struct Node *newNode = createNode();
        if(head==NULL){ //means agar list khali hai to
            head=newNode; // jo newnode hoga wahi 1st node ban jayega
        }
        else{
            temp->next=newNode;
        }
        
        temp=newNode;
        // jab saare elements add ho jaye tab temp ke last me head daal do 
        

    }
    temp->next=head;
    // ab ye circular linked list ban gayi
    
}
void displayList(){
    //termination condition of loop->jab tak temp head ko point nahi karta
    // first check list is empty or not 
    // value of head never changes
    if(head==NULL){
        printf("list is empty!\n");  
    }
    else{
        struct Node *temp=head;
        do { 
            printf( "%d ",temp->data );
            temp=temp->next;
        }
        // traversing tab tak karni hai jab tak last me head na mil jaye

        while(temp!=head); // because pehle element ke liye while loop kaam nahi kar raha tha
    }
}
void insertNodeInBeg(){
    struct Node *newNode=createNode();//creating node
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        //dono ek dusre ko point kar rahe
    }
    else{
        
        newNode->next=head;
        head=newNode;
        
        struct Node *t=head->next;
        while(t->next!=head->next){

            t=t->next;
        }
        t->next=newNode;
    }
}
void insertNodeInEnd(){
    struct Node *newNode=createNode();//creating node
    if(head==NULL){
        head=newNode;
        newNode->next=head;
    }
    else{
        struct Node *temp=head;
       do{                          //temp ko last tak leke jao last node

            temp=temp->next;
        }
        while(temp->next!=head);

        temp->next=newNode;
        newNode->next=head;
    }
}
void insertNodeAtAnyPosition(){
    if(head==NULL){
        printf("Invalid position!!\n"); //list khali hai
    }
    else{
        int pos,cnt=1; //cnt for calculating position
        printf("Enter Position: ");
        scanf("%d",&pos);
        if(pos==1){ //if only 1 element in list
            struct Node *newNode=createNode(); //creating a node
            
            insertNodeInBeg();   
        }
        else{
            struct Node *temp=head;
            do{
                if(cnt==pos-1){
                    break;
                }
                else{
                    cnt++;
                    temp=temp->next;
                }
                
            }
            while(temp->next!=head);
            if(temp->next==head){
                    printf("invalid position!!!\n");
                }
                else{
                    //create node and do linkking
                    struct Node *newNode=createNode(); //creating a node
                    newNode->next=temp->next;
                    temp->next=newNode;

                }
        }
    }
}
void deleteNodeAtAnyPosition(){
    if(head==NULL){
        printf("Invalid position!!\n"); //list khali hai
    }
    else{
        int pos,cnt=1; //cnt for calculating position
        printf("Enter Position: ");
        scanf("%d",&pos);
        if(pos==1){
            head=head->next;
            
        }
        
        
        else{
            
            struct Node*temp=head;
            do{
                if(cnt==pos-1){
                    break;
                }
                cnt++;
                temp=temp->next;
            }
            while(temp->next!=head);
            if(temp->next==NULL){
                printf("invalid position!!!\n");
            }
            else{
                temp->next=temp->next->next;
            }
    }

}
}
void searchElement(){
    if(head==NULL){
        printf("List is empty!!!!\n");
    }
    else{
        int num,flag=0;
        printf("Enter Data to search: ");
        scanf("%d",&num);
        struct Node *temp=head;
        while(temp!=NULL){
            if(temp->data==num){
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==1){
            printf("found!!!\n");
        }
        else{
            printf("not found!!!\n");
        }
    }
}
int main(){

    createcircularList();
    while(1){
        
        printf("1.Insert node in beginning\n");
        printf("2.Insert node in end\n");
        printf("3.Insert node at any position\n");
        printf("4.Delete node from given position\n");
        printf("5.Search node in the list\n");
        printf("6.Display list\n");
        printf("7.Exit\n");
        int choice;
        printf("enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            insertNodeInBeg();

            break;

            case 2:
            insertNodeInEnd();
            break;

            case 3:
            insertNodeAtAnyPosition();
            break;

            case 4:
            deleteNodeAtAnyPosition();
            break;

            case 5:
            searchElement();
            break;

            case 6:
            displayList();
            break;

            case 7:
            exit(0);

            default :
            printf("invalid choice!!!");
            break;
        }
        system("pause");
    }
    return 0;
}
