#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

Node* new_node(int data, Node* link)
{
    Node* ret_node = (Node*)malloc(sizeof(Node));
    ret_node->data = data;
    ret_node->link = link;
    return ret_node;
}

LL new_list()
{
    LL ret_list;
    ret_list.head = new_node(0, NULL);
    ret_list.len = 0;
    return ret_list; 
} 

void insert(LL list, int data, int pos)
{
    int i;
    Node* next = list.head->link;
    Node* in_node = new_node(data, NULL);

    if (pos == 0)
    {
        in_node->link = list.head->link;
        list.head->link = in_node;
    }
    else
    {
        for (i = 0; i < pos-1; i++)
        {
            next = next->link;
        }
        in_node->link = next->link;
        next->link = in_node;
    }
        
    list.len++;
}

void print_list(LL list)
{
    int i;
    Node* next = list.head->link;

    while (next != NULL)
    {
        printf("%d ", next->data);
        next = next->link;
    }

    printf("\n");
}
    
void main(void)
{
    LL list = new_list();
    insert(list, 1, 0);
    insert(list, 2, 1);
    insert(list, 1, 2);

    print_list(list);
}
