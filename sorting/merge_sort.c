#include <stdio.h>

void merge(int *arr, int lb, int mid, int ub)
{
    int i, j, k;
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    int left_arr[n1], right_arr[n2];

    for (i = 0; i < n1; i++)
        left_arr[i] = arr[lb + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = lb;
    while (i < n1 && j < n2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left_arr[i];
        i++, k++;
    }
    while (j < n2)
    {
        arr[k] = right_arr[j];
        j++, k++;
    }
}

void merge_sort(int *arr, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort(arr, lb, mid);
        merge_sort(arr, mid + 1, ub);

        merge(arr, lb, mid, ub);
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
    merge_sort(arr, 0, len - 1);
    printf("AFTER:\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}