#pragma once
#include "node.h"
class BiTreeNode
{
public:
	BiTreeNode();
	BiTreeNode(Node data, BiTreeNode* left, BiTreeNode* right);
	~BiTreeNode();

	void inOrder();
	void preOrder();
	void postOrder();
	Node data;
	BiTreeNode* left;
	BiTreeNode* right;
};

class BiTree {
public:
	BiTree();
	BiTree(const BiTree& origin);
	void makeEmpty();
	~BiTree();
	BiTreeNode* root;
};

