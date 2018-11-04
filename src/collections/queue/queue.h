//
// QUEUE INTERFACE
//

/**
 * @file queue.h
 * @author Alexandr Pankratiew
 * @brief File containing interface of Queue
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "../node.h"

// CONSTRUCTOR (head creation)
Node* queue_create();

// PUSH
void queue_add(Node *head, NodeInfo data);

// POLL (Retrieves and removes the head of this queue)
NodeInfo queue_poll(Node *head);

// PEEK (Retrieves, but does not remove, the head of this queue)
NodeInfo queue_peek(Node *head);

// REMOVE QUEUE
void queue_remove(Node **head);

// IS EMPTY:
int queue_isEmpty(Node *head);

// SIZE:
int queue_size(Node *head);


#endif //QUEUE_H
