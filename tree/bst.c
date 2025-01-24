#include <stdio.h>
#include <stdlib.h>

typedef struct __tree
{
    int val;
    struct __tree *left, *right;
} bst;

bst *init(bst *root, int val)
{
    if (!root)
    {
        root = malloc(sizeof(bst));
        root->left = NULL;
        root->right = NULL;
        root->val = val;
    }
    return root;
}

bst *insert(bst *root, int val)
{
    if (!root)
        return init(root, val);
    if (root->val > val)
    {
        // val is small, that means left
        root->left = insert(root->left, val);
        return root;
    }
    else if (root->val < val)
    {
        root->right = insert(root->right, val);
        return root;
    }
    else
    {
        return root;
    }
}

void inorder(const bst *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void postorder(const bst *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

void preorder(const bst *root)
{
    if (!root)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void free_tree(bst *root)
{
    if (!root)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void)
{
    bst *root = NULL;
    root = init(root, 5);
    for (int i = 0; i < 10; i++)
    {
        insert(root, i * i);
    }

    printf("INORDER:\n");
    inorder(root);
    printf("\n");
    free_tree(root);
    return 0;
}