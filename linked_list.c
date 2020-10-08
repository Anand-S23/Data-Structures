#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

Node* CreateNode(int data)
{
    Node *ret_node = (Node *)malloc(sizeof(Node)); 
    ret_node->data = data; 
    ret_node->next = NULL;
    return ret_node;
}

Linked_List CreateLinkedList()
{
    Linked_List ret_list = {0}; 
    ret_list.head = NULL; 
    ret_list.size = 0;
}

void push(Linked_List *ll, int data)
{
    Node *temp = ll->head; 
    Node *node = CreateNode(data);
    ll->head = node; 
    ll->head->next = temp;
}

int insert(Linked_List *ll, int data, int index)
{
    Node *current = ll->head; 
    Node *node = CreateNode(data);

    if (index <= ll->size && index >= 0)
    {
        if (index == 0)
        {
            Node *temp = ll->head; 
            ll->head = node; 
            ll->head->next = temp;
        }
        else 
        {
            for (int i = 0; i < index; ++i)
            {
                current = current->next;
            }
            Node *temp = current->next; 
            current->next = node; 
            current->next->next = temp; 
        }

        ll->size++;
        return 1;
    }

    return 0; 
}

int pop(Linked_List *ll)
{
    int pop_val = ll->head->data;
    ll->head = ll->head->next;
    return pop_val; 
}

int remove(Linked_List *ll, int index)
{
    Node *current = ll->head; 

    if (index < ll->size && index >= 0)
    {
        if (index == 0)
        {
            pop(ll); 
        }
        else
        {
            for (int i = 0; i < index; ++i)
            {
                current = current->next; 
            }
            Node *temp = current->next; 
            current->next = current->next->next; 
            free(temp);
        }
    }
}

int search(Linked_List *ll, int data)
{
    Node *current = ll->head; 

    for (int i = 0; i < ll->size; ++i)
    {
        if (current->data == data)
        {
            return i; 
        }

        current = current->next; 
    }

    return -1; 
}

int get(Linked_List *ll, int index)
{
    Node *current = ll->head;

    if (index >= ll->size || index < 0)
    {
        printf("Invalid index, index out of range");
        exit(1);
    }

    for (int i = 0; i <= index; ++i)
    {
        current = current->next; 
    }

    return current->data;
}

Linked_List* recursive_reverse(Linked_List *ll, Node *current)
{
    Linked_List *list = ll;

    if (current->next == NULL)
    {
        ll->head->next = current;
        return list;
    }

    reverse(list, current->next);
    Node *temp = current->next;
    temp->next = current;
    current->next = NULL;
}

void reverse(Linked_List *ll)
{
    Node* current = ll->head->next;
    Node* prev = NULL;
    Node* temp;

    while(current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current; 
        current = temp;
    }

    ll->head->next = prev;
}

int empty(Linked_List *ll)
{
    return ll->head->next == NULL; 
}

void print(Linked_List *ll)
{
    Node *current = ll->head; 

    if (current == NULL)
    {
        printf("Empty List\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL \n"); 
}
