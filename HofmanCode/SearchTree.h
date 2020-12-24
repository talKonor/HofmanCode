#include"SearchTreeNode.h"

class BinaryTree  {

	public: 
		BinaryTreeNode* root;
	public:
		BinaryTree();
		~BinaryTree();
		bool isEmpty();
		BinaryTreeNode* find(int key);
		void insert(Node item);
		void Delete(int key);
		BinaryTreeNode* Min();
		BinaryTreeNode* Max();
};