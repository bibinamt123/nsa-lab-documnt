#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

void initQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX_SIZE);
}

int isEmpty(struct CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(struct CircularQueue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->items[q->rear] = data;
        printf("%d enqueued to the queue.\n", data);
    }
}

int dequeue(struct CircularQueue *q) {
    int data;
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    } else {
        data = q->items[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX_SIZE;
        }
        return data;
    }
}

int search(struct CircularQueue *q, int data) {
    if (isEmpty(q)) {
        return 0;
    } else {
        int current = q->front;
        do {
            if (q->items[current] == data) {
                return 1; // Found
            }
            current = (current + 1) % MAX_SIZE;
        } while (current != (q->rear + 1) % MAX_SIZE);
        return 0; // Not found
    }
}

int main() {
    struct CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Searching for 20: %s\n", search(&q, 20) ? "Found" : "Not Found");
    printf("Searching for 40: %s\n", search(&q, 40) ? "Found" : "Not Found");

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
