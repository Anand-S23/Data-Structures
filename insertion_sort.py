def insertion_sort(arr):
    for i, c in enumerate(arr):
        key = c
        j = i - 1

        while(j >= 0 and arr[j] > key):
            arr[j+1] = arr[j]
            j -= 1
        
        arr[j+1] = key


if __name__ == '__main__':
    arr = [2, 4, 1, 5, 6, 3, 7]

    insertion_sort(arr)
    print(arr)