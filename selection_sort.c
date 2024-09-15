#include <stdio.h>

void selection_sort(int *arr, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        size_t min_i = i;
        for (size_t j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_i])
                min_i = j;
        }
        int temp = arr[min_i];
        arr[min_i] = arr[i];
        arr[i] = temp;
    }
}

int main(void)
{
    int arr[] = {9, 8, 11, 7, 2, 5, 1, 9, 10};
    size_t len = sizeof(arr) / sizeof(*arr);
    printf("BEFORE:\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    selection_sort(arr, len);
    printf("AFTER:\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}