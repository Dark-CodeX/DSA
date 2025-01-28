#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct queue
{
    int elements[MAX];
    size_t front, rear;
} queue;

queue *init(queue *q)
{
    q->front = q->rear = -1;
}

bool is_empty(const queue *q)
{
    if (q->front == -1)
        return true;
    return false;
}

bool is_full(const queue *q)
{
    if (q->rear == MAX - 1)
        return true;
    return false;
}

queue *enqueue(queue *q, int val)
{
    if (is_full(q))
    {
        fprintf(stderr, "err: queue-overflow\n");
        return q;
    }
    if (q->front == -1)
        q->front = 0;
    q->elements[++q->rear] = val;
    return q;
}

int dequeue(queue *q)
{
    if (is_empty(q))
    {
        return -1;
    }
    int x = q->elements[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return x;
}

void print(const queue *q)
{
    if(is_empty(q))
    {
        fprintf(stderr, "err: queue is empty\n");
        return;
    }
    for (size_t i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->elements[i]);
    }
}

int main()
{
    queue q;
    init(&q);

    // Test cases
    printf("Enqueue 10, 20, 30\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Current Queue: ");
    print(&q);

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    printf("Current Queue: ");
    print(&q);

    printf("Enqueue 40, 50\n");
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Current Queue: ");
    print(&q);

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q)); // Queue underflow test

    printf("Current Queue: ");
    print(&q);

    return 0;
}