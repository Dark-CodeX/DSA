#include <stdio.h>
#include <stdlib.h>

typedef struct __linked_list__
{
    int val;
    struct __linked_list__ *next;
} linked_list;

linked_list *init(linked_list *head, int val)
{
    head = calloc(1, sizeof(linked_list));
    head->next = NULL;
    head->val = val;
    return head;
}

linked_list *insert(linked_list *head, int v)
{
    linked_list *temp = calloc(1, sizeof(linked_list));
    temp->val = v;
    temp->next = NULL;
    if (!head)
    {
        head = temp;
        return head;
    }
    linked_list *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

void print(linked_list *head)
{
    if (head)
    {
        linked_list *curr = head;
        while (curr)
        {
            printf("%d%s", curr->val, (curr->next ? " -> " : "\n"));
            curr = curr->next;
        }
    }
}

int main()
{
    linked_list *head;
    head = init(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    print(head);
    return 0;
}