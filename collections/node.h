//
// NODE TYPE
//

#ifndef NODE_H
#define NODE_H

typedef struct NodeInfo {
    int intValue;
} NodeInfo;

typedef struct Node {
    NodeInfo info;
    struct Node *next;
} Node;

#endif //NODE_H
