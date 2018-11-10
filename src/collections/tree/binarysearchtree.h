//
// BINARY SEARCH TREE INTERFACE
//


/**
 * @file binarysearchtree.h
 * @author Alexandr Pankratiew
 * @brief File containing interface of Binary Search Tree
 * @note To change the type of the "key" field - you need to change it in the Kay typedef int BstKey and override the
 * implementation of methods bst_isKeyAbove(BstKey key1, BstKey key2), bst_isKeyBelow(BstKey key1, BstKey key2),
 * bst_isKeyEquals(BstKey key1, BstKey key2) in binarysearchtree.c
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
    struct TreeNode *parent;
} TreeNode;

TreeNode* bst_create(BstKey key, NodeInfo rootData);
void bst_insert(TreeNode *root, BstKey key, BstValue data);
BstValue bst_find(TreeNode *root, BstKey key);
BstValue bst_findMax(TreeNode *root);
BstValue bst_findMin(TreeNode *rooy);
void bst_remove(TreeNode *root, BstKey key);
void bst_removeWithChilds(TreeNode *root, BstKey key);
void bst_removeTree(TreeNode **root);
int bst_containsKey(TreeNode *root, BstKey key);
void bst_output(TreeNode *root);

#endif //BINARYSEARCHTREE_H
