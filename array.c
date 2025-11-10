#include<stdio.h>
#include<stdlib.h>
int a[10],pos,elem;
int n=0;
void Insert();
void Create();
void Delete();
void Display();
int main(){
    int ch;
    while(1){
    printf("Enter your choice\n");
    printf("1 Create\n2 Insert\n3 Delete\n4 Display\n5 Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:Create();
        break;
        case 2:Insert();
        break;
        case 3:Delete();
        break;
        case 4:Display();
        break;
        case 5:exit(0);
        break;
    }
}
}
void Create(){
    printf("Enter the size of array\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the %d element\n",i+1);
        scanf("%d",&a[i]);
    }
    return;
}
void Display(){
    if(n==0){
        printf("Array is empty\n");
        return;
    }
    printf("the array elements are\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    return;
}
void Insert(){
    if(n==10){
        printf("The array is full cannpot insrt more elements\n");
        return;
    }
    printf("Enter the lement to insert\n");
    scanf("%d",&elem);
    do{
        printf("Enter a valid position where element is to insert\n");
        scanf("%d",&pos);
    }while(pos>n);
    for(int i=n-1;i>=pos;i--){
        a[i+1]=a[i];
    }
    a[pos]=elem;
    n=n+1;
    Display();
}
void Delete(){
    if(n==0){
        printf("Array is empty\n");
        return;
    }
    do{
        printf("Enter a valis podition where element is to delete\n");
        scanf("%d",&pos);
    }while(pos>n);
    int item;
    item=a[pos];
    printf("Deleted element is %d\n",item);
    for(int i=pos;i<n;i++){
        a[i]=a[i+1];
    }
    n=n-1;
    Display();
}

