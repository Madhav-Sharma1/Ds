#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 100
struct stack{
    int top;
    double a[MAX];
};
double compute(double,double,char);
void push(char,struct stack *);
double pop(struct stack *);
int main(){
    struct stack s;
    s.top=-1;
    char symb;
    double op1,op2,res;
    char postfix[MAX];
    printf("Enter the postfix expression\n");
    gets(postfix);
    for(int i=0;postfix[i]!='\0';i++){
        symb=postfix[i];
        if(isdigit(symb)){
            push(symb,&s);
        }
        else{
            op2=pop(&s);
            op1=pop(&s);
            res=compute(op1,op2,symb);
            s.a[++s.top]=res;
        }
    }
    res=pop(&s);
    printf("The result is %f\n",res);
}
void push(char symb,struct stack *s){
    if(s->top==MAX-1){
        printf("stack overflow\n");
        return;
    }
    else{
        s->a[++s->top]=symb-'0';
        return;
    }
}
double pop(struct stack *s){
    if(s->top==-1){
        printf("Stack is empty\n");
    }
    else{
        int elem=s->a[s->top--];
        return elem;
    }
}
double compute(double op1,double op2,char symb){
    switch(symb){
        case '+':return(op1+op2);
        break;
        case '-':return(op1-op2);
        break;
        case '*':return(op1*op2);
        break;
        case '/':return(op1/op2);
        break;
        case '$':
        case '^':return(pow(op1,op2));
        break;
    }
}
