typedef struct node
{
    int data;
    struct node* link;
} Node;

typedef struct linked_list
{
    Node* head;
    int len;
} LL;
