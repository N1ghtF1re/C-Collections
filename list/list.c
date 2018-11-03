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


/* GET ITEM */

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




#endif //LIST_C
