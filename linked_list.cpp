#include <iostream>

struct Node{
    int value;
    Node* link;
};

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
    
    Node* head;
    Node* tail;
    
    // makes the linked list
    void makeLL()
    {
        Node* n = node(0, NULL);
        head = n;
        tail = head;
    }

    // inserts node to the begining of the list
    void insert(int value)
    {
        Node* n = node(value, head->link);
        head->link = n;
    }

    // removes the first node of the list
    void pop()
    {
        head->link = head->link->link;
    }

    // prints out the current linked list
    void printLL()
    {
        Node* next = head->link;
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


