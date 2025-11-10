#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the total number of disks:\n");
    scanf("%d",&n);
    printf("The disks movement are:\n");
    tower(n,'A','C','B');
    return 0;
}
void tower(int n,char sp,char dp,char ap){
    if(n==1){
        printf("Moving disk %d from %c to %c\n",n,sp,dp);
        return;
    }
    tower(n-1,sp,ap,dp);
    printf("Moving disk %d from %c to %c\n",n,sp,dp);
    tower(n-1,ap,dp,sp);
}