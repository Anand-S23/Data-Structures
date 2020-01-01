#include <stdio.h>
#include <stdlib.h>

int stack[100];
int current = -1;

void push(int num)
{
    current += 1;
    stack[current] = num;
}

void pop()
{
    current -= 1;
}

void top()
{
    printf("%d\n", stack[current]);
}

void isEmpty()
{
    if (current == -1)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("The stack is not empty.\n");
    }
}

int main()
{
    isEmpty();
    push(2);
    push(5);
    push(4);
    pop();
    top();
    isEmpty();
    return 0;
}