#include <stdio.h>

int linear_search(int *arr, int len, int key)
{
    for (int i = 0; i < len; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int main(void)
{
    int arr[] = {1, 99, 4, 45, 23, 43, 54, 67, 61, 69};
    int len = sizeof(arr) / sizeof(*arr);
    int key = 43;
    int i = linear_search(arr, len, key);

    printf("%d was present at %d\n", key, i);
    return 0;
}