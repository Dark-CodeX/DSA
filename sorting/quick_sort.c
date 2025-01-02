#include <stdio.h>

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int *arr, int lb, int ub)
{
    if (lb < ub)
    {
        int pi = partition(arr, lb, ub);

        quick_sort(arr, lb, pi - 1);
        quick_sort(arr, pi + 1, ub);
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
    quick_sort(arr, 0, len - 1);
    printf("AFTER:\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}