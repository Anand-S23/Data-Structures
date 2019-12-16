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

void insert(LL* list, int data, int pos)
{
    int i;
    Node* next = list.head;
    Node* in_node = new_node(0, NULL);

    if (pos > len)
    {
        printf("The list is too short, cannot add node there.\n");
	break;
    } 

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
    
void main(void)
{
    LL list = new_list();
    insert(list, 5, 0);
    insert(list, 6, 1);

    printf("The value of the head is %d\n", list.head->data);
}
