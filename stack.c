#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack{
    int top;
    int arr[MAX];
};
void push(struct stack *s,int ele){
    if(s->top==MAX-1){
        printf("Stack is full\n");
        return;
    }
    s->top=s->top+1;
    s->arr[s->top]=ele;
}
void pop(struct stack *s){
    if(s->top==-1){
        printf("Stack is empty\n");
        return;
    }
    int item=s->arr[s->top];
    printf("Deleted element is %d\n",item);
    (s->top)--;
}
void display(struct stack *s){
    if(s->top==-1){
        printf("Stack is empty\n");
        return;
    }
    printf("Elments of the array are\n");
    for(int i=0;i<=s->top;i++){
        printf("%d\t",s->arr[i]);
    }
    printf("\n");
}
int main(){
    struct stack s;
    s.top=-1;
    int ch,ele;
    while(1){
        printf("Enter your choice\n");
        printf("1 Push\n2 Pop\n3 Display\n4 Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the element to insert\n");
            scanf("%d",&ele);
            push(&s,ele);
            break;
            case 2:pop(&s);
            break;
            case 3:display(&s);
            break;
            case 4:exit(0);
            break;
        }
    }
}
