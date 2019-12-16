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


Node* new_node(int data, Node* link);
LL new_list();
void insert(LL list, int data, int pos);
void delete(LL list, int pos);
void reverse(LL list);
void recursive_reverse(LL list);
void print_list(LL list);
