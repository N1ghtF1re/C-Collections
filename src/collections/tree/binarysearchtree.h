//
// BINARY SEARCH TREE INTERFACE
//


/**
 * @file binarysearchtree.h
 * @author Alexandr Pankratiew
 * @brief File containing interface of Binary Search Tree
 * @note Integer field of node is used as id
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "../node.h"

typedef int BstKey;
typedef NodeInfo BstValue;

typedef struct TreeData {
    BstKey key;
    BstValue value;
} TreeData;

typedef struct TreeNode {
    TreeData info;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parrent;
} TreeNode;

TreeNode* bst_create(BstKey key, NodeInfo rootData);
void bst_insert(TreeNode *root, BstKey key, BstValue data);
NodeInfo bst_find(TreeNode *root, BstKey key);
NodeInfo bst_remove(TreeNode *root, BstKey key);
int bst_containsId(TreeNode *root, BstKey key);

#endif //BINARYSEARCHTREE_H
