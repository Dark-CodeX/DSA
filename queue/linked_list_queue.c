#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct queue
{
    node *front, *rear;
} queue;

bool is_empty(const queue *q)
{
    return q->front == NULL && q->rear == NULL;
}

// enqueue at rear
void enqueue(queue *q, int val)
{
    node *temp = malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// dequeue at front
int dequeue(queue *q)
{
    if (is_empty(q))
    {
        fprintf(stderr, "err: underflow");
        return -1;
    }
    node *temp = q->front;
    q->front = q->front->next;
    if (!q->front)
        q->rear = NULL;
    int ret = temp->data;
    free(temp);
    return ret;
}

int get_front(queue *q)
{
    if (is_empty(q))
    {
        fprintf(stderr, "err: underflow");
        return -1;
    }
    return q->front->data;
}

int get_rear(queue *q)
{
    if (is_empty(q))
    {
        fprintf(stderr, "err: underflow");
        return -1;
    }
    return q->rear->data;
}

int main(void)
{
    queue q = {NULL, NULL};
    // Enqueue elements into the queue
    enqueue(&q, 10);
    enqueue(&q, 20);

    printf("Queue Front: %d\n", get_front(&q));
    printf("Queue Rear: %d\n", get_rear(&q));

    // Dequeue elements from the queue
    dequeue(&q);
    dequeue(&q);

    // Enqueue more elements into the queue
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    // Dequeue an element from the queue
    dequeue(&q);

    printf("Queue Front: %d\n", get_front(&q));
    printf("Queue Rear: %d\n", get_rear(&q));

    return EXIT_SUCCESS;
}