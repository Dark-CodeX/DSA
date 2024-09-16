#include <stdio.h>

void insertion_sort(int *arr, size_t len)
{
    for (size_t i = 1; i <= len - 1; i++)
    {
        size_t j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--; // GOING TOWARDS LEFT
        }
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
    insertion_sort(arr, len);
    printf("AFTER:\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}