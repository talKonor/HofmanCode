#pragma once
#include "BiTree.h"
/// <summary>
/// This class is an instance of BiTree. its a search tree.
/// </summary>
class SearchTree : public BiTree  {

public:
		SearchTree();
		virtual ~SearchTree();
		BiTreeNode* find(char key);
		void insert(Node item);
		void Delete(char key);
		BiTreeNode* Min();
		BiTreeNode* Max();
};