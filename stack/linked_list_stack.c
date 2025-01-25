#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct stack
{
    node *head;
} stack;

bool is_empty(const stack *s)
{
    if (!s->head)
        return true;
    return false;
}

stack *push(stack *s, int val)
{
    node *temp = malloc(sizeof(node));
    temp->next = s->head;
    temp->data = val;
    s->head = temp;

    return s;
}

int pop(stack *s)
{
    if (is_empty(s))
        return -1;
    int x = s->head->data;
    node *temp = s->head->next;
    free(s->head);
    s->head = temp;
    return x;
}

int peek(const stack *s)
{
    return s->head->data;
}

void free_stack(stack *s)
{
    if (s->head)
    {
        node *curr;
        while (s->head)
        {
            curr = s->head;
            s->head = s->head->next;
            free(curr);
        }
    }
}

int main()
{
    stack s = {NULL}; // Initialize stack

    // Demonstrating stack usage
    printf("Pushing elements 10, 20, 30 onto the stack\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));

    printf("Popping elements:\n");
    while (!is_empty(&s))
    {
        printf("%d ", pop(&s));
    }
    printf("\n");

    printf("Trying to pop from empty stack: ");
    printf("%d\n", pop(&s));

    // Free the stack
    free_stack(&s);

    return 0;
}