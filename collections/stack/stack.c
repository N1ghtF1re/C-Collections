//
// STACK IMPLEMENTATION
//

#include "stack.h"
#include "../list/list.h"

Node* stack_create() {
    return list_create();
}

/**
 * Check stack for empty
 * @param head - Pointer to the head of the stack
 * @return 1 is stack is empty, else - 0
 */
int stack_isEmpty(Node *head) {
    return list_isEmpty(head);
}

/**
 * Getting the number of stack items
 * @param head - Pointer to the head of the stack
 * @return size
 */
int stack_size(Node *head) {
    return list_size(head);
}

/**
 * Add item to stack
 * @param head - Pointer to the head of the stack
 * @param data  Element information structure
 */
void stack_push(Node *head, NodeInfo data) {
    list_insertFirst(head, data);
}

/**
 * Pop item in stack
 * @param head - Pointer to the head of the stack
 * @return last item in stack
 */
NodeInfo stack_pop(Node *head) {
    return list_popFirst(head);
}

/**
 * Remove stack
 * @param head  - Pointer to the pointer to the head of the stack (Need use: stack_removeList(&head))
 */
void stack_remove(Node **head) {
    list_removeList(head);
}

