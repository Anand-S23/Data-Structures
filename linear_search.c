#include <stdlib.h>
#include <stdio.h>

int linear_search(int* arr, int size, int num)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }

    return -1;
}

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int pos = linear_search(arr, 5, 2);

    printf("Postion of number: %d\n", pos);
    return 0;
}