#include <iostream>

struct Node{
    int value;
    Node* link;
};

struct LL{
    Node* head;
    Node* tail;
}

Node* node(int value, Node* link)
{
    Node* retval = (Node *)malloc(sizeOf(Node));
    retval->value = value;
    retval->link = link;
    return retval;
}

class LinkedList
{
public:
    // makes the linked list
    LL makeLL()
    {
        LL retval;
        Node* n = node(0, NULL);
        retval.head = n;
        retval.tail = retval.head;
        return retval;
    }

    // inserts node to the begining of the list
    void insert(LL list, int value)
    {
        Node* n = node(value, list.head->link);
        list.head->link = n;
    }

    // removes the first node of the list
    void pop(LL list)
    {
        list.head->link = list.head->link->link;
    }

    // prints out the current linked list
    void printLL(LL list)
    {
        Node* next = list.head->link;
        while (next != NULL)
        {
            std::cout << "Node(" << next->value << ",";
            next = next->link;
        }
        std::cout << ")" << endl;
    }
}

int main() {
    
}


