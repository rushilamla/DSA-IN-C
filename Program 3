#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
int top=-1;
int main(){

    char str[SIZE];
    printf("Enter the expression : ");
    gets(str);

    char stack[SIZE];
    int i, len;
    len=strlen(str);//to find length of string
    for(i=0;i<len;i++){



        if(str[i]=='[' || str[i]=='{' || str[i]=='('){
            top++;
            stack[top]=str[i];

        }
        else if(str[i]==']' || str[i]=='}' || str[i]==')'){
            char ch=stack[top];
            if(ch=='['){
                ch=']';
            }
            else if(ch=='{'){
                ch='}';
            }
            else if(ch=='('){
                ch=')';
            }
            if(ch==str[i]){
                top--;
            }
            else
                break;
        }
    }
    if(top==-1){
        printf("balanced !!!");
    }
    else{
        printf("not balanced !!!");
    }
    return 0;
}
