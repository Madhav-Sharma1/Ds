#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct queue{
    int front,rear,count;
    int items[SIZE];
};
void Insert(struct queue *,int);
void Delete(struct queue *);
void Display(struct queue *);
int main(){
    struct queue cq;
    cq.front=0;
    cq.rear=-1;
    cq.count=0;
    int elem,ch;
    while(1){
        printf("\nEnter your choice\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:if(cq.count==SIZE){
                printf("Queue overflow\n");
            }
            else{
                printf("Enter the element to insert:\n");
                scanf("%d",&elem);
                Insert(&cq,elem);
            }
            break;
            case 2:Delete(&cq);
            break;
            case 3:Display(&cq);
            break;
            case 4:exit(0);
            break;
            default:printf("Enter a valid choice\n");
            break;
        }
    }
}
void Insert(struct queue *cq,int elem){
    cq->rear=(cq->rear+1)%SIZE;
    cq->items[cq->rear]=elem;
    cq->count++;
    return;
}
void Delete(struct queue *cq){
    if(cq->count==0){
        printf("Queue unser flow\n");
        return;
    }
    int ele=cq->items[cq->front];
    printf("Deleted element is %d\n",ele);
    cq->front=(cq->front+1)%SIZE;
    cq->count--;
    return;
}
void Display(struct queue *cq){
    if(cq->count==0){
        printf("Queue under flow\n");
        return;
    }
    int ele;
    int f=cq->front;
    printf("The elements of circular queue are:\n");
    for(int i=0;i<cq->count;i++){
        ele=cq->items[f];
        printf("%d\t",ele);
        f=(f+1)%SIZE;
    }
    return;
}