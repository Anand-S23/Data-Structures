#include <stdio.h>
#include <stdlib.h>


// returns the postion of the number passed in of a sorted array
int binary_search(int* sorted_arr, int size, int num)
{
    int right, left, center;

    center = size / 2;
    left = 0;
    right = size;

    while(1 <= right)
    {
        if (sorted_arr[center] > num)
        {
            right = center - 1;
        }
        else if (sorted_arr[center] < num)
        {
            left = center + 1;
        }
        else if (sorted_arr[center] == num)
        {
            return center;
        }

        center = (right + left) / 2;
    }

    return -1;
}

int main(void)
{
    int sorted_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int pos = binary_search(sorted_array, 10, 2);

    printf("%d\n", pos);
    return 0;
}