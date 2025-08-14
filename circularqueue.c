#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % MAX == front);
}

void enqueue(int value) {
    if (isFull()) {
        printf(" Circular Queue is full, cannot insert %d\n", value);
    } else {
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = value;
        printf("%d enqueued\n", value);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is empty.\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) { 
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        return value;
    }
}

void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60); 
    display();

    return 0;
}

