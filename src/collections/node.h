//
// NODE TYPE
//


/**
 * Description of the collection node type
 * @file node.h
 */

#ifndef NODE_H
#define NODE_H

typedef union NodeInfo {
    int intValue;
    char *stringValue;
    double realValue;
    void *pointerValue;
} NodeInfo;

typedef struct Node {
    NodeInfo info;
    struct Node *next;
} Node;

#endif //NODE_H
