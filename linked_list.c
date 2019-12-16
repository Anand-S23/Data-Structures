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
    Node* current = list.head->link;
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
            current = current->link;
        }
        in_node->link = current->link;
        current->link = in_node;
    }
        
    list.len++;
}

void delete(LL list, int pos)
{
    int i; 
    Node* current = list.head->link;

    for (i = 0; i < pos-1; i++)
    {
        current = current->link;
    }

    Node* temp = current->link;
    current->link = temp->link;
    free(temp);
}

void reverse(LL list)
{
    Node* current = list.head->link;
    Node* prev = NULL;
    Node* temp;

    while(current != NULL)
    {
        temp = current->link;
        current->link = prev;
        prev = current; 
        current = temp;
    }

    list.head->link = prev;
}

void print_list(LL list)
{
    int i;
    Node* current = list.head->link;

    if (current == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->link;
        }
        
        printf("\n");
    }
}
    
void main(void)
{
    LL list = new_list();

    insert(list, 1, 0);
    insert(list, 2, 1);
    insert(list, 3, 2);
    reverse(list);

    print_list(list);
}
