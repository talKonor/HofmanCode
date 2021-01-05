#pragma once
#include "BiTree.h"

class SearchTree : public BiTree  {

public:
		SearchTree();
		~SearchTree();
		BiTreeNode* find(char key);
		void insert(Node item);
		void Delete(char key);
		BiTreeNode* Min();
		BiTreeNode* Max();
};