#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};
typedef struct node *NODE;

// Function to create a new node
NODE getnode() {
    NODE X;
    X = (NODE)malloc(sizeof(struct node));
    return X;
}

// Function to free a node
void freenode(NODE X) {
    free(X);
}

// Function to insert an element at the front
NODE insert_front(NODE first, int item) {
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}

// Function to insert an element at the rear
NODE insert_rear(NODE first, int item) {
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;

    if (first == NULL) {
        return temp;
    }

    cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

// Function to delete an element from the front
NODE delete_front(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("Deleted data is %d\n", temp->info);
    freenode(temp);
    return first;
}

// Function to display the elements of the list and count nodes
void display(NODE first) {
    NODE temp;
    int count = 0;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Contents of the Linked List: ");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
        count++;
    }
    printf("\nNumber of nodes: %d\n", count);
}

// Function to demonstrate Stack (LIFO)
void stack_demo(NODE *first) {
    int item;
    printf("Enter item to push onto stack: ");
    scanf("%d", &item);
    *first = insert_front(*first, item);
    printf("Stack after push: ");
    display(*first);

    if (*first != NULL) {
        *first = delete_front(*first);
        printf("Stack after pop: ");
        display(*first);
    }
}

// Function to demonstrate Queue (FIFO)
void queue_demo(NODE *first) {
    int item;
    printf("Enter item to enqueue: ");
    scanf("%d", &item);
    *first = insert_rear(*first, item);
    printf("Queue after enqueue: ");
    display(*first);

    if (*first != NULL) {
        *first = delete_front(*first);
        printf("Queue after dequeue: ");
        display(*first);
    }
}

// Main function with menu
int main() {
    int choice, item;
    NODE first = NULL;

    for (;;) {
        printf("\n---- MENU ----\n");
        printf("1. Insert at front\n");
        printf("2. Delete from front\n");
        printf("3. Display\n");
        printf("4. Demonstrate Stack\n");
        printf("5. Demonstrate Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to insert at front: ");
                scanf("%d", &item);
                first = insert_front(first, item);
                break;
            case 2:
                first = delete_front(first);
                break;
            case 3:
                display(first);
                break;
            case 4:
                stack_demo(&first);
                break;
            case 5:
                queue_demo(&first);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
