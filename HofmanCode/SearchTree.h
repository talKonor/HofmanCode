
#include "BiTree.h"

class SearchTree : public BiTree  {

public:
		SearchTree();
		~SearchTree();
		bool isEmpty();
		BiTreeNode* find(int key);
		void insert(Node item);
		void Delete(int key);
		BiTreeNode* Min();
		BiTreeNode* Max();
};