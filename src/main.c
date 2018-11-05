#include <stdio.h>
#include <malloc.h>

/**
 * Demonstration of a part of library features. Full functionality is described in the documentation.
 */

#include "collections/list/list.h"
#include "collections/stack/stack.h"
#include "collections/queue/queue.h"
#include "collections/tree/binarysearchtree.h"
#include "collections/hashmap/hashmap.h"

void intOutputArr(NodeInfo* arr, int size) {
    printf("\n");
    for(int i = 0; i < size; i++) {
        printf("[%d]: %d\n", i, arr[i]);
    }
    printf("\n");
}

void listDemo() {
    printf("---------- LIST DEMO ----------");
    NodeInfo value;

    // LISTS DEMO:
    Node* list = list_create();
    value.intValue = 1;
    list_insertFirst(list, value);
    printf("GET FIRST: %d\n", list_getFirst(list).intValue);

    value.stringValue = "Test";
    list_insertFirst(list, value);
    value.intValue = 2;
    list_insertLast(list,value);
    printf("POP FIRST: %s\n", list_popFirst(list).stringValue);

    value.intValue = 3;
    list_insertLast(list, value);

    value.intValue = 4;
    list_insert(list, 1, value);

    int size = list_size(list);
    NodeInfo* arr = list_toArray(list);
    intOutputArr(arr, size);
    free(arr);

    printf("POP LAST: %d", list_popLast(list).intValue);
    arr = list_toArray(list);
    intOutputArr(arr, list_size(list));
    free(arr);

    printf("POP FIRST: %d", list_popFirst(list).intValue);
    intOutputArr(list_toArray(list), list_size(list));


    printf("REMOVE 1th");
    list_remove(list, 1);
    arr = list_toArray(list);
    intOutputArr(arr, list_size(list));
    free(arr);

    list_removeList(&list);
    if(!list) {
        printf("List removed\n");
    }
}

void stackDemo() {
    printf("\n\n\n---------- STACK DEMO ----------\n");
    Node *stack = stack_create();

    const n = 10;

    printf("\nIS_EMPTY: %d\n", stack_isEmpty(stack));

    printf("Placed values:\n");
    for(int i = 0; i < n; i++) {
        printf("%d\n", i);
        NodeInfo value;
        value.intValue = i;
        stack_push(stack, value);
    }
    printf("\nIS_EMPTY: %d\n", stack_isEmpty(stack));

    printf("\nSTACK: \n");
    for(int i = 0; i< n; i++) {
        printf("%d\n", stack_pop(stack).intValue);
    }

    stack_remove(&stack);
    if(!stack) {
        printf("Stack removed\n");
    }
}

void queueDemo() {
    printf("\n\n\n---------- QUEUE DEMO ----------\n");
    Node *queue = queue_create();

    const n = 10;

    printf("\nIS_EMPTY: %d\n", queue_isEmpty(queue));

    printf("Placed values:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
        NodeInfo value;
        value.intValue = i;
        queue_add(queue, value);
    }
    printf("\nIS_EMPTY: %d\n", queue_isEmpty(queue));

    printf("\nQUEUE: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", queue_poll(queue).intValue);
    }

    stack_remove(&queue);
    if(!queue) {
        printf("Queue removed\n");
    }
}

void hashMapDemo() {
    printf("\n\n\n---------- HASHMAP DEMO ----------\n");
    HashMap map = hashmap_create(100);
    HashmapValue defaultValue;
    defaultValue.intValue = -1;

    HashmapValue value;

    printf("\nIS_EMPTY: %d\n", hashmap_isEmpty(map));

    value.intValue = 1;
    hashmap_put(map, "Test", value);
    printf("\nValue of key Test: %d\n", hashmap_get(map, "Test", defaultValue).intValue);

    value.intValue = 6;
    hashmap_put(map, "Test", value);
    printf("\nValue of key Test: %d\n", hashmap_get(map, "Test", defaultValue).intValue);

    if(hashmap_containsKey(map, "Test2")) {
        hashmap_remove(map, "Test2");
    } else {
        printf("\nKey Test2 is not found\n");
    }

    hashmap_removeMap(&map);
    if(!map.table) {
        printf("\nHashMap removed\n");
    }
}

void binarySearchTreeDemo() {
    printf("\n\n\n---------- BINARY SEARCH TREE DEMO ----------\n");
    HashmapValue info;

    info.intValue = 1;

    TreeNode *root = bst_create(5, info);

    info.intValue = 2;
    bst_insert(root, 7, info);
    info.intValue = 3;
    bst_insert(root, 9, info);
    info.intValue = 4;
    bst_insert(root, 6, info);

    printf("Contains Key 5: %d\n", bst_containsKey(root, 5));
    printf("Contains Key 6: %d\n", bst_containsKey(root, 6));
    printf("Contains Key 7: %d\n", bst_containsKey(root, 7));
    printf("Contains Key 15: %d\n\n", bst_containsKey(root, 15));

    printf("Value of key 5: %d\n", bst_find(root, 5).intValue);
    printf("Value of key 9: %d\n", bst_find(root, 9).intValue);

    info.intValue = 10;
    bst_insert(root, 5, info);
    printf("Value of key 5: %d\n", bst_find(root, 5).intValue);
    info.intValue = 11;
    bst_insert(root, 9, info);
    printf("Value of key 9: %d\n", bst_find(root, 9).intValue);

    bst_remove(root, 6);
    bst_removeTree(&root);
    if(!root) {
        printf("\nBinary Search Tree removed\n");
    }

}

int main() {
    listDemo();
    stackDemo();
    queueDemo();
    hashMapDemo();
    binarySearchTreeDemo();
    return 0;
}