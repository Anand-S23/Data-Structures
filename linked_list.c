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
    Node* next = list.head;
    Node* in_node = new_node(0, NULL);

    if (pos > list.len + 1)
    {
        printf("The list is too short, cannot add node there.\n");
    } 
    else
    {
        if (pos == 0)
        {
            in_node->link = list.head->link;
        list.head = in_node;
        }
        else
        {
            int i;
                
            for (i = 0; i < pos; i++)
        {
            next = next->link;
        }
        in_node->link = next->link;
        next = in_node;
        }
        
        list.len++;
    }
}

void print_list(LL list)
{
    int i;
    Node* next = list.head;

    for (i = 0; i < list.len; i++)
    {
        next = next->link;
        printf("%d ", next->data);
    }

    printf("\n");
}
    
void main(void)
{
    LL list = new_list();
    insert(list, 1, 0);
    insert(list, 2, 0);
    insert(list, 3, 0);
    insert(list, 4, 0);
    insert(list, 5, 0);
    insert(list, 6, 0);

    print_list(list);

    Node* next = list.head;
    int i; 

    for (i = 0; i < list.len; i++)
    {
        next = next->link;
        printf("%d ", next->data);
    }

    printf("\n");

    printf("The value of the head is %d\n", list.head->link->data);
    printf("is this even working?");
}
