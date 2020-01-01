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
LL recursive_reverse(LL list, Node* node);
void print_list(LL list);
int lenght(LL list);
int is_empty(LL list);

void push(LL list, int data);
void pop(LL list);
int top(LL list);