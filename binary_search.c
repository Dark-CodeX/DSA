#include <stdio.h>

size_t binary_search(int *arr, size_t len, int key)
{
    if (arr[0] == key)
        return 0;
    else if (arr[len - 1] == key)
        return len - 1;
    else
    {
        size_t low = 0, high = len - 1;
        while (low <= high)
        {
            size_t mid = (low + high) / 2;
            if (arr[mid] == key)
                return mid;
            else if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t len = sizeof(arr) / sizeof(*arr);
    size_t i = binary_search(arr, len, 7);
    printf("INDEX OF 7 WAS: %zu\n", i);
    return 0;
}