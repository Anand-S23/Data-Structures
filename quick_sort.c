#include <stdio.h>

#define ArraySize(arr) (sizeof((arr)) / sizeof((arr)[0]))

void xor_swap(int *a, int *b)
{
    *a ^= *b; 
    *b ^= *a; 
    *a ^= *b;
}

void swap(int *a, int *b)
{
    int temp = *a; 
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right)
{
    int pivot = arr[right];
    int j = (left - 1);

    for (int i = left; i < right; ++i)
    {
        if (arr[i] <= pivot)
        {
            ++j;
            swap(&arr[j], &arr[i]);
        }
    }

    swap(&arr[j + 1], &arr[right]);
    return ++j; 
}

void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int partition_index = partition(arr, left, right);
        quick_sort(arr, left, partition_index - 1);
        quick_sort(arr, partition_index + 1, right);
    }
}

int main(int argc, char **argv) 
{
    int arr[] = {8, 7, 2, 1, 0, 9, 6, 1};
    quick_sort(arr, 0, ArraySize(arr) - 1);

    for (int i = 0; i < ArraySize(arr); ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
