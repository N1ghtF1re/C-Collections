<h1 align="center">C-Collections</h1>
<p align="center"><img width=200 src="https://b.kisscc0.com/20180817/vpe/kisscc0-array-data-structure-cube-computer-icons-can-stock-cube-array-5b774ba6dce746.3093911415345448069048.png?raw=true" style="width: 150px;"></p>

<p align="center">
<a href="https://github.com/N1ghtF1re/C-Collections/stargazers"><img src="https://img.shields.io/github/stars/N1ghtF1re/C-Collections.svg" alt="Stars"></a>
<a href="https://github.com/N1ghtF1re/C-Collections/releases"><img src="https://img.shields.io/badge/downloads-4-brightgreen.svg" alt="Total Downloads"></a>
<a href="https://github.com/N1ghtF1re/C-Collections/releases"><img src="https://img.shields.io/github/tag/N1ghtF1re/C-Collections.svg" alt="Latest Stable Version"></a>
<a href="https://github.com/N1ghtF1re/C-Collections/blob/master/LICENSE"><img src="https://img.shields.io/github/license/N1ghtF1re/C-Collections.svg" alt="License"></a>
</p>
 

## About
A library is a collection of collections for the C language.

## Realized collections
Currently the library contains:
+ Linked List
+ Queue
+ Stack
+ HashMap
+ Binary Search Tree

## Nodes type
The main type is specified in the node.h file.

By default, the informative part of the node is described by the following structure:

```C
typedef union NodeInfo {
    int intValue;
    char *stringValue;
    double realValue;
    void *pointerValue;
} NodeInfo;
```
