#pragma once

#include "SearchTree.h"
#include<iostream>
#include<fstream>
#include <stdlib.h>
#include "HoffmanHeap.h"
using namespace std;
void printTree(BiTreeNode* t1, int& codeSize, string code = "");
int builArrFromTree(SearchTree& tree, BiTree arr[]);
int insertNodeToArr(BiTreeNode* root, BiTree arr[]);
void insertToheap(Heap& h1, BiTreeNode* t1);
SearchTree& createTreeFromFile(ifstream& file);