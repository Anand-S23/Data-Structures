#include <stdio.h>
#include <stdlib.h>

int stack[100];
int current = -1;

void push(int num)
{
    current++;
    stack[current] = num;
}

void pop()
{
    current--;
}

int top()
{
    return stack[current];
}

int isEmpty()
{
    return (current == -1);
}

