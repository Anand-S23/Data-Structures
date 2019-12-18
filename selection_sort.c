#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* arr, int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        int smallest = i;

        for (j = i; j < size; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = i;
            }
        }

        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}

void print_arr(int* arr, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(void)
{
    int arr[5] = {2, 4, 3, 1, 5};
    
    selection_sort(arr, 5);
    print_arr(arr, 5);

    return 0;
}