#include <iostream>

struct Node{
    int value;
    Node* link;
};

Node* node(int value, Node* link)
{
    Node* retval = (Node *)malloc(sizeof(Node));
    retval->value = value;
    retval->link = link;
    return retval;
}

class LinkedList
{
public:
    // variables
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
        std::cout << "Node(";
        while (next != NULL)
        {
            if (next == head->link)
            {
                std::cout << next->value;    
            }
            else 
            {
                std::cout << ", " << next->value;
            }
        }
        std::cout << ")" << std::endl;
    }
};

int main() {
    LinkedList list;
    
    list.makeLL();
    list.insert(10);
    list.insert(20);
    list.printLL();
    list.pop();
    list.printLL();
}

