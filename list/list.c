//
// LIST IMPLEMENTATION
//


#ifndef LIST_C
#define LIST_C

#include <stdlib.h>
#include "list.h"

/**
 * Check list for empty
 * @param head - Pointer to the head of the list
 * @return 1 is list is empty, else - 0
 */
int list_isEmpty(Node *head) {
    if ((head == NULL) || (head->next == NULL)) {
        return 1;
    } else {
        return 0;
    }
}


/* ### GET ITEM ### */

/**
 * Returns Nth item
 * @param head - Pointer to the head of the list
 * @param index - The index of the desired item (Starting from zero, the head is not considered)
 * @return Nth item
 */
NodeInfo list_get(Node* head, int index) {
    if (list_isEmpty(head) || (index < 0)) exit(-1);

    int i = 0;
    Node *tmp = head->next;
    while((i++ < index) && tmp) {
        tmp = tmp->next;
    }
    if(tmp == NULL) exit(-1);

    return tmp->info;
}

/**
 * Gets the last item in the list.
 * @param head - Pointer to the head of the list
 * @return last item
 */
NodeInfo list_getLast(Node *head) {
    if(list_isEmpty(head)) exit(-1);

    Node *tmp = head;
    while(tmp->next) {
        tmp = tmp->next;
    }
    return tmp->info;
}

/**
 * Gets the first item in the list.
 * @param head - Pointer to the head of the list
 * @return first item
 */
NodeInfo list_getFirst(Node *head) {
    if(list_isEmpty(head)) exit(-1);
    return head->next->info;
}


/*  ### POP ITEM ### */

/**
 * Gets and removes the last item in the list.
 * @param head - Pointer to the head of the list
 * @return deleted last item
 */
NodeInfo list_popLast(Node *head) {
    if (list_isEmpty(head)) exit(-1);

    Node *prev = head; // Preview item
    Node *curr = head->next;  // Current item;
    while(curr->next) {
        prev = curr;
        curr = curr->next;
    }
    NodeInfo result = curr->info;
    prev->next = NULL; // Remove last item
    free(curr); // Free memory
    return result;
}

/**
 * Gets and removes the Nth item in the list.
 * @param head - Pointer to the head of the list
 * @return deleted Nth item
 */
NodeInfo list_pop(Node* head, int index) {
    if (list_isEmpty(head)) exit(-1);

    int i = 0;
    Node *curr = head->next;
    Node *prev = head;
    while((i++ < index) && curr) {
        prev = curr;
        curr = curr->next;

    }
    if(curr == NULL) exit(-1);

    NodeInfo result = curr->info;

    // Remove item:
    prev->next = curr->next;
    free(curr);


    return result;
}


/**
 * Gets and removes the first item in the list.
 * @param head - Pointer to the head of the list
 * @return deleted first item
 */
NodeInfo list_popFirst(Node *head) {
    if (list_isEmpty(head)) exit(-1);

    Node *tmp = head->next;

    NodeInfo result = tmp->info;

    head->next = tmp->next;
    free(tmp);

    return result;
}



/*  ### INSERT ITEM ### */

Node* list_createElement(NodeInfo data) {
    Node *el = (Node*) malloc(sizeof(Node));
    el->info = data;
    return el;
}

/**
 * Adds an item to the end of the list.
 * @param head - Pointer to the head of the list
 * @param data - Element information structure
 */
void list_insertLast(Node *head, NodeInfo data) {
    Node *tmp = head;
    while(tmp->next) {
        tmp = tmp->next;
    }

    tmp->next = NULL;
    tmp->next = list_createElement(data);
}

/**
 * Adds an item to the top of the list.
 * @param head - Pointer to the head of the list
 * @param data - Element information structure
 */
void list_insertFirst(Node *head, NodeInfo data) {
    Node *nextEl = head->next; // Current first item, will become the second
    Node *newEl = list_createElement(data); // New first item
    newEl->next = nextEl;
    head->next = newEl;
}

/**
 * Adds an item to Nth position of the list.
 * @param head - Pointer to the head of the list
 * @param data - Element information structure
 */
void list_insert(Node* head, int index, NodeInfo data) {
    int i = 0;
    Node *tmp = head->next;
    while((i++ < index-1) && tmp) {
        tmp = tmp->next;
    }
    if((tmp == NULL) || (tmp->next == NULL)) exit(-1);

    // tmp - element after which you want to insert an element
    Node *newEl = list_createElement(data);
    newEl->next = tmp->next;
    tmp->next = newEl;
}

#endif //LIST_C
