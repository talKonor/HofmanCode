#include "BiTree.h"
#include <iostream>

BiTreeNode::BiTreeNode()
{

	data = { 0,'\0' };
	left = nullptr;
	right = nullptr;
}

BiTreeNode::BiTreeNode(Node data, BiTreeNode* left, BiTreeNode* right)
{
	this->data = data;
	this->left = left;
	this->right = right;

}

BiTreeNode::BiTreeNode(const BiTreeNode& origin)
{
	left = origin.left;
	right = origin.right;
	data = origin.data;
}

BiTreeNode::~BiTreeNode()
{
	if (left != nullptr)
		delete left;
	if (right != nullptr)
		delete right;
}

bool BiTree::isEmpty()
{
	return (root == nullptr);
}

void BiTreeNode::inOrder()
{
	if (left != nullptr)
		left->inOrder();
	std::cout << data.getChar();
	if (right != nullptr)
		right->inOrder();
}

void BiTreeNode::preOrder()
{
	std::cout << data.getChar();
	if (left != nullptr)
		left->preOrder();
	if (right != nullptr)
		right->preOrder();
}

void BiTreeNode::postOrder()
{
	if (left != nullptr)
		left->postOrder();
	if (right != nullptr)
		right->postOrder();

	std::cout << data.getChar();
}

BiTree::BiTree()
{
	root = nullptr;
}
BiTree::BiTree(BiTreeNode* root)
{
	this->root = root;
}
BiTree::BiTree(const BiTree& origin) {
	root = origin.root;
}

void BiTree::makeEmpty() {
	delete root;
}

BiTree::~BiTree()
{
	root = nullptr;
}
