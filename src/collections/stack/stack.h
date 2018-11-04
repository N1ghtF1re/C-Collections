//
// STACK INTERFACE
//

/**
 * @file stack.h
 * @author Alexandr Pankratiew
 * @brief File containing interface of Stack
 */

#ifndef STACK_H
#define STACK_H

#include "../node.h"

// CONSTRUCTOR (head creation)
Node* stack_create();

// PUSH
void stack_push(Node *head, NodeInfo data);

// POP
NodeInfo stack_pop(Node *head);

// REMOVE STACK
void stack_remove(Node **head);

// IS EMPTY:
int stack_isEmpty(Node *head);

// SIZE:
int stack_size(Node *head);

#endif //STACK_H
