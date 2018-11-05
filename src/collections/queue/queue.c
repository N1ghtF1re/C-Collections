//
// QUEUE IMPLEMENTATION
//

/**
 * @file queue.c
 * @author Alexandr Pankratiew
 * @brief File containing implementation of Queue
 */

#include "queue.h"
#include "../list/list.h"

/**
 * Creating a queue head
 * @return Pointer to the created head
 */
Node* queue_create() {
    return list_create();
}

/**
 * Check queue for empty
 * @param head - Pointer to the head of the queue
 * @return 1 is queue is empty, else - 0
 */
int queue_isEmpty(Node *head) {
    return list_isEmpty(head);
}

/**
 * Getting the number of queue items
 * @param head - Pointer to the head of the queue
 * @return size
 */
int queue_size(Node *head) {
    return list_size(head);
}

/**
 * Add item to queue
 * @param head - Pointer to the head of the queue
 * @param data  Element information structure
 */
void queue_add(Node *head, NodeInfo data) {
    list_insertLast(head, data);
}

/**
 * Retrieves and removes the head of this queue
 * @param head - Pointer to the head of the queue
 * @return head of this queue
 */
NodeInfo queue_poll(Node *head) {
    return list_popFirst(head);
}

/**
 * Retrieves, but does not remove, the head of this queue
 * @param head - Pointer to the head of the queue
 * @return head of this queue
 */
NodeInfo queue_peek(Node *head) {
    return list_getFirst(head);
}

/**
 * Remove queue
 * @param head  - Pointer to the pointer to the head of the queue (Need use: queue_remove(&head))
 */
void queue_remove(Node **head) {
    list_removeList(head);
}

