#include <stdio.h>

#define SIZE 100 

int queue[SIZE];
int head = 0;
int tail = -1;

void enqueue(int n);
int dequeue();
void peek();
int isEmpty();
int isFull();
void printQueue();

// Adds Element to queue
void enqueue(int num)
{
    if (isFull())
    {
        printf("Queue is full, cannont not add element.\n");
        return;
    }
    tail++;
    queue[tail] = num;
}

// Removes Element form the queue
int dequeue()
{
    if (isEmpty())
    {
        printf("The list is empty nothing to remove.\n");
        return -1;
    }
        head++;
        return queue[head-1];
}

// Prints out the head of the queue
void peek()
{
    printf("The head is %d.\n", queue[head]);
}

// Returns 1 if queue is empty, 0 if it isn't
int isEmpty()
{
    return (tail == -1);
}

// Return 1 if queue is full, 0 if it isn't
int isFull()
{
    return (tail >= SIZE);
}

// Prints out the queue, along with the head and tail
void printQueue()
{
     for (int i = head; i <= tail; ++i)
    {
        printf("%d ", queue[i]);
    }
    printf("\nHead: %d, Tail: %d\n", head, tail);
}

int main(void)
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printQueue();
    peek();
    dequeue();
    peek();
    printQueue();
}
