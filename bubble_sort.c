#include <stdlib.h>
#include <stdio.h>

void bubble_sort(int* arr, int size)
{
    int i, j; 

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (j != 0 && arr[j] < arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
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
    int arr[5] = {3, 2, 5, 4, 1};
    bubble_sort(arr, 5);
    print_arr(arr, 5);

    return 0;
}