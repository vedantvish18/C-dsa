#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % SIZE == front);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL! Cannot insert %d\n", value);
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

void peek() {
    if (isEmpty())
        printf("Queue is EMPTY!\n");
    else
        printf("Front element: %d\n", queue[front]);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
