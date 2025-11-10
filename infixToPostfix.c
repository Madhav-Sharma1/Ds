#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
struct stack{
    int top;
    char items[MAX];
};
struct stack s;
int pos=0;
void push(char);
char pop();
char infix[MAX],postfix[MAX];
int isFull();
int isEmpty();
int f=0;
int precedence(char);
void compute();
int main(){
    s.top=-1;
    printf("Enter the infix expression\n");
    gets(infix);
    compute();
    if(f==0){
        printf("The postfix expression is\n");
        puts(postfix);
    }
    return 0;
}
void compute(){
    char symbol,elem;
    for(int i=0;infix[i]!='\0';i++){
        symbol=infix[i];
        switch(symbol){
            case '(':push(symbol);
            break;
            case')':while((elem=pop())!='('){
                postfix[pos++]=elem;
            }
            break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '$':while(!isEmpty()&&precedence(symbol)!=-1&& precedence(s.items[s.top])>=precedence(symbol)){
                postfix[pos++]=pop();
            }
            push(symbol);
            break;
            default:if(!isalpha(symbol)){
                printf("Invalid input\n");
                f=1;
                return;
            }
            else{
                postfix[pos++]=symbol;
                break;
            }
        }
    }
    while(!isEmpty()){
        elem=pop();
        postfix[pos++]=elem;
    }
}
void push(char symb){
    if(isFull()){
        printf("stack is full\n");
        return;
    }
    else{
        s.items[++s.top]=symb;
        return;
    }
}
char pop(){
    if(isEmpty())
        printf("Stack is empty\n");
    else{
        int item=s.items[s.top--];
        return item;
    }
}
int isFull(){
    if(s.top==MAX-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
int isEmpty(){
    if(s.top==-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
int precedence(char symb){
    switch(symb){
        case '$':return 3;
        case '*':
        case '/':return 2;
        case '+':
        case '-':return 1;
        case'(':
        case ')':return 0;
        default:printf("Invalid input\n");
        f=1;
        return -1;
    }
}