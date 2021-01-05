#pragma once

#include "SearchTree.h"
#include<iostream>
#include<fstream>
#include "HoffmanHeap.h"
using namespace std;
void printTree(BiTreeNode* t1, int& codeSize, string code = "");
void insertToheap(Heap& h1, BiTreeNode* t1);
SearchTree& createTreeFromFile(ifstream& file);