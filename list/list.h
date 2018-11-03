//
// LIST INTERFACE
//

#ifndef LIST_H
#define LIST_H

typedef struct NodeInfo {
    int intValue;
} NodeInfo;

typedef struct Node {
    NodeInfo info;
    struct Node *next;
} Node;

// CONSTRUCTOR (head creation)
Node* list_create();

// GET ITEM
NodeInfo list_getLast(Node *head);
NodeInfo list_getFirst(Node *head);
NodeInfo list_get(Node* head, int index);

// POP ITEM
NodeInfo list_popLast(Node *head);
NodeInfo list_popFirst(Node *head);
NodeInfo list_pop(Node* head, int index);

// ADD ITEM
void list_insertLast(Node *head, NodeInfo data);
void list_insertFirst(Node *head, NodeInfo data);
void list_insert(Node* head, int index, NodeInfo data);

// LIST SIZE:
int list_size(Node *head);

// DELETE:
void list_removeList(Node **head);
void list_remove(Node *head, int index);

NodeInfo* list_toArray(Node *head);
int list_isEmpty(Node *head);

#endif //LIST_H
