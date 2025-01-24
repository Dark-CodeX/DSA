#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct stack
{
    int data[MAX];
    size_t top;
} stack;

stack *init(stack *s)
{
    s->top = -1;
    return s;
}

bool is_full(const stack *s)
{
    if (s->top == MAX - 1)
        return true;
    return false;
}

bool is_empty(const stack *s)
{
    if (s->top == -1)
        return true;
    return false;
}

stack *push(stack *s, int val)
{
    if (is_full(s))
    {
        fprintf(stderr, "err: stack-overflow\n");
        return s;
    }
    s->data[++s->top] = val;
    return s;
}

int pop(stack *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "err: stack-underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int peek(stack *s)
{
    return s->data[s->top];
}

void print(const stack *s)
{
    if (is_empty(s))
        return;
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main(void)
{
    stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    print(&s);

    printf("Top element: %d\n", peek(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));

    push(&s, 40);
    push(&s, 50);
    print(&s);

    return 0;
}