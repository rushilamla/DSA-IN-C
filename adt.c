#include<stdio.h>
#include<stdlib.h>
#define maxsize 1000
int n;
void create(int list[]){
    int i;
    printf("enter the size of list : ");
    scanf("%d",&n);
    if(n>maxsize){
        printf("list over flow!!!");
    }
    else{
        printf("enter list elements : \n");
        for(i=0;i<n;i++){
            scanf("%d",&list[i]);
        }
    }
}
void display(int list[]){
    if(n==0){
        printf("list is empty");
    }
    else{
        printf("list elements are : \n");
    int i;
    for(i=0;i<n;i++){
        printf("%d\t",list[i]);
    }
    }
}
void insert(int list[]){
    int pos,value;
    printf("enter position : ");
    scanf("%d",&pos);
    printf("enter value to insert : ");
    scanf("%d",value);
    if(pos<n){
        for(int i=n; i>=pos;i--){
            list[i]=list[i-1];
            list[pos]=list[value];
            n++;
        }
        printf("%d",list[pos]);
    }
    else{
        printf("invalid position!!!\n");
    }
}
int main(){
    int list[maxsize];
    while(1){ 
        system("cls");
        printf("1. Create List\n"); //storing data in list but data cannot be more than list size
        printf("2. Insert Elements List\n");
        printf("3. Display All List Elements\n");
        printf("4. Delete element for a List\n");
        printf("5. Search element in list\n");     
        printf("6. Exit\n");   
    
    int choice;
    printf("enter choice : ");
    scanf("%d",&choice);

    switch(choice){

        case 1:
            create(list);
            break;
        case 2:
            insert(list);
            break;
        case 3:
            display(list);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            exit(0);
            break;
        default :
            printf("invalid choice!!\n");
        
        
    }
    system("pause");
    }
    return 0;
}
