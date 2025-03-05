#include <stdio.h>
#include <stdlib.h>

#define max(x, y) \
    x > y ? x : y

typedef struct node
{
    int key;
    struct node *left, *right;
    int height;
} node;

int get_height(node *head)
{
    if (!head)
        return 0;
    return head->height;
}

node *create_node(int key)
{
    node *n = malloc(sizeof(node));
    n->left = n->right = NULL;
    n->key = key;
    n->height = 1;
    return n;
}

int get_balance_factor(node *n)
{
    if (!n)
        return 0;
    return get_height(n->left) - get_height(n->right);
}

node *right_rotate(node *y)
{
    node *x = y->left;
    node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(get_height(y->right), get_height(y->left)) + 1;
    x->height = max(get_height(x->right), get_height(x->left)) + 1;

    return x;
}

node *left_rotate(node *x)
{
    node *y = x->right;
    node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(get_height(y->right), get_height(y->left)) + 1;
    x->height = max(get_height(x->right), get_height(x->left)) + 1;

    return y;
}

node *insert(node *head, int key)
{
    if (!head)
        return create_node(key);
    if (head->key > key)
        // val is small, that means left
        head->left = insert(head->left, key);
    else if (head->key < key)
        head->right = insert(head->right, key);

    head->height = 1 + max(get_height(head->left), get_height(head->right));
    int bf = get_balance_factor(head);

    if (bf != -1 && bf != 0 && bf != 1)
    {
        if (bf > 1 && key < head->left->key)
        {
            // LL
            return right_rotate(head);
        }
        else if (bf < -1 && key > head->right->key)
        {
            // RR
            return left_rotate(head);
        }
        else if (bf > 1 && key > head->left->key)
        {
            // LR
            head->left = left_rotate(head->left);
            return right_rotate(head);
        }
        else if (bf < -1 && key < head->right->key)
        {
            // RL
            head->right = right_rotate(head->right);
            return left_rotate(head);
        }
    }
    return head;
}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main()
{
    node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 4);
    inorder(root);

    return 0;
}