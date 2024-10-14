#include <stdlib.h>
#include <stdio.h>

typedef struct dll
{
    int data;
    struct dll *next, *prev;
} dll;

dll *insert_at_beg(dll *head, int val)
{
    dll *temp = malloc(sizeof(dll));
    temp->data = val;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;

    return head;
}

dll *insert_at_end(dll *head, int val)
{
    dll *temp = malloc(sizeof(dll));
    temp->data = val;
    temp->next = NULL;

    dll *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    temp->prev = curr;
    curr->next = temp;
    return head;
}

dll *insert_at_index(dll *head, int val, int index)
{
    dll *temp = malloc(sizeof(dll));
    temp->data = val;
    temp->next = NULL;

    dll *curr = head;
    int i = 0;
    while (curr->next && i < index - 1)
    {
        curr = curr->next;
        i++;
    }
    temp->next = curr->next;
    temp->prev = curr;
    if (curr->next)
    {
        curr->next->prev = temp;
    }
    curr->next = temp;
    return head;
}

dll *delete_at_beg(dll *head)
{
    if (!head)
        return NULL;
    dll *next = head->next;
    free(head);
    head = next;
    return head;
}

dll *delete_at_end(dll *head)
{
    if (!head)
        return NULL;
    dll *curr = head;
    dll *prev = NULL;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    return head;
}

dll *delete_at_index(dll *head, int index)
{
    if (!head)
        return NULL;
    dll *curr = head, *prev;
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

void print(dll *head)
{
    dll *curr = head;

    printf("+---------------------+---------------------+---------------------+---------------------+\n");
    printf("|      Prev Address    |      Current Address |       Data          |     Next Address     |\n");
    printf("+---------------------+---------------------+---------------------+---------------------+\n");

    while (curr != NULL)
    {
        printf("| %19p | %19p | %19d | %19p |\n", curr->prev, curr, curr->data, curr->next);
        printf("+---------------------+---------------------+---------------------+---------------------+\n");

        curr = curr->next;
    }
}

int main()
{
    dll *list = malloc(sizeof(dll));
    list->data = 10;
    list->next = NULL;
    list->prev = NULL;
    // list = insert_at_beg(list, 20);
    list = insert_at_beg(list, 30);
    //  print(list);

    list = insert_at_end(list, 2);
    list = insert_at_end(list, 3);
    // print(list);

    list = insert_at_index(list, 6969, 2);
    print(list);

    // list = delete_at_beg(list);
    // print(list);

    // list = delete_at_end(list);
    // print(list);

    // list = delete_at_index(list, 1);
    // print(list);

    return 0;
}