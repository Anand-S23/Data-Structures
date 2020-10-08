typedef struct node
{
    int data;
    struct node* next;
} Node;

typedef struct linked_list
{
    Node* head;
    int size;
} Linked_List;

Node* CreateNode(int);
Linked_List CreateList(); 
void push(Linked_List *, int); 
int insert(Linked_List *, int, int); 
int pop(Linked_List *); 
int remove(Linked_List *, int); 
int search(Linked_List *, int); 
int get(Linked_List *, int); 
Linked_List* recursive_reverse(Linked_List *, Node *); 
void reverse(Linked_List *); 
int empty(Linked_List *); 
void print(Linked_List *); 

