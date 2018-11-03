#include <stdio.h>

#include "collections/list/list.h"
#include "collections/stack/stack.h"

int main() {

    Node *head = list_create();
    NodeInfo value;
    printf("%d\n", list_size(head));
    value.intValue = 2;
    list_insertLast(head, value);
    value.intValue = 3;
    printf("%d\n", list_size(head));
    list_insertLast(head, value);
    printf("%d\n", list_size(head));
    value.intValue = 4;
    list_insertLast(head, value);

    NodeInfo info;
    info = list_get(head,1);
    printf("%d", info.intValue);

    info = list_getLast(head);
    printf("%d", info.intValue);

    info = list_getFirst(head);
    printf("%d", info.intValue);

    info = list_popFirst(head);
    printf("%d", info.intValue);

    info.intValue = -1;
    list_insertFirst(head, info);

    info.intValue = 10;
    list_insert(head, 1, info);

    NodeInfo *nodeInfo = list_toArray(head);
    printf("\n\n");
    for(int i = 0; i < list_size(head); i++) {
        printf("%d | %d\n", nodeInfo[i].intValue, list_get(head, i));
    }

    list_remove(head, 1);
    nodeInfo = list_toArray(head);
    printf("\n\n");
    for(int i = 0; i < list_size(head); i++) {
        printf("%d | %d\n", nodeInfo[i].intValue, list_get(head, i));
    }

    Node *stack = stack_create();
    for(int i = 0; i < 10; i++) {
        NodeInfo info1;
        info1.intValue = i;
        stack_push(head, info1);
    }

    for(int i = 0; i < 10; i++) {
        printf("%d", stack_pop(head).intValue);
    }

    return 0;
}