#include<stdio.h>
#include<stdlib.h>
#define MAX 5
char queue[MAX];
int front=0;
int rear=-1,count=0;
void insert(char);
void delete();
void display();
int main(){
    int choice;
    char item;
    while(1){
        printf("\n1.Insert an element\n2.Delete an element\n3.Display\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enter the element to insert\n");
            scanf(" %c",&item);
            insert(item);
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:printf("Invalid choice.Choose again\n");
        }
    }
    return 0;
}
void insert(char item){
    if(count==MAX){
        printf("Queue overflow");
        return;
    }
    rear=(rear+1)%MAX;
    queue[rear]=item;
    count++;
    printf("Insertion successfully\n");
}
void delete(){
    if(count==0){
        printf("Queue underflow\n");
        return;
    }
    char elem;
    elem=queue[front];
    printf("Deleted element is %c\n",elem);
    front=(front+1)%MAX;
    count--;
}
void display(){
    if(count==0){
        printf("Queue unserflow\n");
        return;
    }
    int f=front;
    printf("The elements in queue are:\n");
    for(int i=0;i<count;i++){
        printf("%c\t",queue[f]);
        f=(f+1)%MAX;
    }
}