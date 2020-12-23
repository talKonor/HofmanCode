#include "SearchTreeNode.h"

BinaryTreeNode::BinaryTreeNode(Node value, BinaryTreeNode* left, BinaryTreeNode* right)
{
	this->value = value;
	this->left = left;
	this->right = right;
}

BinaryTreeNode::~BinaryTreeNode()
{
	delete left;
	delete right;
}
