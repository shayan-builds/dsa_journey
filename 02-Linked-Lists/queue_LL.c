#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    size_t size;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool isEmpty(const Queue *q) {
    return q->front == NULL;
}

size_t getSize(const Queue *q) {
    return q->size;
}

bool enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        return false;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
    return true;
}

bool dequeue(Queue *q, int *outValue) {
    if (isEmpty(q)) {
        fprintf(stderr, "Error: queue underflow (queue is empty)\n");
        return false;
    }

    Node *temp = q->front;
    if (outValue != NULL) {
        *outValue = temp->data;
    }

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return true;
}

bool peek(const Queue *q, int *outValue) {
    if (isEmpty(q) || outValue == NULL) {
        return false;
    }
    *outValue = q->front->data;
    return true;
}

void displayQueue(const Queue *q) {
    const Node *curr = q->front;
    printf("FRONT -> ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("REAR\n");
}

void freeQueue(Queue *q) {
    while (!isEmpty(q)) {
        dequeue(q, NULL);
    }
}

int main(void) {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q); // FRONT -> 10 -> 20 -> 30 -> REAR

    int val = 0;
    if (peek(&q, &val)) {
        printf("Front element: %d\n", val); // 10
    }

    if (dequeue(&q, &val)) {
        printf("Dequeued: %d\n", val); // 10
    }

    displayQueue(&q); // FRONT -> 20 -> 30 -> REAR
    printf("Current size: %zu\n", getSize(&q)); // 2

    freeQueue(&q);
    return 0;
}