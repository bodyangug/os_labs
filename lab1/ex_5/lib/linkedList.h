
typedef struct __LinkedList LinkedList;
typedef struct __Node Node;

typedef struct __Node{
    Node* next;
    int val;
}Node;

typedef struct __LinkedList{
    Node* root;
    int lenght;
    
    void (*add)(LinkedList* list, int item);
    int (*size)(LinkedList* list);
    void (*insert)(LinkedList* list, int index, int item);
    void (*removeItem)(LinkedList* list, int index);
    void (*set)(LinkedList* list, int index, int item);
    int (*get)(LinkedList* list, int index);

} LinkedList;


void add (LinkedList* list, int item);
int size (LinkedList* list);
void insert(LinkedList* list, int index, int item);
void removeItem(LinkedList* list, int index);
void set(LinkedList* list, int index, int item);
int get(LinkedList* list, int index);
LinkedList* newLinkedList();