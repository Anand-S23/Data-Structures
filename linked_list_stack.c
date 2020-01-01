#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

// makes a new node using malloc
Node* new_node(int data, Node* link)
{
    Node* ret_node = (Node*)malloc(sizeof(Node));
    ret_node->data = data;
    ret_node->link = link;
    return ret_node;
}

// makes a new list with head of {0, NULL}
LL new_list()
{
    LL ret_list;
    ret_list.head = new_node(0, NULL);
    ret_list.len = 0;
    return ret_list; 
} 

void push(LL list, int data)
{
    Node* in_node = new_node(data, NULL);

    in_node->link = list.head->link;
    list.head->link = in_node;
}

void pop(LL list)
{
    Node* temp = list.head->link;
    list.head->link = temp->link;
    free(temp);
}
    
int top(LL list)
{
    return list.head->link->data;
}

int is_empty(LL list)
{
    return list.head->link == NULL;
}

void main(void)
{
    LL list = new_list();

    push(list, 1);
    push(list, 2);
    push(list, 3);

}
