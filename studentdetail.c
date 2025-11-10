#include<stdio.h>
#include<stdlib.h>
#define NUM_students 2
#define NUM_sub 3
struct student{
    int rollno,semester;
    char name[50];
    int marks[NUM_sub];
};
void enterDetails(struct student *s){
    for(int i=0;i<NUM_students;i++){
        printf("Enter the details of student %d\n",i+1);
        printf("Enter Roll no:");
        scanf("%d",&(s+i)->rollno);
        printf("Enter name:");
        scanf("%s",(s+i)->name);
        printf("Enter Semester:");
        scanf("%d",&(s+i)->semester);
        printf("Enter the subjects marks\n");
        for(int j=0;j<NUM_sub;j++){
            printf("Subject %d:",j+1);
            scanf("%d",&(s+i)->marks[j]);
        }
    }
}
void displayDetails(struct student *s){
    for(int i=0;i<NUM_students;i++){
        printf("\nDetails of student %d\n",i+1);
        printf("Roll no:%d\n",(s+i)->rollno);
        printf("Name:%s\n",(s+i)->name);
        printf("Semester:%d\n",(s+i)->semester);
        printf("Marks:\n");
        for(int j=0;j<NUM_sub;j++){
            printf("Subject %d:%d\t",j+1,(s+i)->marks[j]);
        }
    }
}
void calculateStudentTotalMarks(struct student *s){
    printf("\nTotal marks of each student:\n");
    for(int i=0;i<NUM_students;i++){
        int total=0;
        for(int j=0;j<NUM_sub;j++){
            total+=(s+i)->marks[j];
        }
        printf("%s Roll No:%d:%d\n",(s+i)->name,(s+i)->rollno,total);
    }
}
void subjectWiseTotal(struct student *s){
    printf("\nSubject wise Total marks\n");
    for(int j=0;j<NUM_sub;j++){
        int total=0;
        for(int i=0;i<NUM_students;i++){
            total+=(s+i)->marks[j];
        }
        printf("Subject %d:%d\n",j+1,total);
    }
}
int main(){
    struct student s[NUM_students];
    struct student *ptr=s;
    enterDetails(ptr);
    displayDetails(ptr);
    calculateStudentTotalMarks(ptr);
    subjectWiseTotal(ptr);
    return 0;
}
