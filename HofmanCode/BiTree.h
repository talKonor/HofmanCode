#pragma once
struct Node {
	int frequency;
	char letter;
};
class BiTreeNode
{
public:
	BiTreeNode();
	BiTreeNode(Node data, BiTreeNode* left, BiTreeNode* right);
	~BiTreeNode();

	void inOrder();
	void preOrder();
	void postOrder();


private:
	Node data;
	BiTreeNode* left;
	BiTreeNode* right;
};

class BiTree {
public:
	BiTree();
	~BiTree();
private:
	BiTreeNode* root;
};

