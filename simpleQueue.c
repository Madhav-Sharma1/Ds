#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue{
    int front,rear;
    int items[MAX];
};
void insert(struct queue *q,int item){
    if(q->rear==MAX-1){
        printf("Queue overflow\n");
        return;
    }
    q->rear=q->rear+1;
    q->items[q->rear]=item;
}
void delete(struct queue *q){
    if(q->front>q->rear){
        printf("Queue unserflow\n");
        return;
    }
    int temp=q->items[q->front];
    printf("Deleted element is %d\n",temp);
    q->front=q->front+1;
}
void display(struct queue*q){
    if(q->front>q->rear){
        printf("Queue unserflow\n");
        return;
    }
    printf("Elements of the Queue are:\n");
    for(int i=q->front;i<=q->rear;i++){
        printf("%d\t",q->items[i]);
    }printf("\n");
}
int main(){
    struct queue q;
    int ch,elem;
    q.front=0;
    q.rear=-1;
    while(1){
        printf("Enter your choice\n");
        printf("1 Insert\n2 Delete\n3 Display\n4 Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the element to insert\n");
            scanf("%d",&elem);
            insert(&q,elem);
            break;
            case 2:delete(&q);
            break;
            case 3:display(&q);
            break;
            case 4:exit(0);
            break;
        }
    }
}