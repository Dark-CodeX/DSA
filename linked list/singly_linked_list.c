#include <stdlib.h>
#include <stdio.h>

typedef struct sll
{
    int data;
    struct sll *next;
} sll;

sll *insert_at_beg(sll *head, int val)
{
    sll *temp = malloc(sizeof(sll));
    temp->data = val;

    temp->next = head;
    head = temp;

    return head;
}

sll *insert_at_end(sll *head, int val)
{
    sll *temp = malloc(sizeof(sll));
    temp->data = val;
    temp->next = NULL;

    sll *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

sll *insert_at_index(sll *head, int val, int index)
{
    sll *temp = malloc(sizeof(sll));
    temp->data = val;
    temp->next = NULL;

    sll *curr = head;
    int i = 0;
    while (curr->next && i < index - 1)
    {
        curr = curr->next;
        i++;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

sll *delete_at_beg(sll *head)
{
    if (!head)
        return NULL;
    sll *next = head->next;
    free(head);
    head = next;
    return head;
}

sll *delete_at_end(sll *head)
{
    if (!head)
        return NULL;
    sll *curr = head;
    sll *prev = NULL;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    return head;
}

sll *delete_at_index(sll *head, int index)
{
    if (!head)
        return NULL;
    sll *curr = head, *prev;
    int i = 0;
    while (curr->next && i < index)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }
    prev->next = curr->next;
    free(curr);
    return head;
}

void print(sll *head)
{
    sll *curr = head;
    while (curr)
    {
        printf("%d%s", curr->data, (curr->next ? " -> " : " -> NULL"));
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    sll *list = malloc(sizeof(sll));
    list->data = 10;
    list->next = NULL;
    list = insert_at_beg(list, 20);
    list = insert_at_beg(list, 30);
    print(list);

    list = insert_at_end(list, 2);
    list = insert_at_end(list, 3);
    print(list);

    list = insert_at_index(list, 6969, 2);
    print(list);

    list = delete_at_beg(list);
    print(list);

    list = delete_at_end(list);
    print(list);

    list = delete_at_index(list, 1);
    print(list);

    return 0;
}