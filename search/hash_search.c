#include <stdio.h>

size_t get_hash(int key, size_t len)
{
    return key % len;
}

int *insert(int *arr, size_t len, int key)
{
    if (!arr)
        return NULL;
    size_t i = get_hash(key, len);
    if (arr[i] == 0)
    {
        arr[i] = key;
    }
    else
    {
        fprintf(stderr, "error: collision detected at index '%zu', there's already an element present '%d'\n", i, arr[i]);
    }

    return arr;
}

void print_arr(int *arr, size_t len)
{
    if (!arr)
        return;
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    putc(10, stdout);
}

#define len(x) \
    sizeof(x) / sizeof(*x)

int main(void)
{
    int arr[10] = {};
    insert(arr, len(arr), 23);
    insert(arr, len(arr), 10);
    insert(arr, len(arr), 11);
    insert(arr, len(arr), 17);
    insert(arr, len(arr), 27);

    print_arr(arr, len(arr));

    return 0;
}