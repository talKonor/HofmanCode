#pragma once

#include "SearchTree.h"
#include<iostream>
#include<fstream>
 #include<map>
#include <stdlib.h>
#include "HoffmanHeap.h"
using namespace std;


//prints the coded letters and calculates the total size
void printHuffmanCode(BiTreeNode* t1, int& codeSize, string code = "");	  

//Creates an Array from a Bitree, the created array will NOT be the input tree, but a forest of trees, inorder
int buildArrFromTree(BiTree& tree, BiTree arr[]);	

//takes the node and creates a tree. inserst the node to the arr. works recursivaly.
int insertNodeToArr(BiTreeNode* root, BiTree arr[]);	

// reads the file. for each charecater searches for it in the tree.
//if found, adds +1 to its frequancy, otherwise adds that charecter to the tree.
SearchTree& createTreeFromFile(ifstream& file);

//This function is responable of building the Huffman tree from a search tree 
BiTree buildHuffmanTree(SearchTree& tree);