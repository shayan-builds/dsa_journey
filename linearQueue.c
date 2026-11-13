#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int *arr;
};

void enqueue(struct Queue *q, int val) {
    if (q->r == q->size - 1) {
        printf("Queue is full (overflow)\n");
        return;
    }
    if (q->f == -1) q->f = 0;
    q->r++;
    q->arr[q->r] = val;
    printf("%d enqueued.\n", val);
}

int dequeue(struct Queue *q) {
    if (q->f == -1) {
        printf("Queue is empty (underflow)\n");
        return -1;
    }
    int val = q->arr[q->f];
    if (q->f == q->r) {
        q->f = -1;
        q->r = -1;
    } else {
        q->f++;
    }
    return val;
}

int peek(struct Queue q) {
    if (q.f == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return q.arr[q.f];
}

void display(struct Queue q) {
    if (q.f == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q.f; i <= q.r; i++)
        printf("%d ", q.arr[i]);
    printf("\n");
}

int main() {
    struct Queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *) malloc(q.size * sizeof(int));

    if (q.arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    enqueue(&q, 7);
    enqueue(&q, 11);
    enqueue(&q, 5);
    display(q);

    printf("Peek: %d\n", peek(q));

    printf("Dequeued: %d\n", dequeue(&q));
    display(q);

    free(q.arr);   // give the heap memory back — good habit with malloc
    return 0;
}