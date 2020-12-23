#pragma once
#include "Node.h"


class BinaryTreeNode
{
public:
	Node value;
	BinaryTreeNode *left, *right;

public:
	BinaryTreeNode();
	BinaryTreeNode(Node value, BinaryTreeNode* left, BinaryTreeNode* right);
	~BinaryTreeNode();
	Node getNode()const {
		return value;
	 }
    BinaryTreeNode* getLeftChild()const {
		return left;
	}
    BinaryTreeNode* getRightChild()const {
		return right;
	}
	const BinaryTreeNode operator->()const  {
		return *this;
	}
	//void  operator=(BinaryTreeNode* node)const;
	

};

