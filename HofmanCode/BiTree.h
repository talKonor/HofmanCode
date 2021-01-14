#pragma once
#include "Node.h"
class BiTreeNode
{
public:
	BiTreeNode();
	BiTreeNode(Node data, BiTreeNode* left, BiTreeNode* right);
	BiTreeNode(const BiTreeNode& origin);
	~BiTreeNode();

	void inOrder();	//prints tree in inorder
	void preOrder(); //prints tree in preorder
	void postOrder();	//prints tree in postorder

	Node data;
	BiTreeNode* left; 
	BiTreeNode* right;
	BiTreeNode& operator =(const BiTreeNode& origin) = delete;
};

class BiTree {
public:
	BiTree();
	BiTree(BiTreeNode* root);
	BiTree(const BiTree& origin);
	virtual ~BiTree();
	void makeEmpty();
	bool isEmpty();
	BiTree& operator=(const BiTree& origin) {
		root = origin.root;
		return *this;
	}
	
	BiTreeNode* root;
};

