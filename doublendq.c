#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

    void insertFront(int item) {
        if (isFull()) {
            printf("Overflow\n");
            return;
    }

        if (isEmpty()) {
          front = rear = 0;
    }    else if (front == 0) {
            front = MAX - 1;
    }   else {
            front--;
    }

        deque[front] = item;
        printf("Inserted %d at front\n", item);
}

void insertRear(int item) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = item;
    printf("Inserted %d at rear\n", item);
}

void deleteFront() {
        if (isEmpty()) {
            printf("Underflow\n");
            return;
    }
     printf("Deleted from front: %d\n", deque[front]);

        if (front == rear) {
          front = rear = -1;
    }   else if (front == MAX - 1) {
            front = 0;
    }   else {
            front++;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    printf("Deleted from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void displayDeque() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque contents: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1 Insert Front\n");
        printf("2 Insert Rear\n");
        printf("3 Delete Front\n");
        printf("4 Delete Rear\n");
        printf("5 Display\n");
        printf("6 Exited\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            exit(1);
        }

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter item: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayDeque();
                break;
            case 6:
                printf("Exit\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
